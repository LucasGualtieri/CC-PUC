import geopandas as gpd

# Load the GeoJSON file into a GeoDataFrame
geojson_file = "brazil.json"  # Replace with your GeoJSON file path
gdf = gpd.read_file(geojson_file)

# Ensure the GeoDataFrame has a 'name' or 'id' column for state names
# Replace 'name' with the actual column name if different
state_column = 'NAME_1'  # Change this to your state identifier column

# Initialize an adjacency list dictionary
adjacency_list = {}

# Iterate through each state and find neighboring states
for i, state1 in gdf.iterrows():
    neighbors = []
    for j, state2 in gdf.iterrows():
        if i != j and state1.geometry.intersects(state2.geometry):  # Use intersects instead of touches
            neighbors.append(state2[state_column])
    adjacency_list[state1[state_column]] = neighbors

# Write the adjacency list to a text file
with open("adjacencyList.txt", "w") as f:
    for state, neighbors in adjacency_list.items():
        # Join neighbors into a comma-separated string
        neighbors_str = ", ".join(neighbors)
        f.write(f"{state}: {neighbors_str}\n")

print("Adjacency list generated and saved to adjacencyList.txt")
