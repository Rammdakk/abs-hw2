//------------------------------------------------------------------------------
// Cypher_uni.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "Cypher_uni.h"
#include "Symbols.h"
#include "Cyclic.h"
#include "Number.h"

//------------------------------------------------------------------------------
Random Cypher_uni::rnd20(1, 20);
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
//
////------------------------------------------------------------------------------
//// Вывод параметров текущей строки в поток
//void Out(Cypher_uni &s, ofstream &ofst) {
//    switch (s.k) {
//        case Cypher_uni::SYMBOLS:
//            Out(s.s, ofst);
//            break;
//        case Cypher_uni::CYCLIC:
//            Out(s.c, ofst);
//            break;
//        case Cypher_uni::NUMBER:
//            Out(s.n, ofst);
//            break;
//        default:
//            ofst << "Incorrect figure!" << endl;
//    }
//}
//
////------------------------------------------------------------------------------
//// Вычисление функции строки
//double Devision(Cypher_uni &s) {
//    switch (s.k) {
//        case Cypher_uni::SYMBOLS:
//            return Devision(s.s);
//            break;
//        case Cypher_uni::CYCLIC:
//            return Devision(s.c);
//            break;
//        case Cypher_uni::NUMBER:
//            return Devision(s.n);
//            break;
//        default:
//            return 0.0;
//    }
//}

