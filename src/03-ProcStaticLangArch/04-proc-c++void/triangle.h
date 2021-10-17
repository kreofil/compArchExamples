#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// треугольник
const int TRIANGLE = 2;

struct triangle {
    int k;
    int a, b, c; // стороны
};

// Ввод параметров треугольника из файла
void In(triangle &t, ifstream &ifst);

// Случайный ввод параметров треугольника
void InRnd(triangle &е);

// Вывод параметров треугольника в форматируемый поток
void Out(triangle &t, ofstream &ofst);

// Вывод параметров треугольника в консоль
void stdOut(triangle &t);

// Вычисление периметра треугольника
double Perimeter(triangle &t);

#endif //__triangle__
