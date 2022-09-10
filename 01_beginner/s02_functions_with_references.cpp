// Q: How do I pass a function parameter by value, versus by reference?

// Include the functionality to
// do console streaming
#include <iostream>
using std::cout;
using std::endl;


// Return nothing, pass one parameter by value, and
// pass one parameter by reference (hence the &)
void f(size_t x, size_t &y)
{
	x = 0;
	y = 0;
}

int main(void)
{
	size_t a = 7, b = 14;

	f(a, b);

	// Note that the size_t a did not change because
	// we did not pass it in by reference like we did
	// with size_t b
	cout << a << ' ' << b << endl;

	return 0;
}