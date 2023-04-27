#ifndef CLASSLISTA_H_
#define CLASSLISTA_H_

#include <biblioteca_cpp.h>

class Lista {
	float dados[10];

public:
	float* getDados() { return dados; }
	int getSize() { return arrayLength(dados); }
};

#endif /* BIBLIOTECA_H_ */