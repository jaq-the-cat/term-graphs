#include "line.h"
#include <stdio.h>

void make_lines(LineData d, Point lines[][2], const size_t len_d, int xg) {
    int x = 0;
    for (int i=0, j=0; i<len_d-1; i++, j++) {
        lines[j][0] = POINT(x, d[i]);
        x += xg;
        lines[j][1] = POINT(x, d[i+1]);
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
        mvaddch(y0, x0*2, 'x');
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

int get_h(LineData d, int len_d) {

}

void Gdraw_line(int gx, int gy, LineData d, const size_t len_d, int x_growth) {
    Point lines[len_d-1][2];

    int line_h, line_w = len_d*x_growth;
    for (int i=0; i<len_d; i++)
        if (d[i] > line_h)
            line_h = d[i];
    line_h++;

    make_lines(d, lines, len_d, x_growth);

    // draw lines
    for (int y=gy; y<line_h+gy; y++)
        mvaddch(y, gx, '+');
    for (int x=gx; x<line_w*2+gx; x+=2)
        mvaddstr(line_h+gy, x, "+ ");

    for (int i=0; i<len_d-1; i++) {
        int x0 = lines[i][0].x + gx + 1, y0 = lines[i][0].y + gy;
        int x1 = lines[i][1].x + gx + 1, y1 = lines[i][1].y + gy;
        plot_line(x0, y0, x1, y1);
    }
}
