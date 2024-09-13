#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <pulse/error.h>
#include <pulse/sample.h>
#include <pulse/simple.h>
#include <regex>
#include <thread>

const int SAMPLE_RATE = 44100;
const int SAMPLES = SAMPLE_RATE * 4.2;

void die_arguments() {
  std::cerr << "Invalid argument\n" << "Usage: countdown HH:MM:SS" << std::endl;
  exit(1);
}

void die_pulseaudio_connect() {
  std::cerr << "Failed to connect to pulseaudio" << std::endl;
  exit(1);
}

void die_pulseaudio_write(int err) {
  std::cerr << "Failed to write to pulseaudio: " << pa_strerror(err)
            << std::endl;
  exit(1);
}

int16_t wave(int idx) {
  if (idx % SAMPLE_RATE < (SAMPLE_RATE * 0.5)) {
    return 0;
  }

  double t = (double)idx / (double)SAMPLE_RATE;
  int16_t wave =
      (int16_t)(std::sin(M_PI * t * 660.0) * ((double)INT16_MAX / 4.0));
  return wave;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    die_arguments();
  }

  std::string input(argv[1]);
  std::regex input_regex{"(?:(\\d+):)?(?:(\\d+):)?(\\d+)"};
  std::smatch matches;
  if (!std::regex_match(input, matches, input_regex)) {
    die_arguments();
  }

  int hours = 0, minutes = 0, seconds = 0;
  if (matches[2].str().length() == 0) {
    minutes = std::atoi(matches[1].str().c_str());
  } else {
    hours = std::atoi(matches[1].str().c_str());
    minutes = std::atoi(matches[2].str().c_str());
  }
  seconds = std::atoi(matches[3].str().c_str());

  int duration = hours * 3600 + minutes * 60 + seconds;
  while (duration > 0) {
    hours = duration / 3600;
    minutes = (duration % 3600) / 60;
    seconds = (duration % 60);

    std::cout << "\r";
    std::cout << std::setfill('0') << std::setw(2) << hours << ':';
    std::cout << std::setfill('0') << std::setw(2) << minutes << ':';
    std::cout << std::setfill('0') << std::setw(2) << seconds << std::flush;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    duration--;
  }
  std::cout << std::endl;

  pa_simple *s;
  pa_sample_spec ss;
  ss.format = PA_SAMPLE_S16NE;
  ss.channels = 1;
  ss.rate = 44100;
  s = pa_simple_new(nullptr, "countdown", PA_STREAM_PLAYBACK, nullptr, "Alarm",
                    &ss, nullptr, nullptr, nullptr);

  if (s == nullptr) {
    die_pulseaudio_connect();
  }

  int16_t data[SAMPLES];
  for (int i = 0; i < SAMPLES; i++) {
    data[i] = wave(i);
  }

  int err;
  if (pa_simple_write(s, &data[0], 2 * SAMPLES, &err) < 0) {
    die_pulseaudio_write(err);
  }

  pa_simple_free(s);
}
