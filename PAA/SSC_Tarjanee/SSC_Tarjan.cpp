void DFS(Vertex u, LinearList<int>& disc, LinearList<int>& low, LinearList<Vertex>& parent, Matrix<bool>& bridges, const Graph& G) {

	static int time = 0;

	disc[u] = low[u] = time++;

	for (Vertex v : G.neighbors(u)) {

		if (disc[v] == -1) {

			parent[v] = u;

			DFS(v, disc, low, parent, bridges, G);

			low[u] = std::min(low[u], low[v]);

			if (low[v] > disc[u]) {
				bridges[u][v] = true;
				bridges[v][u] = true;
			}
		}

		else if (v != parent[u]) low[u] = std::min(low[u], disc[v]);
	}
}

void Tarjan(Matrix<bool>& bridges, const Graph& G) {

	LinearList<int> disc(G.n, -1);
	LinearList<int> low(G.n, -1);
	LinearList<Vertex> parent(G.n, -1);

	// Vertex x = Random(0, G.n - 1);
	Vertex x = 0;

	for (Vertex v : G.vertices()) {
		if (disc[v] == -1) {
			DFS(v, disc, low, parent, bridges, G);
		}
	}
}
