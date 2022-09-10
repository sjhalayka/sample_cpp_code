// Q: How do I create overloaded functions?
// Q: How do I use templates to minimize code duplication?

// Include the functionality to
// do console streaming
#include <iostream>
using std::cout;
using std::endl;


// Define a function, using the float type
bool f(float x)
{
	cout << "f(float x) called" << endl;

	if (x == 1.0f)
		return true;
	else
		return false;
}

// Overload the function, using the double type
bool f(double x)
{
	cout << "f(double x) called" << endl;

	if (x == 1.0)
		return true;
	else
		return false;
}

// Define a template-based function instead, which handles 
// all of the data types using one function definition
template<typename T>
bool f(T x)
{
	cout << "f(T x) called" << endl;

	if (x == 1)
		return true;
	else
		return false;
}


int main(void)
{
	float a = 1.0f;
	double b = 1.0;

	// Call the different functions
	f(a);
	f(b);

	// Instead, use the template method by declaring the type in the < > brackets
	// 
	// This is a kind of preview of the possibilities given by
	// including the containers from the Standard **Template** Library 
	// (for instance: vector<float> v, etc).
	f<float>(a);
	f<double>(b);

	return 0;
}