//------------------------------------------------------------------------------
// triangle.cpp - содержит функции обработки треугольника
//------------------------------------------------------------------------------

#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void Triangle::In(ifstream &ifst) {
    ifst >> a >> b >> c;
}

// Случайный ввод параметров треугольника
void Triangle::InRnd() {
    a = Shape::rnd20.Get();
    b = Shape::rnd20.Get();
    do {
        c = Shape::rnd20.Get();
    } while((c >= (a + b))
          || (a >= (c + b))
          || (b >= (c + a)));
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void Triangle::Out(ofstream &ofst) {
    ofst << "It is Triangle: a = " 
         << a << ", b = " << b
         << ", c = " << c
         << ". Perimeter = " << Perimeter() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника
double Triangle::Perimeter() {
    return double(a + b + c);
}