#define O3 13
#define O2 12
#define O1 11
#define O0 10

void throwException(String s) {
	Serial.println(s);
	Serial.println("The program has stopped.");
	delay(1000);
	exit(0);
}

class Bit {

	byte value;

	void setValue(byte value) { this->value = (value - '0') & 0b00000001; }
	void setValue(const Bit& value);

  public:
	Bit() { this->value = 0b00000000; }
	template<typename T>
	Bit(T value) { setValue(value); }

	byte getValue() const { return value; }

	String str() { return value == 1 ? String("1") : String("0"); }

	template<typename T>
	bool operator==(T rValue)   { return this->value == Bit(rValue).getValue(); }
	template<typename T>
	bool operator!=(T rValue)   { return this->value != Bit(rValue).getValue(); }
	Bit operator!  () { return Bit(!this->value); }

	template<typename T>
	Bit operator&  (T rValue) { return Bit(this->getValue() & Bit(rValue).getValue()); }
	
	template<typename T>
	Bit operator|  (T rValue) { return Bit(this->getValue() | Bit(rValue).getValue()); }
	
	template<typename T>
	Bit operator^  (T rValue) { return Bit(this->getValue() ^ Bit(rValue).getValue()); }

	template<typename T>
	int operator* (T rValue) { return this->getValue() * rValue; }

	template<typename T>
	Bit operator=(T value) {
		this->setValue(value);
		return *this;
	}

	// Funcionamento do Friend é complicado
	friend String operator+(String str, Bit bit) { return str + bit.str(); }
	friend String operator+(Bit bit, String str) { return bit.str() + str; }
	friend String operator+=(String& str, Bit bit) { return str += bit.str(); }
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

		if (b > 15) {
			String s = "Error on Nibble - Invalid assignment: value(" + String(b) + ")  must be Hex";
			throwException(s);
		}

		for (int i = 0; i < length; b /= 2, i++) bits[i] = b % 2;
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
	void forEach(Function fn); // PossÃ­vel problema aqui, como ele sabe onde Ã© o fim? Talvez trocar para um for normal

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
			result[i] = result[i] & (*this)[i];
		}
		return result;
	}

	template<typename T>
	Nibble operator| (T rValue) {
		Nibble result(rValue);
		for (int i = 0; i < length; i++) {
			result[i] = result[i] | (*this)[i];
		}
		return result;
	}

	template<typename T>
	Nibble operator^ (T rValue) {
		Nibble result(rValue);
		for (int i = 0; i < length; i++) {
			result[i] = result[i] ^ (*this)[i];
		}
		return result;
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

	// Funcionamento do Friend é complicado
	friend String operator+(String str, Nibble nibble) { return str + nibble.str(); }
	friend String operator+(Nibble nibble, String str) { return nibble.str() + str; }
};

template<typename Function>
void Nibble::forEach(Function fn) { for (int i = 0; i < 4; i++) fn(bits[i]); }

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

  public:
	Instruction() {}
	Instruction(char x, char y, char w) { setArray(x, y, w); }

	Instruction(String instruction) {
		String error = String("Error on Instruction - Constructor(): String(" + instruction + ") is not an instruction.");
		if (instruction.length() != 3) throwException(error);
		setArray(instruction);
	}

	Nibble& operator[](byte pos) { return array[pos]; }

	Nibble& operator[](String s) {
		byte pos;
		s.toUpperCase();
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
		String s;

		s += String((*this)[0].toNumber(), HEX);
		s += String((*this)[1].toNumber(), HEX);
		s += String((*this)[2].toNumber(), HEX);

		s.toUpperCase();

		return s;
	}

	friend String operator+(String str, Instruction i) { return str + i.str(); }

	friend String operator+(Instruction i, String str) { return i.str() + str; }
};

class RegMem {

	byte PC;
	Nibble W, X, Y;

	String* memory;

	bool hasEnded;

  public:

	RegMem(String* s) {
		memory = s;
		*memory += " FIM";
		PC = 0;
		hasEnded = false;
	}

	bool hasFinished() { return hasEnded; }

	Nibble& operator[](byte pos) {
		if (pos == 1) return W;
		else if (pos == 2) return X;
		else if (pos == 3) return Y;
	}

	Instruction next();

	String str();
};

String RegMem::str() {

	String output;

	output += String(PC + 4 - 1) + " | ";
	output += String(W.toNumber(), HEX) + " | ";
	output += String(X.toNumber(), HEX) + " | ";
	output += String(Y.toNumber(), HEX) + " | ";

	// int pos = (PC - 1) * 4;
	for (int i = PC * 4; memory->substring(i, i + 3) != "FIM" && i < (10 * 4) + (PC * 4); i += 4) {
		output += memory->substring(i, i + 3) + " | ";
	}

	output += "FIM";

	output.toUpperCase();

	return output;
}

Instruction RegMem::next() {

	int pos = PC * 4;

	Instruction inst = memory->substring(pos, pos + 3);

	PC++;

	if (memory->substring(PC * 4) == "FIM") hasEnded = true;

	return inst;
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

void setOuput(RegMem program, Nibble output);
void setOuput(RegMem program, Nibble output) {
	
	// Talvez criar uma função chamada setLED para abstrair essa parte do código
	int LED = 10;
	output.forEach([&LED](Bit bit) {
		digitalWrite(LED++, bit.getValue());
	});

	Serial.println(program.str());
}

void loop() {

	while(readString("Deseja comecar?: ") != "SIM"); // Talvez tenham jeitos mais elegantes de fazer isso

	String s = readString("Insira o programa: ");

	RegMem program = &s;

	while (!program.hasFinished()) {

		Instruction inst = program.next();

		program[1] = inst["W"];
		program[2] = inst["A"];
		program[3] = inst["B"];

		Nibble output = InstructionExecution(inst);

		setOuput(program, output);

		delay(1000);
	}

	setDigitalOutput(LOW, 11, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13);
}