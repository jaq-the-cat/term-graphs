#include "generic.h"

int trans_d(float actual_d, float graph_d, float d) {
    return d / (actual_d / graph_d);
}

void graph_lines(int gy, int gh, int gx, int gw) {
    for (int y=gy; y<gh+gy; y++)
        mvaddch(y, gx, '+');
    for (int x=gx; x<gw+gx; x+=2)
        mvaddch(gh+gy, x, '+');
}
