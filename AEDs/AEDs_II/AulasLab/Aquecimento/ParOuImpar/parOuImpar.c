#include <stdio.h>

int main() {
	int value;

	scanf("%d%*c", &value);
	printf("%s", !(value % 2) ? "par" : "impar");

	return 0;
}