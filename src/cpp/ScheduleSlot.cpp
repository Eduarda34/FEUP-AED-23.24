#include "../h/ScheduleSlot.h" //SLOT


ScheduleSlot::ScheduleSlot(string weekDay, float startTime, float duration, string type, Class* c1) {
    this->weekDay = weekDay;
    this->startTime = startTime;
    this->type = type;
    this->duration = duration;
    this->c1 = c1;
}

string ScheduleSlot::getWeekDay() {
    return this->weekDay;
}

float ScheduleSlot::getStartTime() {
    return this->startTime;
}

float ScheduleSlot::getEndTime() {
    return this->startTime+this->duration;
}

float ScheduleSlot::getDuration() {
    return this->duration;
}

string ScheduleSlot::getType() {
    return this->type;
}

bool ScheduleSlot::operator==(const ScheduleSlot& slot) const {
    return ((this->weekDay==slot.weekDay) && (this->startTime==slot.startTime) && (this->duration==slot.duration) && (this->type==slot.type) && (this->c1==slot.c1));
}

Class* ScheduleSlot::getClass(){
    return this->c1;
}

void addClass(Class* c1){
    this->c1 = c1;
}