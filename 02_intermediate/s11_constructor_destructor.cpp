// Q: How do I use pointers within a class 
//    in order to **automatically** perform 
//    memory allocation/deallocation?

#include <iostream>
using std::cout;
using std::endl;



class A
{
protected:

	// Initialize a null pointer
	float* float_ptr = 0;
	size_t num_elements = 0;

public:

	// Allocate memory in the constructor
	// NOTE: The constructor cannot specify
	// a return type (not even void)
	A(const size_t &n)
	{
		num_elements = n;

		cout << "Allocating " << num_elements << " floats" << endl;

		float_ptr = new float[num_elements];
	}

	// Deallocate memory in the destructor
	~A(void)
	{
		if (float_ptr != 0)
		{
			cout << "Deallocating " << num_elements << " floats" << endl;
			
			delete[] float_ptr;
		}
	}
};



int main(void)
{
	cout << "Constructing the object" << endl;

	A a(1234);

	cout << "Letting the object go out of scope..." << endl;

	return 0;
}