import random

def is_sequential(arr):
    # Convert each line into a tuple of integers
    numbers = [list(map(int, line.split())) for line in arr]

    # Ensure the list starts with 1 and ends with 100
    if numbers[0][0] != 1 or numbers[-1][0] != 100:
        return False

    # Iterate through the numbers and check the sequential conditions
    for i in range(1, len(numbers)):
        prev_first = numbers[i - 1][0]
        curr_first = numbers[i][0]

        # Check if the current first number is greater than or equal to the previous one
        # and ensure that it increments by at most 1
        if curr_first < prev_first or curr_first > prev_first + 1:
            return False

    return True

while True:

	# Load the graph data
	file_path = 'graph-test-100.txt'

	# Read the content of the file
	with open(file_path, 'r') as file:
		lines = file.readlines()

	# Extract the number of vertices and edges from the first line
	num_vertices, num_edges = map(int, lines[0].split())

	# Store the edges (each line from the second one onward)
	edges = lines[1:]

	# Determine the number of edges to remove
	edges_to_remove = random.randint(600, 700)

	# Randomly sample edges to remove
	remaining_edges = random.sample(edges, len(edges) - edges_to_remove)

	# Update the number of edges in the first line
	new_edge_count = len(remaining_edges)
	lines[0] = f"{num_vertices} {new_edge_count}\n"

	# Combine the updated graph (first line + remaining edges)
	updated_graph = lines[:1] + remaining_edges

	header = updated_graph.pop(0)

	updated_graph.sort()

	# here I should check if the vertices are
	if is_sequential(updated_graph):
		# Save the updated file
		output_file_path = 'graph-test-100-updated.txt'

		with open(output_file_path, 'w') as output_file:
			output_file.write(header)
			output_file.writelines(updated_graph)

		output_file_path

		break