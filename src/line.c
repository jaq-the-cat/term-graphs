#include "line.h"
#include <stdio.h>

void make_lines(Point d[], Point lines[][2], const size_t len_d) {
    for (int i=0, j=0; i<len_d-1; i++, j++) {
        lines[j][0] = d[i];
        lines[j][1] = d[i+1];
    }
}

void Gdraw_line(Point d[], const size_t len_d) {
    Point lines[15][2];
    make_lines(d, lines, len_d);

    for (int i=0; i<3; i++) {
        int x1 = lines[i][0].x, y1 = lines[i][0].y;
        int x2 = lines[i][1].x, y2 = lines[i][1].y;
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
        for (int j=0; j<step; j++) {
            mvaddch(y, x, 'x');
            x = x + dx;
            y = y + dy;
        }
    }
}
