#include <iostream>

#include "GraphProof.hpp"
#include "timer.hpp"
#include "../DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ Proof.cc -std=c++20 && ./a.out

int main() {

	bool equal = true;

	LinearList<float> fasterBellmanFord, bellmanFord;

	int count = -1;

	Graph g;

	Timer timer;

	for (int i : {10, 100, 200, 300, 400, 500}) {

		for (int ii = 0; equal && ii < 10; ii++) {

			g = Graph::generateRandom(i, -100, 100); // Desabilitar os grafos esparços aumenta a diferença?

			bellmanFord = g.bellmanFord(0, timer);
			cout << "BellmanFord time:         " << timer << "s" << endl;

			timer.start();
			fasterBellmanFord = g.fasterBellmanFord(0);
			cout << "Faster Bellman-Ford time: " << timer << "s" << endl;

			equal = fasterBellmanFord == bellmanFord;

			cout << "|V|: " << i << " ii" << ": " << ii << endl;

			cout << "----------------------------" << endl;

			count++;
		}
	}

	if (!equal) {
		cout << "The graph number " << count << " produced different results:" << endl;
		cout << "Faster Bellman-Ford time: " << fasterBellmanFord << endl;
		cout << "Bellman-Ford: " << bellmanFord << endl;
		cout << g << endl;
	}

	else cout << "All randomly generated graphs produced the same outputs." << endl;

}