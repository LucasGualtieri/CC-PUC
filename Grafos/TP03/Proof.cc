#include <iostream>

#include "GraphProof.hpp"
#include "../DataStructures/include/list/linearList.hpp"

using namespace std;

int main() {

	bool equal = true;

	LinearList<float> dijkstra, bellmanFord;

	int count = -1;

	for (int i = 10; equal && i <= 500; i += 90) {

		for (int ii = 0; equal && ii < 50; ii++) {

			cout << "i: " << i << " ii" << ": " << ii << endl;

			Graph g = Graph::generateRandom(i, -100, 100);

			bellmanFord = g.bellmanFord(0);
			dijkstra = g.dijkstra(0);

			// cout << g << endl;

			equal = dijkstra == bellmanFord;

			count++;
		}
	}

	if (!equal) {
		cout << "The graph number" << count << "produced different results:" << endl;
		cout << "Dijkstra: " << dijkstra << endl;
		cout << "Bellman-Ford: " << bellmanFord << endl;
	}

	else cout << "All randomly generated graphs produced the same outputs." << endl;

}