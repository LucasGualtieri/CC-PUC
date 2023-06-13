#include <stdio.h>

int main(void) {
	int p, d1, d2;

	scanf("%d", &p);
	scanf("%d", &d1);
	scanf("%d", &d2);

	if ((d1 + d2) % 2 == 0) {
		p ? printf("1") : printf("0");
	} else {
		!p ? printf("1") : printf("0");
	}
	return 0;
}