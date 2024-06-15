package AEDs.AEDs_III.Materias.PatternMatching;

import java.time.Duration;
import java.time.Instant;

// clear && javac Concat.java && java Concat.java

public class Concat {

	static class Timer {
	
		private Instant startTime, endTime;

		public Timer() {}

		public void start() {
			this.startTime = Instant.now();
		}

		public void stop() {
			this.endTime = Instant.now();
		}

		public double time() {
			Duration duration = Duration.between(startTime, endTime);
			return duration.getSeconds() + duration.toNanosPart() / 1_000_000_000.0;
		}

		void compare(double time1, double time2) {

			if (time2 < time1) {
				double timesFaster = time1 / time2;
				System.out.printf("The builder time is %.0f times faster than the str time.\n", timesFaster);
			}
			
			else if (time2 > time1) {
				double timesSlower = time2 / time1;
				System.out.printf("The builder time is %.0f times slower than the str time.\n", timesSlower);
			}
			
			else System.out.println("Both times are equal.\n");
		}

		@Override
		public String toString() {
			return String.format("%f seconds", time());
		}
	}

	public static void main(String[] args) {

		@SuppressWarnings("unused")
		String str = "";
		StringBuilder builder = new StringBuilder();

		Timer timer = new Timer();

		double time1, time2;

		for (int i = 10; i < 10_000_000; i *= 10) {

			timer.start();
			for (int j = 0; j < i; j++) str += "a";
			timer.stop();

			time1 = timer.time();

			System.out.println("str: " + timer);

			timer.start();
			for (int j = 0; j < i; j++) builder.append("a");
			builder.toString();
			timer.stop();

			time2 = timer.time();

			System.out.println("builder: " + timer);

			timer.compare(time1, time2);

			System.out.println("===========================================================");
			
		}

	}
}
