#ifndef BAR_H
#define BAR_H

#include "libs.h"

#include "data.h"
#include "render.h"

#define BAR_HEIGHT 30
#define BAR_WIDTH 50

typedef struct {
    int x;
    int h;
} Bar;

void Gdraw_bar(int, int, Bar*, size_t);

// Constructors

#define BAR(x, h) (Bar) {x, h}

#endif
