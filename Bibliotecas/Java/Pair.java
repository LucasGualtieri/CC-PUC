package Bibliotecas.Java;

public class Pair<First, Second> {

	public First first;
	public Second second;

	public Pair(First first, Second second) {
		this.first = first;
		this.second = second;
	}

	// public First getFirst() {
	// 	return first;
	// }

	// public void setFirst(First first) {
	// 	this.first = first;
	// }

	// public Second getSecond() {
	// 	return second;
	// }

	// public void setSecond(Second second) {
	// 	this.second = second;
	// }

	@Override
	public boolean equals(Object o) {

		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair<?, ?> pair = (Pair<?, ?>) o;

		if (first != null ? !first.equals(pair.first) : pair.first != null) return false;
		return second != null ? second.equals(pair.second) : pair.second == null;
	}

	@Override
	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	@Override
	public String toString() {
		return String.format("{ %s, %s }", first, second);
	}
}
