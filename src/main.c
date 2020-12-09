#include "libs.h"
#include "render.h"
#include "bar.h"
#include "line.h"

int main() {
    GWin scr = Ginit();

    /*LineData d = {*/
        /*1,*/
        /*15,*/
        /*5,*/
        /*25,*/
    /*};*/
    /*Gdraw_line(1, 1, d, 4, 6, "X label", "Y label");*/

    Bar d[] = {
        BAR(10, "Pyjamas"),
        BAR(15, "Cereal"),
        BAR(8, "Violins"),
        BAR(5, "Cars"),
        BAR(2, "Mugs"),
    };
    Gdraw_bar(1, 1, d, 5);

    refresh();
    getch();

    end:
    Gend(scr);
    return 0;
}
