#include "libs.h"
#include "render.h"
#include "bar.h"
#include "line.h"

int main() {
    GWin scr = Ginit();

    Gdraw_line(LINE(1, 1, 5, 5), 4);
    refresh();
    napms(3000);

    end:
    Gend(scr);
    return 0;
}
