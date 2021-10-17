//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
void* In(ifstream &ifst) {
    int k;
    ifst >> k;
    switch(k) {
        rectangle *rp;
        triangle  *tp;
        case 1:
            rp = new rectangle;
            rp->k = RECTANGLE;
            In(*rp, ifst);
            return rp;
        case 2:
            tp = new triangle;
            tp->k = TRIANGLE;
            In(*tp, ifst);
            return tp;
        default:
            return 0;
    }
}

// Случайный ввод обобщенной фигуры
void* InRnd() {
    auto k = rand() % 2 + 1;
    switch(k) {
        rectangle *rp;
        triangle  *tp;
        case 1:
            rp = new rectangle;
            rp->k = RECTANGLE;
            InRnd(*rp);
            return rp;
        case 2:
            tp = new triangle;
            tp->k = TRIANGLE;
            InRnd(*tp);
            return tp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(void *s, ofstream &ofst) {
    switch(((rectangle*)s)->k) {
        case RECTANGLE:
            Out(*((rectangle*)s), ofst);
            break;
        case TRIANGLE:
            Out(*((triangle*)s), ofst);
            break;
        default:
            ofst << "Incorrect figure!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double Perimeter(void *s) {
    switch(((rectangle*)s)->k) {
        case RECTANGLE:
            return Perimeter(*reinterpret_cast<rectangle*>(s));
            break;
        case TRIANGLE:
            return Perimeter(*reinterpret_cast<triangle*>(s));
            break;
        default:
            return 0.0;
    }
}

// Удаление обобщенной фигуры
void DeleteShape(void *s) {
   switch(((rectangle*)s)->k) {
        case RECTANGLE:
            delete (rectangle*)s;
            break;
        case TRIANGLE:
            delete (triangle*)s;
            break;
        default:
            break;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в консоль
void stdOut(void *s) {
    switch(((rectangle*)s)->k) {
        case RECTANGLE:
            stdOut(*((rectangle*)s));
            break;
        case TRIANGLE:
            stdOut(*((triangle*)s));
            break;
        default:
            std::cout << "Incorrect figure!" << endl;
    }
}

