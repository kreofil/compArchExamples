#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
# include "shape.h"

// прямоугольник
struct rectangle {
    int x, y; // ширина, высота
};

// Ввод параметров прямоугольника из файла
void In(rectangle &r, ifstream &ifst);

// Случайный ввод параметров прямоугольника
void InRnd(rectangle &r);

// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle &r, ofstream &ofst);

// Вычисление периметра прямоугольника
double Perimeter(rectangle &r);

//------------------------------------------------------------------------------
// прямоугольник как фигура
struct rectangleAsShape {
    shape base;
    rectangle spec;
};

// Инициализация прямоугольника как фигуры
void init (rectangleAsShape &ts);

// Создание прямоугольника как фигуры
shape* createRectangleAsShape();

#endif //__rectangle__
