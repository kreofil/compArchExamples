#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "shape.h"
# include "rnd.h"

//------------------------------------------------------------------------------
// треугольник
struct triangle {
    int a, b, c; // стороны
};

// Ввод параметров треугольника из файла
void In(triangle &t, ifstream &ifst);

// Случайный ввод параметров треугольника
void InRnd(triangle &е);

// Вывод параметров треугольника в форматируемый поток
void Out(triangle &t, ofstream &ofst);

// Вычисление периметра треугольника
double Perimeter(triangle &t);

//------------------------------------------------------------------------------
// треугольник как фигура
struct triangleAsShape {
    shape base;
    triangle spec;
};

// Инициализация треугольника как фигуры
void init (triangleAsShape &ts);

// Создание треугольника как фигуры
shape* createTriangleAsShape();

#endif //__triangle__