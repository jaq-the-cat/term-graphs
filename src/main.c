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
        BAR(10, "Label 1"),
        BAR(15, "Label 2"),
        BAR(8, "Label 3"),
        BAR(5, "Label 4"),
        BAR(2, "Label 5"),
    };
    Gdraw_bar(1, 1, d, 5);

    refresh();
    getch();

    end:
    Gend(scr);
    return 0;
}
