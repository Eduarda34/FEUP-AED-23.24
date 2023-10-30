#ifndef PROJETO_1_CURSO_H
#define PROJETO_1_CURSO_H
#include <iostream>

using namespace std;

class Curso {
private:
    string code;
private:
    Curso(string code);
    void setCode(string code);
    string getCode();
};


#endif
