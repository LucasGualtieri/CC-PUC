package AEDs.AEDs_III.Materias.BasicosJava;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class DateFormat {
    public static void main(String[] args) {
		LocalDateTime currentDateTime = LocalDateTime.now();
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy - HH:mm a");
		String formattedDateTime = currentDateTime.format(formatter);
		System.out.println("Formatted current date and time: " + formattedDateTime);
    }
}
