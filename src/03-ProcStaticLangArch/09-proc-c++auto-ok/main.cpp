//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "container.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    cout << "Start"<< endl;
    container c;
    int size = 100;
    bool isFile;

    ////cout << "argv[1] = " << argv[1] << "\n";
    if(!strcmp(argv[1], "-f")) {
        isFile = true;
    }
    else if(!strcmp(argv[1], "-n")) {
        isFile = false;
        size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) { 
            cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
    }
    else {
        errMessage2();
        return 2;
    }

    // Автоматическое выделение памяти для массива
    shape arr[size];
    Init(c, arr);
    std::cout << "size = " << size << "\n";

    // Проверка источника данных
    if(isFile) {
        ifstream ifst(argv[2]);
        In(c, ifst);
    } else {
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);

    // The 2nd part of task
    ofstream ofst2(argv[4]);
    ofst2 << "Perimeter sum = " << PerimeterSum(c) << "\n";

    Clear(c);
    cout << "Stop"<< endl;
    return 0;
}
