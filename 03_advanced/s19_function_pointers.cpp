// Q: How do I use function pointers?
// Q: How do I optimize branching code 
//    by using a function pointer?

#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using std::chrono::high_resolution_clock;

#include <functional>
using std::function;



void proceed_a(size_t& n)
{
	//cout << "proceed_a()" << endl;
}

void proceed_b(size_t& n)
{
	//cout << "proceed_b()" << endl;
}

void proceed_c(size_t& n)
{
	//cout << "proceed_c()" << endl;
}

void proceed_d(size_t& n)
{
	//cout << "proceed_d()" << endl;
}

// Function pointer typedef
typedef void (*proceed_func_pointer)(size_t&);



class A
{
public:
	void proceed_a(size_t& n)
	{
		cout << "A::proceed_a()" << endl;
	}

	void proceed_b(size_t& n)
	{
		cout << "A::proceed_b()" << endl;
	}

	void proceed_c(size_t& n)
	{
		cout << "A::proceed_c()" << endl;
	}

	void proceed_d(size_t& n)
	{
		cout << "A::proceed_d()" << endl;
	}


};

// Function pointer typedef
typedef void (A::*A_proceed_func_pointer)(size_t &);



class B
{
public:

	static void proceed_a(size_t& n)
	{
		//cout << "B::proceed_a()" << endl;
	}

	static void proceed_b(size_t& n)
	{
		//cout << "B::proceed_b()" << endl;
	}

	static void proceed_c(size_t& n)
	{
		//cout << "B::proceed_c()" << endl;
	}

	static void proceed_d(size_t& n)
	{
		//cout << "B::proceed_d()" << endl;
	}
};

// Function pointer typedef
typedef void (*B_proceed_func_pointer)(size_t&);



int main(void)
{
	size_t param = 1234;

	// Pointer to function example
	proceed_func_pointer p = &proceed_a;
	(*p)(param); // Call function

	// Try using std::function instead of a pointer to function
	function<void(size_t&)> proceed = proceed_a;
	proceed(param);



	// Pointer to member function example
	A a;
	A_proceed_func_pointer f = &A::proceed_a;
	(a.*f)(param); // Call function



	// Pointer to static member function example
	B_proceed_func_pointer f2 = &B::proceed_a;
	(*f2)(param); // Call function



	// Use B::proceed_d() to do timing test
	const size_t function_index = 3;
	const size_t iterations = 1000000000;

	high_resolution_clock::time_point start_time = high_resolution_clock::now();

	for (size_t i = 0; i < iterations; i++)
	{
		// Use if-else method
		if (function_index == 0)
		{
			B::proceed_a(param); // Call function
		}
		else if (function_index == 1)
		{
			B::proceed_b(param); // Call function
		}
		else if (function_index == 2)
		{
			B::proceed_c(param); // Call function
		}
		else if (function_index == 3)
		{
			B::proceed_d(param); // Call function
		}
	}

	high_resolution_clock::time_point end_time = high_resolution_clock::now();
	std::chrono::duration<float, std::milli> elapsed = end_time - start_time;
	cout << "if-else method took took " << elapsed.count() / 1000.0f << " seconds" << endl;



	// Use function pointer method
	start_time = high_resolution_clock::now();

	// Use B::proceed_d() to do timing test
	f2 = &B::proceed_d;

	for (size_t i = 0; i < iterations; i++)
		(*f2)(param); // Call function

	end_time = high_resolution_clock::now();
	elapsed = end_time - start_time;
	cout << "Function pointer method took " << elapsed.count() / 1000.0f << " seconds" << endl;

	// NOTE: The function pointer method should
	//       have taken less time than the if-else
	//       method



	// Use proceed_d() to do timing test
	proceed = proceed_d;

	start_time = high_resolution_clock::now();

	for (size_t i = 0; i < iterations; i++)
		proceed(param); // Call function

	end_time = high_resolution_clock::now();
	elapsed = end_time - start_time;
	cout << "Function<> method took " << elapsed.count() / 1000.0f << " seconds" << endl;

	// NOTE: The function<> method should have taken
	//       *more* time than the function pointer method
	//       Use of function<> is not recommended in
	//       apps that need to be speedy



	return 0;
}