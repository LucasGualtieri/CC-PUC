defmodule Graph do
  defstruct nodes: %{}, edges: %{}

  def new() do
    %Graph{}
  end

  def add_node(graph, node) do
    nodes = Map.put(graph.nodes, node, %{})
    %Graph{graph | nodes: nodes}
  end

  def add_edge(graph, from, to) do
    edges = Map.get(graph.edges, from, %{})
    updated_edges = Map.put(edges, to, true)
    new_edges = Map.put(graph.edges, from, updated_edges)
    %Graph{graph | edges: new_edges}
  end

  def adjacent?(graph, node1, node2) do
    case Map.get(graph.edges, node1) do
      nil -> false
      edges -> Map.has_key?(edges, node2)
    end
  end

  def get_neighbors(graph, node) do
    case Map.get(graph.edges, node) do
      nil -> []
      edges -> Map.keys(edges)
    end
  end
end

# Exemplo de uso
graph = Graph.new()
|> Graph.add_node(:a)
|> Graph.add_node(:b)
|> Graph.add_node(:c)

|> Graph.add_edge(:a, :b)
|> Graph.add_edge(:b, :c)

IO.inspect Graph.adjacent?(graph, :a, :b) # true
IO.inspect Graph.adjacent?(graph, :a, :c) # false

IO.inspect Graph.get_neighbors(graph, :b) # [:c]
