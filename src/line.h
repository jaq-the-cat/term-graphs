#ifndef LINE_H
#define LINE_H

#include "libs.h"

#include "data.h"
#include "render.h"

typedef int LineData[];

void Gdraw_line(LineData, size_t);


// Constructors
#define LINE(x1, y1, x2, y2) (Data) { POINT(x1, y1), POINT(x2, y2) }

#endif
