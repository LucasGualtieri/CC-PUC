#include <iostream>

using namespace std;

class PATRICIA {
	class Node {
		string str;
		Node* children[26];

	  public:

		Node() {}
		Node(string str) : str(str) {}

		string toString() const { return str; }

		string operator+(string str) {
			return this->str + str;
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

  public:
	PATRICIA() : root(new Node()) {}

	void add(string str) {
		// str = simplify();
		add(str, root, 0);
	}

  private:
	void add(string str, Node* node, int pos) {
		char c = str[pos] % 26;
		if ((*node)[c] == nullptr) (*node)[c] = new Node(str);
		else add(str, (*node)[c], pos + 1);
	}

  public:

	string toString() const {
		string result = "{ ";

		Node node = *root;

		for (int i = 0; i < 26; i++) {
			if (node[i] != nullptr) {
				result += *node[i] + ", ";
			}
		}

		return result + "}";
	}

	friend ostream& operator<<(ostream& os, const PATRICIA& tree) {
		os << tree.toString();
		return os;
	}
};

int main() {

	PATRICIA tree;

	tree.add("religiao");
	tree.add("ciencia");

	cout << tree << endl;
}