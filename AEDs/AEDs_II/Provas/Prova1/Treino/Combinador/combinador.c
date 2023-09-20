#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// clear && gcc combinador.c -o combinador && ./combinador < pub.in > result.txt

#define STR_MAX_LEN 100 + 1

int main() {

	char str1[STR_MAX_LEN];
	char str2[STR_MAX_LEN];

	while (scanf("%s%s", str1, str2) != EOF) {
		
		int str1Len = strlen(str1);
		int str2Len = strlen(str2);

		int cursorStr1 = 0;
		int cursorStr2 = 0;

		char resultado[STR_MAX_LEN];

		int i = 0;
		while (i < str1Len + str2Len) {
			if (cursorStr1 < str1Len) {
				resultado[i++] = str1[cursorStr1++];
			}
			if (cursorStr2 < str2Len) {
				resultado[i++] = str2[cursorStr2++];
			}
		}
		resultado[i] = 0;

		printf("%s\n", resultado);
	}
}