import numpy as np
import matplotlib.pyplot as plt
import csv

def generate_sequence(limit):
    """Generates the sequence A_n = 5 * 2^(n-1) up to a given limit."""
    sequence = []
    n = 1
    while (val := 5 * 2**(n-1)) <= limit:
        sequence.append(val)
        n += 1
    return sequence

def read_csv(filename):
    """Reads CSV file and returns lists of indices and times."""
    indices, times = [], []
    with open(filename, newline='') as csvfile:
        reader = csv.reader(csvfile)
        next(reader)  # Skip header
        for row in reader:
            indices.append(int(row[0]))
            times.append(float(row[1]))
    return indices, times

def plot_data(indices, times, special_indices):
    """Plots the data with vertical red lines at special indices."""
    plt.figure(figsize=(10, 5))
    plt.plot(indices, times, marker='o', linestyle='-', label='Insertion Time')
    
    for x in special_indices:
        plt.axvline(x=x, color='r', linestyle='--', alpha=0.7, label='Resize Points' if x == special_indices[0] else "")
    
    plt.xlabel("Insertion Index")
    plt.ylabel("Time (s)")
    plt.title("Insertion Time with Resize Points")
    plt.legend()
    plt.grid()
    plt.show()

# Read data from CSV file
csv_filename = "output.csv"  # Change to your actual filename
indices, times = read_csv(csv_filename)

# Generate sequence up to the last index in the dataset
special_indices = generate_sequence(max(indices))

# Plot the data with vertical lines at special indices
plot_data(indices, times, special_indices)
