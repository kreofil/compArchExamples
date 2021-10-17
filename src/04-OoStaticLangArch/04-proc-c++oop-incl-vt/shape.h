#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "vt.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    // Указатель на таблицу виртуальных методов
    VT* vtPtr;
};

// Ввод параметров обобщенной фигуры из файла
shape* In(ifstream &ifst);

// Случайный ввод обобщенной фигуры
shape *InRnd();

#endif
