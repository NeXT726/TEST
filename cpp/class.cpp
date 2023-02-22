#include <stdio.h>

class A {
private:
	int x;

public:
	A();
	virtual void put1(int, int){print};
	virtual void put2(double){};

	int get();
};

A::A() { x = 1; }
int A::get() { return x; }

class B1 : public A {
public:
	void put2(double);
};

void B1::put2() { printf("1111"); }

class B2 : public A {
public:
	void put1(int, int);
	void put2(double){};
};
void B2::put1() { printf("2222"); }

void test(A*& a) {
	a = new B1();
	a->put2();
}

int main() {
	A* t;
	test(t);
	t->put2();
	// test(t);
	//
	// if (1) {
	// 	t = new B2();
	// }
	// t->put();
	// a = B2();
	// a.put();
}