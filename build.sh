#!/bin/sh
set -e
OS=$(uname) # Detect OS

# Default libraries and flags
LIBS="-L$(pwd)/ncurses/lib -lncursesw -ltinfow -lm"
LIBS_DEBUG="-L$(pwd)/ncurses/lib -lncursesw_g -ltinfow_g -lm"

# Compilation flags
WARNINGS="-Wall -Wextra -Wpedantic"
CFLAGS="-DNCURSES_WIDECHAR"
INCLUDE_DIR="-I$(pwd)/ncurses/include/ncursesw -I$(pwd)/ncurses/include"

# Platform-specific
if   [ "$OS" = "Darwin" ]; then
	LINKER_FLAGS="-Wl,-search_paths_first"
	CFLAGS+=' -D_DARWIN_C_SOURCE'
	cc='clang'
elif [ "$OS" = "Linux" ];  then
	LINKER_FLAGS="--search_paths_first"
	cc='gcc'
else
	echo "Unsupported OS: $OS" ;
	exit 1
fi

# Handle arguments
for arg in "$@"; do
    case $arg in
        -r|--release)
            WARNINGS+="-Werror"
            ;;
        -d|--debug)
            DEBUG="-g"
            LIBS=$LIBS_DEBUG
            ;;
        *) 
            echo "Unknown option: $arg"
            exit 1
            ;;
    esac
done

$cc $WARNINGS $CFLAGS $INCLUDE_DIR $DEBUG all.c $LIBS -o all
