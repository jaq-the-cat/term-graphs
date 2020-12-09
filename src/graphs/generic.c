#include "generic.h"

int trans_h(float actual_h, float gh, float h) {
    return h / (actual_h / gh);
}

void graph_lines(int gy, int gh, int gx, int graph_w) {
    for (int y=gy; y<gh+gy; y++)
        mvaddch(y, gx, '+');
    for (int x=gx; x<graph_w+gx; x+=2)
        mvaddch(gh+gy, x, '+');
}
