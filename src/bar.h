#ifndef BAR_H
#define BAR_H

#include "libs.h"

#include "data.h"
#include "render.h"

void Gdraw_bar(int, int, int[], size_t);

// Constructors

#define BAR(x, h) (Bar) {x, h}

#endif
