#include "ncurses.h"
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>
#include <string.h>

/* SUR MAC-OS */
#define MORP_ENTER       10
#define MORP_ESCAPE      27
#define MORP_SPACE       32
#define MORP_VIRGULE     44
#define MORP_QUESTION    63
#define MORP_BACKSPACE  127

void print_header(int ch) {
    attron(A_DIM);
        mvprintw(0,0, "[ESC] pour quitter.");
        mvprintw(0, COLS-3, "[?]");                   // je voulais rajouter un menu qui explique les regles/les commandes
        mvprintw(0, COLS/2 -2, "%d-%d", LINES, COLS); // debug
        mvprintw(1, COLS-4, " %d ", ch);              // debug de touches
        mvprintw(2, COLS-3, " %c ", (char)ch);        // debug de touches
    attroff(A_DIM);
}

int editText(char buf[64], int y, int x);

int main(void)
{
	//setenv("TERM", "vt100", 1);                // xterm doesn't work on WSL
	// WSL:
	// - https://stackoverflow.com/questions/50495557/ncurses-test-programs-failing-with-message-error-opening-terminal-xterm
	// - https://github.com/microsoft/terminal/issues/240

/*
	setlocale(LC_ALL, "");                      // Unicode characters
    initscr();                                  // start the screen
    //raw();                                      // disable special keys [p.413]
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);    // define palette 0 : white text/black background
    noecho();                                  // disable typed characters on the screen
    keypad(stdscr, TRUE);                      // let you use arrow keys
    curs_set(0);                               // disable cursor

    int ch = getch();

    uint8_t x = 0;
    uint8_t y = 0;
    while (ch != MORP_ESCAPE) {
        // Update ---------
        print_header(ch);

        move(y, x);
        printw("o");

        // Draw -----------
        refresh();

        // Get input ------
        ch = getch();
    }
*/
    initscr();
    if (has_colors()) {
        start_color();
    } else {
        endwin();
        printf("Your terminal doesn't support colors.\n");
        //exit(1);
    }


    curs_set(0);    // disable cursor
    raw();          // disable special keys [p.413]
    noecho();       // disable typed characters on the screen

    //int ch = 0;          // variable de touche pressée

    // Generate random color pairs at runtime
    int colorA, colorB;
    srand(time(NULL));
    colorA = (rand() % 6) + 1;
    do { colorB = (rand() % 6) + 1; } while(colorB == colorA);
    init_pair(1, colorA, COLOR_BLACK);
    init_pair(2, colorB, COLOR_BLACK);


    char nameBuffer[64];
    char namePlayer1[64];
    char namePlayer2[64];

    attrset(COLOR_PAIR(1));
    attron(A_STANDOUT);
    addstr("o");
    attroff(A_STANDOUT);
    addstr(" Player 1> ");
    int nameLength = editText(nameBuffer, 0, 12);

    flash();

    move(1, 0);
    attrset(COLOR_PAIR(2));
    attron(A_STANDOUT);
    addstr("x");
    attroff(A_STANDOUT);
    addstr(" Player 2> ");
    nameLength = editText(nameBuffer, 1, 12);
    flash();

    printw("\n%s VS %s !!!", namePlayer1, namePlayer2);
    flash();




    // screen 3: game


    endwin();
    return 0;
 }

int editText(char buf[64], int y, int x)
{
    int ch = 0;
    int charCount = 0;

    while(ch != MORP_ENTER) {
        switch (ch) {
        default:
            mvaddch(y, x+charCount, ch);
            buf[charCount] = ch;
            charCount++;
            break;

        case MORP_BACKSPACE:
            if (charCount > 0) {
                mvprintw(y, x+charCount-1, "      ");
                buf[charCount] = '\0';
                charCount--;
            } break;

        case MORP_ESCAPE:
            endwin();
            exit(0);

        case KEY_LEFT:
            mvprintw(8, 0, "left!");
            break;

        case MORP_ENTER: break;
        case 0: break;
        }

        // Display cursor
        attron(A_BLINK | A_REVERSE);
            mvaddch(y, x+charCount, ' ');
        attroff(A_BLINK | A_REVERSE);

        ch = getch();
    }

    // Erase cursor
    mvaddch(y, x+charCount, ' ');

    return charCount;
}
