#include <iostream>

#include "GraphProof.hpp"
#include "../DataStructures/include/list/linearList.hpp"

using namespace std;

int main() {

	bool equal = true;

	LinearList<float> dijkstra, bellmanFord;

	int count = -1;

	Graph g;

	for (int i = 10; equal && i <= 1000; i += 90) {

		for (int ii = 0; equal && ii < 50; ii++) {

			cout << "i: " << i << " ii" << ": " << ii << endl;

			g = Graph::generateRandom(i, -100, 100);

			bellmanFord = g.bellmanFord(0);
			dijkstra = g.dijkstra(0);

			equal = dijkstra == bellmanFord;

			count++;
		}
	}

	if (!equal) {
		cout << "The graph number " << count << " produced different results:" << endl;
		cout << "Dijkstra: " << dijkstra << endl;
		cout << "Bellman-Ford: " << bellmanFord << endl;
		cout << g << endl;
	}

	else cout << "All randomly generated graphs produced the same outputs." << endl;

}