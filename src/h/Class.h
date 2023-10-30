#ifndef PROJETO_1_CLASS_H
#define PROJETO_1_CLASS_H
#include <bits/stdc++.h>
using namespace std;

class Class {
private:
    string uCode;
    string classCode;

public:
    Class(string uCode, string classCode);
    string getuCode();
    string getClassCode();
    void setUCode(string code);
    void setClassCode(string code);
};


#endif
