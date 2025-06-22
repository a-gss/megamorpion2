// screen 1
static void printTitle(void)
{
    int y_mega = LINES/2 - 14 ;
    int x_mega = COLS/2  - 30;
    int y_morp = LINES/2 - 14;
    int x_morp = COLS/2  - 31;

    attron(COLOR_PAIR(1));
    mvprintw(y_mega, x_mega+6, "___       ___");
    mvprintw(y_mega+1, x_mega+6, "`MMb     dMM'                            ");
    mvprintw(y_mega+2, x_mega+7, "MMM.   ,PMM                             ");
    mvprintw(y_mega+3, x_mega+7, "M`Mb   d'MM   ____     __       ___     ");
    mvprintw(y_mega+4, x_mega+7, "M YM. ,P MM  6MMMMb   6MMbMMM 6MMMMb    ");
    mvprintw(y_mega+5, x_mega+7, "M `Mb d' MM 6M'  `Mb 6M'`Mb  8M'  `Mb   ");
    mvprintw(y_mega+6, x_mega+7, "M  YM.P  MM MM    MM MM  MM      ,oMM   ");
    mvprintw(y_mega+7, x_mega+7, "M  `Mb'  MM MMMMMMMM YM.,M9  ,6MM9'MM   ");
    mvprintw(y_mega+8, x_mega+7, "M   YP   MM MM        YMM9   MM'   MM   ");
    mvprintw(y_mega+9, x_mega+7, "M   `'   MM YM    d9 (M      MM.  ,MM   ");
    mvprintw(y_mega+10, x_mega+6, "_M_      _MM_ YMMMM9   YMMMMb.`YMMM9'Yb.");
    mvprintw(y_mega+11, x_mega+29, "6M    Yb");
    mvprintw(y_mega+12, x_mega+29, "YM.   d9");
    mvprintw(y_mega+13, x_mega+30, "YMMMM9");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(y_morp+11, x_morp, "___       ___");
    mvprintw(y_morp+12, x_morp, "`MMb     dMM'");
    mvprintw(y_morp+13, x_morp, " MMM.   ,PMM");
    mvprintw(y_morp+14, x_morp, " M`Mb   d'MM   _____  ___  __ __ ____  ___   _____  ___  __   ");
    mvprintw(y_morp+15, x_morp, " M YM. ,P MM  6MMMMMb `MM 6MM `M6MMMMb `MM  6MMMMMb `MM 6MMb  ");
    mvprintw(y_morp+16, x_morp, " M `Mb d' MM 6M'   `Mb MM69 \"  MM'  `Mb MM 6M'   `Mb MMM9 `Mb");
    mvprintw(y_morp+17, x_morp, " M  YM.P  MM MM     MM MM'     MM    MM MM MM     MM MM'   MM ");
    mvprintw(y_morp+18, x_morp, " M  `Mb'  MM MM     MM MM      MM    MM MM MM     MM MM    MM ");
    mvprintw(y_morp+19, x_morp, " M   YP   MM MM     MM MM      MM    MM MM MM     MM MM    MM ");
    mvprintw(y_morp+20, x_morp, " M   `'   MM YM.   ,M9 MM      MM.  ,M9 MM YM.   ,M9 MM    MM ");
    mvprintw(y_morp+21, x_morp, "_M_      _MM_ YMMMMM9 _MM_     MMYMMM9 _MM_ YMMMMM9 _MM_  _MM_");
    mvprintw(y_morp+22, x_morp+31, "MM");
    mvprintw(y_morp+23, x_morp+31, "MM");
    mvprintw(y_morp+24, x_morp+30, "_MM_");
    mvprintw(y_morp+12, x_morp+39, "68b");
    mvprintw(y_morp+13, x_morp+39, "Y89");
    attroff(COLOR_PAIR(2));
}
