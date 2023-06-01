#ifndef TIME_ELAPSED_H
#define TIME_ELAPSED_H

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono;

class Timer {
	high_resolution_clock::time_point beginning;
	high_resolution_clock::time_point end;

public:
	Timer() { }

	void start() {
		beginning = high_resolution_clock::now();
	}

	void stop() {
		end = high_resolution_clock::now();
	}

	// int elapsed() {
	// 	duration<double> duration = end - beginning;
	// 	return static_cast<int>(duration.count() * 1000);
	// }

	double elapsed() {
		duration<double, milli> duration = end - beginning;
		return duration.count();
	}
};

#endif