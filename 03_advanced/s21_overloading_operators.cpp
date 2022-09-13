// Q: How do I use custom data types in 
//    conjunction with map or set?

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;

#include <set>
using std::set;


// 3D vertex with overloaded less-than operator
// This less-than operator is used to sort the
// elements of map and set, for instance
class vertex_3
{
public:

	float x, y, z;

	// Some constructors
	vertex_3(void) : x(0.0f), y(0.0f), z(0.0f) { /*default constructor*/ }
	vertex_3(const float src_x, const float src_y, const float src_z) : x(src_x), y(src_y), z(src_z) { /* custom constructor */ }

	// Overload the less-than operator
	// The last const in this definition lets the compiler and the coder
	// know that no variables are altered within the body of the operator
	bool operator<(const vertex_3& right) const
	{
		if (right.x > x)
			return true;
		else if (right.x < x)
			return false;

		if (right.y > y)
			return true;
		else if (right.y < y)
			return false;

		if (right.z > z)
			return true;
		else if (right.z < z)
			return false;

		return false;
	}
};



// One may also overload the operator outside of the class
//bool operator<(const vertex_3 &lhs, const vertex_3 &rhs)
//{
//	if (rhs.x > lhs.x)
//		return true;
//	else if (rhs.x < lhs.x)
//		return false;
//
//	if (rhs.y > lhs.y)
//		return true;
//	else if (rhs.y < lhs.y)
//		return false;
//
//	if (rhs.z > lhs.z)
//		return true;
//	else if (rhs.z < lhs.	z)
//		return false;
//
//	return false;
//}



int main(void)
{
	// Use an ordered set
	set<vertex_3> s;

	s.insert(vertex_3(1, 2, 3));
	s.insert(vertex_3(4, 5, 6));
	s.insert(vertex_3(10, 2, 9));
	s.insert(vertex_3(10, 2, 5));

	// NOTE: when the element is already in the set,
	//       the duplicate is not added
	s.insert(vertex_3(10, 2, 5));

	// Print elements in order
	for (set<vertex_3>::const_iterator ci = s.begin(); ci != s.end(); ci++)
		cout << ci->x << " " << ci->y << " " << ci->z << endl;

	// Essentially, a set gives you a sorted container of distinct data,
	// For instance, this is handy for welding vertices in a triangle mesh

	return 0;
}