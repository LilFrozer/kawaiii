#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;
/*Задача "Конус"*/
void N_1() {
    double h, R, r, l;
    cout << "ВВЕДИТЕ h -> ";
    cin >> h;
    cout << "ВВЕДИТЕ r -> ";
    cin >> r;
    cout << "ВВЕДИТЕ R -> ";
    cin >> R;
    cout << "ВВЕДИТЕ l -> ";
    cin >> l;
    if (sqrt(pow(h, 2) + pow((R - r), 2)) !=  l) {
        cout << "ERROR" << endl;
    }
    else if (r >= R) {
        if (r == R && h == l) {
            cout << "V = " << (M_PI * pow(r, 2) * h) << endl;
            cout << "S = " << (2 * M_PI * pow(r, 2) + 2 * M_PI * r * h) << endl;
        } 
        else {
            cout << "ERROR" << endl;
        }
    }
    else if (h < 0 || R < 0 || r < 0 || l < 0) {
        cout << "ERROR" << endl;
    }
    else {
        cout << "V = " << (1. / 3.) * M_PI * h * (pow(R, 2) + R * r + pow(r, 2)) << endl;
        cout << "S = " << M_PI * (pow(R, 2) + (R + r) * l + pow(r, 2)) << endl;
    }
}
/*Задача "Разветвление"*/
void N_2() {
    double x, a;
    cout << "ВВЕДИТЕ x -> ";
    cin >> x;
    if (abs(x) < 1) {
        cout << "ВВЕДИТЕ a -> ";
        cin >> a;
        cout << "W = " << a*(log(abs(x)));
    }
    else {
        cout << "ВВЕДИТЕ a -> ";
        cin >> a;
        if ((a-(pow(x,2))) < 0) {
            cout << "ERROR";
        }
        else {
            cout << "W = " << pow((a-pow(x,2)), 0.5);
        }
    }
}
/*Задача "Функция"*/
void N_3() {
    double x = 0, y = 0, b = 0;
    cout << "ВВЕДИТЕ x -> ";
    cin >> x;
    cout << "ВВЕДИТЕ y -> ";
    cin >> y;
    cout << "ВВЕДИТЕ b -> ";
    cin >> b;
    if ((b - y) <= 0 or (b - x) < 0) {
        cout << "ERROR";
    }
    else {
        cout << "z = " << (log(b-y))*pow((b-x), 0.5);
    }
}
/*Задача "Порядок"*/
void N_4() {
    int numb;
    cout << "ВВЕДИТЕ ЧИСЛО -> ";
    cin >> numb;
    if (numb <= 0) {
        cout << "ERROR";
    }
    else {
        for (int i = numb; i < numb + 10; i++) {
            cout << i << " ";
        }
    }
}
/*Задача "Табуляция"*/
void N_5() {
    for (double i = -4; i <= 4; i+=0.5) {
        if (i < 0) {
            if (i != static_cast<int>(round(i))) {
                cout << "X -> " << i << setw(18) << "Y = " << (pow(i,2) - 2*i + 2) / i - 1 << "\n";
            }
            else {
                cout << "X -> " << i << setw(20) << "Y = " << (pow(i,2) - 2*i + 2) / i - 1 << "\n";
            }
        }
        else if (i == 0) {
            cout << "X -> " << i << setw(21) << "Y = " << (-1)*2 << "\n";
        }
        else {
            if (i != static_cast<int>(round(i))) {
                cout << "X -> " << i << setw(19) << "Y = " << (pow(i,2) - 2*i + 2) / i - 1 << "\n";
            }
            else if (i == 1) {
                cout << "X -> 1                 Y = НЕВОЗМОЖНО ПОЛУЧИТЬ\n";
            }
            else {
                cout << "X -> " << i << setw(21) << "Y = " << (pow(i,2) - 2*i + 2) / i - 1 << "\n";
            }
        }
    }
}
/*..........*/
int main() {
    int numb;
    cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ -> 1 - 5\n";
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
        cout << "ERROR";
        break;
    }
    return 0;
}