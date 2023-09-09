#include <stdio.h>
#include "IntArray.h"

// clear && gcc arrayStudy.c && ./a.out

int main() {


	IntArray array = newIntArray(5);
	array.Fill(array, EOA, 3, 5, 4, 1, 45, EOA);

	array.Print(array);

	array.Close(array);

}