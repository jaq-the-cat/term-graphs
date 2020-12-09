#include "line.h"
#include "generic.h"

void make_lines(LineData d, Point lines[][2], const size_t len_d) {
    for (int i=0, x=0; i<len_d-1; i++) {
        lines[i][0] = POINT(x, d[i]);
        x++;
        lines[i][1] = POINT(x, d[i+1]);
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

void Gdraw_line(int gx, int gy, int gw, int gh, LineData d, const size_t len_d, char *title) {
    Point lines[len_d-1][2];

    int graph_h, graph_w = len_d;
    for (int i=0; i<len_d; i++)
        if (d[i] > graph_h)
            graph_h = d[i];
    gh--;
    graph_lines(gy, gh, gx, (gw+2)*2);

    make_lines(d, lines, len_d);
    for (int i=0; i<len_d-1; i++) {
        int x0 = trans_d(graph_w, gw-1, lines[i][0].x) + gx + 1;
        int y0 = gh - trans_d(graph_h, gh-1, lines[i][0].y) + gy - 1;
        int x1 = trans_d(graph_w, gw-1, lines[i][1].x) + gx + 1;
        int y1 = gh - trans_d(graph_h, gh-1, lines[i][1].y) + gy - 1;
        plot_line(x0, y0, x1, y1);
    }

    mvaddstr(gh + 1, gx + 1, title);
}
