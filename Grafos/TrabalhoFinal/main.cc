#include <iostream>

#include "../DataStructures/utils/Pair.hpp"
#include "../DataStructures/include/list/linearList.hpp"

using namespace std;

LinearList<Pair<int, int>> getNeighbors(int i, int j) {
	return {
		{i - 1, j - 1},
		{i - 1, j},
		{i - 1, j + 1},
		{i, j - 1},
		{i, j + 1},
		{i + 1, j - 1},
		{i + 1, j},
		{i + 1, j + 1},
	};
}

// TODO:
float dissimilarity(Pair<int, int> p1, Pair<int, int> p2) {
	return 1;
}	

void foo(/*Graph G, Matrix<Pixel> m*/) {

	// Vertex v = 0;
	int v = 0;

	// for (int i = 0; i < m.width; i++) {
	// 	for (int j = 0; j < m.height; j++) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			// visited.insert({i, j});

			for (auto& [x, y] : getNeighbors(i, j)) {

				// NOTE: Como o grafo é não direcionado, uma vez que a gente insere uma aresta não precisamos inserir de novo
				// Ainda nao sei exatamente como evitar essas repeticoes, talves nao tenha como, talvez eu consiga usar alguma hash
				// talvez nao tenha pra q, talvez seja bem rapido
				// if (!m.inBounds(x, y)) continue;

				// visited.insert({x, y});

				// float weight = dissimilarity({i, j}, {x, y});

				// NOTE: Eu nao sei o que fazer com esse neigbhor ai, pq se eu estou incrementando o v toda vez
				// na segunda iteracao eu preciso que o ponto {0, 1} ja tenha uma aresta pra {0, 0} (da primeira iteracao)
				// NOTE: The following doest seem to make any sense
				// G.addEdge(v, i + j, weight);
				// cout << "v: " << v << ", x + y + 1: " << x + y + 1 << endl;
			}

			v++;
		}
	}
}

int main() {

	foo();

	return 0;
}
