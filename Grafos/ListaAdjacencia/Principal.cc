#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>

// clear && g++ Principal.cc && ./a.out

using namespace std;

template <typename T>
class Graph {
  private:
	typedef unordered_map<T, int> hashNeighbors;

	int size;
	bool diGraph;

	unordered_map<T, vector<tuple<int, int>>> adjacencyList;
	hashNeighbors hashIda;
	vector<T> hashVolta;

	int addNode(T node) {

		int matrixIndex = size++;
		hashIda[node] = matrixIndex;
		hashVolta.push_back(node);

		adjacencyList[node] = vector<tuple<int, int>>();

		return matrixIndex;
	}

  public:
	Graph(bool diGraph = false) : size(0), diGraph(diGraph) {}

	int check(T node) {
		return hashIda.find(node) == hashIda.end() ? -1 : hashIda[node];
	}

	void addEdge(T nodeA, T nodeB, int weight = 1) {

		int hashA = check(nodeA);
		int hashB = check(nodeB);

		// Criando o nó A
		if (hashA == -1) hashA = addNode(nodeA);

		// Criando o nó B
		if (hashB == -1) hashB = addNode(nodeB);

		adjacencyList[nodeA].push_back({hashB, weight});

		if (!diGraph) adjacencyList[nodeB].push_back({hashA, weight});
	}

	string toString(T node) {

		string neighbors = node + ": { ";

		for (auto [neighborHash, weight] : adjacencyList[node]) {
			T neighbor = hashVolta[neighborHash];
			neighbors += neighbor + ", ";
		}

		int len = neighbors.length();
		if (len > 6) neighbors.erase(len - 2, 1);

		return neighbors + "}";
	}

	string toString() {

		string graphToString;

		for (int i = 0; i < size; i++) {
			T node = hashVolta[i];
			graphToString += toString(node) + "\n";
		}

		return graphToString;
	}

	void printList() {

		string graphToString;

		for (int i = 0; i < size; i++) {
			T node = hashVolta[i];

			graphToString += node + ": { ";

			string neighbors;
			for (auto [neighborHash, weight] : adjacencyList[node]) {
				neighbors += to_string(weight) + ", ";
			}

			int len = neighbors.length();
			if (len > 2) neighbors.erase(len - 2, 1);

			graphToString += neighbors + "}\n";
		}

		cout << graphToString;
	}

	friend ostream& operator<<(ostream& os, Graph<T>& g) {
		os << g.toString();
		return os;
	}

};

int main() {

	Graph<string> g(true); // DiGraph

	g.addEdge("L", "A", 5);
	g.addEdge("L", "Go");
	g.addEdge("L", "I");
	g.addEdge("L", "Gu");
	g.addEdge("L", "N");

	g.addEdge("A", "I");
	g.addEdge("A", "Go");
	g.addEdge("A", "Gu");

	g.addEdge("Gu", "Go");
	g.addEdge("Gu", "I");

	cout << g << endl;
	g.printList();

}