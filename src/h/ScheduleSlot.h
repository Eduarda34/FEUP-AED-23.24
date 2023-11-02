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
    string type;
    float duration;
    Class* c1;

public:
    ScheduleSlot(string weekDay, float startTime, float duration, string type, Class* c1);
    string getWeekDay();
    float getStartTime();
    float getEndTime();
    float getDuration();
    string getType();
    bool operator==(const ScheduleSlot& slot) const;
    Class* getClass();
    void addClass(Class* c1);
};


#endif
