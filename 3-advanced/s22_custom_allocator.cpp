// Q: How do I use a custom allocator
//    to perform manual memory management?

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <map>
using std::map;

#include <string>
using std::basic_string;
using std::char_traits;

#include <memory>
using std::malloc;
using std::free;



class vertex_2
{
public:
	float x, y;

	vertex_2(void) : x(0.0f), y(0.0f) { }
	vertex_2(const float src_x, const float src_y) : x(src_x), y(src_y) { }
	vertex_2(const vertex_2& src) : x(src.x), y(src.y) { }

	// Required by the set<> and map<> container
	bool operator<(const vertex_2& right) const
	{
		if (right.x > x)
			return true;
		else if (right.x < x)
			return false;

		if (right.y > y)
			return true;
		else if (right.y < y)
			return false;

		return false;
	}

	// Required by the set<> container
	bool operator() (const vertex_2& a, const vertex_2& b) const
	{
		return a < b;
	}
};




// Spy on the memory management system
// by using a custom allocator
template <typename T>
class custom_allocator
{
public:

	// This must be stated, or the entire
	// code breaks down
	typedef T value_type;

	// NOTE: As pointed out by a fellow coder, we could possibly
	//       use memory obtained from RAM, or from over a network
	//       socket, or from disk, or whatever suits the task at hand

	T* allocate(const size_t count)
	{
		cout << "Allocating " << count << " " << typeid(T).name() << " elements -- " << sizeof(T) * count << " byte(s) of memory" << endl;

		// Use memory management functionality to obtain memory from RAM
		// Use malloc(), to avoid wasting time constructing the objects,
		// because that is not absolutely necessary
		T* p = reinterpret_cast<T*>(malloc(count * sizeof(T)));

		// Something went horribly wrong
		if (p == nullptr)
			cout << "Allocation failure" << endl;

		return p;
	}

	void deallocate(T* p, const size_t count)
	{
		cout << "Deallocating " << count << " " << typeid(T).name() << " elements -- " << sizeof(T) * count << " byte(s) of memory" << endl;

		// Use memory management functions to release memory from RAM
		if (p != nullptr)
			free(p);
	}
};



int main(void)
{
	// Try it out on a vector<char>
	vector<char, custom_allocator<char>> vc;

	vc.push_back('c');
	vc.push_back('a');
	vc.push_back('t');

	for (vector<char, custom_allocator<char>>::const_iterator ci = vc.begin(); ci != vc.end(); ci++)
		cout << *ci << endl;



	// Try it out on a set<vertex_2>
	// First template parameter refers to the operator<
	// Second template parameter refers to the operator()
	set<vertex_2, vertex_2, custom_allocator<vertex_2>> sv;

	sv.insert(vertex_2(1, 5));
	sv.insert(vertex_2(1, 2));
	sv.insert(vertex_2(10, 5));

	for (set<vertex_2, vertex_2, custom_allocator<vertex_2>>::const_iterator ci = sv.begin(); ci != sv.end(); ci++)
		cout << ci->x << " " << ci->y << endl;



	// Try it out on a map<vertex_2, size_t>
	// Third template parameter refers to the operator<
	map<vertex_2, size_t, vertex_2, custom_allocator<vertex_2>> mv;

	mv[vertex_2(4, 5)] = 1;
	mv[vertex_2(6, 2)] = 99;
	mv[vertex_2(1, 3)] = 3;

	for (map <vertex_2, size_t, vertex_2, custom_allocator<vertex_2>>::const_iterator ci = mv.begin(); ci != mv.end(); ci++)
		cout << ci->first.x << " " << ci->first.y << " -> " << ci->second << endl;



	// Try it out on a basic_string<char>
	basic_string<char, char_traits<char>, custom_allocator<char>> s;

	s = "cat ";
	s += "dog ";
	s += "bird ";
	s += "fish";

	cout << s << endl;

	return 0;
}