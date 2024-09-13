# Maintainer: Alexandros Panagiotakis <dev@alpanagi.com>

pkgname=countdown
pkgver=1.0.0
pkgrel=1
pkgdesc="A Countdown Timer for the Terminal"
arch=("x86_64")
url="https://github.com/alpanagi/countdown"
license=("GPL-3.0-or-later")
depends=(gcc-libs glibc)
makedepends=(cmake)
source=("https://github.com/alpanagi/countdown/archive/v${pkgver}.tar.gz")
b2sums=("ccc21e7428742ecb814d38175aa5b8faedd6b8c9df78613f37c5e73cb88e3d251f8928c06f67125c3bf06fd96a37b71c711d4bee2c2f4b39811fcbeefbe72130")

build() {
	cd "${pkgname}-${pkgver}"
    mkdir build/
    cd build
    cmake ../
    cmake --build .
}

package() {
    mkdir -p "${pkgdir}/usr/bin/"
    cp "${srcdir}/${pkgname}-${pkgver}/build/${pkgname}" "${pkgdir}/usr/bin/"
}
