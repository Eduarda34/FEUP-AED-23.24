#include "../h/Course.h"

using namespace std;

Course::Course(string code) {
    this->code = code;
}

void Course::setCode(string code) {
    this->code = code;
}

string Course::getCode() {
    return this->code;
}

void Course::addClass(string& c){
    this->classes.push_back(c);
}

void Course::removeClass(string& c){
    string it;
    if (find(this->classes.begin(),this->classes.end(), it) != this->classes.end()){
        this->classes.erase(it);
    }
}

void Course::addStudent(int student){
    this->students.push_back(student);
}

void Course::removeStudent(int student){
    int it;
    if (find(this->students.begin(),this->students.end(), it) != this->students.end()){
        this->students.erase(it);
    }
}

vector<string> Course::getClasses(){
    return this->classes;
}

vector<int> Course::getStudents(){
    return this->students;
}