// Q: How do I create a basic class?
// Q: How do I create class inheritence?
// Q: How do I create a pure virtual function, 
//    so that the class cannot be instantiated?
// Q: How do I use templates in classes?

// Include the functionality to
// do console streaming
#include <iostream>
using std::cout;
using std::endl;


// Basic class
class A
{
protected:
	size_t x = 1234;
};

// Inherit from class A
class B : public A
{
public:
	void print_x(void)
	{
		cout << x << endl;
	}
};


// Basic class with pure virtual function
class C
{
protected:
	float x = 3.14f;

public:
	// Pure virtual function, making it so that class C
	// cannot be instantiated
	virtual float square_x(void) = 0;
};

// Inherit from class C
class D : public C
{
public:

	float square_x(void)
	{
		return x*x;
	}
};


// Use a template
template<typename T>
class E
{
protected:
	T x = 987;

public:
	T square_x(void)
	{
		cout << typeid(T).name() << endl;

		return x * x;
	}
};



int main(void)
{
	B b;
	b.print_x();

	D d;
	cout << d.square_x() << endl;

	// Is the following syntax for E starting to look a little bit like
	// the STL vector<> container? It should. We will cover that in the
	// next sample.
	E<float> e_float;
	cout << e_float.square_x() << endl;

	E<double> e_double;
	cout << e_double.square_x() << endl;

	return 0;
}