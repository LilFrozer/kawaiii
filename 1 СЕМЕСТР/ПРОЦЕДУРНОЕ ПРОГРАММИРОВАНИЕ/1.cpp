#include <iostream>
#include <math.h>
#include <string>
using namespace std;
/*Задание "ИМЯ"*/
void N_1() {
    cout << "АЛЕКСЕЙ ПОДОПЛЕЛОВ";
}
/*Задание "Арифметика"*/
void N_2() {
    double n1 = 0, n2 = 0;
    cout << "ВВЕДИТЕ ПЕРВОЕ ЧИСЛО -> ";
    cin >> n1;
    cout << "ВВЕДИТЕ ВТОРОЕ ЧИСЛО -> ";
    cin >> n2;
    if (n2 == 0) {
        cout << "ERROR!";
    }
    else {
        cout << "СУММА -> " << n1 + n2 << "\n";
        cout << "РАЗНОСТЬ -> " << n1 - n2 << "\n";
        cout << "ПРОИЗВЕДЕНИЕ -> " << n1 * n2 << "\n";
        cout << "ЧАСТНОЕ -> " << n1 / n2 << "\n";
    }
}
/*Задание "Уравнение"*/
void N_3() {
    /*bx + c = 0 -> bx = -c -> x = -c / b -> b != 0*/
    double b = 0, c = 0, x = 0;
    cout << "ВВЕДИТЕ b -> ";
    cin >> b;
    if (b == 0) {
        cout << "ERROR!";
    }
    else {
        cout << "ВВЕДИТЕ c -> ";
        cin >> c;
        cout << "x - > " << ((-1)*c) / b;
    }
}
/*Задание "Еще уравнение"*/
void N_4() {
    double a = 0, b = 0, c = 0;
    cout << "ВВЕДИТЕ a -> ";
    cin >> a;
    if (a == 0) {
        /*bx + c = 0*/
        N_3();
    }
    else {
        cout << "ВВЕДИТЕ b -> ";
        cin >> b;
        if (b == 0) {
            /*a*x^2 + c = 0 -> x^2 = -c / a*/
            cout << "ВВЕДИТЕ с -> ";
            cin >> c;
            if (((-1)*c / a) < 0) {
                cout << "ERROR!";
            }
            else {
                cout << "x -> " << (-1)*c / a;
            }
        }
        else {
            /*a*x^2 + b*x + c = 0*/
            cout << "ВВЕДИТЕ с -> ";
            cin >> c;
            if ((pow(b, 2) - 4*a*c) < 0) {
                cout << "ERROR!";
            }
            else if ((pow(b, 2) - 4*a*c) == 0) {
                cout << "x -> " << ((-1)*b) / (2*a);
            }
            else {
                cout << "x1 -> " << (((-1)*b)+(pow(b, 2) - 4*a*c)) / (2*a) << "\n";
                cout << "x2 -> " << (((-1)*b)-(pow(b, 2) - 4*a*c)) / (2*a) << "\n";
            }
        }
    }
}
/*Задание "Лампа со шторой"*/
void N_5() {
    string a, b, c;
    cout << "НА УЛИЦЕ ДЕНЬ? ДА / НЕТ\n";
    cin >> a;
    if (a == "YES" or a == "ДА") {
        cout << "НА УЛИЦЕ СВЕТЛО.";
        cout << "ШТОРЫ РАЗДВИНУТЫ? ДА / НЕТ\n";
        cin >> b;
        if (b == "YES" or b == "ДА") {
            cout << "В КОМНАТЕ СВЕТЛО.";
        }
        else {
            cout << "ЛАМПА ВКЛЮЧЕНА? ДА / НЕТ\n";
            cin >> c;
            if (c == "YES" or c == "ДА" ) {
                cout << "В КОМНАТЕ СВЕТЛО.";
            }
            else {
                cout << "В КОМНАТЕ НЕТ СВЕТА.";
            }
        }
    }
    else {
        cout << "ЛАМПА ВКЛЮЧЕНА? ДА / НЕТ\n";
        cin >> c;
        if (c == "YES" or c == "ДА" ) {
            cout << "В КОМНАТЕ СВЕТЛО.";
        }
        else {
            cout << "В КОМНАТЕ НЕТ СВЕТА.";
        }
    }
}
/*..........*/
int main() {
    cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ -> 1 - 5\n";
    int numb;
    cin >> numb;
    switch(numb) {
    case 1:
        system("cls");
        N_1();
        break;
    case 2:
        system("cls");
        N_2();
        break;
    case 3:
        system("cls");
        N_3();
        break;
    case 4:
        system("cls");
        N_4();
        break;
    case 5:
        system("cls");
        N_5();
        break;
    default:
        system("cls");
        cout << "У ТЕБЯ ПРОБЛЕМЫ.";
        break;
    }
    return 0;
}