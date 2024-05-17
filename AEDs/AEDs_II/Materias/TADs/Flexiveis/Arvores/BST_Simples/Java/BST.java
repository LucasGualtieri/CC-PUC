package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.BST_Simples.Java;

public class BST {
	private int size;
	private Node root;

	public BST() {
		this.size = 0;
		this.root = null;
	}

	public Node getRoot() { return this.root; }

	public int getSize() { return this.size; }

	public int getHeight() throws Exception {
		if (this.root == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		}

		return getHeight(0, this.root);

	}

	private int getHeight(int height, Node root) {
		
		return root == null ? height - 1 : Math.max(getHeight(height + 1, root.left), getHeight(height + 1, root.right));

		// if (root != null) {
		// 	height++;
		// 	int leftHeight = getHeight(height, root.left);
		// 	int rightHeight = getHeight(height, root.right);
		// 	height = leftHeight > rightHeight ? leftHeight : rightHeight;
		// }

		// return height;
	}

	public void Insert(int value) throws Exception {
		this.size++;
		this.root = Insert(value, root);
	}
	
	private Node Insert(int value, Node root) throws Exception {

		if (root == null) {
			root = new Node(value);
		} else if (value > root.value) {
			root.right = Insert(value, root.right);
		} else if (value < root.value) {
			root.left = Insert(value, root.left);
		} else {
			this.size--;
			throw new Exception("Erro ao inserir na Árvore: Valor " + value + " repetido.");
		}
		
		return root;

	}
	
	public void InsertVoid(int value) throws Exception {
		if (root == null) root = new Node(value);
		else InsertVoid(value, root);
	}
	
	private void InsertVoid(int value, Node root) throws Exception {
		
		if (value > root.value) {
			if (root.right == null) root.right = new Node(value);
			else InsertVoid(value, root.right);
		} else if (value < root.value) {
			if (root.left == null) root.left = new Node(value);
			else InsertVoid(value, root.left);
		} else {
			throw new Exception("Erro ao inserir na Árvore: Valor repetido.");
		}

	}

	public int Delete(int value) throws Exception {

		int removed;

		if (this.root == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		} else if (value < root.value) {
			removed = Delete(value, root.left, root);
		} else if (value > root.value) {
			removed = Delete(value, root.right, root);
		} else {

			removed = root.value;

			if (root.left == null && root.right == null) {
				this.root = null;
			} else if (root.left == null || root.right == null) {
				this.root = value < this.root.value ? this.root.left : this.root.right;
			} else {

				Node aux = GreatestParentLeft(this.root.left);
				
				if (aux.right != null) {
					this.root.value = aux.right.value;
					aux.right = aux.right.left;
				} else {
					this.root.value = aux.value;
					this.root.left = aux.right;
				}
			}
		}

		return removed;

	}
	
	private int Delete(int value, Node root, Node parent) throws Exception {
		
		int removed;

		if (root == null) {
			throw new Exception("Erro ao remover na árvore: Valor inexistente.");
		} else if (value < root.value) {
			removed = Delete(value, root.left, root);
		} else if (value > root.value) {
			removed = Delete(value, root.right, root);
		} else {

			removed = root.value;

			if (root.left == null && root.right == null) {
				if (value < parent.value) parent.left = null;
				else parent.right = null;
			} else if (root.left == null || root.right == null) {
				if (value < parent.value) parent.left = root.right;
				else parent.right = root.left;
			} else {

				Node aux = GreatestParentLeft(root.left);
				
				if (aux.right != null) {
					root.value = aux.right.value;
					aux.right = aux.right.left;
				} else {
					root.left = aux.left;
					root.value = aux.value;
				}

			}

		}

		return removed;

	}

	private Node GreatestParentLeft(Node root) {

		while (root.right != null && root.right.right != null) {
			root = root.right;
		}
		
		return root;
	}

	// Remover simplificado
	/*
		
		public int delete(int value) throws Exception {
			if (this.root == null) {
				throw new Exception("Erro ao remover na árvore: Árvore vazia.");
			}
			return delete(value, root, null);
		}

		private int delete(int value, Node node, Node parent) throws Exception {
			if (node == null) {
				throw new Exception("Erro ao remover na árvore: Valor inexistente.");
			}

			if (value < node.value) {
				return delete(value, node.left, node);
			} else if (value > node.value) {
				return delete(value, node.right, node);
			} else {
				int removed = node.value;
				if (node.left == null && node.right == null) {
					replaceNode(parent, node, null);
				} else if (node.left == null || node.right == null) {
					replaceNode(parent, node, node.left != null ? node.left : node.right);
				} else {
					Node aux = greatestParentLeft(node.left);
					if (aux.right != null) {
						node.value = aux.right.value;
						aux.right = aux.right.left;
					} else {
						node.value = aux.value;
						node.left = aux.left;
					}
				}
				return removed;
			}
		}

		private void replaceNode(Node parent, Node oldNode, Node newNode) {
			if (parent == null) {
				this.root = newNode;
			} else if (parent.left == oldNode) {
				parent.left = newNode;
			} else {
				parent.right = newNode;
			}
		}

		private Node greatestParentLeft(Node node) {
			// Your implementation here
		}
	*/

	// public void Delete(int value) throws Exception {
	// 	this.root = Delete(value, this.root);
	// 	// this.root = RemoveInt(value, this.root);
	// }

	// private Node Delete(int value, Node root) throws Exception {

	// 	if (root == null) { 
	// 		throw new Exception("Erro ao remover na árvore: Árvore vazia.");
	// 	} else if (value < root.value) {
	// 		root.left = Delete(value, root.left);
	// 	} else if (value > root.value) {
	// 		root.right = Delete(value, root.right);
	// 	} else if (root.right == null) {
	// 		root = root.left;
	// 	} else if (root.left == null) {
	// 		root = root.right;
	// 	} else {
	// 		root.left = GetGreatestNode(root, root.left);
	// 	}

	// 	return root;

	// }
	   

	private Node GetSmallestNode(Node root) {
		Node smallest = root;
		while (smallest.left != null) smallest = smallest.left;
		return smallest;
	}

	Node GetGreatestNode(Node root) { // Should be private
		Node greatest = root;
		while (greatest.right != null) greatest = greatest.right;
		return greatest;
	}

	public int RemoveDep(int value) throws Exception {
		
		int removed;

		if (this.root == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		} else if (value < root.value) {
			removed = RemoveDep(value, root.left, root);
		} else if (value > root.value) {
			removed = RemoveDep(value, root.right, root);
		} else {
			removed = root.value;
			GetSmallestNode(root.right).left = root.left;
			this.root = this.root.right;
		}
		
		return removed;

	}

	private int RemoveDep(int value, Node root, Node rootParent) throws Exception {

		int removed;

		if (root == null) {
			throw new Exception("Erro ao remover na Árvore: Elemento não pertence à árvore.");
		} else if (value < root.value) {
			removed = RemoveDep(value, root.left, root);
		} else if (value > root.value) {
			removed = RemoveDep(value, root.right, root);
		} else {
			removed = root.value;
			if (root.value > rootParent.value) {
				if (root.right == null) {
					rootParent.right = root.left;
				} else {
					GetSmallestNode(root.right).left = root.left;
					rootParent.right = root.right;
				}
			} else {
				if (root.right == null) {
					rootParent.left = root.left;
				} else {
					GetSmallestNode(root.right).left = root.left;
					rootParent.left = root.right;
				}
			}
		}

		return removed;
	}

	public int SearchAndReturn(int value) throws Exception {
		if (this.root == null) {
			throw new Exception("Erro ao buscar na Árvore: Árvore vazia.");
		}
		return SearchAndReturn(value, this.root);
	}
	
	private int SearchAndReturn(int value, Node root) throws Exception {
		
		int searched;

		if (root == null) {
			throw new Exception("Erro ao buscar na Árvore: Elemento " + value + " não existe.");
		} else if (value < root.value) {
			searched = SearchAndReturn(value, root.left);
		} else if (value > root.value) {
			searched = SearchAndReturn(value, root.right);
		} else {
			searched = root.value;
		}

		return searched;

	}
	
	public boolean Search(int value) throws Exception {
		if (this.root == null) {
			throw new Exception("Erro ao buscar na Árvore: Árvore vazia.");
		}
		return Search(value, this.root);
	}
	
	private boolean Search(int value, Node root) throws Exception {
		
		boolean hasBeenFound;

		if (root == null) {
			hasBeenFound = false;
		} else if (value < root.value) {
			hasBeenFound = Search(value, root.left);
		} else if (value > root.value) {
			hasBeenFound = Search(value, root.right);
		} else {
			hasBeenFound = true;
		}

		return hasBeenFound;

	}

	public int getGreatest() throws Exception {
		
		if (this.root == null) {
			throw new Exception("Erro ao buscaar o maior: Árvore vazia");
		}

		Node i;
		for (i = this.root; i.right != null; i = i.right);
		return i.value;
	}

	public int getSmallest() throws Exception {

		if (this.root == null) {
			throw new Exception("Erro ao buscaar o menor: Árvore vazia");
		}

		Node i;
		for (i = this.root; i.left != null; i = i.left);
		return i.value;
	}

	public int RemoveSmallest() throws Exception {
		
		int smallest;
		
		if (this.root == null) {
			throw new Exception("Erro ao remover na Árvore: Árvore vazia.");
		} else if (this.root.left == null) {
			smallest = this.root.value;
			this.root = this.root.right;
		} else {
			smallest = RemoveSmallest(this.root.left, this.root);
		}

		return smallest;

	}
	
	private int RemoveSmallest(Node root, Node rootParent) throws Exception {

		int smallest;

		if (root.left == null) {
			smallest = root.value;
			rootParent.left = root.right;
		} else {
			smallest = RemoveSmallest(root.left, root);
		}

		return smallest;

	}

	public void Print() throws Exception {

		if (root == null) {
			throw new Exception("Erro ao printar na Árvore: Árvore vazia.");
		}

		System.out.print("{ ");
		Print(root);
		System.out.println("\b\b }");

	}

	private void Print(Node root) {

		if (root != null) {
			Print(root.left);
			System.out.printf("%d, ", root.value);
			Print(root.right);
		}

	}

}