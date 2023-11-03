#ifndef PROJETO_1_SLOT_H
#define PROJETO_1_SLOT_H
#include "Class.h"
#include <string>
#include <iostream>

using namespace std;

class ScheduleSlot {
private:
    string weekDay;
    float startTime;
    float endTime;
    string type;
    float duration;
    //Class* c1;

public:
    ScheduleSlot(string weekDay, float startTime, float endTime, float duration, string type);
    string getWeekDay() const;
    float getStartTime() const;
    float getEndTime() const;
    float getDuration() const;
    string getType() const;
    bool compatible(const ScheduleSlot *slot) const;
    bool operator<(const ScheduleSlot& slot) const;
    /*Class* getClass();
    void addClass(Class* c1);*/
};


#endif
