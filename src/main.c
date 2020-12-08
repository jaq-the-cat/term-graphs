#include "libs.h"
#include "render.h"
#include "bar.h"

int main() {
    GWin scr = Ginit();

    Bar d[] = {BAR(1, 10), BAR(4, 5)};
    Gdraw_bar(d, 2);
    refresh();
    napms(3000);

    end:
    Gend(scr);
    return 0;
}
