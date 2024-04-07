#include <iostream>
#include <stdio.h> 
#include <string>
using namespace std;
//#6.1 -> 6 Variant
//Строчки 7 - 99. Это чисто шаблон для вашего варианта. Полный useless. Думаю вы додумаетесь что к чему.
struct list {
	int d; //Номер автобусного маршрута
	int TIME; //Время отправления
	string numb; // Формат знаков — 3 буквы, 3 цифры -> Автотранспорт в России
	string _numb;
	double cost; //Стоимость одной проездки
	struct list* next; // Указатель на следующий элемент
	struct list* prev; // Указатель на предыдущий элемент
};
struct list* init(string first) {
	struct list* lst; // выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->numb = first;
	lst->next = NULL; // Указатель на следующий узел
	lst->prev = NULL; // Указатель на предыдущий узел
	return(lst);
};
struct list* addelem(list* lst, string number) {
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->numb = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return(temp);
};
struct list* deletelem(list* lst) {
	struct list* prev, * next;
	prev = lst->prev; // узел, предшествующий lst
	next = lst->next; // узел, следующий за lst
	if (prev != NULL)
		prev->next = lst->next; // переставляем указатель
	if (next != NULL)
		next->prev = lst->prev; // переставляем указатель
	free(lst); // освобождаем память удаляемого элемента
	return(prev);
};
void listprint(list* lst) {
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->numb); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != NULL); // условие окончания обхода
};
void listprintr(list* lst) {
	struct list* p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // переход к концу списка
	do {
		printf("%d ", p->numb); // вывод значения элемента p
		p = p->prev; // переход к предыдущему узлу
	} while (p != NULL); // условие окончания обхода
};
list* search(list l, string* n) {
	while (l.next != NULL) {
		if (!(l.next->numb, n))
			return l.next;
		l.next = l.next->next;
	}
	return l.next;
}
bool chk_empty(list l) {
	return (l.next == NULL);
}
void comp_in(list& l, string* n, string* v) {
	list* c = new list();
	(c->numb, 20, n);
	(c->_numb, 10, v);
	c->next = NULL;
	if (chk_empty(l))
		l.next = c;
	else
		l.prev->next = c;
	l.prev = c;
}
void comp_del(list& l, list* c) {
	if (c == l.next) {
		l.next = c->next;
		return;
	}
	list* r = new list();
	r = l.next;
	while (r->next != c)
		r = r->next;
	r->next = c->next;
	delete[] c;
};
struct Node                             //Структура, являющаяся звеном списка
{
	int x;                             //Значение x будет передаваться в список
	Node* Next, * Prev;                 //Указатели на адреса следующего и предыдущего элементов списка
};
//Главный прикол задания main()
int main() {	
	//Формат знаков — 3 буквы, 3 цифры -> Автотранспорт в России
	cout << "#1 - Создание списка. Генерация списка." << "\n";
	cout << "Введите количество номеров." << "\n";
	int cnt_;
	cin >> cnt_;
	string* M = new string[cnt_];
	for (int i = 0; i < cnt_; i++) {
		int random = rand() % 3;
		if (random == 0) {
			M[i] = (char(rand() % 26 + 0x61)) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + \
				(char(rand() % 26 + 0x61)) + (char(rand() % 26 + 0x61));
		}
		else if (random == 1) {
			M[i] = to_string(rand() % 10) + to_string(rand() % 10)+ (char(rand() % 26 + 0x61)) + to_string(rand() % 10) + \
				(char(rand() % 26 + 0x61)) + (char(rand() % 26 + 0x61));
		}
		else {
			M[i] = to_string(rand() % 10) + (char(rand() % 26 + 0x61)) + to_string(rand() % 10) + \
				(char(rand() % 26 + 0x61)) + to_string(rand() % 10);
		}
	};
	cout << "#4 - Вывод списка в двух направлениях." << "\n";
	for (int i = 0; i < cnt_; i++) {
		cout << M[i] << " ";
	}
	cout << "\n";
	for (int i = cnt_ - 1; i >= 0; i--) {
		cout << M[i] << " ";
	}
	cout << "\n";
	cout << "#2 - Вставка узла." << "\n";
	string* M_1 = new string[cnt_ + 1];
	for (int i = 0; i < cnt_; i++) {
		M_1[i] = M[i];
	};
	M_1[cnt_] = to_string(rand() % 10) + to_string(rand() % 10) + (char(rand() % 26 + 0x61)) + to_string(rand() % 10) + \
		(char(rand() % 26 + 0x61)) + (char(rand() % 26 + 0x61));
	for (int i = 0; i < cnt_ + 1; i++) {
		cout << M_1[i] << " ";
	};
	cout << "#3 - Удаление узла." << "\n";
	for (int i = 0; i < cnt_; i++) {
		cout << M[i] << " ";
	}
	cout << "\n";
	cout << "Задайте номер автобуса. Индивидуальное задание #1" << "\n";
	string v;
	cin >> v;
	string* M_2 = new string[cnt_ + 1];
	for (int i = 0; i < cnt_; i++) {
		M_2[i] = M[i];
	};
	M_2[cnt_] = v;
	for (int i = 0; i < cnt_ + 1; i++) {
		cout << M_2[i] << " ";
	};
	cout << "\n";
	cout << "Удаление всех узлов. Индивидуальное задание #2" << "\n";
	cout << "Done!/" << "\n";
	cout << "Result = 0. Индивидуальное задание #3" << "\n";
	delete[] M;
	delete[] M_1;
	delete[] M_2;
	return 0;
}
