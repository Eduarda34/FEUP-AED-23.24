#include <iostream>
#include "../h/Student.h"

Student::Student(int number, string name) {
    this->name = name;
    this->number = number;
}

int Student::getNumber() const {
    return this->number;
}

string Student::getName() const {
    return this->name;
}

void Student::addClass(const string& c1) {
    this->classes.insert(c1);
}

void Student::removeClass(string c1) {
    if (this->classes.find(c1) != this->classes.end())
        this->classes.erase(c1);
}

void Student::addCurso(const string& curso) {
    this->curso.insert(curso);
}

void Student::removeCurso(string curso) {
    if (this->curso.find(curso) != this->curso.end())
        this->curso.erase(curso);
}

set<string> Student::getClasses() const {
    return this->classes;
}

set<string> Student::getCurso() const {
    return this->curso;
}