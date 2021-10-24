#include "Number.h"
#include <cstring>

//------------------------------------------------------------------------------
// Ввод параметров зашифрованной строки из файла
void Number::In(ifstream &ifst) {
    ifst >> lenght;
    for (int i = 0; i < lenght; ++i) {
        ifst >> ciphered_text[i];
    }
    for (int i = 0; i < lenght; ++i) {
        char temp;
        ifst >> temp >> cypher[1][i];
        cypher[0][i] = (int) temp;
    }
    for (int i = 0; i < lenght; ++i) {
        for (int j = 0; j < lenght; ++j) {
            if (ciphered_text[i] == cypher[1][j])
                deciphered_text[i] = cypher[0][j];
        }
    }
}

// Случайный ввод параметров строки
void Number::InRnd() {
    Random *rlenght = new Random(12, 20);
    lenght = rlenght->Get();
    for (int i = 0; i < lenght; ++i) {
        ciphered_text[i] = (new Random(1, 10))->Get() * (new Random(1, 10))->Get();
        deciphered_text[i] = (char) ((new Random(97, 122))->Get());
        cypher[0][i] = ciphered_text[i];
        cypher[1][i] = deciphered_text[i];
    }
}

//------------------------------------------------------------------------------
// Вывод параметров строки в форматируемый поток
void Number::Out(ofstream &ofst) {
    ofst << "It Number cipher: ciphered_text = ";
    for (int i = 0; i < lenght; ++i) {
        ofst << ciphered_text[i];
    }
    ofst << ", deciphered_text = " << deciphered_text
         << ". function_result = " << Devision() <<"\n";
}

//------------------------------------------------------------------------------
// Вычисление общей функции
double Number::Devision() {
    int sum = 0;
    for (int i = 0; i < strlen(deciphered_text); ++i) {
        sum += (int) deciphered_text[i];
    }
    return (double) sum / strlen(deciphered_text);
}

