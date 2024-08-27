#include <iostream>
#include <utility>
#include <tuple>
#include <sstream>

// clear && g++ grafo.cc && ./a.out

using namespace std;

class Graph {

	tuple<int, int, int, int>* V;
	pair<int, string>* E;

	int cardV, cardE;

	int lastEdge;

	public:

	Graph(int V, int E) : cardV(V), cardE(E), lastEdge(0) {

		this->V = new tuple<int, int, int, int>[V + 1];
		this->E = new pair<int, string>[E];

		for (int i = 0; i <= V + 1; i++) this->V[i] = {-1, 0, 0, 0};
		// for (int i = 0; i < E; i++) this->E[i] = (0, 0);
	}

	~Graph() {
		// delete[] V;
		// delete[] E;
	}

	void addEdge(int u, int v) {

		// cout << "u: " << u;
		// cout << " v: " << v << endl;

		// cout << "V[u]: " << get<0>(V[u]) << endl;

		if (V[u] == (tuple<int, int, int, int>){ -1, 0, 0, 0 }) {
			get<0>(V[u]) = lastEdge;
			// cout << "get<0>(V[u]): " << get<0>(V[u]) << endl;
		}

		E[lastEdge++] = {v, "no label"};

		// cout << string("E[lastEdge - 1]: ") << get<0>(E[lastEdge - 1]) << endl;
	}

	string str() const {

		// if (get<0>(V[i]) == -1) get<0>(V[i]) = lastEdge - 1;

		// for (int i = cardV + 1; i >= 0; i--) {

		// 	for (int j = i; get<0>(V[j]); j--) {
		// 		if (get<0>(V[i]) == -1) get<0>(V[i]) = lastEdge - 1;
		// 	}
		// }

		stringstream os;

		for (int i = 0; i <= cardV; i++) {

			os << to_string(i) << " { ";

			if (get<0>(V[i]) != -1) {

				for (int j = get<0>(V[i]); j < get<0>(V[i + 1]); j++) {
					os << "{ " << to_string(get<0>(E[j])) << ", " << get<1>(E[j]) << " } ";
				}
			}

			os << "}" << endl;
		}

		os << "V = { ";
		for (int i = 0; i <= cardV + 1; i++) {
			os << get<0>(V[i]) << " ";
		}
		os << "}\n";

		os << "E = { ";
		for (int i = 0; i < cardE; i++) {
			os << get<0>(E[i]) << " ";
		}
		os << "}";

		return os.str();
	}

	friend std::ostream& operator<<(std::ostream& os, const Graph g) {
		os << g.str();
		return os;
	}
};

int main() {

	Graph g(5, 6);

	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 5);
	g.addEdge(5, 2);

	cout << g << endl;
}