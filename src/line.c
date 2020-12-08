#include "line.h"

void Gdraw_line(Data d, size_t len_d) {
    int x1 = 1, y1 = 1;
    int x2 = 5, y2 = 5;
    int dx = (x2 - x1);
    int dy = (y2 - y1);

    int step;
    if (abs(dx) >= abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    dx = dx / step;
    dy = dy / step;
    int x = x1;
    int y = y1;
    for (int i=0; i < step; i++) {
        mvaddch(y, x, 'x');
        x = x + dx;
        y = y + dy;
    }
}
