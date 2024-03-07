#define A_LED 13
#define B_LED 12
#define OUTPUT_LED 11
#define CARRY_OUT_LED 10

#define ctobyte(c) (byte)('0' <= c && c <= '9' ? (c - '0') : c)

void WaitForInput() { while (!Serial.available()); }
byte setBit(byte valor) { return valor & 0b00000001; }
byte setOpCode(byte valor) { return valor & 0b00000011; }

void turnON(int LED);
void turnScreenOFF();
void turnOFF(int LED);
void printBits(byte value);
void setLED(int count, ...);
String readString(String msg = "");
void setOutput(byte A, byte B, byte output, byte carryOut);

void setup() { 
	Serial.begin(9600);
	setLED(4, A_LED, B_LED, OUTPUT_LED, CARRY_OUT_LED);	
}

void loop() {

	String s = readString("Digite o OP. Code: ");
	
	byte A = setBit(ctobyte(s[0]));
	byte B = setBit(ctobyte(s[1]));
	byte code = setOpCode(ctobyte(s[2]));
	byte carryOut = 0b00000000;

	byte output;

	switch (code) {
	case 0:
		Serial.print("AND -> ");
		output = A & B;
		break;
	case 1:
		Serial.print("OR -> ");
		output = A | B;
		break;
	case 2:
		Serial.print("NOT -> ");
		output = !A;
		break;
	case 3:
		Serial.print("SOMA -> ");
		output = A + B;
		carryOut = bitRead(output, 1);
		break;
	}

	output = setBit(output);

	Serial.print("Output: ");
	Serial.println(output);

	setOutput(A, B, output, carryOut);
}

void setLED(int count, ...) {
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++) {
		pinMode(va_arg(args, int), OUTPUT);
	}

	va_end(args);
}

String readString(String msg = "") {
	Serial.print(msg);
	WaitForInput();
	String s = Serial.readString();
	s.trim();
	Serial.println(s);
	return s;
}

void printBits(byte value) {
	Serial.print("{ ");
	for (int i = 7; i >= 0; i--) {
		Serial.print(bitRead(value, i));
		Serial.print(", ");
	}
	Serial.println("}");
}

void setOutput(byte A, byte B, byte output, byte carryOut) {

	turnScreenOFF();

	if (A == 1) turnON(A_LED);
	if (B == 1) turnON(B_LED);
	if (output == 1) turnON(OUTPUT_LED);
	if (carryOut == 1) turnON(CARRY_OUT_LED);
}