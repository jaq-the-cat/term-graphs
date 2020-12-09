#ifndef LINE_H
#define LINE_H

#include "../libs.h"

#include "../data.h"
#include "../render.h"

#define LINE_HEIGHT 30
#define LINE_WIDTH 40

typedef int LineData[];

void Gdraw_line(int, int, int, int, LineData, size_t, char*);


// Constructors
#define LINE(x1, y1, x2, y2) (Data) { POINT(x1, y1), POINT(x2, y2) }

#endif
