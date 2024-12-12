import networkx as nx
import matplotlib.pyplot as plt

def draw_planar_graph(graph):
    """
    Draws a graph with a planar representation if it is planar.
    Falls back to a spring layout otherwise.

    Parameters:
        graph (networkx.Graph): The graph to be drawn.
    """
    # Check if the graph is planar
    is_planar, planar_embedding = nx.check_planarity(graph, counterexample=False)

    if is_planar:
        print("The graph is planar. Drawing using a planar layout.")
        pos = nx.planar_layout(graph)
    else:
        print("The graph is not planar. Falling back to a spring layout.")
        pos = nx.spring_layout(graph)

    # Draw the graph
    plt.figure(figsize=(8, 8))
    nx.draw(graph, pos, with_labels=True, node_color='skyblue', node_size=700, font_size=12, edge_color='gray')
    plt.title("Planar Representation" if is_planar else "Fallback: Spring Layout")
    plt.show()

if __name__ == "__main__":
    # Example: Define a graph
    G = nx.Graph()

    # Add nodes and edges
    G.add_edges_from([
        ('d', 'e'), ('d', 'c'), ('d', 'b'), ('d', 'a'),  # Square
        ('d', 'f'), ('d', 'g'), # Diagonal inside the square
        ('a', 'b'), ('a', 'g'), ('b', 'f'), ('c', 'e'), ('c', 'b'),
        ('e', 'f'), ('g', 'e')
    ])

    # Draw the graph
    draw_planar_graph(G)

