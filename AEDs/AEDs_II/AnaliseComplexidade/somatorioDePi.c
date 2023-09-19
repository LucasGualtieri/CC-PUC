#include <stdio.h>
#include <math.h>

void main() {
	float Pi, i, n = 10000;
	for (i = 1, Pi = 0; i <= n; i++) {
		Pi += 4 * (pow(-1, i + 1) / (2 * i - 1));
		// if ((int)i % 2 != 0) {
		// 	Pi += 4.0 / (2.0 * i - 1);
		// } else {
		// 	Pi -= 4.0 / (2.0 * i - 1);
		// }
	}
	printf("Pi: %g\n", Pi);
}