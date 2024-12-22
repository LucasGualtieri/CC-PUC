#include <iostream>
#include <cmath>
#include <tuple>

#include "../utils.hpp"
#include "../imageToMatrix.hpp"
#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"
#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"

// clear && g++ main.cc -std=c++20 && ./a.out

using namespace std;

using Cut = pair<LinearList<Vertex>, LinearList<Vertex>>;

tuple<Graph, Vertex, Vertex> createGraph(const Matrix<Pixel>& image, bool eightConnected = false) {

	Graph G = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
		.directed()
		.weighted()
	.build();

	int n = image.height * image.width;

	const Vertex source = n + 1, sink = n + 2;

	G.addVertex(source);
	G.addVertex(sink);

	for (Vertex v = 0; v < n; v++) {
		G.addVertex(v);
	}

	for (int i = 0; i < image.height; i++) {

		for (int j = 0; j < image.width; j++) {

			Vertex u = i * image.width + j;

			for (auto& [x, y] : getNeighbors(i, j, image, eightConnected)) {

				float weight = dissimilarity(image[i][j], image[x][y]);

				Vertex v = x * image.width + y;

				G.addEdge(u, v, weight);
				G.addEdge(v, u, weight);
			}
		}
	}

	for (Vertex v : G.vertices()) {

		float foregroundProb = rand();
		float backgroundProb = rand();

		G.addEdge(source, v, backgroundProb);
		G.addEdge(v, sink, foregroundProb);
	}

	return { G, source, sink };
}

pair<float, Cut> boykovKolmogorovMinCut(Vertex source, Vertex sink, const Graph& G) {

	LinearList<int> parent(G.n, -1);
	LinearList<bool> inTree(G.n, false);
	LinkedQueue<Vertex> active = { source };

	inTree[source] = true;

	while (!active.empty()) {

		Vertex cur = active.pop();
		active.pop();

		for (auto [next, cap] : G.neighbors(cur)) {

			if (!inTree[next] && cap > 0) {

				parent[next] = cur;
				inTree[next] = true;

				if (next == sink) {

					float bottleneck = INFINITY;
					Vertex vertex = sink;

					while (vertex != source) {

						int prev = parent[vertex];

						for (auto [n, c] : G.neighbors(prev)) {

							if (n == vertex) {
								bottleneck = min(bottleneck, c);
								break;
							}
						}

						vertex = prev;
					}

					vertex = sink;

					while (vertex != source) {

						int prev = parent[vertex];

						for (auto [n, c] : G.neighbors(prev)){
							if (n == vertex) {
								c -= bottleneck;
								break;
							}
						}

						for (auto [n, c] : G.neighbors(vertex)) {
							if (n == prev) {
								c += bottleneck;
								break;
							}
						}

						vertex = prev;
					}

					fill(parent.begin(), parent.end(), -1);
					fill(inTree.begin(), inTree.end(), false);

					active = LinkedQueue<int>(); // Limpa fila
					active.push(source);
					inTree[source] = true;

					break;
				}

				active.push(next);
			}
		}
	}

	// Identificar o corte mínimo
	LinkedQueue<Vertex> q = {source};
	LinearList<bool> visited(G.n, false);
	visited[source] = true;

	while (!q.empty()) {

		Vertex cur = q.pop();

		for (auto [next, cap] : G.neighbors(cur)) {

			if (!visited[next] && cap > 0) {
				visited[next] = true;
				q.push(next);
			}
		}
	}

	Cut minCut;

	for (Vertex v : G.vertices()) {

		if (visited[v]) minCut.first += v;
		else minCut.second += v;
	}

	float maxFlow = 0;

	for (auto [next, cap] : G.neighbors(source)) {
		maxFlow += cap;
	}

	return { maxFlow, minCut };
}

int main() {

	Matrix<Pixel> image = loadPPM("inputImages/paper", .8);

	auto [G, source, sink] = createGraph(image, true);

	auto [maxFlow, minCut] = boykovKolmogorovMinCut(source, sink, G);

	cout << "Background size: " << minCut.first.size() << endl;
	cout << "Foreground size: " << minCut.second.size() << endl;

	// saveSegmentedImage("outputImages/paper", minCut, image);

	return 0;
}

