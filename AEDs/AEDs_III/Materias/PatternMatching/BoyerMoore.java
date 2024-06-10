package AEDs.AEDs_III.Materias.PatternMatching;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

// clear && javac BoyerMoore.java && java BoyerMoore.java

class BoyerMoore {

	static class Pattern {

		private int[] suffixes, dictionary;

		private byte[] pattern;
		
		public Pattern(String pattern) throws Exception, IOException {

			if (pattern.length() == 0) {
				throw new Exception("Error: Empty pattern.");
			}

			this.pattern = toByteArray(pattern);

			// buildSuffixesArray();
			buildDictionary();
		}

		public Pattern(byte[] pattern) { }
		
		private byte[] toByteArray(String str) throws IOException {

			ByteArrayOutputStream ba_out = new ByteArrayOutputStream();
			DataOutputStream dos = new DataOutputStream(ba_out);

			dos.writeBytes(str);

			return ba_out.toByteArray();
		}

		private void buildDictionary() {

			dictionary = new int[256];

			Arrays.fill(dictionary, -1);

			for (int i = 0; i < pattern.length - 1; i++) {
				dictionary[pattern[i]] = i;
			}
		}

		public void printDictionary() {
			for (int i = 0; i < dictionary.length; i++) {
				if (dictionary[i] != -1) {
					System.out.printf("%c - %d\n", (char)i, dictionary[i]);
				}
			}
		}

		private int dictSearch(int j, byte b) {
			return Math.max(j - dictionary[b], 1);
		}

		public List<Integer> match(String text) throws IOException {

			List<Integer> indices = new LinkedList<>();

			byte[] sequence = toByteArray(text);

			int lastOccurrence, goodSuffix;
			int shift = 1, len = (sequence.length - pattern.length) + 1;

			int i = 0, j = pattern.length - 1;

			while (i < len) {

				if (sequence[i + j] != pattern[j]) {
					lastOccurrence = dictSearch(j, sequence[i + j]);
					goodSuffix = 0;
					shift = Math.max(lastOccurrence, goodSuffix);
					j = pattern.length - 1;
					i += shift;
				}
				
				else if (sequence[i + j] == pattern[j]) {
					if (--j < 0) {
						indices.add(i);
						i++;
						j = pattern.length - 1;
					}
				}
			}

			return indices;
		}

		public List<Integer> match(byte[] sequence) { return null; }
	}

	public static void main(String[] args) throws Exception, IOException {

		String pattern = "ARARA";
		String text = "A ARARA VIU OUTRA ARARA EM ARARAQUARA";

		Pattern p = new Pattern(pattern);

		// p.printDictionary();

		List<Integer> list = p.match(text);

		System.out.println(list);
	}
}