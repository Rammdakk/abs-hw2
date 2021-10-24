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
            "     command -n Number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n Number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }
    clock_t start_time = clock();
    cout << "Start" << endl;
    Container c;

    ////cout << "argv[1] = " << argv[1] << "\n";
    if (!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        c.In(ifst);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = (atoi(argv[2]) + 1);
        if ((size < 1) || (size > 10001)) {
            cout << "incorrect numer of figures = "
                 << size-1
                 << ". Set 0 < Number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.Out(ofst1);

    // The 2nd part of task
    ofstream ofst2(argv[4]);
    ofst2 << "Sorting result:\n";
    c.ShakerSort();
    c.Out(ofst2);

    clock_t end_time = clock();
    double seconds = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    cout << seconds << "s \n";
    cout << "Stop" << endl;
    return 0;
}
