#include <iostream> 
#include <cmath> 
#include <string> 
#include <algorithm> 
#include <vector> 
#include <random> 

using namespace std;

class Foo {
public:
	string message = "I am Foo";

	Foo() {
		cout << "Foo is alive " << this << "\n";
	}

	Foo(const Foo& a) {
		cout << "FOO is more alive " << this << "\n";
	}

	~Foo() {
		cout << "Foo is new dead " << this << "\n";
	}



	string sayName() {
		return message;
	}

	void updateMessage(string s) {
		message = s;
	}


};

class Bar {
public:
	Foo& fooPointer;

	Bar(Foo* a) : fooPointer(*a) {
		cout << "Bar:" << fooPointer.sayName() << "\n";
		fooPointer.updateMessage("Blah Blah");
	}

	~Bar() {
		cout << "Bar: Dieded " << "\n";
	}


};


class Baz {
public:
	Foo& fooPointer;

	Baz(Foo* a) : fooPointer(*a) {
		cout << "Baz: " << fooPointer.sayName() << "\n";
	}

	~Baz() {
		cout << "Baz: Dieded " << "\n";
	}
};


void doAction() {
	Foo* pFoo = new Foo();

	Bar bar = Bar(pFoo); // update Foo member variable here
	Baz baz = Baz(pFoo);
}


int main() {
	doAction();
	// Is Foo dead
	cin.get();
}
