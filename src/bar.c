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
    int l;
    int max_bar_w = 0, max_bar_h = 0;
    for (int i=0; i<len_b; i++) {
        if (d[i].h > max_bar_h)
            max_bar_h = d[i].h;
        if ((l = strlen(d[i].label)) > max_bar_w)
            max_bar_w = l;
    }

    max_bar_h++;

    // draw lines
    for (int y=gy; y<max_bar_h+gy; y++)
        mvaddch(y, gx, '+');
    for (int x=gx; x<max_bar_w*2+gx; x+=2)
        mvaddstr(max_bar_h+gy, x, "+ ");
    
    const int gap = 1;
    int x = gx + gap*2;
    int bar_w;
    for (int i=0; i<len_b; i++) {
        bar_w= strlen(d[i].label) + 4;

        // draw bar sections
        for (int h=0; h<d[i].h; h++) {
            mvaddch(max_bar_h+gy-1-h, x, '[');
            mvaddch(max_bar_h+gy-1-h, x + bar_w-1, ']');
        }

        // draw label
        mvaddstr(max_bar_h+gy-1, x + 2, d[i].label);
        x += bar_w + gap;
    }
}
