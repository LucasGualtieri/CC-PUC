defmodule BinaryTree do
	# Declaração do Struct que representa os nós
	defstruct value: nil, left: nil, right: nil

	# Função chamada apenas quando chegamos nas folhas,
	# ou quando a árvore está fazia
	def insert(value, nil), do: %BinaryTree{value: value}

	def insert(new_value, tree) do
		if new_value < tree.value do
			%BinaryTree{ tree | left: insert(new_value, tree.left) }
		else
			%BinaryTree{ tree | right: insert(new_value, tree.right) }
		end
	end

	def caminharCentral(nil), do: :ok

	def caminharCentral(tree) do
		caminharCentral(tree.left)
		IO.puts(tree.value)
		caminharCentral(tree.right)
	end
end

tree = BinaryTree.insert(10, nil)
tree = BinaryTree.insert(5, tree)
tree = BinaryTree.insert(3456, tree)
tree = BinaryTree.insert(-123, tree)

BinaryTree.caminharCentral(tree)

# IO.puts(inspect tree)
