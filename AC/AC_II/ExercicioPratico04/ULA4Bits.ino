#define O3 13
#define O2 12
#define O1 11
#define O0 10

void throwException(String s) {
	Serial.println(s);
	Serial.println("The program has stopped.");
	exit(0);
}

class Bit {

	byte value;

	byte numbertobit(byte c) {
		// String error = "Error on Bit - setValue(" + String(c + "") + " ): value() must be 1 or 0";
		// if (c != '0' && c != '1') throw runtime_error(error);
		return c - '0';
	}

	void setValue(byte value) { this->value = numbertobit(value) & 0b00000001; }
	void setValue(const Bit& value);
	// void setValue(const Bit& value) { this->value = value.getValue(); }

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
	int operator* (T rValue) { return this->getValue() * rValue; }

	template<typename T>
	Bit operator=(T value) {
		this->setValue(value);
		return *this;
	}

	// Funcionamento do Friend é complicado
	friend String operator+(String str, Bit bit) { return str + bit.toString(); }
	friend String operator+(Bit bit, String str) { return bit.toString() + str;	}
	friend String operator+=(String& str, Bit bit) { return str += bit.toString();	}
};
void Bit::setValue(const Bit& value) { this->value = value.getValue(); }

class Nibble {

	Bit bits[4];

	byte chartobyte(byte c) {
		if (('A' <= c && c <= 'F')) c -= 55;
		else if (('a' <= c && c <= 'f')) c -= 55 + 32;
		else if ('0' <= c && c <= '9') c -= '0';
		return c;
	}

	int toNumber(Nibble value);

	void setArray(byte b) {
		// String error = String("Error on Nibble - Invalid assignment: value must be Hex");
		if (b > 15) {
			String s = "Error on Nibble - Invalid assignment: value(";
			// s += "Error on Nibble - Invalid assignment: value(%d - '%c') must be Hex", b, b;
			throwException(s);
		}

		for (int i = 0; i < length; b /= 2, i++) {
			bits[i] = b % 2;
		}
	}

	void setArray(Nibble nibble);

	byte endianess(byte pos) {
		if (bigEndian) pos = length - pos - 1; 
		return pos;
	}

  public:

	static bool bigEndian;

	const byte length = 4;

	Nibble() { for (int i = 0; i < length; i++) bits[i] = 0; }

	template<typename Function>
	void forEach(Function fn); // Possível problema aqui, como ele sabe onde é o fim? Talvez trocar para um for normal

	String str() {
		String s = "";
		this->forEach([&s](Bit bit) { s = bit + s; });
		return s;
	}

	Bit& operator[](byte pos) { return bits[endianess(pos)]; }

	int potencia(int n, int x) {

		if (x == 0) return 1;
		if (x == 1) return n;

		int result = 1;
		for (int i = 0; i < x; i++) result *= n;

		return result;
	}

	byte toNumber() {
		int result = 0;
		for (int i = 0; i < length; i++) {
			result += (*this)[i] * potencia(2, i);
		}
		return result;
	}

	template<typename T>
	bool operator==(T rValue) {

		bool equals = true;
		Nibble compared(rValue);

		for (int i = 0; i < length; i++) {
			if ((*this)[i] != compared[i]) {
				equals = false;
				i = length;
			}
		}

		return equals;
	}

	template<typename T>
	bool operator!=(T rValue) {

		bool different = false;
		Nibble compared(rValue);

		for (int i = 0; i < length; i++) {
			if ((*this)[i] != compared[i]) {
				different = true;
				i = length;
			}
		}

		return different;
	}

	template<typename T>
	bool operator> (T rValue) {
		Nibble compared(rValue);
		byte val1 = this->toNumber(*this);
		byte val2 = this->toNumber(compared);
		return val1 > val2;
	}


	template<typename T>
	bool operator>= (T rValue) {
		byte val1 = this->toNumber(*this);
		byte val2 = this->toNumber(rValue);
		return val1 >= val2;
	}

	template<typename T>
	bool operator< (T rValue) {
		int val1 = this->toNumber(*this);
		int val2 = this->toNumber(rValue);
		return val1 < val2;
	}

	template<typename T>
	bool operator<= (T rValue) {
		byte val1 = this->toNumber(*this);
		byte val2 = this->toNumber(rValue);
		return val1 <= val2;
	}

	Nibble operator!() {
		Nibble result;
		for (int i = 0; i < length; i++) {
			result[i] = !((*this)[i]);
		}
		return result;
	}

	template<typename T>
	Nibble operator& (T rValue) {
		Nibble result(rValue);
		for (int i = 0; i < length; i++) {
			result[i] &= (*this)[i];
		}
		return result;
	}

	template<typename T>
	Nibble operator&= (T rValue) {
		Nibble result(rValue);
		for (int i = 0; i < length; i++) {
			(*this)[i] &= result[i];
		}
		return *this;
	}

	template<typename T>
	Nibble operator| (T rValue) {
		Nibble result(rValue);
		for (int i = 0; i < length; i++) {
			result[i] |= (*this)[i];
		}
		return result;
	}

	template<typename T>
	Nibble operator|= (T rValue) {
		Nibble result(rValue);
		for (int i = 0; i < length; i++) {
			(*this)[i] |= result[i];
		}
		return *this;
	}

	template<typename T>
	Nibble operator^ (T rValue) {
		Nibble result(rValue);
		for (int i = 0; i < length; i++) {
			result[i] ^= (*this)[i];
		}
		return result;
	}

	template<typename T>
	Nibble operator^= (T rValue) {
		Nibble result(rValue);
		for (int i = 0; i < length; i++) {
			(*this)[i] ^= result[i];
		}
		return *this;
	}
	
	template<typename T>
	Nibble operator=(T value) {
		this->setArray(chartobyte(value));
		return *this;
	}

	Nibble operator=(Nibble value) {
		this->setArray(value);
		return *this;
	}

	friend String operator+(String str, Nibble nibble) { // Funcionamento do Friend é complicado
		return str + nibble.str();
	}

	friend String operator+(Nibble nibble, String str) { // Funcionamento do Friend é complicado
		return nibble.str() + str;
	}
};

template<typename Function>
void Nibble::forEach(Function fn) { for (Bit bit : bits) fn(bit); }

void Nibble::setArray(Nibble nibble) {
	for (int i = 0; i < length; i++) {
		bits[i] = nibble[i];
	}
}

int Nibble::toNumber(Nibble value) {
	int result = 0;
	for (int i = 0; i < length; i++) {
		int teste = (value[i] * pow(2, i));
		result += teste;
	}
	return result;
}

bool Nibble::bigEndian = false;

class Instruction {
	Nibble array[3];

	void setArray(String instruction) {
		for (int i = 0; i < 3; i++) array[i] = instruction[i];
	}

	void setArray(byte x, byte y, byte w) {
		array[0] = x;
		array[1] = y;
		array[2] = w;
	}

	char toHex(Nibble nibble);

	void toUpper(String& s) {
		for (int i = 0; i < s.length(); i++) {
			if ('a' <= s[0] && s[0] <= 'z') s[i] = s[i] - 32;
		}
	}

  public:
	Instruction(char x, char y, char w) { setArray(x, y, w); }

	Instruction(String instruction) {
		String error = String("Error on Instruction - Constructor(): String(" + instruction + ") is not an instruction.");
		if (instruction.length() != 3) throwException(error);
		setArray(instruction);
	}

	Nibble& operator[](byte pos) { return array[pos]; }

	Nibble& operator[](String s) {
		byte pos;
		toUpper(s);
		if (s == "w" || s == "W") pos = 0;
		else if (s == "X" || s == "A") pos = 1;
		else if (s == "Y" || s == "B") pos = 2;
		else {
			throwException("Error on Instruction - Invalid array position(" + s + ").");
		}

		return array[pos];
	}

	Instruction& operator=(String instruction) {
		String error = String("Error on Instruction - Invalid assignment: String(" + instruction + ") is not an instruction.");
		if (instruction.length() != 3) throwException(error);
		setArray(instruction);
		return *this;
	}

	template<typename T>
	Instruction& operator=(T instruction) {
		setArray(instruction);
		return *this;
	}

	String str() {
		String s = "";

		s = s + toHex((*this)[0]);
		s = s + toHex((*this)[1]);
		s = s + toHex((*this)[2]);

		return s;
	}

	friend String operator+(String str, Instruction i) { return str + i.str(); }

	friend String operator+(Instruction i, String str) { return i.str() + str; }
};

char Instruction::toHex(Nibble nibble) {
	char c;
	int value = nibble.toNumber();
	if (0 <= value & value <= 9) c = '0' + value;
	if (10 <= value & value <= 15) c = ('A' - 10) + value;
	return c;
}

// ---------------------------------------------------------------------

void setOuput(Nibble output);
Nibble InstructionExecution(Instruction i);
void WaitForInput() { while (!Serial.available()); }

String readString(String msg = "") {
	Serial.print(msg);
	WaitForInput();
	String s = Serial.readString();
	s.trim();
	Serial.println(s);
	return s;
}

String* split(char c, String s) {

	int count = 1;

	for (int i = 0; i < s.length(); i++) if (s[i] == c) count++;

	String* array = new String[count + 1];

	array[count] = "FIM";

	int arrayIndex = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != c) {
			array[arrayIndex] += s[i];
		} else {
			arrayIndex++;
		}
	}

	return array;
}

void setPinMode(int count, ...) {
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++) {
		pinMode(va_arg(args, int), OUTPUT);
	}

	va_end(args);
}

void setDigitalOutput(int state, int count, ...) {
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++) {
		digitalWrite(va_arg(args, int), state);
	}

	va_end(args);
}

void setDisplay(byte value) {

	setDigitalOutput(LOW, 7, 2, 3, 4, 5, 6, 7, 8);

	if (value == 0x0) setDigitalOutput(HIGH, 6, 2, 3, 4, 5, 6, 7);
	else if (value == 0x1) setDigitalOutput(HIGH, 2, 2, 3);
	else if (value == 0x2) setDigitalOutput(HIGH, 5, 4, 2, 8, 6, 5);
	else if (value == 0x3) setDigitalOutput(HIGH, 5, 4, 2, 8, 3, 5);
	else if (value == 0x4) setDigitalOutput(HIGH, 4, 7, 2, 8, 3);
	else if (value == 0x5) setDigitalOutput(HIGH, 5, 4, 7, 8, 3, 5);
	else if (value == 0x6) setDigitalOutput(HIGH, 6, 4, 7, 8, 6, 5, 3);
	else if (value == 0x7) setDigitalOutput(HIGH, 3, 4, 2, 3);
	else if (value == 0x8) setDigitalOutput(HIGH, 7, 2, 3, 4, 5, 6, 7, 8);
	else if (value == 0x9) setDigitalOutput(HIGH, 5, 2, 3, 4, 7, 8);
	else if (value == 0xA) setDigitalOutput(HIGH, 6, 2, 3, 4, 6, 7, 8);
	else if (value == 0xB) setDigitalOutput(HIGH, 5, 3, 5, 6, 7, 8);
	else if (value == 0xC) setDigitalOutput(HIGH, 4, 4, 7, 6, 5);
	else if (value == 0xD) setDigitalOutput(HIGH, 5, 8, 6, 5, 3, 2);
	else if (value == 0xE) setDigitalOutput(HIGH, 5, 8, 6, 5, 4, 7);
	else if (value == 0xF) setDigitalOutput(HIGH, 4, 8, 6, 4, 7);
}

void setup() { 
	Serial.begin(9600);
	setPinMode(11, 2, 3, 4, 5, 6, 7, 8, O0, O1, O2, O3);
}

Nibble InstructionExecution(Instruction i) {
	
	Nibble output;

	switch (i["W"].toNumber()) {
	case 0x0:
		output = !i["B"];
		break;
	case 0x1:
		output = !(!i["A"] & i["B"]);
		break;
	case 0x2:
		output = !i["A"] & i["B"];
		break;
	case 0x3:
		output = 0x0;
		break;
	case 0x4:
		output = !(i["A"] & i["B"]);
		break;
	case 0x5:
		output = !i["A"];
		break;
	case 0x6:
		output = i["A"] ^ i["B"];
		break;
	case 0x7:
		output = i["A"] & !i["B"];
		break;
	case 0x8:
		output = !i["A"] | !i["B"];
		break;
	case 0x9:
		output = !i["A"] ^ !i["B"];
		break;
	case 0xA:
		output = i["B"];
		break;
	case 0xB:
		output = i["A"] & i["B"];
		break;
	case 0xC:
		output = 0xF;
		break;
	case 0xD:
		output = i["A"] | !i["B"];
		break;
	case 0xE:
		output = i["A"] | i["B"];
		break;
	case 0xF:
		output = i["A"];
		break;
	default:
		throwException("Error on InstructionExecution: Invalid instruction(" + i[0] + ").");
	}

	return output;
}

void setOuput(Nibble output) {
	
	// Talvez criar uma função chamada setLED para abstrair essa parte do código
	int LED = 10;
	output.forEach([&LED](Bit bit) {
		digitalWrite(LED++, bit.getValue());
	});

	setDisplay(output.toNumber());


}

// void loop() {

// 	// readString("Comecar: ");

// 	String s = readString("Digite uma string: ");

// 	String* array = split(' ', s);

// 	for (int i = 0; array[i] != "FIM"; i++) {
// 		Serial.println("String: " + array[i]);
// 	}

// 	delete[] array;

// 	// String thisString = String(13, HEX); // Usar para mostrar os resultado em Hexa

// 	s = readString("Digite a instrucao: ");

// 	Nibble output = InstructionExecution(Instruction(s));
// 	Serial.println("Output = " + output);

// 	setOuput(output);
// }
void loop() {

	while(readString("Deseja começar?: ") != "SIM"); // Talvez tenham jeitos mais elegantes de fazer isso

	String s = readString("Insira o programa: ");
	String* array = split(' ', s);

	for (int i = 0; array[i] != "FIM"; i++) {
		// Instruction i = array[pointerIncrement()];
		Instruction inst = array[i];

		// array[1] = i["W"];
		// array[2] = i["X"];
		// array[3] = i["Y"];

		Nibble output = InstructionExecution(inst);

		setOuput(output);
		// setOuput(output, array);

		delay(1000);
	}

	// Conferir / descomentar a exceção do Bit

}