//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
shape* In(ifstream &ifst) {
    shape *sp;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            sp = createRectangleAsShape();
            break;
        case 2:
            sp = createTriangleAsShape();
            break;
        default:
            return 0;
    }
    sp->vtPtr->In(sp, ifst);
    return sp;
}

// Случайный ввод обобщенной фигуры
shape *InRnd() {
    shape *sp;
    auto k = rand() % 2 + 1;
    switch(k) {
        case 1:
            sp = createRectangleAsShape();
            break;
        case 2:
            sp = createTriangleAsShape();
            break;
        default:
            return 0;
    }
    sp->vtPtr->InRnd(sp);
    return sp;
}
