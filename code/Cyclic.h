#ifndef __cyclic__
#define __cyclic__


//------------------------------------------------------------------------------
// Cyclic.h - содержит описание строки, зашифрованной измененрем кода символа.
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"
#include "Cypher_uni.h"

class Cyclic : public Cypher_uni {
public:
    virtual ~Cyclic() {}

// Ввод параметров строки и шифра из файла
    void In(ifstream &ifst);

// Случайный ввод параметров строки и шифра
    void InRnd();

// Вывод параметров строки в форматируемый поток
    void Out(ofstream &ofst);

// Деление кодов символов незашифрованной строки на число символов в ней
    double Devision();

private:
    int cypher;
    char ciphered_text[100];
    char deciphered_text[100];
};

#endif //__cyclic__
