#include <biblioteca_c.h>

// clear && gcc TP01Q02.c -lm -I /home/lucas/CC-PUC/Bibliotecas -o TP01Q02.exe && ./TP01Q02.exe < pub.in > out.txt

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

	String string = getstr(0);

	while (strcmp(string, "FIM")) {
		printf("%s\n", isPalindromo(string) ? "SIM" : "NAO");
		strcopy(&string, getstr(0));
	}

	return 0;
}
