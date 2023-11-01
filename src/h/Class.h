#ifndef PROJETO_1_CLASS_H
#define PROJETO_1_CLASS_H
#include <string>


using namespace std;

class Class {
private:
    string uCode;
    string curso;

public:
    Class(string uCode, string classCode);
    void setUCode(string code);
    void setCurso(string curso);
    string getCurso() const;

string getuCode() const;
};


#endif
