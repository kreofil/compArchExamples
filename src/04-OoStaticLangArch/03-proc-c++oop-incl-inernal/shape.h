#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    // Ввод обобщенной фигуры
    void (*In)(shape* self, ifstream &ifdt);
    // Случайный ввод обобщенной фигуры
    // Виртуальный метод ввода случайной фигуры
    void (*InRnd)(shape* self);
    // Вывод обобщенной фигуры
    void (*Out)(shape* self, ofstream &ofst);
    // Вычисление периметра обобщенной фигуры
    double (*Perimeter)(shape* self);
    // Удаление обобщенной фигуры
    void (*Delete)(shape* self);
};

// Ввод параметров обобщенной фигуры из файла
shape* In(ifstream &ifst);

// Случайный ввод обобщенной фигуры
shape *InRnd();

#endif