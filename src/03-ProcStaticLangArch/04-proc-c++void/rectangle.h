#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

// прямоугольник
const int RECTANGLE = 1;

struct rectangle {
    int k;
    int x, y; // ширина, высота
};

// Ввод параметров прямоугольника из файла
void In(rectangle &r, ifstream &ifst);

// Случайный ввод параметров прямоугольника
void InRnd(rectangle &r);

// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle &r, ofstream &ofst);

// Вывод параметров прямоугольника в консоль
void stdOut(rectangle &r);

// Вычисление периметра прямоугольника
double Perimeter(rectangle &r);

#endif //__rectangle__
