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

void Student::addClass(const string& c) {
    this->classes.push_back(c);
}

void Student::removeClass(string c) {
    for (size_t i = 0;i < this->classes.size(); i++) {
        if (this->classes[i] == c ) {
            this->classes.erase(this->classes.begin()+i);
            break;
        }
    }
}

void Student::addCurso(const string& curso) {
    this->curso.push_back(curso);
}

void Student::removeCurso(string curso) {
    for (size_t i = 0;i < this->curso.size(); i++) {
        if (this->curso[i] == curso ) {
            this->curso.erase(this->curso.begin()+i);
            break;
        }
    }
}

vector<string> Student::getClasses() const {
    return this->classes;
}

vector<string> Student::getCurso() const {
    return this->curso;
}