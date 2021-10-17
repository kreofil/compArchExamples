//------------------------------------------------------------------------------
// rectangle.cpp - содержит процедуру ввода параметров 
// для уже созданного прямоугольника
//------------------------------------------------------------------------------

#include "rectangle.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void In(rectangle &r, ifstream &ifst) {
    ifst >> r.x >> r.y;
}

// Случайный ввод параметров прямоугольника
void InRnd(rectangle &r) {
    r.x = Random();
    r.y = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle &r, ofstream &ofst) {
    ofst << "It is Rectangle: x = " << r.x << ", y = " << r.y 
         << ". Perimeter = " << Perimeter(r) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double Perimeter(rectangle &r) {
    return 2.0 * (r.x + r.y);
}

//------------------------------------------------------------------------------
// Ввод прямоугольника как фигуры
void inRectangleAsShape(shape* self, ifstream &ifst) {
    rectangleAsShape* ptr = (rectangleAsShape*)self;
    In(ptr->spec, ifst);
}

//------------------------------------------------------------------------------
// Ввод случайного прямоугольника как фигуры
void inRndRectangleAsShape(shape* self) {
    rectangleAsShape* ptr = (rectangleAsShape*)self;
    InRnd(ptr->spec);
}

//------------------------------------------------------------------------------
// Вывод прямоугольника как фигуры
void outRectangleAsShape(shape* self, ofstream &ofst) {
    rectangleAsShape* ptr = (rectangleAsShape*)self;
    Out(ptr->spec, ofst);
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника как фигуры
double perimeterRectangleAsShape(shape* self) {
    rectangleAsShape* ptr = (rectangleAsShape*)self;
    return Perimeter(ptr->spec);
}

//------------------------------------------------------------------------------
// Удаление прямоугольника как фигуры
void deleteRectangleAsShape(shape* self) {
    rectangleAsShape* ptr = (rectangleAsShape*)self;
    delete ptr;
}

//------------------------------------------------------------------------------
// Таблица виртуальных методов прямоугольника
static VT vtRectangle = {
    inRectangleAsShape,
    inRndRectangleAsShape,
    outRectangleAsShape,
    perimeterRectangleAsShape,
    deleteRectangleAsShape
};

//------------------------------------------------------------------------------
// Инициализация прямоугольника как фигуры
void init(rectangleAsShape &ts) {
    ts.base.vtPtr = &vtRectangle;
}

//------------------------------------------------------------------------------
// Создание прямоугольника как фигуры
shape* createRectangleAsShape() {
    rectangleAsShape* ptr = new rectangleAsShape;
    init(*ptr);
    return &(ptr->base);
}
