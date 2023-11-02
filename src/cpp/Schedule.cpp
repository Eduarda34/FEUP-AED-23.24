#include "../h/Schedule.h"

Schedule::Schedule(vector<ScheduleSlot> classes){
    this->sched=classes;
}

void Schedule::addSlot(ScheduleSlot& slot){
    this->sched.push_back(slot);
}

void Schedule::removeSlot(ScheduleSlot slot){
    for (size_t i = 0;i < this->sched.size(); i++) {
        if (this->sched[i] == slot ) {
            this->sched.erase(this->sched.begin()+i);
            break;
        }
    }
}

vector<ScheduleSlot> Schedule::getSchedule() const{
    return this->sched;
}

void Schedule::printSchedule() const{
    vector<string> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    for (string wday : week) {
        cout << wday << ": " << endl << "    | ";
        for (ScheduleSlot slot : this->sched){
            if (slot.getWeekDay() == wday) {
                cout << slot.getStartTime() << " - " << slot.getEndTime() << slot.getClass()->getClassCode() << " " << slot.getType() << " | ";
            }
        }

    }
}
