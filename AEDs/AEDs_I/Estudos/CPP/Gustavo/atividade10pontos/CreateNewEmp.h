#ifndef CREATENEWEMP_H_
#define CREATENEWEMP_H_

#include "D:\Lucas\PUC\AED\workspace\C.CPP\Bibliotecas\biblioteca_cpp.h"
#include "employee.h"

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

#endif /* CREATENEWEMP_H_ */