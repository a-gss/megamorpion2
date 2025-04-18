#!/bin/sh
set -e

# Download ncurses-6.5 and build it statically
VER='6.5'
# Cleanup
rm -rf ncurses/
rm -rf ncurses-${VER}/
rm -f  ncurses-${VER}.tar.gz
# Download
wget https://invisible-mirror.net/archives/ncurses/ncurses-${VER}.tar.gz
tar -xzf ncurses-${VER}.tar.gz
rm ncurses-${VER}.tar.gz
mkdir ncurses
cd ncurses-${VER}
./configure --prefix=${PWD}/../ncurses \
  --enable-static \
  --enable-widec \
  --with-normal \
  --with-debug \
  --with-termlib \
  --disable-shared \
  --without-hashed-db \
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
echo ncurses-${VER} successfully installed in ${PWD}/ncurses !
