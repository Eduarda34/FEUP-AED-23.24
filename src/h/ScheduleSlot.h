#ifndef PROJETO_1_SLOT_H
#define PROJETO_1_SLOT_H
#include <bits/stdc++.h>
#include "Class.h"
using namespace std;

class ScheduleSlot {
private:
    string diaSemana;
    float startTime;
    float endTime;
    string type;
    float duracao;

public:
    DaysTimes(string diaSemana, float startTime, float endTime, float duracao, string type,);
    string getDiaSemana();
    float getStartTime();
    float getEndTime();
    float getDuration();
    string getType();
};


#endif
