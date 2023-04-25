#include <stdio.h>

int main(void) {

	/*
		100 kW = 1/7 do salário mínimo
		1 kW = Salário mínimo/700
		10% desconto = (Salário mínimo/700) * 0.9
	*/
	
	float salMin, gastoDaResistencia, kW, conta, contaDesconto;
	
	printf("Valor do Salário Mínimo: ");
	scanf("%f", &salMin);
	printf("Gasto da resistência: ");
	scanf("%f", &gastoDaResistencia);
	
	kW = salMin / 700.0; // Obs: int/int = int mesmo que kW seja float
	conta = gastoDaResistencia * kW;
	contaDesconto = conta * 0.90;
	
	printf("\nkW = %.0f reais", kW);
	printf("\nValor da Conta é R$ %.2f reais\n", conta);
	printf("Valor da conta com 10%% de desconto é R$ %.2f reais\n", contaDesconto);
	
	return 0;
}