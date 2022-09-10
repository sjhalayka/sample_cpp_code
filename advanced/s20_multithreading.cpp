// Q: How do I use multithreading (concurrency)?
// Q: How do I use atomic and non-atomic data types
//    in conjunction with multithreading?

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <chrono>
using std::chrono::high_resolution_clock;

#include <atomic>
using std::atomic_bool;

#include <thread>
using std::thread;
using std::this_thread::get_id;

#include <mutex>
using std::mutex;



void thread_func(atomic_bool& stop, vector<string>& vs, mutex& m)
{
	high_resolution_clock::time_point start = high_resolution_clock::now();

	while (!stop)
	{
		high_resolution_clock::time_point end = high_resolution_clock::now();
		std::chrono::duration<float, std::milli> elapsed = end - start;

		// Send a signal to the main() function once every second
		if (elapsed.count() >= 1000.0)
		{
			std::thread::id this_id = get_id();
			ostringstream oss;
			oss << "  " << "Thread id: " << this_id << " hello";

			m.lock();

			vs.push_back(oss.str());

			m.unlock();
			
			start = end;
		}
	}
}


int main(void)
{
	const size_t num_threads = 10;

	// Thread parameters are as follows:

	// An atomic type is guaranteed
	// to be entirely read from or 
	// written to without being
	// interrupted
	atomic_bool stop = false;
	
	// A vector to store signals from 
	// the threads
	vector<string> vs;
	
	// Here we use a mutex for read/writing
	// non-atomic types (such as vector<>)
	mutex m;

	// Initialization
	vector<thread> threads;

	// Create the threads
	for (size_t i = 0; i < num_threads; i++)
		threads.push_back(thread(thread_func, ref(stop), ref(vs), ref(m)));

	// Receive signals from threads until eternity
	while (!stop)
	{
		m.lock();

		for (vector<string>::const_iterator ci = vs.begin(); ci != vs.end(); ci++)
			cout << *ci << endl;

		// Clear the signals now that we have used them
		vs.clear();

		m.unlock();
	}

	// Cleanup
	for (size_t i = 0; i < num_threads; i++)
		threads[i].join();

	return 0;
}