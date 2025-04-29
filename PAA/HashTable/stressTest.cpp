#include <iostream>
#include <random>
#include "HashMap.hpp" // Assuming this is the file where your HashMap class is defined

// clear && g++ stressTest.cpp -std=c++23 && ./a.out

using namespace std;

int main() {

    constexpr size_t NUM_OPERATIONS = 100'000'000;
    HashMap<int, int> hashMap([](int key) { return key; });

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'001);

    cout << "Starting stress test..." << endl;

    // Stress test: inserting random key-value pairs
    for (size_t i = 0; i < NUM_OPERATIONS; i++) {
        int value = dist(gen);
        hashMap.add({i, value});
    }

    cout << "Insertion completed." << endl;

    // Stress test: retrieving random keys
    size_t successfulGets = 0;

    for (size_t i = 0; i < NUM_OPERATIONS; i++) {

        auto value = hashMap.get(i);

        if (value != 0) successfulGets++;
    }

    cout << "Retrieval completed. Successful gets: " << successfulGets << endl;

    // Output final hashmap size
    // cout << "Final state of HashMap:" << endl;
    // cout << hashMap << endl;

    return 0;
}
