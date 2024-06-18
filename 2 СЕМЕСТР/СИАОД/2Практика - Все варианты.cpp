#include <iostream>
using namespace std;
/*ДОБРО ПОЖАЛОВАТЬ, ЗДЕСЬ ПРЕДСТАВЛЕНЫ ВСЕ АЛГОРИТМЫ ИЗ ПРАКТИЧЕСКОГО ЗАДАНИЯ 2 | СИАОД*/
/*ВНИМАНИЕ, ВСЕ ПРОВЕРКИ НА ВВОД ДЕЛАТЬ В main() САМИМ. ЕСЛИ ЕСТЬ ВОПРОСЫ, ТО ПИШИТЕ tg: @pawtf*/

/*Простой вставки*/
void Insertion_sort(int* x, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && x[j - 1] > x[j]; j--) {
			int tmp = x[j - 1];
			x[j - 1] = x[j];
			x[j] = tmp;
		}
	}
}


/*Простого выбора*/
void Selection_sort(int* x, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (x[j] < x[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			swap(x[i], x[min_index]);
		}
	}
}


/*Простого обмена*/
void Exchande_sort(int* x, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (x[j] > x[j + 1]) {
				int temp = x[j]; 
				x[j] = x[j + 1];
				x[j + 1] = temp; 
			}
		}
	}
}


/*ПРИЯТНОГО ИСПОЛЬЗОВАНИЯ*/
int main(void) {
	int x1[10] = {}, x2[10] = {}, x3[10] = {};
	cout << "1\n";
	for (int i = 0; i < 10; ++i) {
		int cnt = rand() % 10;
		x1[i] = cnt;
		x2[i] = cnt;
		x3[i] = cnt;
		cout << x1[i] << " ";
	}
	Exchande_sort(x1, 10);
	Insertion_sort(x2, 10);
	Selection_sort(x3, 10);
	cout << "EX\n";
	for (int i = 0; i < 10; ++i) {
		cout << x1[i] << " ";
	}
	cout << "\nINS\n";
	for (int i = 0; i < 10; ++i) {
		cout << x2[i] << " ";
	}
	cout << "\nSEL\n";
	for (int i = 0; i < 10; ++i) {
		cout << x3[i] << " ";
	}
}