#ifndef RENDER_H
#define RENDER_H

#include "libs.h"

#define scr stdscr
typedef WINDOW* GWin;

GWin Ginit();
void Gend(GWin);

#endif
