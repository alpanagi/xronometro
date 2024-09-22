# Maintainer: Alexandros Panagiotakis <dev@alpanagi.com>

pkgname=xronometro
pkgver=1.0.0
pkgrel=1
pkgdesc="A Countdown Timer for the Terminal"
arch=("x86_64")
url="https://github.com/alpanagi/xronometro"
license=("GPL-3.0-or-later")
depends=(gcc-libs glibc)
makedepends=(cmake)
source=("https://github.com/alpanagi/xronometro/archive/v${pkgver}.tar.gz")
b2sums=("c57b05ea26d3a1fd2848a39a6ab0e6dbb559482d323dc67c8e5679b390bed5a254365002d257fc62b519127091bd2727c95df4004a282b12eed6c8efab82257c")

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
