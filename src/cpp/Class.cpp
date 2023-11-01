#include "../h/Class.h"
#include <utility>
#include "Student.cpp"

Class::Class(string uCode, string curso) {
    this->uCode = std::move(uCode);
    this->curso = std::move(curso);
}

string Class::getuCode() const {
    return this->uCode;
}

string Class::getCurso() const {
    return this->curso;
}

void Class::setUCode(string code) {
    this->uCode = code;
}

void Class::setCurso(string curso) {
    this->curso = curso;
}

void Class::addStudent(const Student& student) {
    this->students()
}