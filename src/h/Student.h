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
    vector<string> curso;

public:
    Student(int number, string name);
    int getNumber() const;
    string getName() const;
    void addClass(const string& c);
    void removeClass(string c);
    void addCurso(const string& curso);
    void removeCurso(string curso);
    vector<string> getClasses() const;
    vector<string> getCurso() const;
};


#endif
