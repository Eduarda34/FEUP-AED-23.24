#include "../h/Course.h"


Course::Course(string codigo) {
    this->code = codigo;
}

void Course::setCode(string codigo) {
    this->code = codigo;
}

string Course::getCode() {
    return this->code;
}

void Course::addClass(string& c){
    this->classes.push_back(c);
}

void Course::removeClass(string& c){
    for (size_t i = 0;i < this->classes.size(); i++) {
        if (this->classes[i] == c ) {
            this->classes.erase(this->classes.begin()+i);
            break;
        }
    }
}

void Course::addStudent(int student){
    this->students.push_back(student);
}

void Course::removeStudent(int student){
    for (size_t i = 0;i < this->students.size(); i++) {
        if (this->students[i] == student ) {
            this->students.erase(this->students.begin()+i);
            break;
        }
    }
}

vector<string> Course::getClasses(){
    return this->classes;
}

vector<int> Course::getStudents(){
    return this->students;
}