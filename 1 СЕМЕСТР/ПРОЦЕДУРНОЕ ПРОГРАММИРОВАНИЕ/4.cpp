#define _USE_MATH_DEFINES
#include <string>
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
/*Перевод числа*/
double into_numb(string numb) {
    double cnt = 0;
    stringstream ss;
    ss << numb;
    ss >> cnt;
    return cnt;
}
/*Проверка на ввод числа*/
int check_number(string text) {
    char arr[10] = { '1', '2', '3', '4', '5', '6', '7','8','9','0' };
    int v = 0;
    if (text[0] == '-') {
        text.erase(0, 1);
    }
    for (int c = 0; c < text.length(); c++) {
        int i = 0;
        for (char t : arr) {
            if (text[c] == '.') {
                if (v == 0) {
                    v++;
                    break;
                }
                else {
                    return false;
                }
            }
            if (text[c] == t) {
                break;
            }
            if (i >= 9) {
                return false;
            }
            i++;
        }
    }
    return true;
}
/*Файл*/
void N_1() {
    double SUM = 0;
    ofstream file("file.txt");
    string numb, s; /*Число*/
    int i = 0;
    while (i != 10) {
        int j = i + 1;
        cout << "ВВЕДИТЕ ЧИСЛО #" << j << "\n";
        cin >> numb;
        if (check_number(numb) == 1) {
            file << into_numb(numb) << "\n";
        }
        else {
            cout << "ERROR";
            break;
        }
        i++;
    }
    file.close();
    ifstream file1("file.txt");
    if (file1.is_open()) {
        while(getline(file1, s)) {
            SUM+=into_numb(s);
        }
    }
    else {
        cout << "ERROR";
    }
    file1.close();
    cout << "SUM -> " << SUM;
}
/*Знак числа*/
int signx(double numb) {
    if (numb > 0) {
        return 1;
    }
    else if (numb == 0) {
        return 0;
    }
    else {
        return -1;
    }
}
void N_2() {
    string numb;
    cout << "ВВЕДИТЕ ЧИСЛО -> ";
    cin >> numb;
    if (check_number(numb) == 1) {
        cout << "ОТВЕТ -> " << signx(into_numb(numb));
    }
    else {
        cout << "ERROR";
    }
}
/*Геометрические фигуры*/
void rectangle() {
    double a, b;
    cout << "ВВЕДИТЕ СТОРОНЫ ПРЯМОУГОЛЬНИКА." << endl;
    cin >> a;
    cin >> b;
    if (a > 0 && b > 0) {
        cout << "ПЛОЩАДЬ ПРЯМОУГОЛЬНИКА РАВНА -> " << a * b << endl;
    }
    else {
        cout << "ERROR" << endl;
    }
}
void triangle() {
    double a, b, c;
    cout << "ВВЕДИТЕ СТОРОНЫ ТРЕУГОЛЬНИКА." << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a + b > c && b + c > a && a + c > b && a > 0 && b > 0 && c > 0) {
        double p = (a + b + c) / 2;
        cout << "ПЛОЩАДЬ ТРЕУГОЛЬНИКА РАВНА -> " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl; // Формула Герона
    }
    else {
        cout << "ERROR" << endl;
    }
}
void circle() {
    cout << "ВВЕДИТЕ РАДИУС КРУГА." << endl;
    double r;
    cin >> r;
    double PI = M_PI;
    if (r > 0) {
        cout << "ПЛОЩАДЬ КРУГА РАВНА --> " << PI * r * r << endl;
    }
    else {
        cout << "ERROR" << endl;
    }
}
void N_3() {
    cout << "ВЫБРАТЬ ФИГУРУ." << endl;
    cout << "Прямоугольник -> 0." << endl;
    cout << "Треугольник -> 1." << endl;
    cout << "Круг -> 2." << endl;
    int k;
    cin >> k;
    switch (k) {
    case 0:
        rectangle();
        break;
    case 1:
        triangle();
        break;
    case 2:
        circle();
        break;
    default:
        cout << "ERROR" << endl;
        return N_3();
    }
}
/*Былая слава*/
void N_4() {
    cout << "ФЛАГ." << "\n";
    char flag[13][30];
	for (int x = 0; x < 8; x++) {
		for(int y = 0; y < 6; y++) {
			flag[x][y] = '*';
		}
	}
	for (int x = 0; x < 8; x++) {
		for(int y = 6; y < 30; y++) {
			flag[x][y] = '_';
		}
	}
	for (int x = 8; x < 13; x++) {
	    for (int y = 0; y < 30; y++) {
	        flag[x][y] = '_';
	    }
	    cout << endl;
	}
	for (int x = 0; x < 13; x++) {
	    for (int y = 0; y < 30; y++) {
	        cout << flag[x][y];
	    }
	    cout << "\n";
	}
}
/*Синусоида -> 2 ВАРИАНТА*/
/*
void N_5_1() {
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    SelectObject(hdc, Pen);
    for (float i = -2000.0; i <= 2000.0; i += 0.01) {
        float r = -250.0 * sin(i / 100.0);
        float k = fabs(sin(i / 100.0));
        int y = (int)(-250.0 * k * sin(i / 4.0));
        SetPixel(hdc, (int)i + 600, y + 300 + 250, RGB(100, 250, 250));
        SetPixel(hdc, (int)i + 600, r + 300 + 250, RGB(250, 0, 0));
        SetPixel(hdc, (int)i + 600, -r + 300 + 250, RGB(0, 250, 0));
    };
    for (int x = -2000; x <= 2000 + 100; x++) {
        SetPixel(hdc, x, 300 + 250, RGB(250, 250, 250));
    }
}
void N_5_2() {
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));//цвет осей
    SelectObject(hDC, Pen);
    MoveToEx(hDC, 0, 200, NULL);
    LineTo(hDC, 1000, 200);
    MoveToEx(hDC, 500, 0, NULL);
    LineTo(hDC, 500, 400);
    Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));//цвет графика
    SelectObject(hDC, Pen);
    for (float x = -74.0f; x <= 75.0f; x += 0.01f) //начало и конец графика
    {
        MoveToEx(hDC, 10 * x + 250, -10 * sin(x) + 200, NULL); //период/амплитуда/координата по y
        LineTo(hDC, 10 * x + 250, -10 * sin(x) + 200);
    }
    ReleaseDC(hWnd, hDC);
    while (true) {
        Sleep(0);
    }
}*/
/*Автоматный распознаватель*/
int RIM(char x) { 
    switch (x) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;   
    case 'M': return 1000;
    }
    return -1;
}
bool Check4(string num) {
    vector<string> errorNums = {
     "","VX","VIV","VIIX","VIIV","VIIXL","IIIV","IIV","IIII","IIX","XIIII","XIIIIX",
     "XIIIIX","XXXX","LL","CLC","CLL","DLD","LDD","LLI","MMMCMXCX","AXX","LXA","XXIXX",
     "VVX","VXV","IVI","XLX","LCL","IVV","IXX","XLL","XCC","CDD","CMM","LXL","DCD",
     "MDXCLXIVIL","MDCILXIVIIX","MDMMCLXIVICI"
    };

    if (find(errorNums.begin(), errorNums.end(), num) != errorNums.end())
    {
        return false;
    }
    return true;
}
int convert(string x) {
    int i;
    int j = 0;
    int lenX;
    int result = 0;
    lenX = x.length() - 1;
    for (i = lenX; i >= 0; i--) {
        if (RIM(x[i]) >= j)
            result += RIM(x[i]);
        else
            result -= RIM(x[i]);
        j = RIM(x[i]);
    }
    return result;
}
string toRoman(int x) {
    string res = "";
    int n = x;
    int i = 12;
    int arab[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    string roman[13] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    while (n > 0) {
        while (arab[i] > n) {
            i--;
        }
        res += roman[i];
        n -= arab[i];
    }
    return res;
}
void N_6() {
    string y;
    cout << "ВВВЕДИТЕ РИМСКОЕ ЧИСЛО -> ";
    cin >> y;
    int l = 0;
    for (int i = 0; i < y.length(); i++) {
        if (y[i] == 'I' or y[i] == 'V' or y[i] == 'X' or y[i] == 'L' or y[i] == 'C' or y[i] == 'D' or y[i] == 'M') {
            l += 1;
        }
    }
    if (y.length() == l and Check4(y)) {
        int v = convert(y);
        if (toRoman(v) == y) {
            cout << "ОТВЕТ -> " << convert(y) << endl;
        }
        else {
            cout << "ERROR" << endl;
            return N_6();
        }
    }
    else {
        cout << "ERROR" << endl;
        return N_6();
    }
}
/*Генератор случайных чисел*/
void gen(int m, int b, int c, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s = (m * s + b) % c;
        cout << s << " ";
    }
}
void task7_1() {
    int m = 37;
    int b = 3;
    int c = 64;
    cout << "Введите количество чисел." << endl;
    int n;
    cin >> n;
    gen(m, b, c, n);
}
void task7_2() {
    int m = 25173;
    int b = 13849;
    int c = 65537;
    cout << "Введите количество чисел." << endl;
    int n;
    cin >> n;
    gen(m, b, c, n);
}
void N_7() {
    cout << "ВЫБРАТЬ ВАРИАНТ ГЕНЕРАЦИИ -> 1 / 2." << "\n";
    int num;
    cin >> num;
    switch (num) {
    case 1:
        task7_1();
        break;
    case 2:
        task7_2();
        break;
    default:
        cout << "ERROR" << endl;
        return N_7();
    }
}
/*Умножение матриц*/
void N_8() {
    cout << "Задание #8." << endl;
    int k[3][4]{ {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} }; //Таблица с количеством
    double p[4][2]{ {1.20, 0.5}, {2.80, 0.4}, {5, 1}, {2, 1.5} }; //Таблица с ценой
    double h[3][4][2]; //Новая матрица
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            h[i][j][0] = k[i][j] * p[j][0];
            h[i][j][1] = k[i][j] * p[j][1];
        }
    }
    cout << "Матрица С -->" << endl;
    cout << "Товар" << "      " << "(1 - Ц/К)" << "          " << "(2 - Ц/К)" << "            " << "(3 - Ц/К)" << "           " << "(4 - Ц/К)" << "\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 2; k++) {
                cout << setw(10) << h[i][j][k];
            }
        }
        cout << "\n";
    }
    double d1 = 0; //Максимальная сумма
    double s = 0;
    double minprod = 0; //Плохой продавец
    double maxprod = 0; //Супер продавец
    double d2 = pow(10, 20); //Минимальная сумма
    for (int i = 0; i < 3; i++) {
        s = 0;
        for (int j = 0; j < 4; j++) {
            s += h[i][j][0];
        }
        if (d1 < s) {
            d1 = s;
            maxprod = i + 1;
        }
        if (d2 > s) {
            d2 = s;
            minprod = i + 1;
        }
    }
    cout << "Задание 1." << "\n";
    cout << "Продавец с наибольшей выручкой --> #" << maxprod << " --> " << d1 << "\n";
    cout << "Продавец с наименьшей выручкой --> #" << minprod << " --> " << d2 << "\n";
    double v1 = 0; //Максимальная комиссия
    double Cikl_Commission, sellerMin_Commission, sellerMax_Commission = 0;
    double v2 = pow(10, 20); //Минимальная комиссия
    for (int i = 0; i < 3; i++) {
        Cikl_Commission = 0;
        for (int j = 0; j < 4; j++) {
            Cikl_Commission += h[i][j][1];
        }
        if (v1 < Cikl_Commission) {
            v1 = Cikl_Commission;
            sellerMax_Commission = i + 1;
        }
        if (v2 > Cikl_Commission) {
            v2 = Cikl_Commission;
            sellerMin_Commission = i + 1;
        }
    }
    cout << "Задание 2." << "\n";
    cout << "Продавец с наибольшими комиссионными --> #" << sellerMax_Commission << " --> " << v1 << "\n";
    cout << "Продавец с наименьшими комиссионными --> #" << sellerMin_Commission << " -->  " << v2 << "\n";
    double C = 0; //COMISSIONS
    double M = 0; //MONEYYYYY
    double Cikl = 0;
    for (int i = 0; i < 3; i++) {
        Cikl = 0;
        for (int j = 0; j < 4; j++) {
            M += h[i][j][0];
            C += h[i][j][1];
        }
    }
    cout << "Задание 3." << "\n";
    cout << "Выручка продавцов с помощью денег --> " << M << "\n";
    cout << "Задание 4." << "\n";
    cout << "Выручка продавцов с помощью комисионных --> " << C << "\n";
    cout << "Задание 5." << "\n";
    cout << "Общая сумма денег --> " << C + M << "\n";
}
/*Системы счисления*/
int tn(string w) {
    int y;
    stringstream ss;
    ss << w;
    ss >> y;
    return y;
}
void task23456789_10(string h1, int p) {
    cout << "Введите в какую систему счисления надо перевести." << endl;
    int l;
    cin >> l;
    int k3 = 0; //Десятичная
    int c[100];
    for (int i = h1.length() - 1; i >= 0; i--) {
        c[i] = static_cast<char>(i);
    }
    reverse(h1.begin(), h1.end());
    for (int i = 0; i < h1.length(); i++) {
        string y;
        stringstream ss;
        ss << c[i];
        ss >> y;
        int k2 = atoi(y.c_str()); //index
        string w(1, h1[i]);
        int k = tn(w); //Число
        k3 = k3 + ((pow(p, k2)) * k);
    }
    string m;
    while (k3 > 0) {
        m = m + to_string(k3 % l);
        k3 = k3 / l;
    }
    reverse(m.begin(), m.end());
    cout << "Ответ -->" << " " << m;
}
void task_10(string h1) {
    string m;
    cout << "Введите в какую систему счисления надо перевести." << endl;
    int l;
    cin >> l;
    int k3;
    stringstream ss;
    ss << h1;
    ss >> k3;
    while (k3 > 0) {
        m = m + to_string(k3 % l);
        k3 = k3 / l;
    }
    reverse(m.begin(), m.end());
    cout << "Ответ -->" << " " << m;
}
void task11_12_13_14_15_10(string h1, int p) {
    cout << "Введите в какую систему счисления надо перевести." << endl;
    int l;
    cin >> l;
    int k;
    int k3 = 0; //Десятичная
    int c[100];
    for (int i = h1.length() - 1; i >= 0; i--) {
        c[i] = static_cast<char>(i);
    }
    reverse(h1.begin(), h1.end());
    for (int i = 0; i < h1.length(); i++) {
        string y;
        stringstream ss;
        ss << c[i];
        ss >> y;
        int k2 = atoi(y.c_str()); //index
        string w(1, h1[i]);
        if (w == "A") {
            string w1 = "10";
            k = tn(w1); //Число
        }
        else if (w == "B") {
            string w1 = "11";
            k = tn(w1); //Число
        }
        else if (w == "C") {
            string w1 = "12";
            k = tn(w1); //Число
        }
        else if (w == "D") {
            string w1 = "13";
            k = tn(w1); //Число
        }
        else if (w == "E") {
            string w1 = "14";
            k = tn(w1); //Число
        }
        else if (w == "F") {
            string w1 = "15";
            k = tn(w1); //Число
        }
        else {
            k = tn(w); //Число
        }
        k3 = k3 + ((pow(p, k2)) * k);
    }
    string m;
    while (k3 > 0) {
        m = m + to_string(k3 % l);
        k3 = k3 / l;
    }
    reverse(m.begin(), m.end());
    cout << "Ответ -->" << " " << m;
}
void task9() {
    cout << "Задание 9. Введите число." << endl; //2-16
    string h1; //Число
    cin >> h1;
    cout << "Введите его систему счисления. / 2-16 /" << endl;
    int k;
    cin >> k;
    int v = 0; //proverka 2-10
    int v1 = 0; //ETO NA A B C D E F
    for (int i = 0; i < h1.length(); i++) {
        string o(1, h1[i]);
        if (o == "A" or o == "B" or o == "C" or o == "D" or o == "E" or o == "F") {
            v1 += 1;
        }
    }
    if (v1 == 0) { //Если нету ABCDEF
        for (int i = 0; i < h1.length(); i++) {
            int p2;
            string w(1, h1[i]);
            stringstream ss;
            ss << w;
            ss >> p2;
            if (k <= p2) {
                v += 1;
            }
        }
    }
    int i1 = 10; //A
    int i2 = 11; //B
    int i3 = 12; //C
    int i4 = 13; //D
    int i5 = 14; //E
    int i6 = 15; //F
    if (v1 > 0) { //Что происходит, когда найден ABCDEF
        for (int i = 0; i < h1.length(); i++) {
            string w1(1, h1[i]);
            if (w1 == "A") {
                if (k <= i1) {
                    v += 1;
                }
            }
            else if (w1 == "B") {
                if (k <= i2) {
                    v += 1;
                }
            }
            else if (w1 == "C") {
                if (k <= i3) {
                    v += 1;
                }
            }
            else if (w1 == "D") {
                if (k <= i4) {
                    v += 1;
                }
            }
            else if (w1 == "E") {
                if (k <= i5) {
                    v += 1;
                }
            }
            else if (w1 == "F") {
                if (k <= i6) {
                    v += 1;
                }
            }
        }
    }
    if (v > 0) {
        cout << "Ошибка." << endl;
        return task9();
    }
    switch (k) {
    case 2:
        task23456789_10(h1,k);
        break;
    case 3:
        task23456789_10(h1, k);
        break;
    case 4:
        task23456789_10(h1, k);
        break;
    case 5:
        task23456789_10(h1, k);
        break;
    case 6:
        task23456789_10(h1, k);
        break;
    case 7:
        task23456789_10(h1, k);
        break;
    case 8:
        task23456789_10(h1, k);
        break;
    case 9:
        task23456789_10(h1, k);
        break;
    case 10:
        task_10(h1);
        break;
    case 11:
        task11_12_13_14_15_10(h1, k);
        break;
    case 12:
        task11_12_13_14_15_10(h1, k);
        break;
    case 13:
        task11_12_13_14_15_10(h1, k);
        break;
    case 14:
        task11_12_13_14_15_10(h1, k);
        break;
    case 15:
        task11_12_13_14_15_10(h1, k);
        break;
    case 16:
        task11_12_13_14_15_10(h1, k);
        break;
    default:
        cout << "Ошибка." << endl;
        return task9();
    }
}
/*..........*/
int main() {
    int numb;
    cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ -> 1 - 9\n";
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
        //N_5_1();
        //N_5_2();
        break;
    case 6:
        system("cls");
        N_6();
        break;
    case 7:
        system("cls");
        N_7();
        break;
    case 8:
        system("cls");
        N_8();
        break;
    case 9:
        system("cls");
        task9();
        break;
    default:
        system("cls");
        cout << "ERROR";
        break;
    }
    return 0;
}