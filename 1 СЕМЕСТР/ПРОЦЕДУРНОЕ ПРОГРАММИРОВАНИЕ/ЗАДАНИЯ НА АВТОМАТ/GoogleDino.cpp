/*ВНИМАНИЕ ВСЕ РАБОТЫ ПРОДЕЛАНЫ БЕЗ ИСПОЛЬЗОВАНИЯ ООП*/
/*ЗАПУСКАТЬ СТРОКО В VS COMMUNITY*/
#include <iostream>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <conio.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <mmsystem.h>
#include <stdio.h>
using namespace std;
bool gameis;
HANDLE hConsole;
const int width = 50; //ДИНОЗАВРИК СОСТОИТ ИЗ 5 КЛЕТОК
const int height = 10;
int x, y, z, k, t, o, a, b, c, d, oblx, obly, oblx1, obly1, oblx2, obly2, obl2x, obl2y, obl2x1, obl2y1, obl2x2, obl2y2, score, speed, S;
int kx, ky, k1x, k1y, k2x, k2y, k3x, k3y, down1;
int obl3x, obl3y, obl3x1, obl3y1, obl3x2, obl3y2;
int b1x, b1y, b2x, b2y, c1, c2;
enum eDirection { STOP = 0, JUMP, FALL, LEFT };
enum ColorConsole {
    White = 7,
    Green = 2,
    Blue = 3,
    text1 = 15,
    text2 = 14,
    BIRD = 12,
    text = 11,
    Yellow = 6,
    damn = 4
};
eDirection h;
eDirection w1;
eDirection w3;
void happynewyear() {
    system("cls");
    int Y = 6;
    for (int i = 3; i <= Y; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == i) {
                for (int z = 0; z <= Y - j - 1; ++z) {
                    cout << " ";
                }
                SetConsoleTextAttribute(hConsole, White);
                cout << "$";
            }
            else {
                for (int z = 0; z <= Y - j; ++z) {
                    cout << " ";
                }
            }
            for (int z = 0; z <= 2 * j; ++z) {
                SetConsoleTextAttribute(hConsole, damn);
                cout << "*";
            }
            if (j == i) {
                SetConsoleTextAttribute(hConsole, text1);
                cout << "$";
            }
            cout << "\n";
        }
    }
    cout << "\n";
    SetConsoleTextAttribute(hConsole, White);
}
void clear() {
    COORD H = { 0, 0 };
    SetConsoleCursorPosition(hConsole, H);
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            COORD position = { j, i }; //позиция x и y
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition(hConsole, position);
            cout << "\b";
        }
    }
    SetConsoleCursorPosition(hConsole, H);
}
void setup() {
    c1 = rand() % 30 + 8;
    c2 = rand() % 30 + 7;
    b1y = height - 3;
    b1x = 0;
    b2x = 0;
    b2y = b1y;
    down1 = 6;
    S = 0;
    speed = 1; //СЧЕТЧИК ДЛЯ УСКОРЕНИЯ
    kx = width - 2;
    ky = height - 1;
    k1x = kx - 1;
    k2x = kx - 2;
    k1y = ky;
    k2y = ky;
    gameis = 0;
    h = STOP;
    w1 = STOP;
    obly = 3;
    obly1 = obly;
    obly2 = obly;
    oblx = rand() % 5 + 5;
    oblx1 = oblx - 1;
    oblx2 = oblx + 1;
    obl2x = oblx + 35;
    obl2y = 2;
    obl2x1 = obl2x - 1;
    obl2x2 = obl2x + 1;
    obl2y1 = obl2y;
    obl2y2 = obl2y;
    obl3x = obl2x - (rand() % 25 + 1);
    obl3y = 1;
    obl3y1 = 1;
    obl3y2 = 1;
    obl3x1 = obl3x - 1;
    obl3x2 = obl3x + 1;
    y = height - 1; //y1
    k = height - 2; //y2
    o = height - 3; //y3
    b = height - 3; //y4
    d = height - 2; //y5
    c = 6; //x5
    a = 8; //x4
    x = 7; //x1
    z = 7; //x2
    t = 7; //x3
    score = 0;
}
void draw() {
    //system("cls"); //ОЧИСТКА ТЕРМИНАЛА
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < width; i++) {
        SetConsoleTextAttribute(hConsole, White);
        cout << "#";
    }
    cout << "\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 or j == (width - 1)) {
                SetConsoleTextAttribute(hConsole, White);
                cout << "#";
            }
            else if ((i == ky and j == kx) or (i == k1y and j == k1x) or (i == k2y and j == k2x)) {
                SetConsoleTextAttribute(hConsole, Yellow);
                cout << "X";
            }
            else if ((i == b1y and j == b1x) or (i == b2y and j == b2x)) {
                SetConsoleTextAttribute(hConsole, BIRD);
                cout << "+";
            }
            else if ((i == obly and j == oblx) or (i == obly1 and j == oblx1) or (i == obly2 and j == oblx2) \
                or (i == obl2y and j == obl2x) or (i == obl2y1 and j == obl2x1) or (i == obl2y2 and j == obl2x2) \
                or (i == obl3y and j == obl3x) or (i == obl3y1 and j == obl3x1) or (i == obl3y2 and j == obl3x2)) {
                SetConsoleTextAttribute(hConsole, Blue);
                cout << "9";
            }
            else if ((i == y and j == x) or (i == k and j == z) or (i == o and j == t) or \
                (i == b and j == a) or (i == d and j == c)) {
                SetConsoleTextAttribute(hConsole, Green);
                cout << "$";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    for (int i = 0; i < width; i++) {
        SetConsoleTextAttribute(hConsole, White);
        cout << "#";
    }
    cout << "\n";
    SetConsoleTextAttribute(hConsole, text2);
    cout << "ВАШ СЧЕТ --> " << score << "\n";
    cout << "РАССТОЯНИЕ--> " << S << "\n";
}
void input() {
    if ((y == (height - 1) and x == 7) and (a == 8 and b == height - 3)) {
        if (_kbhit()) {
            switch (_getch()) {
            case 'w':
                h = JUMP;
                break;
            case 'e':
                gameis = 1;
                happynewyear();
                break;
            case 's':
                t++;
                o++;
                a++;
                b++;
                if ((x == kx and y == ky) or (x == k1x and y == k1y) or (x == k2x and y == k2y) or (o == b1y and t == b1x) or (o == b2y and t == b2x) \
                    or (b == b1y and a == b1x) or (b == b2y and a == b2x) or (z == kx and k == ky) or (z == k1x and k == k1y) or (z == k2x and k == k2y) or \
                    (c == kx and d == ky) or (c == k1x and d == k1y) or (c == k2x and d == k2y) or (t == kx and o == ky) or (t == k1x and o == k1y) or (t == k2x and o == k2y) \
                    or (a == kx and b == ky) or (a == k1x and b == k1y) or (a == k2x and b == k2y) or (y == b1y and x == b1x) or (y == b2y and x == b2x) or \
                    (k == b1y and z == b1x) or (k == b2y and z == b2x) or (d == b1y and c == b1x) or (d == b2y and c == b2x)) {
                    gameis = 1;
                    system("cls");
                    string t = "ИГРА ЗАКОНЧЕНА. КОЛИЧЕСТВО ОЧКОВ --> ";
                    SetConsoleTextAttribute(hConsole, text1);
                    for (int i = 0; i < size(t); i++) {
                        cout << t[i];
                        Sleep(40);
                    }
                    cout << score;
                }
                w3 = LEFT;
                break;
            case 'c':
                gameis = 1;
                system("cls");
                string t = "ИГРА ЗАКОНЧЕНА. КОЛИЧЕСТВО ОЧКОВ --> ";
                for (int i = 0; i < size(t); i++) {
                    SetConsoleTextAttribute(hConsole, text);
                    cout << t[i];
                    Sleep(80);
                }
                cout << score;
                break;
            }
        }
    }
}
void logic() {
    switch (h)
    {
    case JUMP:
        int l = height / 2;
        y--;
        k--;
        o--;
        b--;
        d--;
        if ((x == kx and y == ky) or (x == k1x and y == k1y) or (x == k2x and y == k2y) or (o == b1y and t == b1x) or (o == b2y and t == b2x) \
            or (b == b1y and a == b1x) or (b == b2y and a == b2x) or (z == kx and k == ky) or (z == k1x and k == k1y) or (z == k2x and k == k2y) or \
            (c == kx and d == ky) or (c == k1x and d == k1y) or (c == k2x and d == k2y) or (t == kx and o == ky) or (t == k1x and o == k1y) or (t == k2x and o == k2y) \
            or (a == kx and b == ky) or (a == k1x and b == k1y) or (a == k2x and b == k2y) or (y == b1y and x == b1x) or (y == b2y and x == b2x) or \
            (k == b1y and z == b1x) or (k == b2y and z == b2x) or (d == b1y and c == b1x) or (d == b2y and c == b2x)) {
            gameis = 1;
            system("cls");
            string t = "ИГРА ЗАКОНЧЕНА. КОЛИЧЕСТВО ОЧКОВ --> ";
            SetConsoleTextAttribute(hConsole, text1);
            for (int i = 0; i < size(t); i++) {
                cout << t[i];
                Sleep(40);
            }
            cout << score;
        }
        if (y == l) {
            h = STOP;
            w1 = FALL;
        }
        break;
    }
    if (obl2x == 1) {
        obl2x = width - 1;
    }
    if (obl2x1 == 1) {
        obl2x1 = width - 1;
    }
    if (obl2x2 == 1) {
        obl2x2 = width - 1;
    }
    if (oblx == 1) {
        oblx = width - 1;
    }
    if (oblx1 == 1) {
        oblx1 = width - 1;
    }
    if (oblx2 == 1) {
        oblx2 = width - 1;
    }
    if (obl3x == 1) {
        obl3x = width - 1;
    }
    if (obl3x1 == 1) {
        obl3x1 = width - 1;
    }
    if (obl3x2 == 1) {
        obl3x2 = width - 1;
    }
    int c[3] = { 1, 2, 3 };
    random_shuffle(begin(c), end(c));
    if (score < 15) {
        if (c[0] == 1 and kx == 1) {
            kx = width - 2;
            ky = height - 1;
            k1x = kx - 1;
            k2x = kx - 2;
            k1y = ky;
            k2y = ky;
        }
        if (c[0] == 2 and kx == 1) {
            kx = width - 2;
            ky = height - 1;
            k1x = kx - 1;
            k1y = ky;
            k2x = 0;
            k2y = 0;
        }
        if (c[0] == 3 and kx == 1) {
            kx = width - 2;
            ky = height - 1;
            k1y = height - 2;
            k1x = width - 2;
            k2x = 0;
            k2y = 0;
        }
        kx -= speed;
        k1x -= speed;
        k2x -= speed;
        if (kx == c1) {
            b1x = width - 1;
            b2x = width - 2;
        }
        b1x -= speed;
        b2x -= speed;
        oblx--;
        oblx1--;
        oblx2--;
        obl2x--;
        obl2x1--;
        obl2x2--;
        obl3x--;
        obl3x1--;
        obl3x2--;
    }
    else if (15 <= score) {
        if (c[0] == 1 and kx == 2) {
            kx = width - 2;
            ky = height - 1;
            k1x = kx - 1;
            k2x = kx - 2;
            k1y = ky;
            k2y = ky;
        }
        if (c[0] == 2 and kx == 2) {
            kx = width - 2;
            ky = height - 1;
            k1x = kx - 1;
            k1y = ky;
            k2x = 0;
            k2y = 0;
        }
        if (c[0] == 3 and kx == 2) {
            kx = width - 2;
            ky = height - 1;
            k1y = height - 2;
            k1x = width - 2;
            k2x = 0;
            k2y = 0;
        }
        kx -= 2;
        k1x -= 2;
        k2x -= 2;
        if (kx == c2) {
            b1x = width - 1;
            b2x = width - 2;
        }
        b1x -= 2;
        b2x -= 2;
        oblx--;
        oblx1--;
        oblx2--;
        obl2x--;
        obl2x1--;
        obl2x2--;
        obl3x--;
        obl3x1--;
        obl3x2--;
    }
}
void logic2() {
    switch (w1) {
    case FALL:
        int l1 = (height / 2) + 4;
        y++;
        k++;
        o++;
        b++;
        d++;
        if (y == l1) {
            w1 = STOP;
        }
        break;
    }
    if (c == kx) {
        score++;
    }
    switch (w3) {
    case LEFT:
        down1--;
        if (down1 == 0) {
            t--;
            o--;
            a--;
            b--;
            w3 = STOP;
        }
    }
    if (down1 == 0) {
        down1 = 6;
    }
    if ((x == kx and y == ky) or (x == k1x and y == k1y) or (x == k2x and y == k2y) or (o == b1y and t == b1x) or (o == b2y and t == b2x) \
        or (b == b1y and a == b1x) or (b == b2y and a == b2x) or (z == kx and k == ky) or (z == k1x and k == k1y) or (z == k2x and k == k2y) or \
        (c == kx and d == ky) or (c == k1x and d == k1y) or (c == k2x and d == k2y) or (t == kx and o == ky) or (t == k1x and o == k1y) or (t == k2x and o == k2y) \
        or (a == kx and b == ky) or (a == k1x and b == k1y) or (a == k2x and b == k2y) or (y == b1y and x == b1x) or (y == b2y and x == b2x) or \
        (k == b1y and z == b1x) or (k == b2y and z == b2x) or (d == b1y and c == b1x) or (d == b2y and c == b2x)) {
        gameis = 1;
        system("cls");
        string t = "ИГРА ЗАКОНЧЕНА. КОЛИЧЕСТВО ОЧКОВ --> ";
        SetConsoleTextAttribute(hConsole, text1);
        for (int i = 0; i < size(t); i++) {
            cout << t[i];
            Sleep(40);
        }
        cout << score;
    }
}
using namespace std;
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &structCursorInfo);
    setlocale(LC_ALL, "Russian");
    string w1 = "ИГРА ГУГЛ ДИНОЗАВР --> ВЫПОЛНИЛ ПОДОПЛЕЛОВ А.С. <ИНБО-21-23>";
    for (int i = 0; i < size(w1); i++) {
        SetConsoleTextAttribute(hConsole, text1);
        cout << w1[i];
        Sleep(35);
    }
    cout << "\n";
    string w = "Нажмите клавишу X / x для запуска игры.";
    for (int i = 0; i < size(w); i++) {
        SetConsoleTextAttribute(hConsole, text2);
        cout << w[i];
        Sleep(35);
    }
    char c = _getch();
    if (c == 'X' or c == 'x') {
        system("cls");
        setup();
        while (!gameis) {
            if (score < 15) {
                S++;
            }
            if (score >= 15) {
                S += 2;
            }
            draw();
            clear();
            input();
            logic();
            logic2();
        }
    }
    return 0;
}