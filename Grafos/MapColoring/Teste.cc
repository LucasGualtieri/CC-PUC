#include <iostream>
#include <cstdlib> // for system()

// clear && g++ Teste.cc && ./a.out

int main() {
    // Call the Python script
    int result = system("python3 Coloring.py");

    // Check if the command executed successfully
    if (result == 0) {
        std::cout << "Python script executed successfully." << std::endl;
    } else {
        std::cerr << "Error executing Python script." << std::endl;
    }

    return 0;
}
