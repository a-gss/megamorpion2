#!/bin/sh
WARNINGS="-Wall -Wextra -Wpedantic"
CFLAGS="-D_DARWIN_C_SOURCE -DNCURSES_WIDECHAR"
INCLUDE_DIR="-I$(pwd)/ncurses/include/ncursesw -I$(pwd)/ncurses/include"
LIBS="-L$(pwd)/ncurses/lib -Wl,-search_paths_first -lncursesw -ltinfow -lm"
LIBS_DEBUG="-L$(pwd)/ncurses/lib -lncursesw_g -ltinfow_g -lm"

while getopts ":hcdvsr" opt; do
    case $opt in
        r | release) WARNINGS+="-Werror" ;;
        d | debug)
            DEBUG="-g"
            LIBS=$LIBS_DEBUG
            ;;
        \?) echo "Invalid option: -$OPTARG" >&2 ; exit 1 ;;
    esac
done

clang $WARNINGS $CFLAGS $INCLUDE_DIR $DEBUG all.c $LIBS -o all
