#ifndef PROJETO_1_MENU_H
#define PROJETO_1_MENU_H
#include "Course.h"
#include "Class.h"
#include "StudentRequest.h"
#include "Student.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

struct compareStud {
    bool operator()(Student* e1, Student* e2) const {
        return e1->getNumber() < e2->getNumber();
    }
};

struct compareCurso {
    bool operator()(Course* u1, Course* u2) const {
        return u1->getCode() < u2->getCode();
    }
};

struct compareClass {
    bool operator()(Class* c1, Class* c2) const {
        if (c1->getClassCode() == c2->getClassCode())
            return c1->getUCode() < c2->getUCode();

        return c1->getClassCode() < c2->getClassCode();
    }
};

typedef set<Student*, compareStud> studentSet;
typedef set<Course*, compareCurso> cursoSet;
typedef set<Class*, compareClass> classSet;

class Menu {
public:
    void readStud(studentSet* students, classSet* classes, cursoSet* cursos);
    void readClass(classSet* classes);
    void readCursos(cursoSet* cursos);
    void clearScreen();
    void wait();
    void listStud(studentSet* students, int ch1, int ch2, int ch3, int ch4, int ch5, int max, int min, int a);
    void listClasses(classSet* classes, studentSet* students, int ch1, int ch2, int ch3);
    void listCourses(cursoSet* courses, studentSet* students, int ch1, int ch2, int ch3);
    void studFilters(studentSet *students);
    void classFilters(classSet* classes, studentSet* students);
    void cursoFilters(cursoSet* courses, studentSet* students);
    void listEverything(studentSet* students, classSet* classes, cursoSet* courses);
};




#endif //PROJETO_1_MENU_H
