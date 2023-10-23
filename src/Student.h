#ifndef PROJETO_1_STUDENT_H
#define PROJETO_1_STUDENT_H

#include <string.h>
#include <vector>

using namespace std;

class Student {
private:
    int number;
    string name;

public:
    Student(int number, string name);
    int getNumber() const;
    string getName() const;
};


#endif
