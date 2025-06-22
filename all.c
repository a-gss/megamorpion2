#include "ncurses/include/ncursesw/ncurses.h"
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int ch = 0; // global

#include "megamorpion.h"
#include "screen1.h"
#include "screen2.h"
#include "screen3.h"

int main(void)
{
	//setenv("TERM", "vt100", 1);                // xterm doesn't work on WSL
	// WSL:
	// - https://stackoverflow.com/questions/50495557/ncurses-test-programs-failing-with-message-error-opening-terminal-xterm
	// - https://github.com/microsoft/terminal/issues/240

    initscr();
    if (has_colors()) {
        start_color();
    } else {
        endwin();
        printf("Your terminal doesn't support colors.\n");
        exit(1);
    }

    curs_set(0);            // disable cursor
    //raw();                // disable special keys [p.413]
    cbreak();
    noecho();               // disable typed characters on the screen
    keypad(stdscr, TRUE);   // enable keypad directionnal arrows
	setlocale(LC_ALL, "");  // Unicode characters

    // Generate random color pairs at runtime
    int colorA, colorB;
    srand(time(NULL));
    colorA = (rand() % 6) + 1;
    do { colorB = (rand() % 6) + 1; } while(colorB == colorA);
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, colorA, COLOR_BLACK);
    init_pair(2, colorB, COLOR_BLACK);

//goto screen3;

    #include "screen1.inc"
    #include "screen2.inc"
    //#include "screen3.inc"


// screen 3
screen3:
    clear();
    print_header(ch);

    // Print 9 small grids

    if (ch == TERM_RESIZE) ;
    for (int xOff=0; xOff<3; xOff++) {
        for(int yOff=0; yOff<3; yOff++) {
            printGrid(3, 1,
                // initial space + N*grid height + spacer
                (LINES-BIG_GRID_HEIGHT)/2 + 1 + yOff*(SMALL_GRID_HEIGHT + 3),
                (COLS-BIG_GRID_WIDTH)/2 + 3 + xOff*(SMALL_GRID_WIDTH + 5)
            );
        }
    }

    printGrid(15, 7, (LINES-BIG_GRID_HEIGHT)/2, (COLS-BIG_GRID_WIDTH)/2 + 1); // BIG GRID

    getch();

    // ------------------------------------------------------------------------
    //clear();
    //do {
    //    mvprintw(0, 0, "Le debuggueur de touche. [ENTER] pour quitter.");
    //    mvprintw(1, 0, " %d     ", ch);
    //    mvprintw(2, 0, " %c     ", (char)ch);
    //    getCH();
    //} while(ch != KEY_ENTER);

    endwin();
    return 0;
}
