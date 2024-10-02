import geopandas as gpd
import matplotlib.pyplot as plt

# Load the GeoJSON file into a GeoDataFrame
geojson_file = "brazil.json"  # Replace with your GeoJSON file path
gdf = gpd.read_file(geojson_file)

# Print unique state names to help with matching
print("Unique state names in GeoDataFrame:")
print(gdf['NAME_1'].unique())

NumberToString = {
    0: Acre,
    1: Alagoas,
    2: Amapá,
    3: Amazonas,
    4: Bahia,
    5: Ceará,
    6: DistritoFederal,
    7: EspíritoSanto,
    8: Goiás,
    9: Maranhão,
    10: MatoGrosso,
    11: MatoGrossodoSul,
    12: MinasGerais,
    13: Pará,
    14: Paraíba,
    15: Paraná,
    16: Pernambuco,
    17: Piauí,
    18: RiodeJaneiro,
    19: RioGrandedoNorte,
    20: RioGrandedoSul,
    21: Rondônia,
    22: Roraima,
    23: SantaCatarina,
    24: SãoPaulo,
    25: Sergipe,
    26: Tocantins
}

StringToNumber = {
    Acre: 0,
    Alagoas: 1,
    Amapá: 2,
    Amazonas: 3,
    Bahia: 4,
    Ceará: 5,
    DistritoFederal: 6,
    EspíritoSanto: 7,
    Goiás: 8,
    Maranhão: 9,
    MatoGrosso: 10,
    MatoGrossodoSul: 11,
    MinasGerais: 12,
    Pará: 13,
    Paraíba: 14,
    Paraná: 15,
    Pernambuco: 16,
    Piauí: 17,
    RiodeJaneiro: 18,
    RioGrandedoNorte: 19,
    RioGrandedoSul: 20,
    Rondônia: 21,
    Roraima: 22,
    SantaCatarina: 23,
    SãoPaulo: 24,
    Sergipe: 25,
    Tocantins: 26
}

# Read the color mapping from the text file
color_map = {}
with open("state_colors.txt", "r") as f:  # Replace with your color mapping file path
    for line in f:
        state_color_pair = line.strip().split(":")
        if len(state_color_pair) == 2:
            state = state_color_pair[0].strip()  # Get the state name and strip whitespace
            color = state_color_pair[1].strip().split()[0]  # Get the color and strip whitespace
            color_map[state.replace(" ", "")] = color  # Remove spaces from the state names and map to color

# Map the colors to a new column in the GeoDataFrame
gdf['color'] = gdf['NAME_1'].str.replace(" ", "")  # Remove spaces from the state names
gdf['color'] = gdf['color'].map(color_map)

# Check for any states that didn't find a color mapping
missing_colors = gdf[gdf['color'].isna()]['NAME_1'].unique()
if missing_colors.size > 0:
    print(f"Missing color mappings for: {', '.join(missing_colors)}")

# Plot the map
fig, ax = plt.subplots(figsize=(10, 10))  # Adjust the figure size as needed
gdf.plot(ax=ax, color=gdf['color'], edgecolor='black')

# Add a title and remove axis for a cleaner map
ax.set_title("Map of Brazil with Assigned Colors")
ax.axis('off')

# Save the plot as an image file
plt.savefig("brazil_map_colored_from_file.png", dpi=300)  # Change DPI for higher resolution if needed
plt.show()
