// Q: If the constructor cannot specify a return type,
//    then how do we signal a failure? For instance,
//    what happens when we try to allocate more memory
//    than what the system has? Two methods are provided:
//    1) exceptions alone, and 2) exceptions in conjunction
//    with a boolean value
//
//    NOTE: exceptions obviously take up CPU cycles. 
//          Some C++ programmers actually prefer to
//          entirely disable exceptions altogether in
//          the compile options


#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <exception>
using std::exception;



class A
{
protected:

	vector<float> elements;

public:

	// Allocate memory in the constructor
	// NOTE: The constructor cannot specify
	// a return type (not even void)
	A(const size_t& n)
	{
		// Ask for exabytes and exabytes of data
		// This should trigger the bad_alloc exception
		cout << "Asking for " << n << " floats..." << endl;

		elements.resize(n);
	}

	// Deallocate memory in the destructor
	~A(void)
	{
		// Nothing to do here	
	}
};



class B
{
protected:

	vector<float> elements;
	bool init_ok = false;

public:

	bool get_init_ok(void)
	{
		return init_ok;
	}

	// Allocate memory in the constructor
	// NOTE: The constructor cannot specify
	// a return type (not even void)
	B(const size_t& n)
	{
		// Ask for exabytes and exabytes of data
		// This should trigger the bad_alloc exception
		cout << "Asking for " << n << " floats..." << endl;

		init_ok = true;

		try
		{
			elements.resize(n);
		}
		catch (...)
		{
			init_ok = false;
		}
	}

	// Deallocate memory in the destructor
	~B(void)
	{
		// Nothing to do here	
	}
};



int main(void)
{
	cout << "Constructing the object" << endl;

	// Ask for exabytes and exabytes of data
	// This should trigger an exception
	try
	{
		// Ask for exabytes and exabytes of data
		// NOTE: a negative 1 signed int is equal
		// to the greatest value of the size_t
		A a(-1);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}


	// Do not explicitly use exceptions
	B b(-1);

	if (b.get_init_ok())
		cout << "B constructed OK";
	else
		cout << "B did not construct OK";



	return 0;
}