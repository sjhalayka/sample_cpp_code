// Q: How do I take parameters in main() 
//    from the commandline?

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;



// First parameter gives the argument count argc
// Second parameter is a pointer to one or more char pointers
int main(int argc, char** argv)
{
	cout << argc << " arguments found" << endl;

	for (int i = 0; i < argc; i++)
	{
		string s = argv[i];

		// Do stuff with s...

		cout << s << endl;
	}

	return 0;
}