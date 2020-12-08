#ifndef DATA_H
#define DATA_H

typedef struct {
    int x, y;
} Point;

typedef Point Data[];

// Constructors

#define POINT(x, y) (Point) { x, y }

#endif
