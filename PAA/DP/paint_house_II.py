import time

"""
    🧩 Problem: Paint House II (Hard Version)
    You are given a matrix 'costs' of size n x k, where costs[i][j] is the cost of painting house i with color j.

    - You have to paint all the houses, and
    - No two adjacent houses can have the same color.

    Return the minimum total cost to paint all the houses.

    🏷️ Constraints:
        - 1 <= n <= 1000 (houses)
        - 1 <= k <= 100 (colors)
        - costs[i][j] <= 20,000
"""

def brute_force(costs, current_house_index = 0, last_color_index = -1):

    n, k = len(costs), len(costs[0])

    indices = [i for i in range(k) if i != last_color_index]

    if (current_house_index == n - 1):
        return min([costs[current_house_index][i] for i in indices])

    results = []

    for i in indices:
        results.append(
            costs[current_house_index][i] +
            brute_force(costs, current_house_index + 1, i)
        )

    return min(results)

def top_down(costs, current_house_index = 0, last_color_index = -1, dp = None):

    n, k = len(costs), len(costs[0])

    if dp is None:
        dp = [[-1 for _ in range(k)] for _ in range(n)]



# costs = [
#     [1, 5, 2],
#     [2, 4, 9]
# ]

# costs = [
#     [17, 2, 17],
#     [16, 16, 5],
#     [14, 3, 19],
#     [19, 1, 23]
# ]

costs = [
    [82, 15, 4, 95, 36],
    [32, 29, 18, 95, 14],
    [87, 95, 70, 12, 76],
    [55, 5, 4, 12, 28],
    [30, 65, 78, 4, 72],
    [26, 92, 84, 90, 70],
    [54, 29, 58, 76, 36],
    [1, 100, 98, 71, 47],
    [64, 59, 13, 78, 71],
    [80, 13, 46, 45, 82],
    [30, 65, 78, 4, 72],
    [26, 92, 84, 90, 70],
]

start = time.perf_counter()
print(brute_force(costs))
end = time.perf_counter()
print(f"Execution time: {end - start:.6f} seconds")

# start = time.perf_counter()
# print(top_down(costs))
# end = time.perf_counter()
# print(f"Execution time: {end - start:.6f} seconds")

# print(bottom_up(costs))
