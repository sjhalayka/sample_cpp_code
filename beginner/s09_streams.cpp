// Q: How do I use the cin and cout (console) streams?
// Q: How do I use the file streams?
// Q: How do I use the string streams? In other words,
//    how do I convert between a string of text and a
//    size_t (or any other POD type) and back again?    

// Include the functionality to
// do console streaming
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

// File streaming
#include <fstream>
using std::ifstream;
using std::ofstream;

// String streaming
#include <sstream>
using std::istringstream;
using std::ostringstream;



int main(void)
{
	// Use basic console streaming 
	cout << "Hello world!" << endl;

	cout << "Type in some text and press Enter" << endl;

	string s;
	getline(cin, s);

	cout << "You typed: " << s << endl;



	// Use basic text-based file streaming
	ofstream outfile("sample.txt");

	if (outfile.fail())
	{
		cout << "Could not open for writing" << endl;
		return -1;
	}

	outfile << s << endl;
	outfile.close();

	ifstream infile("sample.txt");

	if (infile.fail())
	{
		cout << "Could not open for reading" << endl;
		return -1;
	}

	string s2;

	while (getline(infile, s2))
		cout << s2 << endl;

	infile.close();
	


	// Use basic string streaming
	size_t size_t_var = 12345;

	// Convert size_t to string
	ostringstream oss;
	oss << "The number is: " << size_t_var << endl;
	cout << oss.str() << endl;

	// Convert string to size_t
	string sstr = "98765";
	istringstream iss(sstr);
	iss >> size_t_var;
	cout << size_t_var << endl;



	return 0;
}