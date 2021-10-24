//------------------------------------------------------------------------------
// container_Constr.cpp - содержит методы класса, для обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : len{0} {}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}
//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifst) {
    while (!ifst.eof()) {
        if ((storage[len] = Cypher_uni::StaticIn(ifst)) != 0) {
            len++;
        }
    }
}


//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Cypher_uni::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len-1 << " elements.\n";
    for (int i = 0; i < len-1; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

//------------------------------------------------------------------------------
// Вычисление суммы периметров всех фигур в контейнере
void Container::ShakerSort() {
    int control = this->len - 2;
    int left = 0;
    int right = this->len - 2;
    do {
        for (int i = left; i < right; i++) {
            if ((*this->storage[i]).Devision() > (*this->storage[i + 1]).Devision()) {
                std::swap(this->storage[i], this->storage[i + 1]);
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) {
            if ((*this->storage[i]).Devision() < (*this->storage[i - 1]).Devision()) {
                std::swap(this->storage[i], this->storage[i - 1]);
                control = i;
            }
        }
        left = control;
    } while (left < right);
}
