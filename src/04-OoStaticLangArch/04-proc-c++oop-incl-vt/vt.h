#ifndef __vt__
#define __vt__

//------------------------------------------------------------------------------
// vt.h - описание таблицы, используемой для моделирование виртуальных методов
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

struct shape;

//------------------------------------------------------------------------------
// таблица виртуальных методов
struct VT {
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

#endif //__vt__
