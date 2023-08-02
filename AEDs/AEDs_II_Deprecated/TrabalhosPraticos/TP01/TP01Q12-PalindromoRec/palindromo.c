#include <biblioteca_c.h>

// clear && gcc palindromo.c -o palindromo && ./palindromo < pub.in > out.txt

bool CaractereEspecial(char c) {
	return !(isalpha(c) || c == ' ' || c == '-' || c >= '0' && c <= '9');
}

bool isPalindromo(char* string, int comeco, int fim) {
	if (comeco >= fim) {
		return true;
	}

	if (CaractereEspecial(string[comeco])) {
		if (string[comeco] != string[fim - 1]) {
			return false;
		} else if (string[comeco + 1] != string[fim]) {
			return false;
		} else {
			return isPalindromo(string, comeco + 2, fim - 2);
		}
	} else {
		if (string[comeco] != string[fim]) {
			return false;
		}
	}

	return isPalindromo(string, ++comeco, --fim);
}

int main() {

	char* string = getstr(0);

	while (strcmp(string, "FIM")) {
		if (isPalindromo(string, 0, strlen(string) - 1)) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
		strcopy(&string, getstr(0));
	}

	return 0;
}