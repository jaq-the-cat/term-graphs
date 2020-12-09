#include "bar.h"

char* make_bar(char* label, int w) {
    char *bar = malloc(sizeof(char)*w);
    bar[0] = '[';
    for (int i=1; i<w-1; i++)
        bar[i] = ' ';
    bar[w-1] = ']';
    return bar;
}

void Gdraw_bar(int gx, int gy, Bar d[], size_t len_b) {
    int bar_h = 0;
    for (int i=0; i<len_b; i++)
        if (d[i].h > bar_h)
            bar_h = d[i].h;
    bar_h++;
    int bar_w = 6;

    // draw lines
    for (int y=gy; y<bar_h+gy; y++)
        mvaddch(y, gx, '+');
    for (int x=gx; x<bar_w*2+gx; x+=2)
        mvaddstr(bar_h+gy, x, "+ ");
    
    const int gap = 1;
    int x = gx + gap*2;
    for (int i=0; i<len_b; i++) {
        int w = strlen(d[i].label) + 4;
        // draw bar sections
        for (int h=0; h<d[i].h; h++) {
            mvaddch(bar_h+gy-1-h, x, '[');
            mvaddch(bar_h+gy-1-h, x+w-1, ']');
        }
        // draw label
        mvaddstr(bar_h+gy-1, x + 2, d[i].label);
        x += w + gap;
    }
}
