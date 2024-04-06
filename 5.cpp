#include <iostream>
#include <stdio.h> 
#include <string>
using namespace std;
//#5.1 -> 6 Variant
struct Node {
	double val; //Тип данных согласно варианту
	Node* next;
	Node(double _val): val(_val), next(nullptr) {}
};
struct list {
	Node* first;
	Node* last;
	list() : first(nullptr), last(nullptr) {}
	bool is_empty() {
		return first == nullptr;
	}
	void _add(double _val) {
		Node* ref = new Node(_val);
		if (is_empty()) {
			first = ref;
			last = ref;
			return;
		}
		last->next = ref;
		last = ref;
	}
	void print() {
		if (is_empty()) { 
			return; 
		};
		Node* ref = first;
		while (ref) {
			cout << ref -> val << " ";
			ref = ref->next;
		}
		cout << "\n";
	}
	Node* find(double _val) {
		Node* ref = first;
		while (ref && ref->val != _val) ref = ref->next;
			return (ref && ref->val == _val) ? ref : nullptr;
	}
	void remove(double _val) {
		if (is_empty()) return;
		if (first->val == _val) { 
			Node* ref = first;
			first = ref->next;
			delete ref;
			return; 
		}
		else if (last->val == _val){
			if (is_empty()) {
				return;
			}
			if (first == last) {
				Node* ref = first;
				first = ref->next;
				delete ref;
				return;
			}
			Node* ref = first;
			while (ref->next != last) ref = ref->next;
			ref->next = nullptr;
			delete last;
			last = ref;
			return;
		}
		Node* slow = first;
		Node* fast = first->next;
		while (fast && fast-> val != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			cout << "Cancel." << "\n";
			return;
		}
		slow->next = fast->next;
		delete fast;
	}
	//Разработать функцию, которая вставляет перед последним узлом два новых узла.
	void addingtwo() {
		int k = 0;
		while (k != 2) {
			int j_ = k + 1;
			cout << "Введите элемент #" << j_ << "\n";
			double _j;
			cin >> _j;
			_add(_j);
			k++;
		}
	}
	//Удаляет из списка L первое отрицательное значение, если оно присутствует в списке.
	void removeMINUS() {
		if (is_empty()) {
			return;
		};
		Node* ref = first;
		while (ref != nullptr) {
			if (ref->val >= 0) {
				ref = ref->next;
			}
			else {
				remove(ref->val);
				break;
			}
		}
	}
	//Найти в списке L максимальное значение и перенести его узел в конец списка.
	void findMAX() {
		int _cnt = 0, cnt_ = 0; 
		if (is_empty()) {
			return;
		};
		Node* ref = first;
		while (ref != nullptr) {
			ref = ref->next;
			_cnt++;
		}
		double* M = new double[_cnt];
		Node* ref_ = first;
		while (ref_ != nullptr) {
			M[cnt_] = ref_->val;
			ref_ = ref_->next;
			cnt_++;
		}
		double temp;
		for (int i = 0; i < _cnt - 1; i++) {
			for (int j = 0; j < _cnt - i - 1; j++) {
				if (M[j] > M[j + 1]) {
					// меняем элементы местами
					temp = M[j];
					M[j] = M[j + 1];
					M[j + 1] = temp;
				}
			}
		}
		double MAX = M[_cnt - 1]; //Максимальный элемент
		remove(MAX);
		_add(MAX);
		delete[] M;
	}
};
list Create(int len) {
	list M;
	double val;
	cout << "1./ -> Руками." << "\n";
	for (int i = 0; i < len; i++) {
		cout << "Введите " << len - i << " элемент." << "\n";
		cin >> val;
		M._add(val);
	}
	M.print();
	cout << "Успех." << "\n";
	return M;
}
list autoCreate(int len) {
	list M;
	cout << "2./ -> Генератором." << "\n";
	srand(time(NULL));
	for (int i = 0; i < len; i++) {
		M._add(rand());
	}
	M.print();
	cout << "Успех." << "\n";
	return M;
}
int main() {
	//1. Разработать функцию, которая вставляет перед последним узлом два новых узла.
	//2. Удаляет из списка L первое отрицательное значение, если оно присутствует в списке.
	//3. Найти в списке L максимальное значение и перенести его узел в конец списка.
	int cnt_;
	cout << "Введите количество элементов." << "\n";
	cin >> cnt_;
	list N;
	cout << "Способ заполнить -> 1 - Руками. / 2 - Генератором." << "\n";
	int j;
	cin >> j;
	switch (j) {
	case 1:
		N = Create(cnt_);
		cout << "Односвязный список." << "\n";
		N.print();
		/*cout << "Задание #1. Вариант 6." << "\n";
		N.addingtwo();
		N.print();*/
		cout << "Задание #2. Вариант 6." << "\n";
		N.removeMINUS();
		N.print();
		cout << "Задание #3. Вариант 6." << "\n";
		N.findMAX();
		N.print();
		break;
	case 2:
		N = autoCreate(cnt_);
		N.print();
		break;
	default:
		cout << "0;";
	}
	return 0;
}
