#include <fstream>
#include <sstream>
#include <iostream>
#include "h/Student.h"
#include "h/Class.h"
#include "h/Curso.h"

using namespace std;

typedef set<Student*, compStudent> studentsSet;
typedef set<Class*, compClass> classSet;
typedef set<Curso*, compCurso> cursoSet;

void rClasses(classSet* classes);
void rCurso(cursoSet* curso);
void theStudents(studentsSet* students);
void theClasses(classSet* classes);


struct compStudent {
    bool operator() (Student* s1, Student* s2) const {
        return s1->getNumber() < s2->getNumber();
    }
};

struct compClass {
    bool operator() (Class* c1, Class* c2) const {
        return c1->getUCode() < c2->getUCode();
    }
};

/*struct compCourse {
    bool operator() (Course* )
};*/


void readStud(studentsSet* students) {
    ifstream file ("C:\\Users\\LENOVO\\OneDrive\\Ambiente de Trabalho\\FEUP\\23-24\\AED\\Projeto 1\\schedule\\students_classes.csv");
    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream a(line);

        int number;
        string name;

        a >> number;
        a.ignore();

        getline(a, name, ",");
        //getline(a, course, ",");
        //a >> c1;

        auto student = new Student(number, name);
        auto x = students->find(student);
        if (x == students->end()) {
            students->insert(student);
            x = students->find(student);
        }

        //(*x)->addCourse(course);
        //(*x)->addClass(cl);
    }
}



void listStud(studentsSet* students) {
    for (auto const& students : *students) {
        cout << students->getNumber() << " - " << students->getName() << endl;
    }
}

void readClasses(classSet* classes) {
    ifstream file ("C:\\Users\\LENOVO\\OneDrive\\Ambiente de Trabalho\\FEUP\\23-24\\AED\\Projeto 1\\schedule\\classes.csv");
    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream  a(line);

        string classCode;
        string cursoCode;
        string diaSemana;
        string startTime;
        string endTime;
        string classType;

        getline(a, classCode, ',');
        getline(a, cursoCode, ',');
        getline(a, diaSemana, ',');
        getline(a, startTime, ',');
        getline(a, endTime, ',');
        getline(a, classType, ',');

        auto class1 = new Class(cursoCode, classCode);
        classes->insert(class1);
    }
}


int main() {
    studentsSet students;
    classSet classes;
    cursoSet curso;

    readStud(&students);
    listStud(&students);
    readClasses(&classes);

    cout << " --- " << endl;
    cout << "0 - exit" << endl;

    return 0;
}