#include "bar.h"
#include "generic.h"

char* make_bar(char* label, int w) {
    char *bar = malloc(sizeof(char)*w);
    bar[0] = '[';
    for (int i=1; i<w-1; i++)
        bar[i] = ' ';
    bar[w-1] = ']';
    return bar;
}

void Gdraw_bar(int gx, int gy, int gh, Bar d[], size_t len_b) {
    int l;
    int graph_w = 2, max_bar_h = 0;
    for (int i=0; i<len_b; i++) {
        if (d[i].h > max_bar_h)
            max_bar_h = d[i].h;
        graph_w += strlen(d[i].label) + 4;
    }
    graph_w++; // right padding

    graph_lines(gy, gh, gx, graph_w);

    const int gap = 1;
    int x = gx + gap*2;
    int bar_w;
    int ah;
    for (int i=0; i<len_b; i++) {
        bar_w = strlen(d[i].label) + 2;

        // get translated bar height
        ah = trans_d(max_bar_h, gh, d[i].h);
        if (ah < 1) ah = 1;

        // draw bar sections
        for (int h=0; h<ah; h++) {
            mvaddch(gy+gh-1-h, x, '[');
            mvaddch(gy+gh-1-h, x + bar_w-1, ']');
        }

        // draw label
        mvaddstr(gy+gh-1, ++x, d[i].label);

        x += bar_w + gap;
    }
}
