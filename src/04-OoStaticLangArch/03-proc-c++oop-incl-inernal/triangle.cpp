//------------------------------------------------------------------------------
// triangle.cpp - содержит функции обработки треугольника
//------------------------------------------------------------------------------

#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void In(triangle &t, ifstream &ifst) {
    ifst >> t.a >> t.b >> t.c;
}

// Случайный ввод параметров треугольника
void InRnd(triangle &t) {
    t.a = Random();
    t.b = Random();
    do {
        t.c = Random();
    } while((t.c >= (t.a + t.b))
          || (t.a >= (t.c + t.b))
          || (t.b >= (t.c + t.a)));
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void Out(triangle &t, ofstream &ofst) {
    ofst << "It is Triangle: a = " 
         << t.a << ", b = " << t.b
         << ", c = " << t.c
         << ". Perimeter = " << Perimeter(t) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника
double Perimeter(triangle &t) {
    return double(t.a + t.b + t.c);
}

//------------------------------------------------------------------------------
// Ввод треугольника как фигуры
void inTriangleAsShape(shape* self, ifstream &ifst) {
    triangleAsShape* ptr = (triangleAsShape*)self;
    In(ptr->spec, ifst);
}

//------------------------------------------------------------------------------
// Ввод случайного треугольника как фигуры
void inRndTriangleAsShape(shape* self) {
    triangleAsShape* ptr = (triangleAsShape*)self;
    InRnd(ptr->spec);
}

//------------------------------------------------------------------------------
// Вывод треугольника как фигуры
void outTriangleAsShape(shape* self, ofstream &ofst) {
    triangleAsShape* ptr = (triangleAsShape*)self;
    Out(ptr->spec, ofst);
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника как фигуры
double perimeterTriangleAsShape(shape* self) {
    triangleAsShape* ptr = (triangleAsShape*)self;
    return Perimeter(ptr->spec);
}

//------------------------------------------------------------------------------
// Удаление треугольника как фигуры
void deleteTriangleAsShape(shape* self) {
    triangleAsShape* ptr = (triangleAsShape*)self;
    delete ptr;
}

//------------------------------------------------------------------------------
// Инициализация треугольника как фигуры
void init(triangleAsShape &ts) {
    ts.base.In = inTriangleAsShape;
    ts.base.InRnd = inRndTriangleAsShape;
    ts.base.Out = outTriangleAsShape;
    ts.base.Perimeter = perimeterTriangleAsShape;
    ts.base.Delete = deleteTriangleAsShape;
}

//------------------------------------------------------------------------------
// Создание треугольника как фигуры
shape* createTriangleAsShape() {
    triangleAsShape* ptr = new triangleAsShape;
    init(*ptr);
    return &(ptr->base);
}
