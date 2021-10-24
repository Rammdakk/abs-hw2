#ifndef __cypher_uni__
#define __cypher_uni__

//------------------------------------------------------------------------------
// Cypher_uni.h - содержит описание обобщающей зашифрованной строки,
//------------------------------------------------------------------------------
#include <fstream>

using namespace std;

#include "rnd.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся строки шифрования
class Cypher_uni {
protected:
    static Random rnd20;
    static Random rnd3;
public:
    virtual ~Cypher_uni() {};

    // Ввод обобщенной фигуры
    static Cypher_uni *StaticIn(ifstream &ifdt);

    // Ввод обобщенной фигуры
    virtual void In(ifstream &ifdt) = 0;

    // Случайный ввод обобщенной фигуры
    static Cypher_uni *StaticInRnd();

    // Виртуальный метод ввода случайной фигуры
    virtual void InRnd() = 0;

    // Вывод обобщенной фигуры
    virtual void Out(ofstream &ofst) = 0;

    // Вычисление функции строки
    virtual double Devision() = 0;
};

#endif
