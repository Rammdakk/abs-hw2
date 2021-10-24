#include "Symbols.h"

Random Symbols::rnd20(1, 20);
//------------------------------------------------------------------------------
// Ввод параметров зашифрованной строки из файла
void Symbols::In(ifstream &ifst) {
    ifst >> ciphered_text;
    length = strlen(ciphered_text);
    for (int i = 0; i < length; ++i) {
        ifst >> cypher[0][i]>> cypher[1][i];
    }
    // Расшифровка, заменой символов с шифра на символы ключа.
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; j ++) {
            if (ciphered_text[i] == cypher[0][j])
                deciphered_text[i]= cypher[1][j];
        }
    }
}


// Случайный ввод параметров зашифрованной строки
void Symbols::InRnd() {
    length = (char) (new Random(3, 10))->Get();
    for (int i = 0; i < length; ++i) {
        char symb = (char) (new Random(97, 122))->Get();
        ciphered_text[i] = symb;
        char symb_new = (char) (new Random(97, 122))->Get();
        deciphered_text[i] = symb_new;
        cypher[0][i] = symb;
        cypher[1][i] = symb_new;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров строки в форматируемый поток
void Symbols::Out(ofstream &ofst) {
    ofst << "It symbols cipher: ciphered_text = " << ciphered_text << ", deciphered_text = " << deciphered_text
         << ". function_result = " << Symbols::Devision()<<"\n";
}

//------------------------------------------------------------------------------
// Вычисление общей функции
double Symbols::Devision() {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += (int) deciphered_text[i];
    }
    return (double) sum / length;
}
