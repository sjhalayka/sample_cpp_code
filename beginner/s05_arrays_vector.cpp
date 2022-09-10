// Q: How do I create a C-style array on the stack?
// Q: How do I create a C++-style array on the heap using new[] and delete[]?
// Q: How do I create a C++-style array on the heap using vector<>?

// Include the functionality to
// do console streaming
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main(void)
{
	// C-style array
	float arr[50]; // When we know the size ahead of time

	arr[0] = 123.456f; // Alter first element



	// C++ - style array using new[]/delete[]
	size_t x = 50;

	float* arr2 = new float[x]; // When we do not know the size aheaad of time

	arr2[0] = 987.654f; // Alter first element

	// You absolutely need to delete[] the memory allocated by new[]
	delete[] arr2;



	// C++ - style array using the vector container
	vector<float> arr3(x);

	arr3[0] = 456.789f; // Alter first element

	// Note that the vector<> automatically deallocates its internal memory
	// when it goes out scope



	return 0;
}