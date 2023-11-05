#ifndef PROJETO_1_CLASS_H
#define PROJETO_1_CLASS_H
#include <string>
#include "../h/ScheduleSlot.h"
#include "../h/Student.h"
#include <set>

using namespace std;

class Class {
private:
    string uCode;
    string classCode;
    ScheduleSlot* slot;
    set<int> students;

public:
    Class(string uCode, string classCode);
    string getUCode();
    string getClassCode();
    void setUCode(string code);
    void setClassCode(string code);
    bool operator==(const Class& c1) const;
    ScheduleSlot* getSlot() const;
    void setSlot(ScheduleSlot* slot);
    set<int> getStudents() const;
    void addStudent(Student* student);
};


#endif
