// Q: How do I create if else if else conditionals?
// Q: How do I create a switch conditional?
// Q: How do I perform short-circuiting in the case
//    of the && (Boolean and) or || (Boolean or) operator?

// Include the functionality to
// do console streaming
#include <iostream>
using std::cout;
using std::endl;


int main(void)
{
	// Basic if, else if, else
	int x = 4;
	int y = 2;

	// If x does not equal 1, 
	// then skip the comparison of y altogether
	// This is called short-circuiting
	if (x == 1 && y == 2)
	{
		cout << "First if" << endl;
	}
	else if (x == 4 && y == 5) // Since x == 4, the comparison of y also occurs
	{
		cout << "Second if" << endl;
	}
	else
	{
		cout << "else" << endl;
	}


	// Basic switch statement
	switch (x)
	{
		case 1:
		{
			cout << "First case" << endl;
			break;
		}
		case 2:
		{
			cout << "Second case" << endl;
			break;
		}
		case 4:
		{
			cout << "Last case" << endl;
			break;
		}
	}

	return 0;
}