#ifndef PROJETO_1_COURSE_H
#define PROJETO_1_COURSE_H
#include <bits/stdc++.h>

using namespace std;

class Course {
private:
    string code;
    vector<string>classes;
    vector<int>students;
public:
    Course(string code);
    void setCode(string code);
    string getCode();
    void addClass(string& c);
    void removeClass(string& c);
    void addStudent(int student);
    void removeStudent(int student);
    vector<string> getClasses();
    vector<int> getStudents();
};


#endif
