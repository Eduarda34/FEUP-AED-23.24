#ifndef PROJETO_1_SLOT_H
#define PROJETO_1_SLOT_H
#include "Class.h"
#include <string>

using namespace std;

class ScheduleSlot {
private:
    string diaSemana;
    float startTime;
    float endTime;
    string type;
    float duracao;

public:
    ScheduleSlot(string diaSemana, float startTime, float endTime, float duracao, string type);
    string getDiaSemana();
    float getStartTime();
    float getEndTime();
    float getDuration();
    string getType();
};


#endif
