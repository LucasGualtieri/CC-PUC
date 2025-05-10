import matplotlib.pyplot as plt
import pandas as pd
from matplotlib.ticker import FuncFormatter

# Read the CSV
df = pd.read_csv("quicksort_results.csv")

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(df['n'], df['iterative_time'], label='Iterative Quicksort', marker='o')
plt.plot(df['n'], df['recursive_time'], label='Recursive Quicksort', marker='s')

plt.xscale('log')
plt.yscale('log')

# Remove log scale from Y axis to show actual second values
# plt.yscale('log')  # You can comment this out if you want exact seconds shown
plt.xlabel('Input Size (n)')
plt.ylabel('Time (seconds)')

# Format the Y-axis to show seconds nicely
def format_seconds(x, _):
    return f"{x:.3f}s"  # Format to 3 decimal places

plt.gca().yaxis.set_major_formatter(FuncFormatter(format_seconds))

plt.title('Quicksort Performance Comparison')
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.savefig("quicksort_comparison.png")
plt.show()
