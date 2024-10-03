import geopandas as gpd

# Load the GeoJSON file into a GeoDataFrame
geojson_file = "Mapas/brazil.json"  # Replace with your GeoJSON file path
gdf = gpd.read_file(geojson_file)

# Ensure the GeoDataFrame has a 'name' or 'id' column for state names
# Replace 'name' with the actual column name if different
state_column = 'NAME_1'  # Change this to your state identifier column

# Initialize an adjacency list dictionary
adjacency_list = {}

StringToNumber = {
	"Acre": 0,
	"Alagoas": 1,
	"Amapá": 2,
	"Amazonas": 3,
	"Bahia": 4,
	"Ceará": 5,
	"DistritoFederal": 6,
	"EspíritoSanto": 7,
	"Goiás": 8,
	"Maranhão": 9,
	"MatoGrosso": 10,
	"MatoGrossodoSul": 11,
	"MinasGerais": 12,
	"Pará": 13,
	"Paraíba": 14,
	"Paraná": 15,
	"Pernambuco": 16,
	"Piauí": 17,
	"RiodeJaneiro": 18,
	"RioGrandedoNorte": 19,
	"RioGrandedoSul": 20,
	"Rondônia": 21,
	"Roraima": 22,
	"SantaCatarina": 23,
	"SãoPaulo": 24,
	"Sergipe": 25,
	"Tocantins": 26
}

numberOfStates = 0
numberOfAdjacencies = 0

# Iterate through each state and find neighboring states
for i, state1 in gdf.iterrows():
	numberOfStates += 1
	neighbors = []
	for j, state2 in gdf.iterrows():
		if i != j and state1.geometry.intersects(state2.geometry):  # Use intersects instead of touches
			neighbors.append(state2[state_column])
			numberOfAdjacencies += 1
	adjacency_list[state1[state_column]] = neighbors

# Write the adjacency list to a text file
with open("adjacencyList.txt", "w") as f:
	f.write(f"{numberOfStates} {numberOfAdjacencies}\n")
	for state, neighbors in adjacency_list.items():
		for neighbor in neighbors:
			f.write(f"{StringToNumber[state]} {StringToNumber[neighbor]}\n")

print("Adjacency list generated and saved to adjacencyList.txt")
