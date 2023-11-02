#include "../h/Class.h"

Class::Class(string uCode, string classCode) {
    this->uCode = uCode;
    this->classCode = classCode;
}

string Class::getUCode() {
    return this->uCode;
}

string Class::getClassCode() {
    return this->classCode;
}

void Class::setUCode(string code) {
    this->uCode = code;
}

void Class::setClassCode(string code) {
    this->classCode = code;
}

bool Class::operator==(const Class& c1) const{
    return ((this->uCode==c1.uCode) && (this->classCode==c1.classCode));
}