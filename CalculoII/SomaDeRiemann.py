def SomaDeRiemann(f = lambda x: 1, a = 0, b = 0, n = 1000000):
	soma = 0
	deltaX = (b - a) / n

	for i in range(1, n + 1):
		soma += deltaX * f(a + i * deltaX)

	return soma

def main():

	continuar = 'yes'

	while continuar == 'yes' or continuar  == 'y':

		expression = input("Digite a função de x (por exemplo, 'x**2', 'x*2 + 2'): ")
		a = float(input("Digite o valor de a: "))
		b = float(input("Digite o valor de b: "))

		# Converte a expressão em uma função lambda
		result = SomaDeRiemann(a = a, b = b, f = eval(f"lambda x: {expression}"))
		print(f"Soma de Riemann: {result}")

		continuar = input("Deseja calcular outra soma de Riemann? (Y/N): ").strip().lower()
		print()

	print("Encerrando o programa.")

main()
