#ifndef PROJETO_1_CLASS_H
#define PROJETO_1_CLASS_H
#include <string>
#include "ScheduleSlot.h"


using namespace std;

class Class {
private:
    string uCode;
    string classCode;
    ScheduleSlot* slot;

public:
    Class(string uCode, string classCode);
    string getUCode();
    string getClassCode();
    void setUCode(string code);
    void setClassCode(string code);
    bool operator==(const Class& c1) const;
    ScheduleSlot* getSlot() const;
    void setSlot(ScheduleSlot* slot);
};


#endif
