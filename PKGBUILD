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
b2sums=("d3fdd6de30613cfc5080efa55a7acdaa05e4839415ea109a42458980f8370d0b8930596306b723e87fa0ee07cc17c72d2126ece436eeb988f1d89a597a976a24")

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
