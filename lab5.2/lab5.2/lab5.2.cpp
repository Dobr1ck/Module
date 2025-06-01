// lab5.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
};

using namespace std;

class A {
public:
	string s;
	A() {
		cout << "konstruktor of class A" << endl;
	}

	A(const char* a) {
		s = a;
		cout << "Custom konstruktor of class A" << endl;
		cout << s << endl;
	}
	virtual ~A() {
		cout << "destruktor of class A" << endl;
		cout << typeid(*this).name() << endl;
	}
};

class B : public A {
public:
	B() {
		cout << "konstruktor of class B" << endl;
	}
	B(const char* a) :A(a) {
		cout << "Custom konstruktor of class B" << endl;
		cout << a << endl;
	}
	~B() {
		cout << "destruktor of class B" << endl;
		cout << typeid(*this).name() << endl;
	}
};

void del(vector<A*> v) {
	for (int i = 0; i < v.size(); i++)
		delete v[i];
	v.clear();
}
vector<A*>v;
list <A*> l;

int main() {
	l.push_back(new A("first"));
	l.push_back(new B("second"));
	// скопировать из списка в вектор
	for (list<A*>::iterator it = l.begin(); it != l.end(); ++it) {
		v.push_back(*it);
	}
	l.clear();
	del(v);
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
