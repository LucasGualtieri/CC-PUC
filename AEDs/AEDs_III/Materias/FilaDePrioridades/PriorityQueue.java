package AEDs.AEDs_III.Materias.FilaDePrioridades;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class PriorityQueue<T extends Comparable<T>> implements Iterable<T> {

	private T[] array;
	private int N;

	@SuppressWarnings("unchecked")
	public PriorityQueue() {
		array = (T[]) new Comparable[11]; // Initialize with a capacity of 10
		N = 0;
	}

	public void add(T item) {

		if (N == array.length) resize();

		array[N++] = item;

		heapifyUp();
	}

	public T poll() {

		if (N == 0) throw new IllegalStateException("Queue is empty");

		T item = array[0];
		array[0] = array[--N];

		heapifyDown();

		return item;
	}

	public T peek() {

		if (N == 0) throw new IllegalStateException("Queue is empty");

		return array[0];
	}

	private void resize() {
		array = Arrays.copyOf(array, array.length + array.length / 3);
	}

	private void heapifyUp() {

		int index = N - 1;

		while (index > 0) {

			int parentIndex = (index - 1) / 2;
			
			if (array[index].compareTo(array[parentIndex]) < 0) {
				// Check if sibling exists
				// int siblingIndex = index % 2 == 0 ? index - 1 : index + 1;
				// if (siblingIndex < N && siblingIndex != index) {
				// 	swap(parentIndex, siblingIndex);  // Swap parent with sibling first
				// }
				swap(index, parentIndex);
				index = parentIndex;
			}

			else break;
		}
	}

	private void heapifyDown() {

		int index = 0;

		while (index * 2 + 1 < N) {

			int smallerChildIndex = index * 2 + 1;
			int rightChildIndex = index * 2 + 2;

			if (rightChildIndex < N && array[rightChildIndex].compareTo(array[smallerChildIndex]) < 0) {
				smallerChildIndex = rightChildIndex;
			}

			if (array[index].compareTo(array[smallerChildIndex]) > 0) {
				// Check if sibling exists
				// int siblingIndex = smallerChildIndex % 2 == 0 ? smallerChildIndex - 1 : smallerChildIndex + 1;
				// if (siblingIndex < N && siblingIndex != index) {
				// 	swap(smallerChildIndex, siblingIndex);  // Swap parent with sibling first
				// }
				swap(index, smallerChildIndex);
				index = smallerChildIndex;
			}
			
			else break;
		}
	}

	private void swap(int index1, int index2) {
		T temp = array[index1];
		array[index1] = array[index2];
		array[index2] = temp;
	}

	public boolean isEmpty() { return N == 0; }

	public int getN() { return N; }

	@Override
	public Iterator<T> iterator() {
		return new PriorityQueueIterator();
	}

	private class PriorityQueueIterator implements Iterator<T> {
		private final PriorityQueue<T> copy;

		public PriorityQueueIterator() {
			copy = new PriorityQueue<>();
			for (int i = 0; i < N; i++) {
				copy.add(array[i]);
			}
		}

		@Override
		public boolean hasNext() {
			return !copy.isEmpty();
		}

		@Override
		public T next() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			return copy.poll();
		}
	}

	public String toString() {
		StringBuilder s = new StringBuilder();

		s.append("{ ");

		for (T item : this) {
			s.append(item + ", ");
		}

		if (s.length() > 2) s.delete(s.length() - 2, s.length());

		s.append(" }");

		return s.toString();
	}
}
