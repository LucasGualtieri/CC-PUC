#ifndef TIME_ELAPSED_H
#define TIME_ELAPSED_H

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono;

class Timer {
	high_resolution_clock::time_point beginning;
	high_resolution_clock::time_point end;
	bool running;

public:
	Timer() { }

	void start() {
		beginning = high_resolution_clock::now();
		running = true;
	}

	void stop() {
		end = high_resolution_clock::now();
		running = false;
	}

	// int result() {
	// 	duration<double> duration = end - beginning;
	// 	return static_cast<int>(duration.count() * 1000);
	// }

	double result() {
		if (running) stop();
		// duration<double, std::milli> duration = end - beginning;
		duration<double> duration = end - beginning;
		return duration.count();
	}

	friend std::ostream& operator<<(std::ostream& os, Timer& timer) {
		os << timer.result();
		return os;
	}

};

#endif