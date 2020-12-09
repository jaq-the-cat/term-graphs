#include "libs.h"
#include "render.h"
#include "graphs/bar.h"
#include "graphs/line.h"

int f(int x) {
    return x*x;
}

int main() {
    GWin scr = Ginit();

    int ld[10];
    for (int x=2; x<10; x++)
        ld[x] = f(x);
    Gdraw_line(
            2, 1, 20,          // graph transform
            ld, 10,            // data
            3,                 // x growth
            "Cock over time"); // label

    Bar bd[] = {
        BAR(10, "Pyjamas"),
        BAR(15, "Cereal"),
        BAR(8,  "Violins"),
        BAR(5,  "Cars"),
        BAR(2,  "Mugs"),
    };
    Gdraw_bar(
            2, 22, 10, // graph transform
            bd, 5);    // data

    refresh();
    getch();

    end:
    Gend(scr);
    return 0;
}
