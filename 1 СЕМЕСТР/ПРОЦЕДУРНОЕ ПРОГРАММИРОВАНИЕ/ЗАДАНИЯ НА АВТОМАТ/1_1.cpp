#include <iostream>
#include <string> /*String*/
#include <windows.h> /*Sleep*/
#include <conio.h> /*getch*/
#include <stdio.h>
#include <mmsystem.h>
using namespace std;
int main();
void game_create();
void game_update();
void game_logic();
void game_exit();
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
const int width = 10;
const int height = 10;
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
        Sleep(100);
        game_create();
        game_update();
        game_logic();
        if (_kbhit()) {
            char c1 = _getch(); /*Выход из игры -> Для разработчика*/
            if (c1 == 'k' or c1 == 'K') {
                game_is == 0;
                game_exit();
                break;
            }
        }
    }
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
void game_create() {
    int x_ship = 2, y_ship = -10;
}
void game_update() {
    system("cls");
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
BOOL ShowConsoleCursor(BOOL bShow) {
    CONSOLE_CURSOR_INFO cci;
    HANDLE hStdOut;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hStdOut == INVALID_HANDLE_VALUE)
        return FALSE;
    if(!GetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    cci.bVisible = bShow;
    if(!SetConsoleCursorInfo(hStdOut,&cci))
        return FALSE;
    return TRUE;
}
void game_logic() {
    
}
int main() {
    ShowConsoleCursor(FALSE); /*Скрывает курсор*/
    get_window_menu();
    /*Спасибо за просмотр!*/
    return 0;
}