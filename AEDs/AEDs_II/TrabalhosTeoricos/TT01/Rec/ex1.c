#include <stdio.h>

int multRec(int x, int y) {
	return y > 1 ? x + multRec(x, y - 1) : x;
}

int main() {
	int x = 3, y = 3;
	printf("%d\n", multRec(x, y));

	return 0;
}