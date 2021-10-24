#ifndef __number__
#define __number__

//------------------------------------------------------------------------------
// Number.h - содержит описание строки, зашифрованной заменой букв на числа
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "Cypher_uni.h"

// строка, шифрующаяся числами.
class Number : public Cypher_uni {
public:
    virtual ~Number(){}
// Ввод параметров строки из файла
    virtual void In(ifstream &ifst);

// Случайный ввод параметров строки
    virtual void InRnd();

// Вывод параметров строки в форматируемый поток
    virtual void Out(ofstream &ofst);

// Деление кодов символов незашифрованной строки на число символов в ней
    virtual double Devision();

private:
    int lenght;
    int cypher[2][100];
    int ciphered_text[100];
    char deciphered_text[100];
};

#endif //__number__
