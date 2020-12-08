#include "render.h"

GWin Ginit() {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, true);
    return stdscr;
}

void Gend(GWin stdscr) {
    nodelay(stdscr, false);
    echo();
    nocbreak();
    endwin();
}
