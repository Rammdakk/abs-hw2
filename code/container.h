#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "Cypher_uni.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container();

    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(ifstream &ifst);

    // Случайный ввод содержимого контейнера
    void InRnd(int size);

    // Вывод содержимого контейнера в указанный поток
    void Out(ofstream &ofst);

    // Вычисление суммы периметров всех фигур в контейнере
    void ShakerSort();

private:
    void Clear();    // Очистка контейнера от данных
    int len; // текущая длина
    Cypher_uni *storage[10000];
};

#endif