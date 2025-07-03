#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include <sstream>

using namespace std;

// clear && g++ -std=c++23 tromino.cpp && ./a.out

#define DEBUGGING false

int rand(int min, int max) {

    random_device rd;  // Seed
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<> dist(min, max);

    return dist(gen);
}

template<typename T>
string matrixToString(const vector<vector<T>>& matrix) {

    ostringstream oss;

    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            oss << elem << " ";
        }
        oss << '\n';
    }

    return oss.str();
}

void Tromino(pair<int, int> hole, tuple<int, int, int, int> limits, vector<vector<string>>& grid) {

	auto [x, y] = hole;
	auto [L, R, T, B] = limits;

	bool westSide = x < (L + R) / 2;
	bool northSide = y < (T + B) / 2;

	int n = R - L;

	// NW
	if (northSide && westSide) {

		grid[(T + B) / 2 - 1][(L + R) / 2] = "|";
		grid[(T + B) / 2][(L + R) / 2] = "┘";
		grid[(T + B) / 2][(L + R) / 2 - 1] = "-";

		if (n > 2) {
			Tromino(hole, {L, (L + R) / 2, T, (T + B) / 2}, grid); // NW
			Tromino({(L + R) / 2, (T + B) / 2 - 1}, {(L + R) / 2, R, T, (T + B) / 2}, grid); // NE
			Tromino({(L + R) / 2, (T + B) / 2}, {(L + R) / 2, R, (T + B) / 2, B}, grid); // SE
			Tromino({(L + R) / 2 - 1, (T + B) / 2}, {L, (L + R) / 2, (T + B) / 2, B}, grid); // SW
		}
	}

	// NE
	else if (northSide && !westSide) {

		grid[(T + B) / 2 - 1][(L + R) / 2 - 1] = "|";
		grid[(T + B) / 2][(L + R) / 2 - 1] = "└";
		grid[(T + B) / 2][(L + R) / 2] = "-";

		if (n > 2) {
			Tromino({(L + R) / 2 - 1, (T + B) / 2 - 1}, {L, (L + R) / 2, T, (T + B) / 2}, grid); // NW
			Tromino(hole, {(L + R) / 2, R, T, (T + B) / 2}, grid); // NE
			Tromino({(L + R) / 2, (T + B) / 2}, {(L + R) / 2, R, (T + B) / 2, B}, grid); // SE
			Tromino({(L + R) / 2 - 1, (T + B) / 2}, {L, (L + R) / 2, (T + B) / 2, B}, grid); // SW
		}
	}

	// SE
	else if (!northSide && !westSide) {

		grid[(T + B) / 2][(L + R) / 2 - 1] = "|";
		grid[(T + B) / 2 - 1][(L + R) / 2 - 1] = "┌";
		grid[(T + B) / 2 - 1][(L + R) / 2] = "-";

		if (n > 2) {
			Tromino({(L + R) / 2 - 1, (T + B) / 2 - 1}, {L, (L + R) / 2, T, (T + B) / 2}, grid); // NW
			Tromino({(L + R) / 2, (T + B) / 2 - 1}, {(L + R) / 2, R, T, (T + B) / 2}, grid); // NE
			Tromino(hole, {(L + R) / 2, R, (T + B) / 2, B}, grid); // SE
			Tromino({(L + R) / 2 - 1, (T + B) / 2}, {L, (L + R) / 2, (T + B) / 2, B}, grid); // SW
		}
	}

	// SW
	else if (!northSide && westSide) {

		grid[(T + B) / 2][(L + R) / 2] = "|";
		grid[(T + B) / 2 - 1][(L + R) / 2] = "┐";
		grid[(T + B) / 2 - 1][(L + R) / 2 - 1] = "-";

		if (n > 2) {
			Tromino({(L + R) / 2 - 1, (T + B) / 2 - 1}, {L, (L + R) / 2, T, (T + B) / 2}, grid); // NW
			Tromino({(L + R) / 2, (T + B) / 2 - 1}, {(L + R) / 2, R, T, (T + B) / 2}, grid); // NE
			Tromino({(L + R) / 2, (T + B) / 2}, {(L + R) / 2, R, (T + B) / 2, B}, grid); // SE
			Tromino(hole, {L, (L + R) / 2, (T + B) / 2, B}, grid); // SW
		}
	}
}

string Tromino(char hole, char nothing, pair<int, int> holePos, int n) {

	vector<vector<string>> grid(n, vector<string>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			grid[i][j] = nothing;
		}
	}

	grid[holePos.second][holePos.first] = hole;

	Tromino(holePos, { 0, n, 0, n }, grid);

	return matrixToString(grid);
}

int main() {

	int n = pow(2, 3);
	pair<int, int> holePos = {rand(0, n - 1), rand(0, n - 1)};
	// pair<int, int> holePos = {n - 1, n - 1};

	cout << Tromino('@', '0', holePos, n) << endl;

	return 0;
}
