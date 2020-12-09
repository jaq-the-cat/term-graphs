#include "line.h"
#include "generic.h"

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

void Gdraw_line(int gx, int gy, int gh, LineData d, const size_t len_d, int x_growth, char *xlabel, char *ylabel) {
    Point lines[len_d-1][2];

    int line_h, line_w = len_d*x_growth;
    for (int i=0; i<len_d; i++)
        if (d[i] > line_h)
            line_h = d[i];

    gh--;

    graph_lines(gy, gh, gx, len_d*2*x_growth-3*2);
    make_lines(d, lines, len_d, x_growth);

    for (int i=0; i<len_d-1; i++) {
        int x0 = lines[i][0].x + gx;
        int y0 = trans_h(line_h, gh-1, lines[i][0].y) + gy;
        int x1 = lines[i][1].x + gx;
        int y1 = trans_h(line_h, gh-1, lines[i][1].y) + gy;
        plot_line(x0, y0, x1, y1);
    }

    mvaddstr(gh, gx+2, xlabel);
    mvaddstr(gh, gx+2 + strlen(xlabel) + 1, "-v");
    mvaddstr(gh-1, gx + 2, "<-");
    mvaddstr(gh-1, gx + 5, ylabel);
}
