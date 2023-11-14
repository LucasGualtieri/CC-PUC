class Questao3 {
	int[] ordenaVetor(int[] vetA, int[] vetB) {
		int M = vetA.length, N = vetB.length;
		int i = M - 1, j = N - 1;
		int TAM = 0;
		int[] vetC = new int[M + N];
	
		while (i >= 0 || j >= 0) {
			if (i >= 0 && j >= 0) {
				vetC[TAM++] = vetA[i] < vetB[j] ? vetA[i--] : vetB[j--];
			} else {
				vetC[TAM++] = i >= 0 ? vetA[i--] : vetB[j--];
			}
		}
	
		return vetC;
	}
}