#ifndef PROJETO_1_STUDENTREQUEST_H
#define PROJETO_1_STUDENTREQUEST_H
#include <iostream>
#include <fstream>
#include "Menu.h"

using namespace std;

class StudentRequest {
private:
    string tipo;
    string studentID;
    string uCode;
    string initialClassCode;
    string finalClassCode;
public:
    StudentRequest(string tipo, string studentID, string uCode, string initialClassCode, string finalClassCode);
    StudentRequest(string studentID, string uCode, string initialClassCode, string finalClassCode);
    string getTipo();
    string getStudentID();
    string getUCode();
    void processRequest(StudentRequest request);
};


#endif
