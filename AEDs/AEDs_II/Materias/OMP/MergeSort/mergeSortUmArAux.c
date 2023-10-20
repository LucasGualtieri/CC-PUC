#include <stdio.h>
#include "../AuxLibs/IntArray.h"

// clear && gcc mergeSortMelhorado.c && ./a.out

void MergeSort(IntArray array);

void MergeSortRec(int left, int right, int* array);

void Merge(int left, int mid, int right, int* array);

void main() {

	IntArray array = newIntArray(8);
	
	IntArrayFillRand(0, 50, array);
	// array.FillRand(0, 50, array);
	IntArrayPrint(array);
	// array.Print(array);

	MergeSort(array);
	IntArrayPrint(array);

}

void MergeSort(IntArray array) {
	MergeSortRec(0, array.size - 1, array.array);
}

void MergeSortRec(int left, int right, int* array) {
	if (left < right){
		int mid = (left + right) / 2;
		MergeSortRec(left, mid, array);
		MergeSortRec(mid + 1, right, array);
		Merge(left, right, array);
	}
}

void Merge(int left, int mid, int right, int* array) {
	// int auxSize = (right - left) + 1, mid = ((auxSize + 1) / 2);

	// Lib.Jogador[] array = lista.array;
	// Lib.Jogador[] auxArray = new Lib.Jogador[auxSize];

	// for (int i = 0; i < auxSize; i++) auxArray[i] = array[left + i];
	// log.incrementarMovimentacoes(auxSize);

	// for (int i = 0, j = mid; left <= right; left++) {
	// 	if (i < mid && j < auxSize) {
	// 		boolean comp = lista.CompareToStr(auxArray[i], auxArray[j], log);
	// 		array[left] = comp ? auxArray[i++] : auxArray[j++];
	// 	} else {
	// 		array[left] = i < mid ? auxArray[i++] : auxArray[j++];
	// 	}
	// 	log.incrementarMovimentacoes();
	// }
}