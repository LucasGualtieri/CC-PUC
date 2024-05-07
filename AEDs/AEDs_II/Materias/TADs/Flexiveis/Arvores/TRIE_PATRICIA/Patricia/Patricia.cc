#include <iostream>
#include <vector>

using namespace std;

// clear && g++ Patricia.cc && ./a.out

// Tratamento de String
void toUpper(string& str) {
	for (char& c : str) c = toupper(c);
}

string simplify(string str) {
	toUpper(str);
	return str;
}

#define DEBUGGIN true

void consoleLog(string msg, bool condition = true) {
	if (DEBUGGIN && condition) cout << msg << endl;
}

class PATRICIA {

	class Node {
		bool isLeaf;

	  public:
		Node* children[26];
		string str;

		Node() {}
		Node(string str) : str(str), isLeaf(true) {}

		bool IsLeaf() { return isLeaf; }
		void clearLeaf() { isLeaf = false; }

		string toString() const { return str; }

		string operator+(string str) {
			return this->str + str;
		}

		friend string& operator+=(string& str, const Node& node) {
			return str += node.str;
		}

		Node*& operator[](int i) {
			return children[i];
		}

		friend ostream& operator<<(ostream& os, const Node& node) {
			os << node.toString();
			return os;
		}
	};

	Node* root;

	int fn(string str, string nodeStr) {
		int i = 0;
		int len = nodeStr.length();

		while(str[i] == nodeStr[i] && i < len) i++;
		return i;
	}

	// string > 1 && ou || i > len da string original

	// Na hora de quebar um determinado nó:
	// 1° filho: Recebe o restante da string (ou seja, original.substring(i)) sendo pai de todos os filhos do nó original
	// 2° filho: Passa a ter o valor nova.substring(i);
	// Pai recebe original.substring(0, i) passa a de fato ser pai dos dois filhos

	void add(string str, Node*& node) {

		int pos = fn(str, node->str);
		cout << "pos: " << pos << endl;
		cout << "str[pos]: " << str[pos] << endl;

		char childPos = str[pos] - 'A';
		Node*& child = node->children[childPos];

		if (child == nullptr) {
			cout << "Teste: " << str.substr(pos) << endl;
			child = new Node(str.substr(pos));
		}

		// else {
		// 	bool control = false;

		// 	Node* parent = node->children[childPos];

		// 	int i = fn(str, parent->str);
		// 	consoleLog("i: " + to_string(i), control);

		// 	string rightChildStr = str.substr(i);
		// 	consoleLog("rightChildStr: " + rightChildStr, control);

		// 	string leftChildStr = parent->str.substr(i);
		// 	consoleLog("leftChildStr: " + leftChildStr, control);

		// 	parent->clearLeaf();

		// 	parent->str = parent->str.substr(0, i);
		// 	consoleLog("parent->str: " + parent->str, control);

		// 	parent->children[leftChildStr[0] - 'A'] = new Node(leftChildStr);
		// 	parent->children[rightChildStr[0] - 'A'] = new Node(rightChildStr);
		// }
	
	}

  public:
	PATRICIA() : root(new Node()) {}

	void add(string str) {

		str = simplify(str);

		char childPos = str[0] - 'A';
		Node*& child = root->children[childPos];

		if (child == nullptr) child = new Node(str);

		else {
			child->clearLeaf();
			add(str, child);
		}
	}

	string toString() const {

		vector<string> lista;

		toString("", root, lista);

		string result = "empty";

		for (string str : lista) result += str + ", ";

		int len = result.length();

		if (len > 2) {
			result.erase(len - 2, 2);
			result.erase(0, string("empty").length());
		}

		return "{ " + result + " }";
	}

	void toString(string str, Node* node, vector<string>& lista) const {

		for (int i = 0; i < 26; i++) {

			Node* child = node->children[i];

			if (child != nullptr) {
				if (child->IsLeaf()) lista.push_back(str + child->str);
				else toString(str + child->str, child, lista);
			}
		}
	}

	friend ostream& operator<<(ostream& os, const PATRICIA& tree) {
		os << tree.toString();
		return os;
	}
};

int main() {

	PATRICIA tree;

	tree.add("ABC");
	tree.add("ABCD");
	// tree.add("ABCE");

	cout << tree << endl;
}