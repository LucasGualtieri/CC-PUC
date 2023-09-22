#include <biblioteca_c.h>

int main() {

	char buffer[30];

	FILE* file = fopen("teste.txt", "r"); // w = write

	fscanf(file, "%s", buffer); // "%s" para no espaço [%^\n]

	fgets(buffer, 30, file);

	printf("buffer: '%s'\n", buffer);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}