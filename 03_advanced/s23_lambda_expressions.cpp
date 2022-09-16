// Q: How do I use lambda expressions?

#include <iostream>
using std::cout;
using std::endl;



template<class T>
class A
{
public:

	T x;

	void print(void) const
	{
		cout << "Type: " << typeid(T).name() << ", value: " << x << endl;
	}
};



template<class T>
class B
{
public:

	T x;

	void print(void) const
	{
		cout << "Type: " << typeid(T).name() << ", value: " << x << endl;
	}
};



class C 
{
public:

	void print(void) const 
	{
		cout << "Nothing to print here" << endl;
	}
};



int main(void)
{
	// Create a lambda expression that takes in 
	// any type that has a print() function
	//
	// Note that the lambda can be defined in
	// any scope, not just the global or 
	// class scope like it is with functions.
	// This allows you to write the lambda
	// close to where it will be used.
	//
	// Using auto for the parameter type
	// allows us to automatically use the
	// lambda expression on a wide variety
	// of data types, as long the type has
	// a print() member function.
	// In other words, auto is a necessary evil
	auto l = [](const auto &value) { value.print(); };


	A<size_t> as;
	as.x = 100;
	l(as);

	A<float> af;
	af.x = 123.456f;
	l(af);	

	B<char> bc;
	bc.x = 'z';
	l(bc);

	C c;
	l(c);

	return 0;
}