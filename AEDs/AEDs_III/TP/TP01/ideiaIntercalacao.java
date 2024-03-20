// Essa implementação deveria supostamente (junto com as outras ideias) deveria ser capaz de lidar com segmentos de tamanho variável,
// e inclusive permite puxar do disco mais segmentos para a ram para dar continuação à intercalação.

public static void foo(int max, Queue[]<T> queueArray) {

	int min = Infinity;
	int pos = -1;

	static int max = -Infinity;

	for (int i = 0; i < queueArray.length; i++) {
		if (!queueArray[i].Empty()) {
			Key k = queueArray[i].getHead().getKey(); // Pensar em como estipular essa key pelo "parametro?"
			if (k >= max && k < min) {
				min = k;
				pos = i;
			}
		}
	}
	
	if (pos == -1) max = -Infinity; // Marca o fim da intercalação de um conjunto de segmentos

	return pos;
}

Intercalação() {
	int pos;
	File[] destinos = new File[M];
	Arrays.fill(destinos, new file("..."));

	Queue<T> queueDestino = new Queue<>(z / (2 * y));

	for (int i = 0; i < N; i++) {
		while ((pos = foo(queueArray)) != -1) {
			x = queueArray[pos].remove();
			queueDestino.push(x);	
			// Pseudo Código
			/*
			queueArray.forEach(queue -> {
				if (queue.empty()) {
					queue.importNextXBytes();
				}
			});
			*/
		}

		destinos[i % 3].push(queueDestino().toByteArray());
		queueDestino.Flush();
	}
}