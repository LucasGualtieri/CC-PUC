#include "/home/lucas/AEDsII/Bibliotecas/biblioteca_c.h"

// clear && gcc palindromo.c -o palindromo && ./palindromo < pub.in > out.txt

int CaractereEspecial(char c) {
	return !(isalpha(c) || c == ' ' || c == '-' || c >= '0' && c <= '9');
}

bool isPalindromo(char* string) {
	for (int i = 0, j = strlen(string) - 1; i < j; i++, j--) {
		if (CaractereEspecial(string[i])) {
			if (string[i] != string[j - 1] && string[i + 1] != string[j]) {
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

	char* string = getstr();

	while (strcmp(string, "FIM")) {
		printf("%s\n", isPalindromo(string) ? "SIM" : "NAO");
		string = getstr();
	}

	return 0;
}