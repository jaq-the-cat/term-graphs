#include "bar.h"
#include <math.h>

char* make_bar(char* label, int w) {
    char *bar = malloc(sizeof(char)*w);
    bar[0] = '[';
    for (int i=1; i<w-1; i++)
        bar[i] = ' ';
    bar[w-1] = ']';
    return bar;
}

int get_trans_h(int actual_h, int gh, int h) {
    return h / (actual_h / gh);
}

void Gdraw_bar(int gx, int gy, int gh, Bar d[], size_t len_b) {
    int l;
    int graph_w = 2, max_bar_h = 0;
    for (int i=0; i<len_b; i++) {
        if (d[i].h > max_bar_h)
            max_bar_h = d[i].h;
        graph_w += strlen(d[i].label) + 5;
    }
    graph_w++; // right padding


    // draw lines
    for (int y=gy; y<gh+gy; y++)
        mvaddch(y, gx, '+');
    for (int x=gx; x<graph_w+gx; x+=2)
        mvaddstr(gh+gy, x, "+ ");
    
    const int gap = 1;
    int x = gx + gap*2;
    int bar_w;
    int ah;
    for (int i=0; i<len_b; i++) {
        bar_w = strlen(d[i].label) + 4;

        char e[25];
        ah = get_trans_h(max_bar_h, gh, d[i].h);
        sprintf(e, "%d ", d[i].h / (max_bar_h / gh));
        mvaddstr(0, 0, e);
        sprintf(e, "%d ", d[i].h);
        mvaddstr(1, 0, e);
        sprintf(e, "%d %d  ", max_bar_h, gh);
        mvaddstr(2, 0, e);
        // draw bar sections
        for (int h=0; h<ah; h++) {
            mvaddch(ah+gy-1-h, x, '[');
            mvaddch(ah+gy-1-h, x + bar_w-1, ']');
        }

        // draw label
        mvaddstr(ah+gy-1, x + 2, d[i].label);

        refresh();
        napms(1000);
        x += bar_w + gap;
    }
}
