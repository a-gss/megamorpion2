#!/bin/sh
set -e
# Download ncurses-6.5 and build it statically
VER='6.5'
wget https://invisible-mirror.net/archives/ncurses/ncurses-${VER}.tar.gz
tar -xzf ncurses-${VER}.tar.gz
rm ncurses-${VER}.tar.gz
mkdir ncurses
cd ncurses-${VER}
./configure --prefix=${PWD}/../ncurses \
  --enable-static \
  --enable-widec \
  --disable-db-install \
  --disable-shared \
  --with-normal \
  --with-debug \
  --with-termlib \
  --with-terminfo-dirs=/usr/share/terminfo:/usr/local/share/terminfo \
  --without-ada \
  --without-cxx --without-cxx-binding \
  --without-progs \
  --without-tests \
  --without-manpages \
  --without-curses

make -j$(nproc) && make install
cd ..
rm -rf ncurses-${VER}
rm -rf ncurses/bin
echo ---------------------------------------------------------------------------
echo ncurses-${VER} successfully compiled in ${PWD}/ncurses !

# For Windows:
# prebuilt binaries in <https://invisible-mirror.net/archives/ncurses/win32/?C=M;O=D>
# "win32/mingw64.zip"
