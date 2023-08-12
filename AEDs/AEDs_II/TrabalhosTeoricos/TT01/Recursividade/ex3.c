#include <stdio.h>

int multRec(int x, int y) {
	return y > 1 ? x + multRec(x, y - 1) : x;
}

int main() {
	printf("%d\n", multRec(5, 13));
	return 0;
}