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

    int d[] = {
        10,
        15,
        8,
        5,
        2,
    };
    Gdraw_bar(1, 1, d, 5);

    refresh();
    napms(3000);

    end:
    Gend(scr);
    return 0;
}
