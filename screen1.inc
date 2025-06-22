do {
    clear();
    mvprintw(0, 0, "Press [esc] to quit");
    printTitle();

//cross();

    // Color selector
    attron(COLOR_PAIR(1));
    mvprintw(LINES/2+11 , COLS/2 - 9, "^");
    mvprintw(LINES/2+13 , COLS/2 - 9, "v");
    attron(A_STANDOUT);
    mvprintw(LINES/2+12, COLS/2 - 5 -8, "Player 1");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(LINES/2+12, COLS/2 + 6, "Player 2");
    attroff(A_STANDOUT);
    mvprintw(LINES/2+12, COLS/2 + 4, "<");
    mvprintw(LINES/2+12, COLS/2 + 15, ">");
    attroff(COLOR_PAIR(2));

    attron(A_BLINK);
    mvprintw(LINES/2+15, COLS/2 - 7, "> Press ENTER <");
    attroff(A_BLINK);

    switch (ch){
        case KEY_UP:    if (--colorA == 0) colorA = 6; break;
        case KEY_LEFT:  if (--colorB == 0) colorB = 6; break;
        case KEY_DOWN:  if (++colorA == 7) colorA = 1; break;
        case KEY_RIGHT: if (++colorB == 7) colorB = 1; break;
        default: break;
    }

    init_pair(1, colorA, COLOR_BLACK);
    init_pair(2, colorB, COLOR_BLACK);

    ch = getCH();
} while (ch != KEY_ENTER);
