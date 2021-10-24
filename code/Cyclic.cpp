//------------------------------------------------------------------------------
// Cyclic.cpp - содержит функции обработки треугольника
//------------------------------------------------------------------------------

#include "Cyclic.h"
#include "string.h"

//------------------------------------------------------------------------------
// Ввод параметров строки и шифра из потока
void Cyclic::In(ifstream &ifst) {
    ifst >> ciphered_text >> cypher;
    for (int i = 0; i < strlen(ciphered_text); ++i) {
        deciphered_text[i] = (char) (cypher + (int) ciphered_text[i]);
    }
}


// Случайный ввод параметров строки и шифра
void Cyclic::InRnd() {
    cypher = (char) (new Random(1, 10))->Get();
    int lenght = (char) (new Random(1, 10))->Get();
    for (int i = 0; i < lenght; ++i) {
        char symb = (char) ((new Random(97, 122))->Get());
        ciphered_text[i] = symb;
        deciphered_text[i] = (char) ((cypher + (int) symb - 97) % 26 + 97);
    }
}

//------------------------------------------------------------------------------
// Вывод параметров строки в поток
void Cyclic::Out(ofstream &ofst) {
    ofst << "It Cyclic cipher: ciphered_text = " << ciphered_text << ", deciphered_text = " << deciphered_text
         << ". function_result = " << Devision() <<"\n";
}

//------------------------------------------------------------------------------
// Вычисление функции общей для всех строк.
double Cyclic::Devision() {
    int sum = 0;
    for (int i = 0; i < strlen(deciphered_text); ++i) {
        sum += (int) deciphered_text[i];
    }
    return (double) sum / strlen(deciphered_text);
}
