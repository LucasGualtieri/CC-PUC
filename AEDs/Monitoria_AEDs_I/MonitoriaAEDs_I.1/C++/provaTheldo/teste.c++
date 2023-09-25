#include <biblioteca_cpp.h>

int main() {
	int n = 2, d = 3;

	string aux;

	aux += to_string(n);
	aux += '/';
	aux += to_string(d);

	cout << aux << endl;

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}