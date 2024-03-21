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

	byte ntobyte(byte c) { return '0' <= c && c <= '9' ? (c - '0') : c; } // Talvez lançar uma exceção?
	void setValue(byte value) { this->value = ntobyte(value) & 0b00000001; }
	void setValue(const Bit& value);

  public:
	Bit() { this->value = 0b00000000; }
	template<typename T>
	Bit(T value) { setValue(value); }

	byte getValue() const { return value; }

	String str() { return value == 1 ? String("1") : String("0"); }
	String toString() { return value == 1 ? "1" : "0"; }

	template<typename T>
	bool operator==(T rValue)   { return this->value == Bit(rValue).getValue(); }
	template<typename T>
	bool operator!=(T rValue)   { return this->value != Bit(rValue).getValue(); }
	template<typename T>
	bool operator> (Bit rValue) { return this->value >  Bit(rValue).getValue(); }
	template<typename T>
	bool operator>=(Bit rValue) { return this->value >= Bit(rValue).getValue(); }
	template<typename T>
	bool operator< (Bit rValue) { return this->value <  Bit(rValue).getValue(); }
	template<typename T>
	bool operator<=(Bit rValue) { return this->value <= Bit(rValue).getValue(); }
	Bit operator!  () { return Bit(!this->value); }

	template<typename T>
	Bit operator&  (T rValue) { return Bit(this->getValue() & Bit(rValue).getValue()); }
	template<typename T>
	Bit operator&= (T rValue) {
		*this = Bit(this->getValue() & Bit(rValue).getValue());
		return *this;
	}
	
	template<typename T>
	Bit operator|  (T rValue) { return Bit(this->getValue() | Bit(rValue).getValue()); }
	template<typename T>
	Bit operator|= (T rValue) {
		*this = Bit(this->getValue() | Bit(rValue).getValue());
		return *this;
	}
	
	template<typename T>
	Bit operator^  (T rValue) { return Bit(this->getValue() ^ Bit(rValue).getValue()); }
	template<typename T>
	Bit operator^= (T rValue) {
		*this = Bit(this->getValue() ^ Bit(rValue).getValue());
		return *this;
	}

	template<typename T>
	Bit operator=(T value) {
		this->setValue(value);
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

	Serial.println("b1 e b2 sao: " + String((b1 == b2) ? "Iguais" : "Diferentes"));

	Serial.println("b1: " + b1 + " - !b1: " + !b1);

	Serial.println("b1 & b2: " + (b1 & b2));
	Serial.println("b1 & 1: " + (b1 & 1));
	Serial.println("b1 & '1': " + (b1 & '1'));

	Serial.println("b1 | b2: " + (b1 | b2));
	Serial.println("b1 | 0: " + (b1 | 0));
	Serial.println("b1 | '0': " + (b1 | '0'));
	
	Serial.println("b1 ^ b2: " + (b1 ^ b2));
	Serial.println("b1 ^ 1: " + (b1 ^ 1));
	Serial.println("b1 ^ '1': " + (b1 ^ '1'));

	Serial.println("--------------------------------");
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