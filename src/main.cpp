#include <iostream>
#include "Student.h"
#include "Class.h"


typedef set<Student*, compStudent> studentsSet;
typedef set<Class*, compClass> classSet;
//curso

void rClasses(classesSet* classes);
void rCourses(coursesSet* courses);
void theStudents(studentsSet* students);

using namespace std;

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
    ifstream file ("C:\\Users\\LENOVO\\OneDrive\\Ambiente de Trabalho\\FEUP\\23-24\\AED\\Projeto 1\\schedule\\students_classes.csv")

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


int main() {
    studentsSet students;
    classSet classes;

    readStud(&students);
    listStud(&students);
    
    return 0;
}