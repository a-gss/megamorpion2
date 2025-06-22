#define BIG_GRID_HEIGHT   23
#define BIG_GRID_WIDTH    47
#define SMALL_GRID_WIDTH  11
#define SMALL_GRID_HEIGHT  5

void printGrid(int width, int height, int yOff, int xOff)
{
    // horitonzal lines
    for (int i=0; i<3; i++) {
        mvhline(yOff+height, xOff + i*width + i, ACS_HLINE, width);
        mvhline(yOff+2*height+1, xOff + i*width + i, ACS_HLINE, width);
    }

    // vertical lines
    mvvline(yOff, xOff + width, ACS_VLINE, 3*height + 2);
    mvvline(yOff, xOff + 2*width+1, ACS_VLINE, 3*height + 2);

    // nodes
    // i don't know which way is the best honestly so i'll just leave both implementations
    // sequentiel
    mvaddch(yOff + 1*height + 0, xOff + 1*width + 0, ACS_PLUS);
    mvaddch(yOff + 1*height + 0, xOff + 2*width + 1, ACS_PLUS);
    mvaddch(yOff + 2*height + 1, xOff + 1*width + 0, ACS_PLUS);
    mvaddch(yOff + 2*height + 1, xOff + 2*width + 1, ACS_PLUS);

    /* loop
    for (int dy = 1; dy <= 2; dy++) {
        for (int dx = 1; dx <= 2; dx++) {
           mvaddch(yOff + dy*height + (dy==2), xOff + dx*width + (dx==2), ACS_PLUS);
        }
    } */
}
