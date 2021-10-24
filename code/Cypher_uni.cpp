//------------------------------------------------------------------------------
// Cypher_uni.cpp - содержит методы связанные с обработкой обобщенной строки
// и создания произвольной строки шифра.
//------------------------------------------------------------------------------

#include "Cypher_uni.h"
#include "Symbols.h"
#include "Cyclic.h"
#include "Number.h"

//------------------------------------------------------------------------------
Random Cypher_uni::rnd3(1, 3);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной строки и ее шифра из файла
Cypher_uni *Cypher_uni::StaticIn(ifstream &ifst){
    int k;
    ifst >> k;
    Cypher_uni *sp = nullptr;
    switch (k) {
        case 1:
            sp = new Symbols;
            sp->In(ifst);
            return sp;
        case 2:
            sp = new Cyclic;
            sp->In(ifst);
            return sp;
        case 3:
            sp = new Number;
            sp->In(ifst);
            return sp;
        default:
            return 0;
    }
}


// Случайный ввод обобщенной строки и ее шифра
Cypher_uni *Cypher_uni::StaticInRnd() {
    auto k = Cypher_uni::rnd3.Get();
    Cypher_uni *sp = nullptr;
    switch (k) {
        case 1:
            sp = new Symbols;
            sp->InRnd();
            return sp;
        case 2:
            sp = new Cyclic;
            sp->InRnd();
            return sp;
        case 3:
            sp = new Number;
            sp->InRnd();
            return sp;
        default:
            return 0;
    }
}


