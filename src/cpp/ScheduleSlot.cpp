#include "../h/ScheduleSlot.h" //SLOT


ScheduleSlot::ScheduleSlot(string diaSemana, float startTime, float endTime, float duracao, string type) {
    this->diaSemana = diaSemana;
    this->startTime = startTime;
    this->endTime = endTime;
    this->type = type;
    this->duracao = duracao;
}

string ScheduleSlot::getDiaSemana() {
    return this->diaSemana;
}

float ScheduleSlot::getStartTime() {
    return this->startTime;
}

float ScheduleSlot::getEndTime() {
    return this->endTime;
}

float ScheduleSlot::getDuration() {
    return this->duracao;
}

string ScheduleSlot::getType() {
    return this->type;
}
