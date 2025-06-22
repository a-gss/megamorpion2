{
    clear();
    attrset(COLOR_PAIR(0));
    mvprintw(0, 0, "Press [esc] to quit");

    char p1_name[64];
    attrset(COLOR_PAIR(1));
    attron(A_STANDOUT);
    mvprintw(2, 0, "o");
    attroff(A_STANDOUT);
    addstr(" Player 1> ");
    editText(p1_name, 64, 2, 12);

    char p2_name[64];
    move(1, 0);
    attrset(COLOR_PAIR(2));
    attron(A_STANDOUT);
    mvprintw(3, 0, "x");
    attroff(A_STANDOUT);
    mvprintw(3, 1, " Player 2> ");
    editText(p2_name, 64, 3, 12);

    // wait any key is pressed
    do {
        // erase shit
        move(LINES/2, 0);
        clrtoeol();

        // print cool message
        int coolmsglen = strlen(p1_name) + strlen(p2_name) + 4; // +4 is " VS "
        move(LINES/2, (COLS - coolmsglen)/2);

        attron(A_STANDOUT | COLOR_PAIR(1));
        printw("%s", p1_name);
        attroff(A_STANDOUT | COLOR_PAIR(1));

        printw(" VS ");

        attron(A_STANDOUT | COLOR_PAIR(2));
        printw("%s", p2_name);
        attroff(A_STANDOUT | COLOR_PAIR(2));

        getCH();
    } while (ch == TERM_RESIZE);
}
