#include <iostream>

using namespace std;
class Point {
public:
	void method1() {
		cout << "Point: method1()\n";
		method2();
	}
	virtual void method2() {
		cout << "Point: method2()\n";
	}

	void overrided() {
		cout << "Point: overrided()\n";
	}
	virtual void overlappedBase() {
		cout << "Point: overrided()\n";
	}
	void overlappedDesc() {
		cout << "Point: overlappedDesc()\n";
	}

	Point() {
		cout << "Point()\n";
	}
	virtual ~Point() {
		cout << "~Point\n";
	}
};
class Point2D : public Point {
public:
	void method2() {
		cout << "Point2D: method2()\n";
	}

	void overrided() {
		cout << "Point2D: overrided()\n";
	}
	void overlappedBase() {
		cout << "Point2D: overlappedBase()\n";
	}
	void overlappedDesc() {
		cout << "Point2D: overridedDesc()\n";
	}

	Point2D() {
		cout << "Point2D()\n";
	}
	~Point2D() {
		cout << "~Point2D\n";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Метод 1 и метод 2 определены в базовом классе. Метод 2 также переопределен в классе-потомке." << endl
		<< "Давайте проверим, какой метод будет вызван, если мы создадим объект-потомок и вызовем метод1::\n";
	Point2D p2d;
	p2d.method1();

	cout << "\n";

	cout << "Первый случай: создание указателя базового класса, объекта базового класса:\n";
	Point* pointer = new Point;
	pointer->overrided();
	pointer->overlappedBase();
	pointer->overlappedDesc();
	delete pointer;

	cout << "Второй случай: создание указателя класса-потомка, объекта класса-потомка:\n";
	Point2D* pointer2D = new Point2D;
	pointer2D->overrided();
	pointer2D->overlappedBase();
	pointer2D->overlappedDesc();
	delete pointer2D;

	cout << "Второй случай: создание указателя базового класса, объекта класса-потомка:\n";
	Point* p = new Point2D;
	p->overrided();
	p->overlappedBase();
	p->overlappedDesc();
	delete p;

	return 0;
}