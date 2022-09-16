// Q: How do I use the pseudorandom number
//    generation capabilities of C++?
// Q: How do I generate a truly random number?
// Q: How do I use the complex class and
//    its related functionality?

#include <iostream>
using std::cout;
using std::endl;

#include <complex>
using std::complex;

#include <random>
using std::mt19937;
using std::uniform_real_distribution;
using std::uniform_int_distribution;
using std::random_device;



int main(void)
{
	// Here we use the Mersenne Twister algorithm
	// for generating pseudorandom numbers
	//mt19937 generator(123456789);

	// Here we use a truly random number generator,
	// if available
	random_device generator;

	// Define the distribution
	uniform_real_distribution<float> distribution(0, 1);

	const size_t total = 10000000;
	size_t within_radius = 0;

	// Use a Monte Carlo method to approximate pi
	for (size_t i = 0; i < total; i++)
	{
		// Get pseudorandom location (hence the name Monte Carlo)
		complex<float> c(distribution(generator), distribution(generator));

		if (abs(c) < 1)
			within_radius++;
	}

	cout << "pi is approximated as: " << 4.0f * static_cast<float>(within_radius) / static_cast<float>(total) << endl;
	cout << "pi is actually:        " << 4.0f * atanf(1.0f) << endl;

	return 0;
}