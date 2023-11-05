#include "../h/Menu.h"
#include <iostream>
#include <fstream>
#include "../h/Course.h"
#include "../h/Class.h"

using namespace std;



void Menu::readStud(studentSet* students, classSet* classes, cursoSet* cursos) {
    ifstream file("schedule/students_classes.csv");
    string line;
    getline(file, line); //ingora a primiera linha

    while(getline(file, line)) {
        istringstream a(line);
        int n;

        string studName, course, code;

        a >> n;
        a.ignore();

        getline(a, studName, ',');
        getline(a, course, ',');
        a >> code;

        auto clas_s = new Class(code, course);
        auto iterator = classes->find(clas_s);
        if (iterator != classes->end()) {
            (*iterator)->addStudent(n);
        }

        auto studen_t = new Student(n, studName);
        auto iterator2 = students->find(studen_t);
        if (iterator2 == students->end()) {
            students->insert(studen_t);
            iterator2 = students->find(studen_t);
        }

        (*iterator2)->addClass(make_pair(course, code));

        auto cours_e = new Course(course);
        auto iterator3 = course.find(cours_e);
        if (iterator3 != course.end()) {
            (*iterator3)->addStudent(n);
        }
    }
}

void Menu::readClass(classSet *classes) {
    ifstream file("schedule/classes.csv");
    string line;
    getline(file, line); //ignora a primeira linha

    while (getline(file, line)) {
        istringstream a(line);

        string classCode, courseCode, day, type;
        float starTime, endTime, duration;

        getline(a, classCode, ',');
        getline(a, courseCode, ',');
        getline(a, day, ',');

        a >> starTime;
        a.ignore();
        a >> duration;
        a.ignore();
        a >> type;

        auto c = new Class(classCode, courseCode);
        auto iterator = classes->find(c);
        if (iterator == classes->end()) {
            classes->insert(c);
            iterator = classes->find(c);
        }

        endTime = starTime + duration;

        (*iterator)->setSlot(ScheduleSlot(day, starTime, endTime, duration, type));
    }
}

void Menu::readCursos(cursoSet* cursos) {
    ifstream file("schedule/classes_per_uc.csv");
    string line;
    getline(file, line); //ignora a primeira linha

    while (getline(file, line)) {
        istringstream a(line);
        string courseCode, classCode;

        getline(a, courseCode, ',');
        a >> classCode;

        auto cours_e = new Course(courseCode);
        auto iterator = cursos->find(cours_e);
        if (iterator == cursos->end()) {
            cursos->insert(cours_e);
            iterator = cursos->find(cours_e);
        }
        (*iterator)->addClass(classCode);
    }
}

void Menu::clearScreen() {
    cout << string(50, '\n');
}

void Menu::wait() {
    cout << endl << "Please, press any key to continue...";
    cin.get();
}

void Menu::listStud(studentSet* students, int ch1, int ch2, int ch3, int ch4, int ch5, int max, int min, int a) {
    clearScreen();

    vector<Student*> v;

    if(ch5 == 1) {
        for (auto student : *students) {
            if (student->getClasses().size() > a) {
                v.push_back(student);
            }
        }
    }

    else if(ch5 == 2) {
        for (auto student : *students) {
            if (student->getClasses().size() < a) {
                v.push_back(student);
            }
        }
    }

    else if (ch4 == 1) {
        for (auto student : *students) {
            if (student->getNumber() >= min && student->getNumber() <= max) {
                v.push_back(student);
            }
        }
    }

    else {
        for (auto student : *students) {
            v.push_back(student);
        }
    }

    sort(v.begin(), v.end(), [ch1, ch2](Student* x, Student* y) {
        if (ch1 == 0) {
            if (ch2 == 0)
                return x->getNumber() < y->getNumber();

            else
                return x->getNumber() > y->getNumber();

        }

        else {
            if (ch2 == 0)
                return x->getName() < y->getName();

            else
                return x->getName() > y->getName();

        }
    });

    for (auto student : v) {
        cout << "  " << student->getNumber() << " - " << student->getName() << endl;

        if (ch3 == 1) {
            for (const auto& clas_s : student->getClasses())
                cout << "    " << clas_s[0] << " - " << clas_s[1] << endl;
        }
    }
}

void Menu::listClasses(classSet* classes, studentSet* students, int ch1, int ch2, int ch3) {
    clearScreen();

    vector<Class*> v;

    for (auto cl : *classes) {
        v.push_back(cl);
    }

    sort(v.begin(), v.end(), [ch1, ch2](Class* x, Class* y) {
        if (ch1 == 0) {
            if (ch2 == 0)
                return x->getUCode() < y->getUCode();

            else
                return x->getUCode() > y->getUCode();
        }

        else {
            if (ch2 == 0)
                return x->getStudents().size() < y->getStudents().size();

            else
                return x->getStudents().size() > y->getStudents().size();
        }
    });


    for (auto cl : v) {
        cout << "  " << cl->getClassCode() << " - " << cl->getClassCode() << endl;

        if (ch3 == 1) {
            for (const auto& s: cl->getStudents()) {
                auto iterator = students->find(new Student(s, ""));
                cout << "    " << (*iterator)->getNumber() << " - " << (*iterator)->getName() << endl;
            }
        }
    }
}

void Menu::listCourses(cursoSet* courses, studentSet* students, int ch1, int ch2, int ch3) {
    clearScreen();
    vector<Course*> v;

    for (auto course : *courses) {
        v.push_back(course);
    }

    sort(v.begin(), v.end(), [ch1](Course* x, Course* y) {
        if (ch1 == 0)
            return x->getStudents().size() < y->getStudents().size();

        else
            return x->getStudents().size() > y->getStudents().size();

    });

    if (ch2 == 1) {
        for (auto course: v) {
            cout << "  " << course->getCode() << endl;

            for (const auto &clas_s: course->getClasses())
                cout << "    " << clas_s << endl;
        }
    }

    if (ch3 == 1) {
        for (auto course: v) {
            cout << "  " << course->getCode() << endl;

            for (const auto &student: course->getStudents()) {
                auto iterator = students->find(new Student(student, ""));
                cout << "        " << (*iterator)->getNumber() << " - " << (*iterator)->getName() << endl;
            }
        }
    }
}

void Menu::studFilters(studentSet *students) {
    clearScreen();

    int ch1 = -1, ch2 = -1, ch3 = -1, ch4 = -1, ch5 = -1;
    int min, max, n;

    cout << "Ver: Todos os estudantes (0) | Estudantes em mais de x turmas (1) | Estudantes em menos de n turmas (2)" << endl;
    while (ch5 != 0 && ch5 != 1 && ch5 != 2) {
        cout << "Opcao:";
        cin >> ch5;
        cout << endl;
    }


    if (ch5 == 1 || ch5 == 2) {
        cout << "Numero de turmas:";
        cin >> n;
        cout << endl;
    }

    cout << "Ordenar por: numero(0) | nome (1)" << endl;
    while (ch1 != 0 && ch1 != 1) {
        cout << "Opcao:";
        cin >> ch1;
        cout << endl; }

    cout << "Filtrar por: nada (0) | range (1)" << endl;
    while (ch4 != 0 && ch4 != 1) {
        cout << "Option:";
        cin >> ch4;
        cout << endl;
    }

    if (ch4 == 1) {
        cout << "Range:" << endl;
        cout << "Min:";
        cin >> min;
        cout << "Max:";
        cin >> max;
        cout << endl;
    }

    cout << "Colocar por ordem: crescente (0) | decrescente (1)" << endl;
    while (ch2 != 0 && ch2 != 1) {
        cout << "Opcao:";
        cin >> ch2;
        cout << endl;
    }

    cout << "Pretende ver as turmas dos estudantes?: nao (0) | sim (1)" << endl;

    while (ch3 != 0 && ch3 != 1) {
        cout << "Opcao:";
        cin >> ch3;
        cout << endl;
    }

    listStud(students, ch1, ch2, ch3, ch4, ch5, max, min, n);
    wait();
}

void Menu::classFilters(classSet* classes, studentSet* students) {
    clearScreen();

    int ch1 = -1, ch2 = -1, ch3 = -1;

    cout << "Ordenar por: codigo (0) | ocupacao (1)" << endl;
    while (ch1 != 0 && ch1 != 1) {
        cout << "Opcao:";
        cin >> ch1;
        cout << endl;
    }

    cout << "Ordem: crescente (0) | decrescente (1)" << endl;
    while (ch2 != 0 && ch2 != 1) {
        cout << "Opcao:";
        cin >> ch2;
        cout << endl; }

    cout << "Ver turma do estudante?: nao (0) | sim (1)" << endl;
    while (ch3 != 0 && ch3 != 1) {
        cout << "Opcao:";
        cin >> ch3;
        cout << endl; }

    listClasses(classes, students, ch1, ch2, ch3);
    wait();
}

void Menu::cursoFilters(cursoSet* courses, studentSet* students) {
    clearScreen();

    int ch1 = -1, ch2 = -1, ch3 = -1;

    cout << "Ordem (por ocupacao): crescente (0) | decrescente (1)" << endl;
    while (ch1 != 0 && ch1 != 1) {
        cout << "Opcao:";
        cin >> ch1;
        cout << endl;
    }

    cout << "Ver turmas das UCs?: nao (0) | sim (1)" << endl;
    while (ch2 != 0 && ch2 != 1) {
        cout << "Opcao:";
        cin >> ch2;
        cout << endl;
    }

    if (ch2 == 0) {
        cout << "Ver estudantes das UCs?: nao (0) | sim (1)" << endl;
        while (ch3 != 0 && ch3 != 1) {
            cout << "Opcao:";
            cin >> ch3;
            cout << endl;
        }
    }

    listCourses(courses, students, ch1, ch2, ch3);
    wait();
}

void Menu::listEverything(studentSet* students, classSet* classes, cursoSet* courses) {
    char choose = '1';

    while (choose != '0') {
        clearScreen();

        cout << " __________________________________________________ " << endl;
        cout << "  1 - Listar Estudantes                             " << endl;
        cout << "  2 - Listar Turmas                                 " << endl;
        cout << "  3 - Listar UCs                                    " << endl;
        cout << "  0 - Return                                        " << endl;
        cout << " __________________________________________________ " << endl;

        cin >> choose;

        switch (choose) {
            case '1':
                studFilters(students);
                break;

            case '2':
                classFilters(classes, students);
                break;

            case '3':
                cursoFilters(courses, students);
                break;

            case '0':
                cout << "Opcao invalida." << endl;
                wait();
                break;
        }
    }
}