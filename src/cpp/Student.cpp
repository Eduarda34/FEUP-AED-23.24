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

void Student::addClass(string& c) {
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

void Student::addCourse(string& course) {
    this->course.push_back(course);
}

void Student::removeCourse(string course) {
    for (size_t i = 0;i < this->course.size(); i++) {
        if (this->course[i] == course ) {
            this->course.erase(this->course.begin()+i);
            break;
        }
    }
}

vector<string> Student::getClasses() const {
    return this->classes;
}

vector<string> Student::getCourse() const {
    return this->course;
}