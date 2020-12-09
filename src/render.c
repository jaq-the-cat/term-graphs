#include "render.h"

GWin Ginit() {
    initscr();
    cbreak();
    noecho();
    return stdscr;
}

void Gend(GWin stdscr) {
    nodelay(stdscr, false);
    echo();
    nocbreak();
    endwin();
}
