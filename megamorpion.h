#include "ncurses/include/ncursesw/ncurses.h"
#define PLAYER1 1
#define PLAYER2 2

/* MAC-OS AZERTY */
#define KEY_ENTER           10
#define KEY_ESCAPE          27
#define KEY_SPACE           32
#define KEY_VIRGULE         44
#define KEY_QUESTION        63
#define KEY_BACKSPACE      127
#define KEY_CTRL_BACKSPACE  21
#define KEY_DOWN           258
#define KEY_UP             259
#define KEY_LEFT           260
#define KEY_RIGHT          261
#define KEY_E_ACCENT_AIGU  169
#define TERM_RESIZE        410

typedef struct {
    unsigned int x;
    unsigned int y;
} vec2;

typedef struct {
    unsigned int bigX;
    unsigned int bigY;
    unsigned int smallX;
    unsigned int smallY;
} cursorPos_t;

void print_header(int ch)
{
    attron(A_DIM);
        mvprintw(0,0, "Press [esc] to quit.");
        mvprintw(0, COLS-3, "[?]");                   // je voulais rajouter un menu qui explique les regles/les commandes
        mvprintw(0, COLS/2 -2, "%d-%d", LINES, COLS); // debug
        mvprintw(1, COLS-4, " %d ", ch);              // debug de touches
        mvprintw(2, COLS-3, " %c ", (char)ch);        // debug de touches
    attroff(A_DIM);
}

int getCH(void)
{
    ch = getch();
    if (ch == KEY_ESCAPE){
        endwin();
        exit(0);
    }
    return ch;
}

void cross(void)
{
    //croix multi centrée pour giga centrage actif
    mvvline(0, COLS/2, ACS_VLINE, LINES);
    mvhline(LINES/2, 0, ACS_HLINE, COLS);
    mvaddch(LINES/2, COLS/2, ACS_PLUS);
}

void erase_cursor(cursorPos_t cursorPos)
{
    move(cursorPos.bigY + cursorPos.smallY, cursorPos.bigX + cursorPos.smallX);
    addch(' ');
}

void print_cursor(cursorPos_t cursorPos)
{
    move(cursorPos.bigY + cursorPos.smallY, cursorPos.bigX + cursorPos.smallX);
    attron(A_STANDOUT | COLOR_PAIR(1));
        addch(' ');
    attroff(A_STANDOUT | COLOR_PAIR(1));
}
