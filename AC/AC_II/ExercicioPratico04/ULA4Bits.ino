#define A_LED 13
#define B_LED 12
#define OUTPUT_LED 11
#define CARRY_OUT_LED 10

void WaitForInput() { while (!Serial.available()); }
// byte setBit(byte valor) { return valor & 0b00000001; }
byte setOpCode(byte valor) { return valor & 0b00000011; }

void turnON(int LED);
void turnScreenOFF();
void turnOFF(int LED);
void printBits(byte value);
void setLED(int count, ...);
String readString(String);
void setOutput(byte A, byte B, byte output, byte carryOut);

class Bit {
  private:
	byte value;

	byte ctobyte(byte c) { return '0' <= c && c <= '9' ? (c - '0') : c; } // Talvez lançar uma exceção?
	void setValue(byte value) { this->value = ctobyte(value) & 0b00000001; }
	void setValue(const Bit& value);

  public:
	Bit() { this->value = 0b00000000; }
	template<typename T>
	Bit(T value) { setValue(value); }

	byte getValue() const { return value; }

	String str() { return value == 1 ? String("1") : String("0"); }
	String toString() { return value == 1 ? "1" : "0"; }

	bool operator==(Bit rValue) { return this->getValue() == rValue.getValue(); }
	bool operator!=(Bit rValue) { return this->getValue() != rValue.getValue(); }
	bool operator> (Bit rValue) { return this->getValue() >  rValue.getValue(); }
	bool operator>=(Bit rValue) { return this->getValue() >= rValue.getValue(); }
	bool operator< (Bit rValue) { return this->getValue() <  rValue.getValue(); }
	bool operator<=(Bit rValue) { return this->getValue() <= rValue.getValue(); }
	Bit operator!  () { return Bit(!this->getValue()); }

	template<typename T>
	Bit operator&  (T rValue) { return Bit(this->getValue() & Bit(rValue).getValue()); }
	template<typename T>
	Bit operator&= (T rValue) {
		*this = Bit(this->getValue() & Bit(rValue).getValue());
		return *this;
	}

	Bit operator|  (Bit rValue) { return Bit(this->getValue() | rValue.getValue()); }
	Bit operator|= (Bit rValue) {
		*this = Bit(this->getValue() | rValue.getValue());
		return *this;
	}

	Bit operator^  (Bit rValue) { return Bit(this->getValue() ^ rValue.getValue()); }
	Bit operator^= (Bit rValue) {
		*this = Bit(this->getValue() ^ rValue.getValue());
		return *this;
	}

	Bit operator=(Bit bit) {
		this->setValue(bit.getValue());
		return *this;
	}

	Bit operator=(byte bit) {
		this->setValue(bit);
		return *this;
	}

	friend String operator+(String str, Bit bit) { // Funcionamento do Friend é complicado
		return str + bit.toString();
	}
};

void Bit::setValue(const Bit& value) { this->value = value.getValue(); }

class Nibble {
  public:
	Bit bits[4];
};

void setup() { 
	Serial.begin(9600);
	setLED(4, A_LED, B_LED, OUTPUT_LED, CARRY_OUT_LED);	
}

void loop() {

	String s = readString("Digite o 'OP. Code': ");

	Bit b1 = s[0], b2 = s[1];
	// Bit b1 = 0, b2 = 1;
	// Bit b1 = Bit(1), b2 = Bit(0);

	Serial.println(b1 == b2 ? "Iguais" : "Diferentes");

	Serial.println("b1: " + b1 + " - !b1: " + !b1);

	Serial.println("b1 & b2: " + (b1 & b2));

	Serial.println("b1 | b2: " + (b1 | b2));

	// Serial.println("--------------------------------");

	// Teste t;
	// int n = (t = atoi(s.c_str()));
	// Serial.println("T: " + String(t.getN()));
	// Serial.println("N: " + String(n));

	// byte A = setBit(ctobit(s[0]));
	// byte B = setBit(ctobit(s[1]));
	// byte code = setOpCode(ctobit(s[2]));
	// byte carryOut = 0b00000000;

	// byte output;

	// switch (code) {
	// case 0:
	// 	Serial.print("AND -> ");
	// 	output = A & B;
	// 	break;
	// case 1:
	// 	Serial.print("OR -> ");
	// 	output = A | B;
	// 	break;
	// case 2:
	// 	Serial.print("NOT -> ");
	// 	output = !A;
	// 	break;
	// case 3:
	// 	Serial.print("SOMA -> ");
	// 	output = A + B;
	// 	carryOut = bitRead(output, 1);
	// 	break;
	// }

	// output = setBit(output);

	// Serial.print("Output: ");
	// Serial.println(output);

	// setOutput(A, B, output, carryOut);
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