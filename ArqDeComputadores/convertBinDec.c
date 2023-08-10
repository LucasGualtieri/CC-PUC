#include <stdio.h>
#include <math.h>
#include <string.h>

int ctoi(char c) {
    return c - 48;
}

int convert(char* BIN) {
    int sum = 0, len = strlen(BIN);
    for (int i = 0; i < len; i++) {
        sum += ctoi(BIN[i]) * pow(2, len - 1 - i);
    }
    return sum;
}

int main() {

    char BIN[] = "1110";
    printf("%d", convert(BIN));

}