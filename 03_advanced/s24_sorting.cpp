// Q: How do I use classes in conjunction 
// with the C++ algorithm library, for 
// instance sort()?

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <random>
using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

#include <chrono>
using std::chrono::high_resolution_clock;

#include <algorithm>
using std::sort;



class A
{
public:
	float x = 0, y = 0;

	// Less-than operator must be overloaded
	// for sort() to work
	bool operator<(const A& right) const
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

	bool operator==(const A& right) const
	{
		if (right.x == x && right.y == y)
			return true;

		return false;
	}
};



// A relatively slow sorting method
template<typename T>
void counting_sort(const vector<T>& input_data, vector<T>& output_data)
{
	map<T, size_t> m;

	for (size_t i = 0; i < input_data.size(); i++)
		m[input_data[i]]++;

	output_data.resize(input_data.size());

	size_t index = 0;

	for (auto const ci : m)
		for (size_t i = 0; i < ci.second; i++)
			output_data[index++] = ci.first;
}



int main(void)
{
	// Generate some random data
	mt19937 generator(123456789);
	uniform_real_distribution<float> distribution(0, 1);
    // uniform_int_distribution<size_t> distribution(0, 100);

	const size_t num_elements = 1000000;

	vector<A> input_data(num_elements);

	for (size_t i = 0; i < num_elements; i++)
	{
		A a;
		a.x = distribution(generator);
		a.y = distribution(generator);

		input_data[i] = a;
	}



	vector<A> output_data;

	// Use the counting sort method
	high_resolution_clock::time_point start_time = high_resolution_clock::now();

	counting_sort<A>(input_data, output_data);

	high_resolution_clock::time_point end_time = high_resolution_clock::now();
	std::chrono::duration<float, std::milli> elapsed = end_time - start_time;
	cout << "Took " << elapsed.count() / 1000.0f << " seconds" << endl;



	// Use the standard sort function
	vector<A> input_data2 = input_data;

	start_time = high_resolution_clock::now();

	sort(input_data2.begin(), input_data2.end());

	end_time = high_resolution_clock::now();
	elapsed = end_time - start_time;
	cout << "Took " << elapsed.count() / 1000.0f << " seconds" << endl;



	// Make sure that the sorted vectors are equal
	cout << (input_data2 == output_data) << endl;

	return 0;
}