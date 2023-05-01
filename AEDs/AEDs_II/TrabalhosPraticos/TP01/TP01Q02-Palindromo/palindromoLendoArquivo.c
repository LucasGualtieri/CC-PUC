#include <biblioteca_c.h>

// clear && gcc palindromoLendoArquivo.c -lm -I /home/lucas/CC-PUC/Bibliotecas -o palindromoLendoArquivo.exe && ./palindromoLendoArquivo.exe > out.txt

int CaractereEspecial(char c) {
	return !(isalpha(c) || c == ' ' || c == '-' || c >= '0' && c <= '9');
}

bool isPalindromo(char* string) {
	for (int i = 0, j = strlen(string) - 1; i < j; i++, j--) {
		if (CaractereEspecial(string[i])) {
			if (string[i] != string[j - 1]) {
				return false;
			} else {
				i++, j--;
			}
		} else {
			if (string[i] != string[j]) return false;
		}
	}
	return true;
}

int main() {

	FILE* pubIn = fopen("pub.in", "r");
	String string;
	strcopy(&string, getstr(pubIn));

	while (strcmp(string, "FIM")) {
		printf("%s\n", isPalindromo(string) ? "SIM" : "NAO");
		strcopy(&string, getstr(pubIn));
	}

	return 0;
}