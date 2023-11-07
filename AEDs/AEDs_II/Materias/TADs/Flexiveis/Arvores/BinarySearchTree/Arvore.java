// clear && javac Arvore.java && java Arvore.java

class Arvore {

	static void TreeSort(int[] array) throws Exception {

		BST treeSort = new BST();

		for (int i = 0; i < array.length; i++) {
			treeSort.Insert(array[i]);
		}

		for (int i = 0; i < array.length; i++) {
			array[i] = treeSort.RemoveSmallest();
		}

	}

	static void ArrayPrint(int[] array) {
		System.out.print("{ ");
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%d, ", array[i]);
		}
		System.out.println("\b\b }");
	}

	public static void main(String[] args) throws Exception {

		System.out.println("------ ÁRVORE ------");

		BST arvore = new BST();

		arvore.InsertVoid(4);
		arvore.Insert(5);
		arvore.InsertVoid(6);
		arvore.Insert(3);
		arvore.InsertVoid(2);
		arvore.Insert(1);

		arvore.Print();

		// int removed = arvore.Remove(2);

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