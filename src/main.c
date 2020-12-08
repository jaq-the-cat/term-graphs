#include "libs.h"
#include "render.h"
#include "bar.h"

int main() {
    GWin scr = Ginit();

    Gdraw_bar();
    refresh();
    napms(3000);

    end:
    Gend(scr);
    return 0;
}
