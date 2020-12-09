#include "render.h"

GWin Ginit() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    return stdscr;
}

void Gend(GWin stdscr) {
    nodelay(stdscr, false);
    curs_set(1);
    echo();
    nocbreak();
    endwin();
}
