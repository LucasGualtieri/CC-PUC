#include <cmath>
#include <iostream>

#include "timer.hpp"

using namespace std;

// clear && g++ IsPrime.cc -std=c++23 && ./a.out

bool IsPrime(long long n) {

	if (n == 2 || n == 3) return true;
	if (n < 2 || n % 2 == 0 || n % 3 == 0) return false;

    const long long LS = sqrt(n);

    for (long long i = 5; i <= LS; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {

	long long n = 100'000'000'000'000'000;

	int count = 1;

	Timer t;

	t.start();
	long long i = n + 1;
	while (!IsPrime(i) && !IsPrime(i + 2)) {
		count++;
		i += 6;
	}

	cout << i << "or " << i + 2 << " is prime." << endl;
	t.stop();

	cout << t << endl;

	cout << "count = " << count << endl;

	return 0;
}
