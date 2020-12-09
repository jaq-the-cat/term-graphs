#include "libs.h"
#include "render.h"
#include "graphs/bar.h"
#include "graphs/line.h"

int f(int x) {
    return x*x;
}

int main() {
    GWin scr = Ginit();

    const int ld_len = 60;
    int ld[ld_len];
    for (int x=1; x<ld_len; x++)
        ld[x] = f(x);
    Gdraw_line(
            2, 1, 100, 50,     // graph transform
            ld, ld_len,        // data
            "Cock over time"); // label

    Bar bd[] = {
        BAR(10, "Pyjamas"),
        BAR(15, "Cereal"),
        BAR(8,  "Violins"),
        BAR(5,  "Cars"),
        BAR(2,  "Mugs"),
    };
    Gdraw_bar(
            2, 52, 10, // graph transform
            bd, 5);    // data

    refresh();
    getch();

    end:
    Gend(scr);
    return 0;
}
