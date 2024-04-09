#include <string>
#include <iostream>
#include <chrono>
#include <sstream>
#include <conio.h>
#include <tchar.h>
#include <clocale>
#include <fstream>
using namespace std;
//#1
/*int poisk_max(int* x, int n) {
    int max = x[0];
    for (int i = 0; i < n; ++i) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    return max;
}
int func(int* arr, int n) {
    int max = arr[0];
    if (n == 1)
        max = arr[0];
    else {
        int prevResult = func(arr, n - 1);
        if (prevResult > arr[n - 1]) {
            max = prevResult;
        }
        else {
            max = arr[n - 1];
        }
    }
    return max;
}
void print(int* M, int n) {
    for (int i = 0; i < n; ++i) {
        cout << M[i] << " ";
    }
    cout << "\n";
}
int main() {
    srand(time(NULL));
    cout << "Start!" << "\n";
    int n;
    cin >> n;
    int* M = new int[n];
    for (int i = 0; i < n; i++) {
        M[i] = rand();
    }
    print(M, n);
    cout << "MAX1 = " << poisk_max(M, n) << "\n";
    cout << "MAX2 = " << func(M, n) << "\n";
}*/
//#2
struct main_{
    int data;
    struct main_* next;
};
main_* head, * tail;
int cnt = 0; //Количество элементов
void Create();
void Add_last(main_* temp);
void Head_to_tail();
void show_menu();
void menu();
void Loading(struct main_* array);
void inf();
void is_empty();
//Создание очереди
void Create() {
    head = (main_*)malloc(sizeof(main_));
    head->next = NULL;
    tail = head;
    cnt = 0;
}
//Проверка на пустой список
void is_empty() {
    if (cnt == 0) {
        cout << "Список пуст!" << endl;
        system("pause");
        menu();
    }
}
/*Функция, которая добавляет элемент в конец*/
void Add_last(main_* temp) {
    tail->data = temp->data;
    tail->next = (main_*)malloc(sizeof(main_));
    tail = tail->next;
    tail->next = NULL;  //Обнуление указателя на следующий элемент 
    cnt++;
}
/*Считывание элемента из "головы" и перенос в "хвост"*/
void Head_to_tail() {
    main_* buff = head;
    tail->data = buff->data;
    tail->next = (main_*)malloc(sizeof(main_));
    tail = tail->next;
    tail->next = NULL;
    buff = head->next;
    free(head);
    head = buff;
}
/*Вывод списка*/
void Tablitsa() {
    for (int i = 0; i < cnt; i++) {
        printf("%d) %d\n", i + 1, head->data);
        Head_to_tail();
    }
}
/*Вывод информации для главного меню*/
void show_menu() {
    cout << "1 - Добавить элемент" << endl;
    cout << "2 - Просмотр одного элемента" << endl;
    cout << "3 - Просмотр всех элементов" << endl;
    cout << "4 - Выход" << endl;
}
/*Загрузка данных из очереди в массив*/
void Loading(struct main_* array) {
    for (int i = 0; i < cnt; i++) {
        array[i].data = head->data;
        Head_to_tail();
    }
}
/*Ввод элементов с клавиатуры*/
void input() {
    main_ queue;
    int num = 0;
    cout << "Введите число: ";
    cin >> num;
    queue.data = num;
    Add_last(&queue);
}
/*Информация об элементе*/
void inf() {
    int Num = 0;
    cout << "Введите номер элемента." << "\n";
    cin >> Num;
    Num = Num - 1;
    main_* array = new main_[cnt];
    Loading(array);
    cout << "Число-> " << array[Num].data << endl;
}
/*Главное меню*/
void menu() {
    char ch;
    show_menu();
    while (1) {
        ch = _getch();
        if (ch == 49) {
            input();
            menu();
        }
        if (ch == 50) {
            //is_empty();
            inf();
            menu();
        }
        if (ch == 51) {
            //is_empty();
            Tablitsa();
            menu();
        }
        if (ch == 52) {
            exit(0);
        }
    }
}
int main() {
    Create();
    menu();
    return 0;
}