#include "libs.h"
#include "render.h"
#include "bar.h"
#include "line.h"

int main() {
    GWin scr = Ginit();

    LineData d = {
        1,
        15,
        5,
        25,
    };
    Gdraw_line(1, 1, d, 4, 6);

    int bar[] = {
        5,
        10,
        2,
        25,
    };
    Gdraw_bar(1, 30, bar, 4);

    refresh();
    napms(3000);

    end:
    Gend(scr);
    return 0;
}
