#include <iostream>
#include <math.h>
#include <stdio.h>

// clear && g++ TestesUla.cc -lm && ./a.out

using namespace std;

typedef unsigned char Byte;
typedef string String;

String readString(String);

class Bit {

	Byte value;

	Byte numbertobit(Byte c) {
		// if (c != '0' && c != '1') {
		// 	throw runtime_error("Error on Bit - setValue(): value must be 1 or 0");
		// }
		return c - '0';
	}

	void setValue(Byte value) { this->value = numbertobit(value) & 0b00000001; }
	void setValue(const Bit& value);

  public:
	Bit() { this->value = 0b00000000; }
	template<typename T>
	Bit(T value) { setValue(value); }

	Byte getValue() const { return value; }

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

	friend String operator+(String str, Bit bit) { // Funcionamento do Friend é complicado
		return str + bit.toString();
	}

	friend String operator+(Bit bit, String str) { // Funcionamento do Friend é complicado
		return bit.toString() + str;
	}

	friend String operator+=(String& str, Bit bit) { // Funcionamento do Friend é complicado
		return str += bit.toString();
	}
};
void Bit::setValue(const Bit& value) { this->value = value.getValue(); }

class Nibble {

	Bit bits[4];

	Byte chartobyte(Byte c) {
		if (('A' <= c && c <= 'F')) c -= 55;
		else if (('a' <= c && c <= 'f')) c -= 55 + 32;
		else if ('0' <= c && c <= '9') c -= '0';
		return c;
	}

	void setArray(Byte Byte) {
		if (Byte > 15) throw runtime_error("Error on Nibble - Constructor(): value > 15");

		for (int i = 0; i < length; Byte /= 2, i++) {
			bits[i] = Byte % 2;
		}
	}

	Byte endianess(Byte pos) {
		if (bigEndian) pos = length - pos - 1; 
		return pos;
	}

	int nibbleToNumber(Nibble value) {
		int result = 0;
		for (int i = 0; i < length; i++) {
			int teste = (value[i] * pow(2, i));
			result += teste;
		}
		return result;
	}

  public:

	static bool bigEndian;

	const Byte length = 4;

	Nibble() { for (int i = 0; i < length; i++) bits[i] = 0; }

	Nibble(Byte value) { setArray(chartobyte(value)); }

	template<typename Function>
	void forEach(Function fn) { for (Bit bit : bits) fn(bit); } // Possível problema aqui, como ele sabe onde é o fim? Talvez trocar para um for normal

	String str() {
		String s = "";
		this->forEach([&s](Bit bit) { s = bit + s; });
		return s;
	}

	Bit& operator[](Byte pos) { return bits[endianess(pos)]; }

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
		Byte val1 = nibbleToNumber(*this);
		Byte val2 = nibbleToNumber(compared);
		return val1 > val2;
	}

	template<typename T>
	bool operator>= (T rValue) {
		Byte val1 = nibbleToNumber(*this);
		Byte val2 = nibbleToNumber(rValue);
		return val1 >= val2;
	}

	template<typename T>
	bool operator< (T rValue) {
		int val1 = nibbleToNumber(*this);
		int val2 = nibbleToNumber(rValue);
		return val1 < val2;
	}

	template<typename T>
	bool operator<= (T rValue) {
		Byte val1 = nibbleToNumber(*this);
		Byte val2 = nibbleToNumber(rValue);
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

	friend String operator+(String str, Nibble nibble) { // Funcionamento do Friend é complicado
		return str + nibble.str();
	}

	friend String operator+(Nibble nibble, String str) { // Funcionamento do Friend é complicado
		return nibble.str() + str;
	}
};

bool Nibble::bigEndian = false ;

void println(String s = "") { cout << s << endl; }
void print(String s = "") { cout << s; }

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

	println("--------------------------------");
	// nibble.forEach([](Bit bit) {
	// 	print(bit.str());
	// });
}

int main() {

	while(true) {
		// overloadTesteDoBit();
		TestandoNibble();
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