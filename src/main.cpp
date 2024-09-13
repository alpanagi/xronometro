#include <chrono>
#include <iomanip>
#include <iostream>
#include <regex>
#include <thread>

void die() {
  std::cerr << "Invalid argument\n" << "Usage: countdown HH:MM:SS" << std::endl;
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    die();
  }

  std::string input(argv[1]);
  std::regex input_regex{"(?:(\\d+):)?(?:(\\d+):)?(\\d+)"};
  std::smatch matches;
  if (!std::regex_match(input, matches, input_regex)) {
    die();
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
}
