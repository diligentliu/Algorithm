#include "main.h"
#include "solution.h"

template <typename T>
class Base {
public:
	void func() {
		T& derived = static_cast<T&>(*this);
		derived.func();
	}
};

class Derived_1 : public Base<Derived_1> {
public:
	void func() {
		std::cout << "Derived_1 class" << std::endl;
	}
};

class Derived_2 : public Base<Derived_2> {
public:
	void func() {
		std::cout << "Derived_2 class" << std::endl;
	}
};

int main() {
	Base<Derived_1> *d1 = new Derived_1();
	Base<Derived_2> *d2 = new Derived_2();
	d1->func();
	d2->func();
	delete d1;
	delete d2;
	return 0;
}