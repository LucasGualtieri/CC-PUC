#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"
#include "../../../PAA-TP01/DataStructures/include/graph/Graph.hpp"
#include "../../../PAA-TP01/DataStructures/include/queue/maxHeap.hpp"

using namespace std;

LinearList<int> constructPath(Vertex source, Vertex target, const LinearList<int>& predecessors) {

	LinearList<int> path;

	if (predecessors[target] != -1) {
		while (target != -1) {
			path.push_front(target);
			target = predecessors[target];
		}
	}

	return path;
}

LinearList<int> maxMinPath(Vertex source, Vertex target, const Graph& G) {

	size_t n = G.n;

	LinearList<int> predecessors(n, -1);
	MaxHeap<int, float> Q(n, -INFINITY);
	LinearList<float> nodeCapacity(n, -INFINITY);

	nodeCapacity[source] = INFINITY;

	while (!Q.empty()) {

		Vertex u = Q.pop().first;

		if (u == target) break;

		for (auto [v, capacity] : G.edgesOf(u)) {

			float newCapacity = min(nodeCapacity[u], capacity);

			if (nodeCapacity[v] < newCapacity) {
				predecessors[v] = u;
				nodeCapacity[v] = newCapacity;
				Q.decreaseKey({v, nodeCapacity[v]});
			}
		}
	}

	return constructPath(source, target, predecessors);
}
