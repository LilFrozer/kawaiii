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
#include <stdio.h>
#include <random>
#include <cctype>
using namespace std;
int check(string text) {
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
bool dv(string s) {
    int k = s.length();
    string dv1 = "01";
    if (k == 1) {
        if (s == "0") {
            return 1;
        }
        if (s == "1") {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (s[0] == '-') {
            string s1;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '-') {
                    string s3(1, s[i]);
                    s1 += s3;
                }
            }
            if (s1.length() == (s.length() - 1)) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            int v2 = 0;
            for (int i = 0; i < k; i++) {
                if (dv1.find(s[i]) != -1) {
                    v2++;
                }
            }
            if (v2 == k) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}
string perevod(string v) {
    if (v[0] == '-') {
        int k1 = 0; // 10
        string s1;
        for (int i = 0; i < v.length(); i++) {
            if (v[i] != '-') {
                string w(1, v[i]);
                s1 += w;
            }
        }
        int* n = new int[s1.length()]; //index
        for (int i = 0; i < s1.length(); i++) {
            n[i] = static_cast<char>(i);
        }
        reverse(s1.begin(), s1.end());
        for (int i = 0; i < s1.length(); i++) {
            int n3;
            stringstream ss;
            ss << s1[i];
            ss >> n3;
            k1 += (pow(2, n[i]) * n3);
        }
        if (k1 == 0) {
            return "0";
        }
        else {
            string ch;
            while (k1 > 0) {
                ch = ch + to_string(k1 % 4);
                k1 = k1 / 4;
            }
            reverse(ch.begin(), ch.end());
            return ('-' + ch);
        }
    }
    else {
        int k = 0; // 10
        int* n = new int[v.length()]; //index
        for (int i = 0; i < v.length(); i++) {
            n[i] = static_cast<char>(i);
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.length(); i++) {
            int n2;
            stringstream ss;
            ss << v[i];
            ss >> n2;
            k += (pow(2, n[i]) * n2);
        }
        if (k == 0) {
            return "0";
        }
        else {
            string ch;
            while (k > 0) {
                ch = ch + to_string(k % 4);
                k = k / 4;
            }
            reverse(ch.begin(), ch.end());
            return ch;
        }
    }
}
int comp1(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
void task2_22() {
    cout << "Задание 22." << "\n";
    ofstream file("task2_22.txt");
    string h;
    string alh = { 'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y' };
    cout << "Введите строку." << "\n";
    getline(cin, h);
    h.erase(remove(h.begin(), h.end(), ' '), h.end());
    file << h;
    file.close();
    ifstream file1("task2_22.txt");
    string line, line1;
    int k = 0; //ГЛАСНЫЕ
    if (file1.is_open()) {
        while (getline(file1, line)) {
            line1 += line;
        }
        for (int i = 0; i < line1.length(); i++) {
            if (alh.find(line1[i]) != -1) {
                k++;
            }
        }
        string j; //Строка с гласными
        for (int i = 0; i < line1.length(); i++) {
            if (alh.find(line1[i]) != -1) {
                j += line1[i];
            }
        }
        int l1 = 0;
        int l2 = 0;
        int l3 = 0;
        int l4 = 0;
        int l5 = 0;
        int l6 = 0;
        string a1 = { 'A', 'a' };
        string e1 = { 'E', 'e' };
        string i1 = { 'I', 'i' };
        string o1 = { 'O', 'o' };
        string u1 = { 'U', 'u' };
        string y1 = { 'Y', 'y' };
        for (int i = 0; i < j.length(); i++) {
            if (a1.find(j[i]) != -1) {
                l1++;
            }
            if (e1.find(j[i]) != -1) {
                l2++;
            }
            if (i1.find(j[i]) != -1) {
                l3++;
            }
            if (o1.find(j[i]) != -1) {
                l4++;
            }
            if (u1.find(j[i]) != -1) {
                l5++;
            }
            if (y1.find(j[i]) != -1) {
                l6++;
            }
        }
        cout << j << "\n";
        int p[6];
        p[0] = static_cast<char>(l1); //A
        p[1] = static_cast<char>(l2); //E
        p[2] = static_cast<char>(l3); //I
        p[3] = static_cast<char>(l4); //O
        p[4] = static_cast<char>(l5); //U
        p[5] = static_cast<char>(l6); //Y
        for (int i = 0; i < 6; i++) {
            if (p[i] == 0) {
                if (i == 0) {
                    cout << "В СТРОКЕ НЕТУ ГЛАСНОЙ БУКВЫ Aa" << "\n";
                }
                if (i == 1) {
                    cout << "В СТРОКЕ НЕТУ ГЛАСНОЙ БУКВЫ Ee" << "\n";
                }
                if (i == 2) {
                    cout << "В СТРОКЕ НЕТУ ГЛАСНОЙ БУКВЫ Ii" << "\n";
                }
                if (i == 3) {
                    cout << "В СТРОКЕ НЕТУ ГЛАСНОЙ БУКВЫ Oo" << "\n";
                }
                if (i == 4) {
                    cout << "В СТРОКЕ НЕТУ ГЛАСНОЙ БУКВЫ Yy" << "\n";
                }
            }
        }
        qsort(p, 6, sizeof(int), comp1);
        int k = 0; //Счетчик
        for (int i = 0; i < 6; i++) {
            if (p[i] != 0) {
                k++;
            }
        }
        string c3;
        for (int i = 0; i < 6; i++) {
            if (p[i] != 0) {
                c3 += to_string(p[i]);
                c3 += " ";
            }
        }
        int* c4 = new int[k];
        istringstream ss(c3);
        for (int i = 0; i < k; ++i) {
            ss >> c4[i];
        }
        cout << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << " " << p[4] << " " << p[5] << "\n";
        cout << k << "\n";
        cout << c3 << "\n";
        if (c4[0] == (l1)) {
            cout << "Минимальная буква --> Aa" << " " << l1 << endl;
        }
        if (c4[0] == (l2)) {
            cout << "Минимальная буква --> Ee" << " " << l2 << endl;
        }
        if (c4[0] == (l3)) {
            cout << "Минимальная буква --> Ii" << " " << l3 << endl;
        }
        if (c4[0] == (l4)) {
            cout << "Минимальная буква --> Oo" << " " << l4 << endl;
        }
        if (c4[0] == (l5)) {
            cout << "Минимальная буква --> Uu" << " " << l5 << endl;
        }
        if (c4[0] == (l6)) {
            cout << "Минимальная буква --> Yy" << " " << l6 << endl;
        }
    }
    else {
        cout << "Ошибка." << "\n";
        return task2_22();
    }
    file1.close();
}
void dz_4() {
    cout << "Задание 22." << "\n";
    double n = 0;
    string n1;
    cout << "Введите количество чисел." << "\n";
    cin >> n1;
    if (!(check(n1))) {
        cout << "Ошибка." << "\n";
        return dz_4();
    }
    else {
        stringstream ss;
        ss << n1;
        ss >> n;
        if (n > 0 and (n == int(n))) {
            string* h1 = new string[int(n)]; //МАССИВ[4]
            string* h = new string[int(n)]; //МАССИВ[2]
            int i = 0;
            while (i != n) {
                int s1 = i + 1;
                cout << "Введите число #" << s1 << "." << "\n";
                string s; //Двоичка
                cin >> s;
                if (dv(s)) {
                    h[i] = s;
                }
                else {
                    cout << "Ошибка." << "\n";
                    return dz_4();
                }
                i++;
            }
            for (int i = 0; i < n; i++) {
                h1[i] = perevod(h[i]);
            }
            cout << "" << "\n";
            cout << "Массив с двоичными числами." << "\n";
            for (int i = 0; i < n; i++) {
                cout << h[i] << "\n";
            }
            cout << "" << "\n";
            cout << "Массив с числами в четверичной системе счисления." << "\n";
            for (int i = 0; i < n; i++) {
                cout << h1[i] << "\n";
            }
        }
        else {
            cout << "Ошибка." << "\n";
            return dz_4();
        }
    }
}
void dz_6() {
    cout << "Задание 53." << "\n";
    double h;
    int n1; //Строки
    int n2; //Столбцы
    cout << "Введите количество строк в двумерном массиве." << "\n";
    cin >> n1;
    cout << "Введите количество столбцов в двумерном массиве." << "\n";
    cin >> n2;
    double** c = new double* [n1];
    double* m = new double[n1]; //Средние значения
    for (int i = 0; i < n1; ++i) {
        c[i] = new double[n2];
        for (int j = 0; j < n2; ++j)
        {
            int s1 = i + 1;
            int s2 = j + 1;
            cout << "Введите число --> Строка #" << s1 << ". Столбец #" << s2 << "." << "\n";
            cin >> c[i][j];
        }
    }
    cout << "" << "\n";
    cout << "Исходный массив #1." << "\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
    for (int i = 0; i < n1; ++i) {
        double sum = 0;
        for (int j = 0; j < n2; ++j) {
            sum += c[i][j];
        }
        sum = sum / double(n2);
        m[i] = sum;
    }
    cout << "" << "\n";
    cout << "Средние значения по строкам #1." << "\n";
    for (int i = 0; i < n1; i++) {
        cout << m[i] << "\n";
    }
    for (int i = 1; i < n2; i++) {
        for (int j = n2; j >= i; j--) {
            if (m[j - 1] < m[j]) {
                for (int k = 0; k < n1; k++) {
                    swap(c[k][j - 1], c[k][j]);
                }
                swap(c[j - 1], c[j]);
            }
        }
    }
    cout << "" << "\n";
    cout << "Преобразованный массив #2." << "\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    double* m1 = new double[n1];
    double sum1 = 0;
    for (int i = 0; i < n1; ++i) {
        double sum1 = 0;
        for (int j = 0; j < n2; ++j) {
            sum1 += c[i][j];
        }
        sum1 = sum1 / double(n2);
        m1[i] = sum1;
    }
    cout << "" << "\n";
    cout << "Средние значения по строкам #2" << "\n";
    for (int i = 0; i < n1; i++) {
        cout << m1[i] << "\n";
    }
}
int dec(string s) {
    char let[] = { '0','1','2','3','4','5','6','7','8','9' };
    int n = 0, j;
    for (int i = 0; i < s.length(); i++) {
        for (j = 0; j < 10; j++)
            if (s[i] == let[j])
                break;
        n *= 10;
        n += j;
    }
    return n;
}
int preobr(string numb) {
    string tmp;
    int rez = 0;
    int w = 0;
    char ch;
    while (isdigit(numb[w]))
    {
        tmp.append(1, numb[w]);
        ++w;
    }
    rez = dec(tmp);
    while (w < numb.length())
    {
        ch = numb[w];
        tmp.erase(0, tmp.length());
        w++;
        while (w < numb.length() && isdigit(numb[w]))
        {
            tmp.append(1, numb[w]);
            ++w;
        }
        switch (ch)
        {
        case '+': 
            rez += dec(tmp); 
            break;
        case '-': 
            rez -= dec(tmp);
        }
    }
    return rez;
}
bool hn(string h) {
    int v = 0;
    string y = "0123456789";
    for (int i = 0; i < h.length(); i++) {
        if (y.find(h[i]) != -1) {
            v++;
        }
    }
    if (v == h.length() and h[0] != '0') {
        return 1;
    }
    else {
        return 0;
    }
}
void spinneri_N1() {
    cout << "СПИННЕРЫ 1" << "\n";
    long long a, b, c, n = 0, st = 0, end;
    cout << "Введите стоимость основания спинера." << "\n";
    cin >> a;
    cout << "Введите стоимость одной лопасти." << "\n";
    cin >> b;
    cout << "Введите максимальную стоимость всего спинера." << "\n";
    cin >> c;
    end = c + 2;
    n = (end + st) / 2;
    if (a + b > c) {
        cout << "Бублик.";
    }
    else {
        while (a + b * n > c or a + b * (n + 1) <= c) {
            if (a + b * n >= c) {
                end = n + 1;
                n = (end + st) / 2;
            }
            else {
                st = n - 1;
                n = (end + st) / 2;
            }
        }
        cout << "Ответ --> " << n;
    }
}
void spinneri_N_3() {
    cout << "ЗАДАНИЕ #3 ИЗ СПИННЕРОВ." << "\n";
    string n1, m1;
    cout << "Введите число N." << "\n";
    getline(cin, n1);
    if (hn(n1) and stoi(n1) < 75000) {
        cout << "Введите число M." << "\n";
        getline(cin, m1);
        int n;
        stringstream ss;
        ss << n1;
        ss >> n;
        if (hn(m1) and stoi(m1) < 75000) {
            int m;
            int cnt = 0; //Счетчик
            stringstream ss;
            ss << m1;
            ss >> m;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n-i; j++) {
                    for (int k = 0; k < m; k++) {
                        cnt += m - k;
                    }
                }
            }
            cout << "Ответ --> " << cnt << "\n";
        }
        else {
            cout << "Ошибка." << "\n";
            return spinneri_N_3();
        }
    }
    else {
        cout << "Ошибка." << "\n";
        return spinneri_N_3();
    }
}
void dz_60_80() {
    cout << "БАЗА ЗАДАНИЙ #80." << "\n";
    string hello = "+-";
    string res = "1989";
    int v = 0; //Счетчик
    string h1 = "+-------";
    string h2 = "++------";
    string h3 = "+++-----";
    string h4 = "++++----";
    string h5 = "+++++---";
    string h6 = "++++++--";
    string h7 = "+++++++-";
    string omg;
    string* c = new string[256]; //2^8
    c[254] = "++++++++";
    c[255] = "--------";
    do omg += h1 + " ";
    while (next_permutation(h1.begin(), h1.end()));
    do omg += h2 + " ";
    while (next_permutation(h2.begin(), h2.end()));
    do omg += h3 + " ";
    while (next_permutation(h3.begin(), h3.end()));
    do omg += h4 + " ";
    while (next_permutation(h4.begin(), h4.end()));
    do omg += h5 + " ";
    while (next_permutation(h5.begin(), h5.end()));
    do omg += h6 + " ";
    while (next_permutation(h6.begin(), h6.end()));
    do omg += h7 + " ";
    while (next_permutation(h7.begin(), h7.end()));
    istringstream ss(omg);
    for (int i = 0; i < 256; ++i) {
        ss >> c[i];
    }
    for (int i = 0; i < 256; i++) {
        string numb = "12894*4193*9510*8653*4381*2546*1158*8645*2587";
        string g = c[i];
        numb[5] = g[0];
        numb[10] = g[1];
        numb[15] = g[2];
        numb[20] = g[3];
        numb[25] = g[4];
        numb[30] = g[5];
        numb[35] = g[6];
        numb[40] = g[7];
        int x = preobr(numb);
        if (to_string(x) == res) {
            cout << "Ответ --> " << c[i] << "\n";
        }
    }
    delete[] c;
}
string ly(string h, int n) {
    int k = 1;
    for (int i = 0; i < h.length(); i++) {
        string w(1, h[i]);
        int t = stoi(w);
        k = k * t;
    }
    if (k == n) {
        return h;
    }
}
void xxxmanera(int h1, int s, int n, const string& f) {
    if (h1 == n) {
        cout << f << "\n";
        return;
    }
    for (int i = s; i <= n / h1; ++i) {
        if (n % i == 0) { 
            if (f.empty()) {
                xxxmanera(h1 * i, i, n, to_string(i));
            }
            else {
                xxxmanera(h1 * i, i, n, f + "*" + to_string(i));
            }
        }
    }
}
void scallymilano(int h1, int s, int n, int k, const string& f) {
    if (h1 == n) {
        cout << f << "\n";
        return;
    }
    for (int i = s; i <= n / h1; ++i) {
        if (n % i == 0 and i < k) {
            if (f.empty()) {
                scallymilano(h1 * i, i, n, k, to_string(i));
            }
            else {
                scallymilano(h1 * i, i, n, k, f + "*" + to_string(i));
            }
        }
    }
}
void dz_60_90() {
    cout << "БАЗА ЗАДАНИЙ #90." << "\n"; //У КВАДРАТОВ ВСЕГДА НЕЧЕТ КОЛИЧЕСТВО ДЕЛИТЕЛЕЙ --> У ОСТАЛЬНЫХ ЧЕТ
    string k1; //YES
    string N1; //NO
    cout << "Введите число N." << "\n";
    getline(cin, N1);
    if (hn(N1) and stoi(N1) > 0) {    // 1 < K < N
        cout << "Введите K." << "\n";
        getline(cin, k1);
        stringstream ss;
        int n;
        ss << N1;
        ss >> n;
        if (hn(k1) and stoi(k1) < n and stoi(k1) > 0) {
            stringstream ss;
            int k;
            ss << k1;
            ss >> k;
            cout << "Ответ/" << "\n";
            scallymilano(1, 2, n, k, "");
        }
        else if (k1 == "0") {
            cout << "Ответ/" << "\n";
            xxxmanera(1, 2, n, "");
        }
        else {
            cout << "Ошибка." << "\n";
            return dz_60_90();
        }
    }
    else {
        cout << "Ошибка." << "\n";
        return dz_60_90();
    }
}
int pobeda1(string j, int n) {
    int k = 0;
    string* c = new string[n];
    for (int i = 1; i <= n; i++) {
        c[i - 1] = to_string(i);
    }
    for (int i = 0; i < n; i++) {
        string w(1, j[i]);
        if (c[i] == w) {
            k++;
            break;
        }
    }
    return k;
}
int pobeda2(int* c, int j) {
    int k = 0;
    int* c1 = new int[j];
    for (int i = 1; i <= j; i++) {
        c1[i - 1] = static_cast<char>(i);
    }
    for (int i = 0; i < j; i++) {
        if (c[i] == c1[i]) {
            k++;
            break;
        }
    }
    delete[] c1;
    return k;
}
void yataklublushari() {
    cout << "ЗАДАЧА ПРО ШАРИКИ, Я ТАКИЕ ШАТАЛ." << "\n";
    string n1; //Количество шариков
    cout << "Введи количество шаров." << "\n";
    cin >> n1;
    if (hn(n1)) {
        int l = 0; //Счетчик
        int n;
        stringstream ss;
        ss << n1;
        ss >> n;
        if (n < 10) {
            string k; //Строка с шарами
            for (int i = 1; i <= n; i++) {
                k += to_string(i);
            }
            do l += pobeda1(k, n);
            while (next_permutation(k.begin(), k.end()));
            cout << "Ответ --> " << l << "\n";
        }
        else {
        int* c = new int[n];
        for (int i = 1; i <= n; i++) {
            c[i - 1] = static_cast<char>(i); //2293839 //25232230
        }
        do {
            l += pobeda2(c, n);
        } while (next_permutation(c, c + n));
        cout << "Ответ --> " << l << "\n";
        }
    }
    else {
        cout << "Ошибка." << "\n";
        return yataklublushari();
    }
}
string uniq(string str) {
    string h;
    for (int i = 0; i < str.length(); i++) {
        bool appears = false;
        for (int j = 0; j < i; j++) {
            if (str[j] == str[i]) {
                appears = true;
                break;
            }
        }
        if (!appears) {
            h += str[i];
        }
    }
    return h;
}
void sudoka() {
    int a1[9] = { 1,2,3,4,5,6,7,8,9 };
    int board[9][9] = { 0 };
    srand(time(NULL));
    random_shuffle(begin(a1), end(a1));
    int a2[9] = { a1[1], a1[2], a1[0], a1[4], a1[5], a1[3], a1[8], a1[6], a1[7] };
    int a3[9] = { a1[2], a1[0], a1[1], a1[5], a1[3], a1[4], a1[7], a1[8], a1[6] };
    for (int i = 0; i < 9; i++) { //1
        board[0][i] = a1[i];
    }
    for (int i = 3; i < 9; i++) { //k2
        swap(a1[i - 3], a1[i]);
    }
    for (int i = 0; i < 9; i++) { //2
        board[1][i] = a1[i];
    }
    for (int i = 3; i < 9; i++) { //k3
        swap(a1[i - 3], a1[i]);
    }
    for (int i = 0; i < 9; i++) { //3
        board[2][i] = a1[i];
    }
    for (int i = 0; i < 9; i++) { //4
        board[3][i] = a2[i];
    }
    for (int i = 3; i < 9; i++) { //k5
        swap(a2[i - 3], a2[i]);
    }
    for (int i = 0; i < 9; i++) { //5
        board[4][i] = a2[i];
    }
    for (int i = 3; i < 9; i++) { //k6
        swap(a2[i - 3], a2[i]);
    }
    for (int i = 0; i < 9; i++) { //6
        board[5][i] = a2[i];
    }
    for (int i = 0; i < 9; i++) { //4
        board[6][i] = a3[i];
    }
    for (int i = 3; i < 9; i++) { //k5
        swap(a3[i - 3], a3[i]);
    }
    for (int i = 0; i < 9; i++) { //5
        board[7][i] = a3[i];
    }
    for (int i = 3; i < 9; i++) { //k6
        swap(a3[i - 3], a3[i]);
    }
    for (int i = 0; i < 9; i++) { //6
        board[8][i] = a3[i];
    }
    for (int i = 3; i < 9; i++) {
        swap(board[i][3], board[i - 3][3]); 
    }
    for (int i = 3; i < 9; i++) {
        swap(board[i][4], board[i - 3][4]);
    }
    for (int i = 3; i < 9; i++) {
        swap(board[i][5], board[i - 3][5]);
    }
    for (int i = 6; i < 9; i++) {
        swap(board[i][6], board[i - 6][6]);
    }
    for (int i = 6; i < 9; i++) {
        swap(board[i][7], board[i - 6][7]);
    }
    for (int i = 6; i < 9; i++) {
        swap(board[i][8], board[i - 6][8]);
    }
    swap(board[3][6], board[6][6]);
    swap(board[3][7], board[6][7]);
    swap(board[3][8], board[6][8]);
    swap(board[4][6], board[7][6]);
    swap(board[4][7], board[7][7]);
    swap(board[4][8], board[7][8]);
    swap(board[5][6], board[8][6]);
    swap(board[5][7], board[8][7]);
    swap(board[5][8], board[8][8]);
    cout << "ФИНИШ." << "\n";
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 and i != 0) {
            cout << "------------------------" << "\n";
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 and j != 0) {
                cout << " | ";
            }
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    
}
/*..........*/
int main() {
    //task2_22(); //НАИМЕНЬШАЯ ГЛАСНАЯ
    //dz_4(); //[2] --> [4]
    //dz_6(); //НУ ПРОСТО АД
    //yataklublushari(); //ШАРЫЫЫЫЫЫЫ
    //spinneri_N1(); //спинеры же это так круто, особенно вычислять лопасти
    //spinneri_N_3(); //ПОБЕДА
    //dz_60_80(); //та строка та самая плюса и минуса
    //dz_60_90(); //ПРОГРАММА НЕ ПРОГРАММА 
    //sudoka(); // АЛОООО ЭТО СДУК
}
/*ВСЕМ СПАСИБО ЗА ПРОСМОТР!*/