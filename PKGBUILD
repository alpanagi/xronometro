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
b2sums=("babcc826d58b0e7c898219a1fa27fab1f556cc7056c41917af4881d5d2afac81758cd5d91c87cc2f0b5f9ec3910dbdd24c5ce743be292152ba6ecd3f98d41bcc")

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
