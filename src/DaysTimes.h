#ifndef PROJETO_1_DAYSTIMES_H
#define PROJETO_1_DAYSTIMES_H
#include <iostream>
#include "Class.h"

using namespace std;

class DaysTimes {
private:
    string diaSemana;
    string starTime;
    string endTime;
    string type;
    int duracao;

public:
    DaysTimes(string diaSemana, string starTime, string endTime, string type, int duracao);
    string getDiaSemana();
    string getStarTime();
    string getEndTime();
};


#endif
