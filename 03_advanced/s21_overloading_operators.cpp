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



class vertex_3
{
public:

	float x, y, z;

	// Some constructors
	vertex_3(void) : x(0.0f), y(0.0f), z(0.0f) { /*default constructor*/ }
	vertex_3(const float src_x, const float src_y, const float src_z) : x(src_x), y(src_y), z(src_z) { /* custom constructor */ }

	inline const vertex_3& cross(const vertex_3& right) const
	{
		static vertex_3 temp;

		temp.x = y * right.z - z * right.y;
		temp.y = z * right.x - x * right.z;
		temp.z = x * right.y - y * right.x;

		return temp;
	}
};



// Overload the less-than operator
// This less-than operator is used to sort
// the elements of containers, such as map and set
bool operator<(const vertex_3 &lhs, const vertex_3 &rhs)
{
	if (rhs.x > lhs.x)
		return true;
	else if (rhs.x < lhs.x)
		return false;

	if (rhs.y > lhs.y)
		return true;
	else if (rhs.y < lhs.y)
		return false;

	if (rhs.z > lhs.z)
		return true;
	else if (rhs.z < lhs.z)
		return false;

	return false;
}

// Overload the multiplication operator
// A vector times a scalar is not allowed
// so we convert the scalar to a vector
// and perform the cross product
vertex_3 operator*(const vertex_3 &lhs, const float rhs)
{
	return lhs.cross(vertex_3(rhs, 0, 0));
}

// Overload the multiplication operator again
// A scalar times a vector is allowed
vertex_3 operator*(const float lhs, const vertex_3& rhs)
{
	static vertex_3 temp;

	temp.x = lhs * rhs.x;
	temp.y = lhs * rhs.y;
	temp.z = lhs * rhs.z;

	return temp;
}



int main(void)
{
	// Use an ordered set
	// Essentially, a set gives you a sorted container of distinct data,
	// For instance, this is handy for welding vertices in a triangle mesh
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



	// Use the overloaded multiplication operators
	// This can only be achieved by moving the 
	// operators to outside of the class body, like
	// we have done above
	vertex_3 v(1, 2, 3);

	vertex_3 two_times_v = 2.0f * v;
	vertex_3 v_times_two = v * 2.0f;
	
	cout << two_times_v.x << ' ' << two_times_v.y << ' ' << two_times_v.z << endl;
	cout << v_times_two.x << ' ' << v_times_two.y << ' ' << v_times_two.z << endl;

	return 0;
}