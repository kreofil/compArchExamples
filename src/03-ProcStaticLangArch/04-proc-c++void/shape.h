#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
// Ввод обобщенной фигуры
void *In(ifstream &ifst);

// Случайный ввод обобщенной фигуры
void *InRnd();

// Вывод обобщенной фигуры
void Out(void *s, ofstream &ofst);

// Вычисление периметра обобщенной фигуры
double Perimeter(void *s);

// Удаление обобщенной фигуры
void DeleteShape(void *s);

// Вывод параметров текущей фигуры в консоль
void stdOut(void *s);

#endif
