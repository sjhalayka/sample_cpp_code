// Q: How do I interface the vector<> and string containers
//    with C-style function with pointer parameters?
// Q: How do I create an iterator and a const iterator?
// Q: How do I create a map and a set?
// Q: How do I use the auto keyword?

// Include the functionality to
// do console streaming
#include <iostream>
using std::cout;
using std::endl;

// Include the functionality to use some of the 
// Standard Template Library containers
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;

#include <set>
using std::set;


// Create a C-style function to 
// take in a pointer as a parameter
// Here both the pointer and the char array
// that it points to are set to const,
// to indicate that they will not be altered
// in the function
// 
// The reason I do all of this is so that you know how to 
// interface with the C code that's still used in many
// 3rd-party libraries like OpenGL
void p(const char* const src, const size_t array_size)
{
	// First check to see that the pointer is valid
	if (src == 0)
		return;

	for(size_t i = 0; i < array_size; i++)
		cout << static_cast<int>(src[i]) << endl;
}



int main(void)
{
	vector<char> c(5);

	// Use the [] operator to set the contents of char_array
	for (size_t i = 0; i < c.size(); i++)
		c[i] = static_cast<char>(i);

	// Get the address of the array's first element
	// and pass that in as a pointer
	p(&c[0], c.size());



	// Get the address of the string's first element
	// and pass that in as a pointer
	string s = "The fox";
	p(s.c_str(), s.size());

	s[0] = 't';

	cout << s << endl;



	// Use a const_iterator instead of the [] operator
	// We introduce this because some of the containers in 
	// the Standard Template Library do not overload
	// the [] operator, like with set, for example
	for (vector<char>::const_iterator ci = c.begin(); ci != c.end(); ci++)
		cout << *ci;

	cout << endl;

	for (string::const_iterator ci = s.begin(); ci != s.end(); ci++)
		cout << *ci;

	cout << endl;

	// Use a variable iterator to alter the elements
	for (vector<char>::iterator i = c.begin(); i != c.end(); i++)
		*i = (*i) + 2;

	for (vector<char>::const_iterator ci = c.begin(); ci != c.end(); ci++)
		cout << *ci;

	cout << endl;



	// Use an ordered map
	map<size_t, char> m;

	// Add elements to the map
	// The key is a size_t, and the value is a char
	// This is similar to the dictionary object in
	// a lot of other programming languages
	m[12345] = 'c';
	m[50000] = 'a';
	m[1] = 't';

	// Print elements in order
	for (map<size_t, char>::const_iterator ci = m.begin(); ci != m.end(); ci++)
		cout << ci->first << " -> " << ci->second << endl;

	cout << endl;



	// Use an ordered set
	set<char> s2;

	// Add elements to the set
	s2.insert('c');
	s2.insert('a');
	s2.insert('t');

	// Note that when the element is already in the set,
	// the duplicate is not added
	s2.insert('t');

	// Print elements in order
	for (set<char>::const_iterator ci = s2.begin(); ci != s2.end(); ci++)
		cout << *ci << endl;



	// Disclaimer: the auto keyword can make the syntax more readable,
	// but it can be easily abused
	for (auto ci = s2.begin(); ci != s2.end(); ci++)
		cout << *ci << endl;

	// Hardcore auto usage, where nothing is explicit
	for (auto i : s2)
		cout << i << endl;

	// This is just ridiculous...
	auto z = 0;
	auto y = 12345;
	auto x = 0.0f;
	auto w = 1.05;
	auto v = 1e30;
	auto u = 0;



	return 0;
}