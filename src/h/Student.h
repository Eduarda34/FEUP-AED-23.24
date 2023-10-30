#ifndef PROJETO_1_STUDENT_H
#define PROJETO_1_STUDENT_H



using namespace std;

class Student {
private:
    int number;
    string name;
    set<string> classes;
    set<string> curso;

public:
    Student(int number, string name);
    int getNumber() const;
    string getName() const;
    void addClass(const string& c1);
    void removeClass(string c1);
    void addCurso(const string& curso);
    void removeCurso(string curso);
    set<string> getClasses() const;
    set<string> getCurso() const;
};


#endif
