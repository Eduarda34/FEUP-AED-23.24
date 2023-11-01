#ifndef PROJETO_1_SCHEDULE_H
#define PROJETO_1_SCHEDULE_H

#include "ScheduleSlot.h"


class Schedule {
private:
    //set<SheduleSlot> slot;
    Class c1;
    list<ScheduleSlot> schedule;

public:
    Schedule(Class c1, list<ScheduleSlot> classes);
    Class getClass();
    list<ScheduleSlot> getClasses();
    void addClass(ScheduleSlot class_);
    void removeClass(ScheduleSlot class_);
    void setClass(Class c1); //setter da turma
    void setClasseS(list<ScheduleSlot> classes); //setter da lista de aulas
};


#endif