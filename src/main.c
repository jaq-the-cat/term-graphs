#include "libs.h"
#include "render.h"
#include "bar.h"
#include "line.h"

int main() {
    GWin scr = Ginit();

    LineData d = {
        1,
        10,
        5,
        15,
    };
    Gdraw_line(d, 4);
    refresh();
    napms(3000);

    end:
    Gend(scr);
    return 0;
}
