#include "libs.h"
#include "render.h"
#include "graphs/bar.h"
#include "graphs/line.h"

int main() {
    GWin scr = Ginit();

    LineData ld = {
        1,
        15,
        5,
        25,
    };
    Gdraw_line(1, 1, 20, ld, 4, 6, "X label", "Y label");

    Bar bd[] = {
        BAR(10, "Pyjamas"),
        BAR(15, "Cereal"),
        BAR(8, "Violins"),
        BAR(5, "Cars"),
        BAR(2, "Mugs"),
    };
    Gdraw_bar(1, 21, 10, bd, 5);

    refresh();
    getch();

    end:
    Gend(scr);
    return 0;
}
