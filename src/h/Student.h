#ifndef PROJETO_1_STUDENT_H
#define PROJETO_1_STUDENT_H
#include <string>
#include <vector>
#include <algorithm>
#include "Schedule.h"

using namespace std;

class Student {
private:
    int number;
    string name;
    vector<string> classes;
    vector<string> course;
    Schedule* sched;

public:
    Student(int number, string name);
    int getNumber() const;
    string getName() const;
    void addClass(string& c);
    void removeClass(string c);
    void addCourse(string& course);
    void removeCourse(string course);
    vector<string> getClasses() const;
    vector<string> getCourse() const;
    Schedule* getSchedule() const;
    void setSchedule(Schedule* sched);
};


#endif
