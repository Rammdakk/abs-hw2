#ifndef __symbols__
#define __symbols__

//------------------------------------------------------------------------------
// symbols.h - содержит описание строки, зашифрованной посимвольной заменой
//------------------------------------------------------------------------------

#include <fstream>
#include "string.h"

using namespace std;

#include "rnd.h"
#include "Cypher_uni.h"

// строка
class Symbols : public Cypher_uni {
protected:
    static Random rnd20;
public:
    virtual ~Symbols() {}

    // Ввод параметров строки и ее шифра из файла
    virtual void In(ifstream &ifst);

    // Случайный ввод параметров строки и ее шифра
    virtual void InRnd();

    // Вывод параметров строки в форматируемый поток
    virtual void Out(ofstream &ofst);

    // Деление кодов символов незашифрованной строки на число символов в ней
    virtual double Devision();

private:
    int length;
    char ciphered_text[100]; // зашифрованный текст
    char deciphered_text[100]; // открытая строка
    char cypher[2][100]; // шифр
};


#endif //__symbols__
