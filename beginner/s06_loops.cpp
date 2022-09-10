// Q: How do I create a basic for-loop?
// Q: How do I create a basic do-while loop?
// Q: How do I create a basic while loop?
// Q: How do I short-circuit loops using continue and break?

// Include the functionality to
// do console streaming
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main(void)
{
	const size_t x_size = 10, y_size = 15;

	vector<float> y(y_size);
	vector<vector<float>> arr2d(x_size, y);

	// Basic for-loop
	for (size_t i = 0; i < x_size; i++)
	{
		for (size_t j = 0; j < y_size; j++)
		{
			// static_cast<> converts from one type to another
			// Here we are converting from size_t to float
			arr2d[i][j] = static_cast<float>(i) * static_cast<float>(j);
			cout << arr2d[i][j] << ' ';
		}

		cout << endl;
	}



	vector<float> arr1d(x_size);

	srand(123);

	// Initialize array with pseudorandom numbers
	for (size_t i = 0; i < arr1d.size(); i++)
		arr1d[i] = rand() / static_cast<float>(RAND_MAX) - 0.5f;



	// Basic do-while loop
	size_t index = 0;

	// Note that the first iteration is performed no matter what
	do
	{
		cout << "Do-while loop index: " << index << ' ' << arr1d[index] << endl;
		index++;

	} while (index < arr1d.size() && arr1d[index - 1] <= 0);



	// Basic while loop
	index = 0;

	// The first iteration is performed only if 
	// the criteria are satisfied
	while (index < arr1d.size() && arr1d[index] <= 0)
	{
		cout << "While loop index: " << index << ' ' << arr1d[index] << endl;
		index++;
	}


	// Basic use of continue; and break;
	for(size_t i = 0; i < arr1d.size(); i++)
	{ 
		if (i == 2)
		{
			// Go back to top of loop
			cout << "Short-ciruiting using continue" << endl;
			continue;
		}

		if (i == 8)
		{
			// Break out of the loop altogether
			cout << "Short-circuiting using break" << endl;
			break;
		}

		cout << "iteration " <<  i + 1 << endl;
	}


	return 0;
}