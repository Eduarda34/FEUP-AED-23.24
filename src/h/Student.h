#ifndef PROJETO_1_STUDENT_H
#define PROJETO_1_STUDENT_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    int number;
    string name;
    vector<string> classes;
    vector<string> course;

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
};


#endif
