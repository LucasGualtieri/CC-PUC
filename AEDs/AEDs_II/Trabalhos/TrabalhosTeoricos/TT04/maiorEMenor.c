#include <stdio.h>

int main() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int n = (int)(sizeof(array) / sizeof(array[0]));
	int element;
	int maior = array[0], menor = maior;

	int comps1 = 0, comps2 = 0;
	
	for (int i = 1; i < n; i++) {
		element = array[i];
		comps1 += 2;
		comps2++;
		if (element > maior) maior = element;
		else if (element < menor) menor = element;
	}
	
	printf("O maior valor é: %d\n", maior);
	printf("O menor valor é: %d\n", menor);
	printf("O número total de comparações foi: %d\n", comps1);
	printf("O número total de comparações roubadas foi: %d\n", comps2);

}
