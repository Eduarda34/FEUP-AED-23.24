#include "../h/StudentRequest.h"

StudentRequest::StudentRequest(string tipo, string studentID, string uCode, string initialClassCode, string finalClassCode) {
    this->tipo=tipo;
    this->studentID=studentID;
    this->uCode=uCode;
    this->initialClassCode=initialClassCode;
    this->finalClassCode=finalClassCode;
}

StudentRequest::StudentRequest(string studentID, string uCode, string initialClassCode, string finalClassCode) {
    this->studentID=studentID;
    this->uCode=uCode;
    this->initialClassCode=initialClassCode;
    this->finalClassCode=finalClassCode;
}

string StudentRequest::getTipo() {
    return this->tipo;
}

string StudentRequest::getStudentID() {
    return this->studentID;
}

string StudentRequest::getUCode(){
    return this->uCode;
}

void processRequest(StudentRequest request){

}