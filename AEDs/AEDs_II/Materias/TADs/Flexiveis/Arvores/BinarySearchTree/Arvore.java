// clear && javac Arvore.java && java Arvore.java

import java.util.Random;

class Arvore {

	public static void TreeSort(int[] array) throws Exception {

		BST treeSort = new BST();

		for (int i = 0; i < array.length; i++) {
			treeSort.Insert(array[i]);
		}

		for (int i = 0; i < array.length; i++) {
			array[i] = treeSort.RemoveSmallest();
		}

	}

	// class TreeSort {
	// 	// private static TreeSort(Node root, int[] array) {
	// 	// 	if (root != null) {
	// 	// 		TreeSort(root.left, array);
	// 	// 		array[size++] = root.value;
	// 	// 		TreeSort(root.right, array);
	// 	// 	}
	// 	// }
	// }


	static void ArrayPrint(int[] array) {
		System.out.print("{ ");
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%d, ", array[i]);
		}
		System.out.println("\b\b }");
	}

	static int Log2(int N) {
		return (int)(Math.log(N)/ Math.log(2));
	}

	static Random generator = new Random(0);

	static int randomInt() {
		return Math.abs(generator.nextInt());
	}

	static void RandomInsertion(BST arvore) throws Exception {

		for (int i = 0; i < 10000; i++) {

			try {
				arvore.Insert(randomInt());
			} catch (Exception exception) {
				System.out.println(exception.getMessage());
			}
			
			int N = arvore.getSize();
			System.out.printf("Quantidade elementos: %d - ", N);
			System.out.printf("Altura: %d - ", arvore.getHeight());
			System.out.printf("Log(%d): %d - ", N, Log2(N));
			System.out.printf("Log(%d) x 1,39: %d\n", N, (int)(Log2(N) * 1.39));

		}

	}

	public static void main(String[] args) throws Exception {

		System.out.println("------ ÁRVORE ------");

		BST arvore = new BST();

		// RandomInsertion(arvore);

		arvore.InsertVoid(5);
		arvore.Insert(1);
		arvore.InsertVoid(9);
		arvore.Insert(0);
		arvore.InsertVoid(2);
		arvore.Insert(7);
		arvore.Insert(10);
		arvore.Insert(6);

		arvore.Print();
		
		int removed = arvore.Delete(5);
		System.out.println("Removido: " + removed);
		arvore.Print();

		removed = arvore.Delete(0);
		System.out.println("Removido: " + removed);
		arvore.Print();

		removed = arvore.Delete(9);
		System.out.println("Removido: " + removed);
		arvore.Print();

		removed = arvore.Delete(10);
		System.out.println("Removido: " + removed);
		arvore.Print();

		removed = arvore.Delete(2);
		System.out.println("Removido: " + removed);
		arvore.Print();

		removed = arvore.Delete(7);
		System.out.println("Removido: " + removed);
		arvore.Print();

		removed = arvore.Delete(1);
		System.out.println("Removido: " + removed);
		arvore.Print();

		removed = arvore.Delete(6);
		System.out.println("Removido: " + removed);
		try {
			arvore.Print();
		} catch (Exception exception) {
			System.out.println(exception.getMessage());
		}

		// int removed = arvore.RemoveDep(2);
		// System.out.printf("Removed: %d\n", removed);

		// try {
		// 	arvore.Insert(5);
		// } catch(Exception error) {
		// 	System.out.println(error.getMessage());
		// }

		// try {
		// 	arvore.SearchAndReturn(10);
		// } catch (Exception error) {
		// 	System.out.println(error.getMessage());
		// }

		// int searched = arvore.SearchAndReturn(5);
		// System.out.printf("Elemento procurado: %d\n", searched);

		// System.out.printf("Elemento 4 pertence à árvore? %b\n", arvore.Search(4));
		// System.out.printf("Elemento 11 pertence à árvore? %b\n", arvore.Search(11));

		// int greatestValue = arvore.getGreatest();
		// int smallestValue = arvore.getSmallest();

		// System.out.printf("Greatest tree value: %d\n", greatestValue);
		// System.out.printf("Smallest tree value: %d\n", smallestValue);

		// arvore.Print();

		// System.out.println("------- ARRAY -------");

		// int[] array = new int[] { 4, 5, 6, 3, 2, 1 };

		// ArrayPrint(array);
		// TreeSort(array);
		// ArrayPrint(array);

	}
}