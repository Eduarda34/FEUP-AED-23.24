#include "../h/ScheduleSlot.h" //SLOT


ScheduleSlot::ScheduleSlot(string weekDay, float startTime, float endTime, float duration, string type) {
    this->weekDay = weekDay;
    this->startTime = startTime;
    this->endTime = endTime;
    this->type = type;
    this->duration = duration;
    //this->c1 = c1;
}

string ScheduleSlot::getWeekDay() const {
    return this->weekDay;
}

float ScheduleSlot::getStartTime() const {
    return this->startTime;
}

float ScheduleSlot::getEndTime() const {
    return this->startTime + this->duration;
}

float ScheduleSlot::getDuration() const {
    return this->duration;
}

string ScheduleSlot::getType() const {
    return this->type;
}

/*bool ScheduleSlot::operator==(const ScheduleSlot& slot) const {
    return ((this->weekDay==slot.weekDay) && (this->startTime==slot.startTime) && (this->duration==slot.duration) && (this->type==slot.type) && (this->c1==slot.c1));
}*/

bool ScheduleSlot::compatible(const ScheduleSlot *slot) const {
    if (this->weekDay != slot->getWeekDay())
        return true;

    if (this->startTime >= slot->getEndTime() || this->endTime <= slot->getStartTime())
        return true;

    return false;
}

bool ScheduleSlot::operator<(const ScheduleSlot& slot) const {
    return this->startTime < slot.startTime;
}