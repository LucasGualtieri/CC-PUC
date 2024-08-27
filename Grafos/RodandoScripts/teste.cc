#include <iostream>
#include <sstream>

// clear && g++ teste.cc && ./a.out

using namespace std;

void gerarArquivo(int i) {

	FILE* file = fopen("graph.dot", "w");

	stringstream ss;

	ss << "graph G {" << endl
	<< "	// Nodes" << endl
	<< "\t" << i << "[label=\"Node " << i << "\", fillcolor=\"red\", style=\"filled\"];" << endl
	<< "\t" << i + 1 << "[label=\"Node " << i + 1 << "\", fillcolor=\"green\", style=\"filled\"];" << endl
	<< "\t" << i + 2 << "[label=\"Node " << i + 2 << "\", fillcolor=\"orange\", style=\"filled\"];" << endl
	<< "\t" << i << " -- " << i + 1 << ";" << endl
	<< "\t" << i + 1 << " -- " << i + 2 << ";" << endl
	<< "\t" << i + 2 << " -- " << i << ";" << endl
	<< "}\n";

	fprintf(file, "%s", ss.str().c_str());

	fclose(file);
}

int main() {

	for (int i = 0; i < 3; i++) {
		gerarArquivo(i);
		string script = string("circo -Tpng graph.dot -o image") + to_string(i) + string(".png");
		system(script.c_str());
	}
}