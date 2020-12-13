# Maintainer: Caleb Rotello <calebrotello[at]protonmail[dot]com>

pkgname=aurgrep
pkgver=0.0.1
pkgrel=1
pkgdesc='Simple tool to search, download, and update AUR packages.'
url='https://github.com/calebrotello/aurgrep'
arch=('any')
license=('MIT')
depends=('git' 'libcurlpp')
makedepends('cmake')

source=('$url/archive/master.tar.gz')

prepare() {
    cd "$pkgname-$pkgver"
    mkdir build
    cmake CMakeLists.txt build
}

build() {
    cd "$pkgname-$pkgver/build"
    ./configure --prefix=/usr
    make
#    mkdir build
#    cmake CMakeLists.txt build
}

package() {
    cd "$pkgname-$pkgver/build"
    make DESTDIR="$pkgdir/" install
    #cmake --build build -- DESTDIR="$pkgdir" install
}
