using System;

class Program {

	static bool isPalin(string input) {

		int left = 0, right = input.Length - 1;
		char[] charArray = input.ToCharArray();

		while (left <= right) {
			if (charArray[left++] != charArray[right--]) return false;
		}
		
		return true;
	}
	
	public static void Main (string[] args) {
		string input;

		while(!(input = Console.ReadLine()).Equals("FIM")) {
			Console.WriteLine(isPalin(input) ? "SIM" : "NAO");
		}
	}
}