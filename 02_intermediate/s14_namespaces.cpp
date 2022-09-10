// Q: How do I use namespaces in order
//    to prevent collisions?

#include <iostream>
using std::cout;
using std::endl;

// For the std::max() function
#include <algorithm>



namespace collision_protection
{
	float max(const float& a, const float& b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
};



int main(void)
{
	// How to handle collisions using ::
	cout << collision_protection::max(3.14f, 2.0f) << endl;
	cout << std::max(3.14f, 2.0f) << endl;

	return 0;
}