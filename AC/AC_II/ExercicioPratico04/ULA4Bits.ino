#define O3 13
#define O2 12
#define O1 11
#define O0 10

extern int __heap_start, *__brkval;

int freeMemory() {
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void throwException(String s) {
	Serial.println(s);
	Serial.println("The program has stopped.");
	Serial.flush();
	exit(0);
}

class Bit {

	byte value;

	byte numbertobit(byte c) {
		String error = "Error on Bit - setValue(" + String(c, DEC) + "): value() must be 1 or 0";
		if (!(c == '0' || c == '1' || c == 0 || c == 1)) throwException(error);
		return c - '0';
	}

	void setValue(byte value) { this->value = numbertobit(value) & 0b00000001; }
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
			String s = "Error on Nibble - Invalid assignment: value(" + String(b) + ") must be Hex";
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

	void setArray(byte x, byte y, byte s) {
		array[0] = x;
		array[1] = y;
		array[2] = s;
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
		if (s == "W" || s == "S") pos = 2;
		else if (s == "X" || s == "A") pos = 0;
		else if (s == "Y" || s == "B") pos = 1;
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

	byte instructionCount;

	String setStarPos(byte n) {

		String temp;

		if (PC + 4 == 100) n += 2;
		else if (PC + 4 >= 10) n++;

		for (int i = 0; i < n + 16; i++) temp += " ";
		temp += "|\n";

		for (int i = 0; i < n + 16; i++) temp += " ";
		temp += "V\n";

		return temp;
	}

	byte countInstructions(String s) {
		byte count = 0;
		for (int i = 0; i < s.length(); i++) if (s[i] == ' ') count++;
		return count;
	}

	void setInstructionLine(int start, int n, String origem, String& output) {
		for (int i = start; i < n && origem.substring(i, i + 3) != "FIM"; i += 4) {
			output += origem.substring(i, i + 3) + " | ";
		}
	}

  public:

	RegMem(String& s) {
		memory = &s;
		*memory += " FIM";
		PC = 0;
		instructionCount = countInstructions(*memory);
	}

	bool hasFinished() { return memory->substring(PC * 4) == "FIM"; } //  || (PC + 4) * 4 == 100

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

	output += String(PC + 4) + " | ";
	output += String(W.toNumber(), HEX) + " | ";
	output += String(X.toNumber(), HEX) + " | ";
	output += String(Y.toNumber(), HEX) + " | ";

	static byte starPos;
	if (PC == 0) starPos = 1;

	byte itemsCount = 5 * 4;

	if (PC < 4 || instructionCount <= 5) { // Linha que pode ser alterada: valor original: PC < 3
		
		Serial.print(setStarPos(starPos));
		if (PC > 0) starPos += 6; // Linha que pode ser alterada: valor original: não tem o IF
		
		if (instructionCount <= 5) {
			setInstructionLine(0, itemsCount, *memory, output);
			output += "FIM";
		}

		else {
			setInstructionLine(0, itemsCount + 1, *memory, output);
			output += "...";
		}
	}

	else if (PC < (instructionCount - 3) + 1) { // Linha que pode ser alterada: valor original: PC < instructionCount - 3

		Serial.print(setStarPos(starPos));
		
		output += "... | ";

		byte shift = (PC - 3) * 4; // Linha que pode ser alterada: valor original: (PC - 2) * 4

		setInstructionLine(shift, itemsCount + shift, *memory, output);

		output += "...";
	}

	else {

		Serial.print(setStarPos(starPos));
		starPos += 6;

		output += "... | ";

		byte shift = (instructionCount - 5) * 4;

		setInstructionLine(shift, itemsCount + shift, *memory, output);

		output += "FIM";
	}

	output.toUpperCase();

	return output;
}

Instruction RegMem::next() {

	int pos = PC * 4;

	Instruction inst = memory->substring(pos, pos + 3);

	PC++;

	return inst;
}

// ---------------------------------------------------------------------

void setOutput(RegMem program);
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

void setOutput(RegMem program) {
	
	Nibble output = program[1];

	int LED = 10;
	output.forEach([&LED](Bit bit) {
		digitalWrite(LED++, bit.getValue());
	});

	setDisplay(output.toNumber());

	Serial.println(program.str());
}

Nibble InstructionExecution(Instruction i) {
	
	Nibble output;

	switch (i["S"].toNumber()) {
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

void setup() { 
	Serial.begin(9600);
	setPinMode(11, 2, 3, 4, 5, 6, 7, 8, O0, O1, O2, O3);
}

void loop() {

	String s = readString("Insira o programa: ");

	RegMem program = s;
	setOutput(program);

	while(readString("Deseja comecar?: ") != "SIM"); // Talvez tenham jeitos mais elegantes de fazer isso

	while (!program.hasFinished()) {

		Instruction inst = program.next();

		program[2] = inst["X"];
		program[3] = inst["Y"];

		program[1] = InstructionExecution(inst);

		setOutput(program);

		delay(1000);
	}

	setDigitalOutput(LOW, 11, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13);
}