//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
shape* In(ifstream &ifst) {
    int k;
    ifst >> k;
    switch(k) {
        rectangle *rp;
        triangle  *tp;
        case 1:
            rp = new rectangle;
            rp->k = shape::RECTANGLE;
            In(*rp, ifst);
            return rp;
        case 2:
            tp = new triangle;
            tp->k = shape::TRIANGLE;
            In(*tp, ifst);
            return tp;
        default:
            return 0;
    }
}

// Случайный ввод обобщенной фигуры
shape *InRnd() {
    auto k = rand() % 2 + 1;
    switch(k) {
        rectangle *rp;
        triangle  *tp;
        case 1:
            rp = new rectangle;
            rp->k = shape::RECTANGLE;
            InRnd(*rp);
            return rp;
        case 2:
            tp = new triangle;
            tp->k = shape::TRIANGLE;
            InRnd(*tp);
            return tp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape &s, ofstream &ofst) {
    switch(s.k) {
        case shape::RECTANGLE:
            Out(*((rectangle*)&s), ofst);
            break;
        case shape::TRIANGLE:
            Out(*((triangle*)&s), ofst);
            break;
        default:
            ofst << "Incorrect figure!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double Perimeter(shape &s) {
    switch(s.k) {
        case shape::RECTANGLE:
            return Perimeter(*reinterpret_cast<rectangle*>(&s));
            break;
        case shape::TRIANGLE:
            return Perimeter(*reinterpret_cast<triangle*>(&s));
            break;
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Удаление обобщенной фигуры
void DeleteShape(shape *s) {
   switch(((rectangle*)s)->k) {
       case shape::RECTANGLE:
            delete (rectangle*)s;
            break;
       case shape::TRIANGLE:
            delete (triangle*)s;
            break;
       default:
            break;
    }
}
