#include <stdarg.h>

#define SEC_TO_MS(segundos) (segundos * 1000)
#define CLOCK_SPEED SEC_TO_MS(1)

const int redLED = 13;
const int yellowLED = 12;
const int greenLED = 11;
const int blueLED = 10; // LED Azul, pisca a cada Clock

// Tempo em clock que cada luz do Semáforo dura

#define RED_CLK_TIME 3
#define YELLOW_CLK_TIME 2
#define GREEN_CLK_TIME 4

// Tempo somado para facilitar as contas no código do Semaforo

#define RED_SEMAFORO_TIME RED_CLK_TIME
#define YELLOW_SEMAFORO_TIME RED_CLK_TIME + GREEN_CLK_TIME + YELLOW_CLK_TIME
#define GREEN_SEMAFORO_TIME RED_CLK_TIME + GREEN_CLK_TIME

void setLED(int count, ...) {
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++) {
		pinMode(va_arg(args, int), OUTPUT);
	}

	va_end(args);
}

void setup() {
	Serial.begin(9600);
	setLED(4, redLED, yellowLED, greenLED, blueLED);
}

void turnON(int LED) {
	digitalWrite(LED, HIGH);
}

void turnOFF(int LED) {
	digitalWrite(LED, LOW);
}

void toggleLED(int LED) {
	digitalWrite(LED, digitalRead(LED) == HIGH ? LOW : HIGH);
}

bool isLEDOn(int LED) {
	return digitalRead(LED) == HIGH;
}

void turnSemaforoOFF() {
	turnOFF(redLED);
	turnOFF(greenLED);
	turnOFF(yellowLED);
}

void Semaforo() {

	static int clkCount = 1;

	turnSemaforoOFF();

	if (clkCount <= RED_SEMAFORO_TIME) {
		turnON(redLED);
	} else if (clkCount <= GREEN_SEMAFORO_TIME) {
		turnON(greenLED);
	} else if (clkCount <= YELLOW_SEMAFORO_TIME) {
		turnON(yellowLED);
	}

	clkCount = clkCount == YELLOW_SEMAFORO_TIME ? 1 : clkCount + 1;
}

void loop() { // Cada loop representa um clock
	toggleLED(blueLED);
	if (isLEDOn(blueLED)) Semaforo();
	delay(CLOCK_SPEED);
}