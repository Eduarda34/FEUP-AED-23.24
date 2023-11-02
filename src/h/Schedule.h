#ifndef PROJETO_1_SCHEDULE_H
#define PROJETO_1_SCHEDULE_H

#include "ScheduleSlot.h"
#include <vector>

using namespace std;


class Schedule {
private:
    vector<ScheduleSlot> sched;

public:
    Schedule(vector<ScheduleSlot> classes);
    void addSlot(ScheduleSlot& slot);
    void removeSlot(ScheduleSlot slot);
    vector<ScheduleSlot> getSchedule() const;
    void printSchedule() const;

};


#endif