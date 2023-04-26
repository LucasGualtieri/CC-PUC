#include <stdio.h>

int main(void) {
	int d1, d2, par;

	scanf("%d", &par);
	scanf("%d", &d1);
	scanf("%d", &d2);

	if ((d1 + d2) % 2 == 0) {
		par ? printf("1") : printf("0");
	} else {
		!par ? printf("1") : printf("0");
	}
	return 0;
}