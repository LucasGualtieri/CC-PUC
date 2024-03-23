#include <iostream>
#include <math.h>
#include <stdio.h>
#include <tuple>

// clear && g++ TestesUla.cc -lm && ./a.out

using namespace std;

typedef unsigned char Byte;
typedef string String;

String readString(String);

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

	int ToNumber(Nibble value);

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


	int ToNumber() {
		int result = 0;
		for (int i = 0; i < length; i++) {
			int teste = ((*this)[i] * pow(2, i));
			result += teste;
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
		byte val1 = this->ToNumber(*this);
		byte val2 = this->ToNumber(compared);
		return val1 > val2;
	}


	template<typename T>
	bool operator>= (T rValue) {
		byte val1 = this->ToNumber(*this);
		byte val2 = this->ToNumber(rValue);
		return val1 >= val2;
	}

	template<typename T>
	bool operator< (T rValue) {
		int val1 = this->ToNumber(*this);
		int val2 = this->ToNumber(rValue);
		return val1 < val2;
	}

	template<typename T>
	bool operator<= (T rValue) {
		byte val1 = this->ToNumber(*this);
		byte val2 = this->ToNumber(rValue);
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

int Nibble::ToNumber(Nibble value) {
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
	int value = nibble.ToNumber();
	if (0 <= value & value <= 9) c = '0' + value;
	if (10 <= value & value <= 15) c = ('A' - 10) + value;
	return c;
}

void println(String s = "") { cout << s << endl; }
void print(String s = "") { cout << s; }

void TestandoInstrucao() {

	String s = readString("Ler instrução: ");
	println("s = " + s);
	
	Instruction i(s);

	println("i[0] = " + i[0]);
	println("i[1] = " + i[1]);
	println("i[2] = " + i[2]);
	
	// i[2] = 0xA;
	// println("i[2] = " + i[2]);

	println();

	i = tuple<char, char, char> (9, 0xA, 'f');

	println("i[0] = " + i[0]);
	println("i[1] = " + i[1]);
	println("i[2] = " + i[2]);

	println();

	i = "0e0";

	println("i[0] = " + i[0]);
	println("i[1] = " + i[1]);
	println("i[2] = " + i[2]);

	println("i = " + i);
	println(i + " = i");

	println("---------------");
}

void overloadTesteDoBit() {

	String s = readString("Digite dois Bits: ");

	Bit b1 = s[0], b2 = s[1];
	// Bit b1 = 0, b2 = 1;
	// Bit b1 = Bit(1), b2 = Bit(0);

	println("b1 e b2 sao: " + String((b1 == b2) ? "Iguais" : "Diferentes"));

	println("b1: " + b1 + " - !b1: " + !b1);

	println();

	println(b1 + " & " + b2 + " = " + (b1 & b2));
	println(b1 + " & 1 = " + (b1 & 1));
	println(b1 + " & '1' = " + (b1 & '1'));

	println();

	println(b1 + " | " + b2 + " = " + (b1 | b2));
	println(b1 + " | 0 = " + (b1 | 0));
	println(b1 + " | '0' = " + (b1 | '0'));
	
	println();
	
	println(b1 + " ^ " + b2 + " = " + (b1 ^ b2));
	println(b1 + " ^ 1 = " + (b1 ^ 1));
	println(b1 + " ^ '1' = " + (b1 ^ '1'));

	println("--------------------------------");
}

void TestandoNibble() {
	String s = readString("Ler nibble: ");

	Nibble nibble(s[0]);
	println(nibble.str());

	println("nibble == 4 " + String(nibble == 4 ? "True" : "False"));
	println("nibble != 4 " + String(nibble != 4 ? "True" : "False"));
	println("nibble < 4 " + String(nibble < 4 ? "True" : "False"));
	println("nibble <= 4 " + String(nibble <= 4 ? "True" : "False"));
	println("nibble > 4 " + String(nibble > 4 ? "True" : "False"));
	println("nibble >= 4 " + String(nibble >= 4 ? "True" : "False"));
	println("nibble = " + nibble + " - !nibble = " + !nibble);

	println();

	println(nibble + " & 0100 = " + (nibble & 4));
	println(nibble + " &= 0100 = " + (nibble &= 4));
	println("nibble = " + nibble);

	println();
	
	nibble = 0xF;

	println(nibble + " | 0100 = " + (nibble | 4));
	println(nibble + " |= 0100 = " + (nibble |= 4));
	println("nibble = " + nibble);
	
	println();

	nibble = 'F';

	println(nibble + " ^ 0100 = " + (nibble ^ 4));
	println(nibble + " ^= 0100 = " + (nibble ^= 4));
	println("nibble = " + nibble);

	print("\nNibble: ");
	for (int i = 0; i < 4; i++) print(nibble[i].str());

	Nibble::bigEndian = true;

	print("\nNibble: ");
	for (int i = 0; i < 4; i++) print(nibble[i].str());

	println("\n--------------------------------");
	// nibble.forEach([](Bit bit) {
	// 	print(bit.str());
	// });
}

Nibble InstructionExecution(Instruction i) {
	
	Nibble output;

	switch (i[0].ToNumber()) {
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
		throw runtime_error("Error on InstructionExecution: Invalid instruction(" + i[0] + ").");
	}

	return output;
}

int main() {

	while(true) {
		// overloadTesteDoBit();
		// TestandoNibble();
		// TestandoInstrucao();
		Nibble output = InstructionExecution(Instruction("A04"));

		// setOutput(output); // Será uma função que printará na tela o resultado? e setará os LEDS

		println("Output = " + output);

		break;
	};
	return 0;
}

String readString(String msg = "") {
	cout << msg;
	String s;
	cin >> s;
	// s.trim();
	// Serial.println(s);
	return s;
}