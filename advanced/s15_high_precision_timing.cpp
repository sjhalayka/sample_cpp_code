// Q: How do I use high-precision timing,
//    in order to time the performance of
//    a chunk of code?


#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <chrono>
using std::chrono::high_resolution_clock;



void f(vector<float>& v)
{
	for (size_t i = 0; i < v.size(); i++)
		v[i] *= 2.0f;
}



int main(void)
{
	// Begin high-precision timing
	high_resolution_clock::time_point start_time = high_resolution_clock::now();

	// Do a bunch of calls to a function
	for (size_t i = 0; i < 10000000; i++)
	{
		vector<float> vfloat { 1.0f, 3.14f, 5.0f};
		f(vfloat);
	}

	// End high-precision timing
	high_resolution_clock::time_point end_time = high_resolution_clock::now();
	std::chrono::duration<float, std::milli> elapsed = end_time - start_time;
	cout << "Took " << elapsed.count() / 1000.0f << " seconds" << endl;

	return 0;
}