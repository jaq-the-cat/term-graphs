#include "line.h"
#include <stdio.h>

void make_lines(Point d[], Point lines[][2], const size_t len_d) {
    for (int i=0, j=0; i<len_d-1; i++, j++) {
        lines[j][0] = d[i];
        lines[j][1] = d[i+1];
    }
}

void plot_line(int x0, int y0, int x1, int y1) {
    int dx =  abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1-y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;  /* error value e_xy */
    int e2;
    while (1) {   /* loop */
        mvaddch(x0, y0, 'x');
        if (x0 == x1 && y0 == y1) break;
        e2 = 2*err;
        if (e2 >= dy) { /* e_xy+e_x > 0 */
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) { /* e_xy+e_y < 0 */
            err += dx;
            y0 += sy;
        }
    }
}

void Gdraw_line(Point d[], const size_t len_d) {
    Point lines[len_d-1][2];
    make_lines(d, lines, len_d);

    for (int i=0; i<len_d-1; i++) {
        int x0 = lines[i][0].x, y0 = lines[i][0].y;
        int x1 = lines[i][1].x, y1 = lines[i][1].y;
        plot_line(y0, x0, y1, x1);
    }
}
