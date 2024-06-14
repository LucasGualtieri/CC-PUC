package AEDs.AEDs_III.Materias.PatternMatching;

class RopeNode {
	String value;
	RopeNode left, right;
	int length;

	// Construtor para folhas
	public RopeNode(String value) {
		this.value = value;
		this.left = this.right = null;
		this.length = value.length();
	}

	// Construtor para nós internos
	public RopeNode(RopeNode left, RopeNode right) {
		this.left = left;
		this.right = right;
		this.length = left.length + right.length;
		this.value = null;
	}
}

public class Rope {
	private RopeNode root;

	public Rope(String value) {
		this.root = new RopeNode(value);
	}

	private Rope(RopeNode root) {
		this.root = root;
	}

	// Concatenação
	public Rope concatenate(Rope other) {
		return new Rope(new RopeNode(this.root, other.root));
	}

	// Método auxiliar para encontrar o caractere no índice dado
	private char getChar(RopeNode node, int index) {
		if (node.value != null) {
			return node.value.charAt(index);
		}
		if (index < node.left.length) {
			return getChar(node.left, index);
		} else {
			return getChar(node.right, index - node.left.length);
		}
	}

	// Método para obter caractere no índice
	public char charAt(int index) {
		return getChar(root, index);
	}

	// Método auxiliar para conversão de RopeNode para String
	private String toString(RopeNode node) {
		if (node.value != null) {
			return node.value;
		}
		return toString(node.left) + toString(node.right);
	}

	// Método para conversão de Rope para String
	@Override
	public String toString() {
		return toString(root);
	}

	// Método auxiliar para dividir Rope
	private RopeNode[] split(RopeNode node, int index) {
		if (node.value != null) {
			return new RopeNode[] {
					new RopeNode(node.value.substring(0, index)),
					new RopeNode(node.value.substring(index))
			};
		}

		if (index < node.left.length) {
			RopeNode[] leftSplit = split(node.left, index);
			return new RopeNode[]{
					leftSplit[0],
					new RopeNode(leftSplit[1], node.right)
			};
		} else {
			RopeNode[] rightSplit = split(node.right, index - node.left.length);
			return new RopeNode[]{
					new RopeNode(node.left, rightSplit[0]),
					rightSplit[1]
			};
		}
	}

	// Inserção
	public Rope insert(String str, int index) {

		RopeNode[] splitNodes = split(root, index);
		RopeNode middleNode = new RopeNode(str);

		return new Rope(
			new RopeNode(
				splitNodes[0],
				new RopeNode(middleNode, splitNodes[1])
			)
		);
	}

	// Deleção
	public Rope delete(int start, int end) {

		RopeNode[] firstSplit = split(root, start);
		RopeNode[] secondSplit = split(firstSplit[1], end - start);

		return new Rope(
			new RopeNode(firstSplit[0], secondSplit[1])
		);
	}

	// Substring
	public Rope substring(int start, int end) {

		RopeNode[] firstSplit = split(root, start);
		RopeNode[] secondSplit = split(firstSplit[1], end - start);

		return new Rope(secondSplit[0]);
	}

	public static void main(String[] args) {
		Rope rope1 = new Rope("Hello ");
		Rope rope2 = new Rope("World!");
		Rope rope3 = rope1.concatenate(rope2);

		System.out.println(rope3); // Output: Hello World!
		System.out.println(rope3.charAt(0)); // Output: H
		System.out.println(rope3.charAt(6)); // Output: W

		Rope rope4 = rope3.insert("Beautiful ", 6);
		System.out.println(rope4); // Output: Hello Beautiful World!

		Rope rope5 = rope4.delete(6, 16);
		System.out.println(rope5); // Output: Hello World!

		Rope rope6 = rope5.substring(0, 5);
		System.out.println(rope6); // Output: Hello

		Rope rope7 = rope5.substring(6, 11);
		System.out.println(rope7); // Output: World
	}
}
