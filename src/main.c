#include "libs.h"
#include "render.h"
#include "bar.h"
#include "line.h"

int main() {
    GWin scr = Ginit();

    Point d[] = {
        POINT(1, 1),
        POINT(10, 10),
        POINT(20, 5),
        POINT(30, 15),
    };
    Gdraw_line(d, 4);
    refresh();
    napms(3000);

    end:
    Gend(scr);
    return 0;
}
