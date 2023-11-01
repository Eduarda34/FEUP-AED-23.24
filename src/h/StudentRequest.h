#ifndef PROJETO_1_STUDENTREQUEST_H
#define PROJETO_1_STUDENTREQUEST_H
#include <iostream>

using namespace std;

class StudentRequest {
public:
    StudentRequest(string tipo, string studentID, string uCode, string initialClassCode, string finalClassCode);
    StudentRequest(string studentID, string uCode, string initialClassCode, string finalClassCode);
    string getTipo();
    string getStudentID();
    string getUCode();
};


#endif
