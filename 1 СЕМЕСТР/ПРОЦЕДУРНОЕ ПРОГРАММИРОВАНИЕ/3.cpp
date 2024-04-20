#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
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
/*Проверка на буквы, исключение цифр*/
int check_char(string h) {
    string numb = "0123456789";
    int cnt = 0;
    for (int i = 0; i < h.length(); ++i) {
        if (numb.find(h[i]) != -1) {
            cnt++;
            break;
        }
    }
    if (cnt > 0) {
        return 0;
    }
    else {
        return 1;
    }
}
/*Заем*/
void N_1() {
    string S1, n1, p1;
    double S = 0, n = 0, p = 0, m = 0, r = 0;
    cout << "ВВЕДИТЕ S -> ";
    cin >> S1;
    if (check_number(S1) == 1 and into_numb(S1) > 0) {
        S = into_numb(S1);
        cout << "ВВЕДИТЕ N -> ";
        cin >> n1;
        if (check_number(n1) == 1 and into_numb(n1) > 0) {
            n = into_numb(n1);
            cout << "ВВЕДИТЕ p -> ";
            cin >> p1;
            if (check_number(p1) == 1 and into_numb(p1) >= 0) {
                p = into_numb(p1);
                if (p == 0) {
                    m = S / (12*n);
                    cout << "M -> " << m;
                }
                else if (12 * (pow(1 + r, n) - 1) < 0) {
                    cout << "ERROR";
                }
                else {
                    r = p / 100;
                    m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
                    cout << "M -> " << m;
                }
            }
            else {
                cout << "ERROR";
            }
        }
        else {
            cout << "ERROR";
        }
    }
    else {
        cout << "ERROR";
    }
}
/*Ссуда*/
void N_2() {
    double S = 0, n = 0, m = 0, r = 0, M1 = 0, R1 = 0.0001;
    string S1, n1, m1;
    cout << "ВВЕДИТЕ S -> ";
    cin >> S1;
    if (check_number(S1) == 1 and into_numb(S1) > 0) {
        S = into_numb(S1);
        cout << "ВВЕДИТЕ M -> ";
        cin >> m1;
        if (check_number(m1) == 1 and into_numb(m1) > 0) {
            m = into_numb(m1);
            cout << "ВВЕДИТЕ N -> ";
            cin >> n1;
            if (check_number(n1) == 1 and into_numb(n1) > 0) {
                n = into_numb(n1);
                while (M1 < m) {
                    r = R1;
                    M1 = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
                    R1+=0.0001;
                }
                cout << "P = " << r * 100 << "%" << "\n";
            }
            else {
                cout << "ERROR";
            }
        }
        else {
            cout << "ERROR";
        }
    }
    else {
        cout << "ERROR";
    }
}
/*Копирование файла*/
void N_3() {
    string s_file, s;
    ofstream file("file.txt");
    cout << "ВВЕДИТЕ ЧТО-УГОДНО\n";
    cin >> s_file;
    file << s_file << "\n";
    file.close();
    ifstream file1("file.txt");
    if (file1.is_open()) {
        while (getline(file1, s)) {
            cout << s;
        }
    }
    else {
        cout << "ERROR";
    }
    file1.close();
}
/*Фильтр*/
void N_4() {
    string s_file_, s_, s_new, numb = "0123456789";
    ofstream file_("file1.txt");
    cout << "ВВЕДИТЕ ЧТО-УГОДНО\n";
    getline(cin, s_file_);
    file_ << s_file_ << "\n";
    file_.close();
    ifstream file2("file1.txt");
    if (file2.is_open()) {
        while (getline(file2, s_)) {
            s_new+=s_;
        }
        for (int i = 0; i < s_new.length(); ++i) {
            if (numb.find(s_new[i]) != -1) {
                cout << s_new[i];
            }
        }
    }
    else {
        cout << "ERROR";
    }
    file2.close();
}
/*Сортировка букв*/
void N_5() {
    string a, b;
    cout << "ВВЕДИТЕ ЧТО-УГОДНО\n";
    getline(cin, a);
    if (a.length() > 30 or check_char(a) != 1) {
        cout << "ERROR";
    }
    else {
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != ' ') {
                b+=a[i];
            }
        }
        for (int i = 0; i < b.length() - 1; ++i) {
            for (int j = 0; j < b.length() - i - 1; ++j) {
                if (b[j] > b[j + 1]) {
                    char temp = b[j];
                    b[j] = b[j + 1];
                    b[j + 1] = temp;
                }
            }
        }
        cout << "ОТВЕТ -> " << b;
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