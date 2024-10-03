import geopandas as gpd
import matplotlib.pyplot as plt

# Load the GeoJSON file into a GeoDataFrame
geojson_file = "brazil.json"  # Replace with your GeoJSON file path
gdf = gpd.read_file(geojson_file)

# Plot the GeoDataFrame
fig, ax = plt.subplots(figsize=(10, 10))  # Adjust the figure size as needed
gdf.plot(ax=ax, color='lightblue', edgecolor='black')

# Add a title and remove axis for a cleaner map
ax.set_title("Map from GeoJSON")
ax.axis('off')

# Save the plot as an image file
plt.savefig("map.png", dpi=300)  # Change DPI for higher resolution if needed
plt.show()
