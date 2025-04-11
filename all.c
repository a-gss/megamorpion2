#include <stdlib.h>
#include "ncurses.h"

int main(void)
{
	setenv("TERM", "vt100", 1);  // Remplace "xterm" par "vt100" si nécessaire
    initscr();
    addstr("Goodbye, cruel C programming!");
    refresh();
    getch();

    endwin();
    return 0;
 }
