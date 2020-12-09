#ifndef BAR_H
#define BAR_H

#include "../libs.h"

#include "../data.h"
#include "../render.h"

typedef struct {
    int h;
    char *label;
} Bar;

void Gdraw_bar(int, int, int, Bar[], size_t);

// Constructors

#define BAR(h, label) (Bar) {h, label}

#endif
