#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <biblioteca_cpp.h>

bool checkDate(string date) {
	date = MaskDate(date);

	time_t now = time(0);
	tm* ltm = localtime(&now);

	int currentYear = 1900 + ltm->tm_year;
	int currentMonth = 1 + ltm->tm_mon;
	int currentDay = ltm->tm_mday;

	int year = stoi(&date[6]);
	int month = stoi(&date[3]);
	int day = stoi(date);

	if (month > 12) return 0;
	if (day > 31) return 0;

	if (year < currentYear) return 1;
	if (year == currentYear) {
		if (month < currentMonth) return 1;
	}
	if (month == currentMonth) {
		if (day <= currentDay) {
			return 1;
		}
	}
	return 0;
}

class employee {
	int id;
	string name;
	string admissionDate;
	string cpf;
	char role;
	float salary;

public:
	// Constructor
	employee() {
		id = Rand(0, 1000);
		admissionDate = "dd/mm/aaaa";
		cpf = "000.000.000-00";
	}

	bool setCpf(string arg) {
		if (!checkCPF(arg) || arg.length() < 11 || arg.length() > 14) {
			cout << "CPF inválido!" << endl;
			return false;
		}
		cpf = arg;
		return true;
	}

	string getCpf() { return MaskCPF(cpf); }

	bool setAdmissionDate(string date) {
		if (!checkDate(date) || date.length() < 8 || date.length() > 10) {
			cout << "Data inválida!" << endl;
			return false;
		}
		admissionDate = date;
		return true;
	}

	string getAdmissionDate() { return MaskDate(admissionDate); }
};

#endif /* EMPLOYEE_H_ */