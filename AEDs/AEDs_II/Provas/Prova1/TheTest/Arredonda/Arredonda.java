package AEDs.AEDs_II.Provas.Prova1.TheTest.Arredonda;

import java.util.*;

// clear && javac Arredonda.java && java Arredonda < pub.in > result.txt

public class Arredonda {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

		float num, cutoff;

        while (scanner.hasNext()) {

			num = Float.parseFloat(scanner.nextLine());
			cutoff = Float.parseFloat(scanner.nextLine());

			
			float numF = num - (int)num;
			float cutoffF = cutoff - (int)cutoff;

			// System.out.println(fractionLen(num));

			if (numF >= cutoffF) {
				System.out.printf("%.0f\n", Math.ceil(num));
			} else {
				System.out.printf("%.0f\n", Math.floor(num));
			}
        }

        scanner.close();
    }
}