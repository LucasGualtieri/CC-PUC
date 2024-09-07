#include <iostream>

using namespace std;

int main() {

	for (int i = 0; i < 100; i++) {
		// if (i % 2 == 1) {
		// 	cout << "i: " << i << endl;
		// 	cout << "i * 2: " << i * 2 << endl;
		// 	cout << "------------------" << endl;
		// }
		// int n = i * 4;
		// cout << n << endl;
		// cout << (n * n - n) / 2 << endl;
		// cout << "------------------" << endl;
		// if (i % 2 == 0 && (i / 2) % 2 == 0) {
		// 	cout << "i: " << i << endl;
		// 	cout << i / 2 << endl;
		// 	cout << "------------------" << endl;
		// }
		// cout << 4 * i + 2 << endl;
		// cout << (4 * i + 2) / 2 << endl;
		// cout << "------------------" << endl;
		if ((i * i - i) % 4 == 0) {
			cout << "i: " << i << endl;
		}
	}
}