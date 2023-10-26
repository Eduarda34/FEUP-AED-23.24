#include <iostream>
#include "Class.h"

Class::Class(string uCode, string classCode) {
    this->uCode = uCode;
    this->classCode = classCode;
}

string Class::getuCode() {
    return this->uCode;
}

string Class::getClassCode() {
    return this->classCode;
}