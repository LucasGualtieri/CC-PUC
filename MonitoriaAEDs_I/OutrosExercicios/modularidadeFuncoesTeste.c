#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int num = 3;

static float PI = 3.14;

int f1(float x[3]) {

	float soma = 0;

	for (int i = 0; i < num; i++)
		soma = soma + pow(x[i], 2);

	return soma;
}

double f2(float x[2]) {

	double rose = 0;

	for (int i = 0; i < num - 2; i++)

		rose = 100 * pow((pow(x[i], 2) - x[i + 1]), 2) + pow((1 - x[i]), 2);

	return rose;
}

int f3(float x[5]) {
	float jong = 0;

	for (int i; i <= num; i++)
		jong = jong + floor(x[i]);

	return jong;
}

double f4(double x[30]) {

	double gauss = 0;
	double soma = 0;
	int i = 0;

	for (i; i <= 4; i++)
		soma = soma + i * pow(x[i], 4);

	gauss = 0.5 * (1.0 + erf(M_SQRT1_2 * x[i]));

	return gauss;
}

double f5(float x[2], float a[25]) {

	double sheke = 0;
	int sum1 = 0, sum2 = 0;

	for (int j = 0; j <= 25; j++) {

		sum1 = sum1 + a[j];

		for (int i = 0; i <= 2; i++) {

			sum2 = sum2 + x[i];
			sheke = 0.002 + sum1 * (1 / (sum2 * pow(x[i] - a[j + i], 6)));
		}
	}

	return sheke;
}

double f6(int n, float x[2]) {

	double scha;

	double par1, par2, par3;

	par1 = pow(x[0], 2);

	par2 = pow(x[1], 2);

	par3 = par1 + par2;

	scha = pow(par3, 0.25) * ((pow(sin(50 * pow(par3, 0.1)), 2)) + 1.0);

	return scha;
}

double
f7(int n, float x[2]) {

	double resul;

	double par1, par2;

	par1 = pow(x[0], 2);

	par2 = pow(x[1], 2);

	resul = ((par1 + par2) / 2) * cos(20 * PI * x[0]) * cos(20 * PI * x[1]) + 2;

	return scha;
}

double
f8(int n, float x[10]) {

	double rastri = 0;

	for (int i = 0; i < n; i++)

		rastri
			= rastri + pow(x[i], 2.0) - 10 * cos(2 * PI * x[i]);

	rastri = 10 * rastri;

	return rastri;
}

int main() {
	printf("Hello world!\n");
	return 0;
}