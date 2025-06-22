#!/bin/bash
set -e
OS=$(uname)

# Default libraries and flags
LIBS="$(pwd)/ncurses/lib -lncursesw -ltinfow -lm"
LIBS_DEBUG="$(pwd)/ncurses/lib -lncursesw_g -ltinfow_g -lm"

# Compilation flags
WARNINGS="-Wall -Wextra -Wpedantic -Wno-macro-redefined -Wno-unused-but-set-variable"
CFLAGS="-DNCURSES_WIDECHAR"
INCLUDE_DIR="-I$(pwd)/ncurses/include/ncursesw -I$(pwd)/ncurses/include"

# Platform-specific
if [ "$OS" = "Darwin" ]; then
	LINKER_FLAGS="-Wl,-search_paths_first"
	CFLAGS+=' -D_DARWIN_C_SOURCE'
	cc='clang'
elif [ "$OS" = "Linux" ];  then
	LINKER_FLAGS=""
	cc='gcc'
else
	echo "Unsupported OS: $OS" ;
	exit 1
fi

# Handle arguments
for arg in "$@"; do
    case $arg in
        -r|--release)
            O="-O2"
            WARNINGS+=" -Werror"
            STRIP_BINARY=true
            ;;
        -d|--debug)
            O="-O0"
            DEBUG="-g"
            LIBS=$LIBS_DEBUG
            ;;
        *)
            echo "Unknown option: $arg"
            exit 1
            ;;
    esac
done

in='all.c'
out='all'

# Final command
$cc $O $WARNINGS $CFLAGS $INCLUDE_DIR $DEBUG $in $LINKER_FLAGS -L$LIBS -o $out

if [ "$STRIP_BINARY" = true ]; then
    strip $out
fi
