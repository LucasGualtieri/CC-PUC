#include <biblioteca_cpp.h>

#include "CreateNewEmp.h"
#include "employee.h"
// #include <System.JSON.hpp>

void CreateNewEmp() {
	employee emp;
	string str;

	// do {
	// 	cout << "Digite seu CPF: ";
	// 	cin >> str;
	// } while (!emp.setCpf(str));
	// cout << emp.getCpf() << endl;

	do {
		cout << "Digite a data: ";
		cin >> str;
	} while (!emp.setAdmissionDate(str));
	cout << emp.getAdmissionDate() << endl;
}

int main() {
	SetConsoleOutputCP(65001);

	CreateNewEmp();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}