defmodule BinaryTree do
  defstruct value: nil, left: nil, right: nil

  def insert(nil, value), do: %BinaryTree{value: value}

  def insert(tree, new_value) do
    if new_value < tree.value do
      %BinaryTree{tree | left: insert(tree.left, new_value)}
    else
      %BinaryTree{tree | right: insert(tree.right, new_value)}
    end
  end

  def caminhar_central(nil), do: :ok

  def caminhar_central(tree) do
    caminhar_central(tree.left)
    IO.puts(tree.value)
    caminhar_central(tree.right)
  end
end

tree = BinaryTree.insert(nil, 10)
tree = BinaryTree.insert(tree, -5)
tree = BinaryTree.insert(tree, 25)
tree = BinaryTree.insert(tree, 2)
tree = BinaryTree.insert(tree, 10)
tree = BinaryTree.insert(tree, 100)

BinaryTree.caminhar_central(tree)
