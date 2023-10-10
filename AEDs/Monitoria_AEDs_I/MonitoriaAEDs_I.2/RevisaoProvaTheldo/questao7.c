#include <stdio.h>
#include <string.h>

int main() {
    char string[80] = "";
    while (!strcmp(string, "PARAR")) {
        scanf("%s", string);
	int len = strlen(string);
        for (int i = 0; i < len; i++) {
            if (string[i] == '-') {
	        printf("É composta");
                i = len;
            } else if (i == len - 1) {
                printf("Não é composta");
            }
        }
    }
}