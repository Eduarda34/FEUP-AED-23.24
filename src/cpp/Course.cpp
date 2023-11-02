#include "../h/Course.h"


Course::Course(string cod) {
    this->code = cod;
}

void Course::setCode(string cod) {
    this->code = cod;
}

string Course::getCode() const {
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

vector<string> Course::getClasses() const{
    return this->classes;
}

vector<int> Course::getStudents() const{
    return this->students;
}