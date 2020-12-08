#include "bar.h"

void Gdraw_bar(Bar* d, size_t len_b) {

    int gy = 1, gx = 1;

    // draw lines
    for (int y=gy; y<BAR_HEIGHT+gy; y++)
        mvaddch(y, gx, '+');
    for (int x=gx; x<BAR_WIDTH*2+gx; x+=2)
        mvaddstr(BAR_HEIGHT+gy, x, "+ ");
    
    for (int i=0; i<len_b; i++)
        for (int h=0; h<d[i].h; h++)
            mvaddstr(BAR_HEIGHT+gy-1-h, (d[i].x)*4, "[    ]");
}
