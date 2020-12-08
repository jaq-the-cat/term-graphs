#include "bar.h"

void Gdraw_bar() {

    // draw lines
    for (int y=1; y<BAR_HEIGHT+1; y++)
        mvaddch(y, 1, '+');
    for (int x=1; x<BAR_WIDTH*2+1; x+=2)
        mvaddstr(BAR_HEIGHT+1, x, "+ ");
    
    /*for (int i=0; i<len_d; i++) { }*/
}
