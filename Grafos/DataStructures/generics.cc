#include <iostream>

// clear && g++ generics.cc -std=c++20 && ./a.out

// Template de classe com tipo padrão e valor padrão
template <typename T = int, typename K = int>
class MyClass {

  public:
	T first;
	K second;

	MyClass() { second = 25; }

	void display() const {
		std::cout << "First: " << first << std::endl;
		std::cout << "Second: " << second << std::endl;
	}
};

void teste(auto fn) {
	fn();
}

int main() {

	MyClass<std::string> obj1; // Usa os valores padrão (int, 0)
	obj1.first = "Lucas";
	obj1.display();

	teste([]() {
		std::cout << "Hello world!" << std::endl;
	});

	return 0;
}