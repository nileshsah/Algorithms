#include <iostream>
using namespace std;

class A {
	int a;
public:
	A() {
	  a = 0;
	}	
	void setA() {
		cout << " Enter number: "; cin >> a;
	}
	void showA() {
		cout << " Value: " << a << endl;
	}
};

class B {
	int b;
public:
	B() {
	  b = 0;
	}	
	void setB() {
		cout << " Enter number: "; cin >> b;
	}
	void showB() {
		cout << " Value: " << b << endl;
	}
};

class C : public A,B{
	int c;
public:
	C() {
	  c = 0;
	}	
	void setC() {
		cout << " Enter number: "; cin >> c;
	}
	void showC() {
		cout << " Value: " << c << endl;
	}
};

class D : public C {
	int d;
public:
	D() {
	  d = 0;
	}	
	void setD() {
		cout << " Enter number: "; cin >> d;
	}
	void showD() {
		cout << " Value: " << d << endl;
	}
};

class E : public D{
	int e;
public:
	E() {
	  e = 0;
	}	
	void setE() {
		cout << " Enter number: "; cin >> e;
	}
	void showE() {
		cout << " Value: " << e << endl;
	}
};

class F : public D{
	int f;
public:
	F() {
	  f = 0;
	}	
	void setF() {
		cout << " Enter number: "; cin >> f;
	}
	void showF() {
		cout << " Value: " << f << endl;
	}
};

int main() {
	
}
