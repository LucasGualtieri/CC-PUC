#include <iostream>
#include <cstdlib> // for system()

#include "../DataStructures/include/list/linearList.hpp"
#include "Graph.hpp"

using namespace std;

// clear && g++ Teste.cc && ./a.out

int main() {

    Graph g = {
        { 0, { 1, 2, 3, 4, 5 }},
        { 1, { 0, 2, 5 }},
        { 2, { 0, 1, 3 }},
        { 3, { 0, 2, 4 }},
        { 4, { 0, 3, 5, 6 }},
        { 5, { 0, 1, 4 }},
        { 6, { 4 }}
    };

    // cout << g << endl;

    LinearList<string> cores = g.colorVertices();

    cout << cores << endl;

    // for (int i = 0; i <= 6; i++) {
    //     cout << "v: " << i << " - " << cores[i] << endl;
    // }

    // // Call the Python script
    // int result = system("python3 Coloring.py");

    // // Check if the command executed successfully
    // if (result == 0) {
    //     std::cout << "Python script executed successfully." << std::endl;
    // } else {
    //     std::cerr << "Error executing Python script." << std::endl;
    // }

    return 0;
}