// Q: How do I create and read binary files?

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// For reading/writing binary data to disk
#include <fstream>
using std::ifstream;
using std::ofstream;



int main(void)
{
	vector<double> v{ 1.0, 3.14, 5.5 };

	// Write vector contents to file
	ofstream outfile("sample.bin", ofstream::binary);

	if (outfile.fail())
	{
		cout << "Could not open file for writing" << endl;
		return -1;
	}

	// Convert the address of the first element of the vector into a const char pointer
	// Write v.size() * sizeof(double) bytes to disk
	outfile.write(reinterpret_cast<const char*>(&v[0]), v.size() * sizeof(double));
	outfile.close();



	ifstream infile("sample.bin", ifstream::binary);

	if (infile.fail())
	{
		cout << "Could not open file for reading" << endl;
		return -1;
	}

	// Make sure to allocate!
	vector<double> v2(v.size());

	// Convert the address of the first element of the vector into a char pointer
	// Read v2.size() * sizeof(double) bytes to disk
	infile.read(reinterpret_cast<char*>(&v2[0]), v2.size() * sizeof(double));

	// bytes_read should be equal to v2.size() * sizeof(double)
	size_t bytes_read = infile.tellg();

	infile.close();

	cout << "Wrote/read " << bytes_read << " bytes" << endl;



	return 0;
}