#include "bar.h"

void Gdraw_bar(int gx, int gy, int d[], size_t len_b) {
    int bar_h;
    for (int i=0; i<len_b; i++)
        if (d[i] > bar_h)
            bar_h = d[i];
    int bar_w = len_b * 9;

    // draw lines
    for (int y=gy; y<bar_h+gy; y++)
        mvaddch(y, gx, '+');
    for (int x=gx; x<bar_w*2+gx; x+=2)
        mvaddstr(bar_h+gy, x, "+ ");
    
    int x = 0;
    for (int i=0; i<len_b; i++) {
        for (int h=0; h<d[i]; h++)
            mvaddstr(bar_h+gy-1-h, x*8 + 5, "[    ]");
        x += 1;
    }
}
