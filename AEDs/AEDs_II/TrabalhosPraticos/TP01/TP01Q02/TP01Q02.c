#include "/home/lucas/PC-HOME/CC-PUC/AEDs/AEDs_II/TrabalhosPraticos/Lib.h"

// clear && gcc TP01Q02.c -o TP01Q02 && ./TP01Q02 < pub.in > result.txt

#define isSpecialChar(c) !(isalnum(c) || c == ' ' || c == '-')

bool isPalindromo(String str) {

	int left = -1, right = strlen(str);

	while (++left <= --right) {
		if (!isSpecialChar(str[left]) || !isSpecialChar(str[right])) {
			if (str[left] != str[right]) return false;
		}
	}

	return true;
}

int main() {
	char str[STR_MAX_LEN];
	while (!equals(readstr(str), "FIM")) {
		printf("%s\n", isPalindromo(str) ? "SIM" : "NAO");
	}
}