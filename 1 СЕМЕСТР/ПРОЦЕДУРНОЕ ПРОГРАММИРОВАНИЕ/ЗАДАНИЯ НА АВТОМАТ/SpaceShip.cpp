/*ВНИМАНИЕ ВСЕ РАБОТЫ ПРОДЕЛАНЫ БЕЗ ИСПОЛЬЗОВАНИЯ ООП*/
/*ЗАПУСКАТЬ СТРОГО В VS COMMUNITY*/
#include <iostream>
#include <string> /*String*/
#include <Windows.h> /*Sleep*/
#include <conio.h> /*getch*/
#include <stdio.h>
#include <mmsystem.h>
using namespace std;
int main();
void game_update();
void game_logic();
void game_exit();
void clear();
HANDLE hConsole;
enum ColorConsole {
    Grey = 8,
    White = 7,
    Yellow = 6,
    Purple = 5,
    Red = 4,
    Blue = 3,
    Green = 2
};
enum eDirection { STOP = 0, SHOOT };
eDirection dir;
const int width = 40; /*ШИРИНА ОКНА ИГРЫ*/
const int height = 16; /*ВЫСОТА ОКНА ИГРЫ*/
int x_1_ship = 1, y_1_ship = 8, x_2_ship = 2, y_2_ship = 8;
/*x КООРДИНАТЫ МЕТЕОРИТОВ*/
int meteor_x_1 = -1, meteor_x_2 = -1, meteor_x_3 = -1, meteor_x_4 = -1, meteor_x_5 = -1, meteor_x_6 = -1, meteor_x_7 = -1, meteor_x_8 = -1, meteor_x_9 = -1, meteor_x_10 = -1, \
meteor_x_11 = -1, meteor_x_12 = -1, meteor_x_13 = -1, meteor_x_14 = -1;
/*y КООРДИНАТЫ МЕТЕОРИТОВ*/
int meteor_y_1 = -1, meteor_y_2 = -1, meteor_y_3 = -1, meteor_y_4 = -1, meteor_y_5 = -1, meteor_y_6 = -1, meteor_y_7 = -1, meteor_y_8 = -1, meteor_y_9 = -1, meteor_y_10 = -1, \
meteor_y_11 = -1, meteor_y_12 = -1, meteor_y_13 = -1, meteor_y_14 = -1;
int get_weapon_x = -1, get_weapon_y = -1;
bool game_is = 0; /*Изначально игра не запущена.*/
void get_window_menu() {
    system("cls");
    /*ПОЛУЧЕНИЕ ДЕСКРИПТОРА ОКНА*/
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string start_1 = "КОСМИЧЕСКИЙ КОРАБЛЬ. \nДЛЯ НАЧАЛА ИГРЫ НАЖМИТЕ X / x.";
    SetConsoleTextAttribute(hConsole, Yellow);
    for (int i = 0; i < start_1.length(); ++i) {
        cout << start_1[i];
        Sleep(30);
        if (start_1[i] == '.' and start_1[i + 1] == ' ') {
            SetConsoleTextAttribute(hConsole, White);
        }
    }
    char c3 = _getch();
    if (c3 == 'x' or c3 == 'X') {
        system("cls");
        game_is = true;
    }
    while (game_is == true) {
        game_update();
        game_logic();
        clear(); /*ОЧИСТКА ТЕРМИНАЛА ОТ КУРСОРА*/
        if (game_is == 0) {
            break;
        }
    }
    game_exit();
};
void game_exit() {
    system("cls");
    string end_1 = "МОЛОДЕЦ!\n";
    string end_2 = "НАЧАТЬ ИГРУ ЗАНОГО -> R / r.\n";
    string end_3 = "ВЫХОД -> ЛЮБАЯ КЛАВИША.";
    for (int i = 0; i < end_1.length(); ++i) {
        SetConsoleTextAttribute(hConsole, Yellow);
        cout << end_1[i];
        Sleep(20);
    }
    SetConsoleTextAttribute(hConsole, White);
    for (int i = 0; i < end_2.length(); ++i) {
        cout << end_2[i];
        Sleep(20);
    }
    for (int i = 0; i < end_3.length(); ++i) {
        cout << end_3[i];
        Sleep(20);
    }
    char c = _getch();
    if (c == 'R' or c == 'r') {
        main();
    }
    else {
        system("cls");
        SetConsoleTextAttribute(hConsole, White);
        cout << "РАЗРАБОТЧИК -> https://github.com/LilFrozer";
    }
}
void game_update() {
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
            else if ((j == x_2_ship and i == y_2_ship) or (j == x_1_ship and i == y_1_ship)) {
                SetConsoleTextAttribute(hConsole, Green);
                if (j == 2) {
                    cout << ">";
                }
                else {
                    cout << "|";
                }
            }
            else if ((j == meteor_x_1 and i == meteor_y_1) or (j == meteor_x_2 and i == meteor_y_2) or (j == meteor_x_3 and i == meteor_y_3) or \
                (j == meteor_x_4 and i == meteor_y_4) or (j == meteor_x_5 and i == meteor_y_5) or (j == meteor_x_6 and i == meteor_y_6) or \
                (j == meteor_x_7 and i == meteor_y_7) or (j == meteor_x_8 and i == meteor_y_8) or (j == meteor_x_9 and i == meteor_y_9) or \
                (j == meteor_x_10 and i == meteor_y_10) or (j == meteor_x_11 and i == meteor_y_11) or (j == meteor_x_12 and i == meteor_y_12) or \
                (j == meteor_x_13 and i == meteor_y_13) or (j == meteor_x_14 and i == meteor_y_14)) {
                SetConsoleTextAttribute(hConsole, Yellow);
                cout << "$";
            }
            else if (j == get_weapon_x and i == get_weapon_y) {
                SetConsoleTextAttribute(hConsole, Red);
                if (j % 2 == 0) {
                    cout << "-";
                }
                else {
                    cout << "+";
                }
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
}
void game_logic() {
    srand(time(NULL));
    int new_random = rand() % 14;
    /*МЕХАНИКУ МЕТЕОРИТОВ ДОДУМЫВАЙ САМ, ЛЕНТЯЙ*/
    if (_kbhit()) {
        char c = _getch();
        if ((c == 'w' or c == 'W') and y_1_ship != 0 and y_2_ship != 0) { /*ВВЕРХ*/
            y_1_ship--;
            y_2_ship--;
        }
        else if ((c == 's' or c == 'S') and y_1_ship != 15 and y_2_ship != 15) { /*ВНИЗ*/
            y_1_ship++;
            y_2_ship++;
        }
        else if ((c == 'D' or c == 'd') and dir == STOP) { /*ВЫСТРЕЛЛЛЛ*/
            get_weapon_x = x_2_ship + 1;
            get_weapon_y = y_2_ship;
            dir = SHOOT;
        }
        else if (c == 'k' or c == 'K') { /*Выход из игры -> Для разработчика*/
            game_is = false;
        }
    }
    switch (dir) {
    case SHOOT:
        get_weapon_x++;
        if (get_weapon_x == width - 1) {
            dir = STOP;
        }
    }
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
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &structCursorInfo);
    get_window_menu();
    /*Спасибо за просмотр!*/
    return 0;
}