#include "Curso.h"
#include <iostream>

Curso::Curso(string code) {
    this->code = code;
}

void Curso::setCode(string code) {
    this->code = code;
}

string Curso::getCode() {
    return this->code;
}