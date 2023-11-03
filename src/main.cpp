#include <fstream>
#include <sstream>
#include <iostream>
#include "h/Student.h"
#include "h/Class.h"
#include "h/Course.h"
#include "h/Menu.h"


int main() {
    auto menu = new Menu();

    studentSet students;
    classSet classes;
    cursoSet courses;

    char choose = '1';

    menu->readClass(&classes);
    menu->readCursos(&courses);
    menu->readStud(&students, &classes, &courses);

    while (choose != '0') {
        menu->clearScreen();

        cout << " __________________________________________________ " << endl;
        cout << "  1 - Listagens                                     " << endl;
        cout << "  2 - Ver Horário                                   " << endl;
        cout << "  3 - Pedidos                                       " << endl;
        cout << "  0 - Exit                                          " << endl;
        cout << " __________________________________________________ " << endl;

        cin >> choose;

        switch (choose) {
            case '1':
                menu->listEverything(&students, &classes, &courses);
                break;

            case '0':

            default:
                cout << "Opcao invalida." << endl;
                menu->wait();
                break;
        }
    }
    return 0;
}