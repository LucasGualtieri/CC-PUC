from functools import reduce

import operator as op

hammingPos = lambda bits: reduce(op.xor, [i for (i, bit) in enumerate(bits) if bit])

def hammingError(bits):
	# Conta a quantidade de UM's
	onesCount = reduce(lambda x, y: x + y, [bit for bit in bits if bit == 1])

	# Verifica se o valor da posição 0 condiz com a quantidade geral de UM's
	overallParity = True if bits[0] == 0 and onesCount % 2 == 0 else False

	# Verifica se há erro de paridade em algum dos setores
	sectorParity = hammingPos(bits) == 0

	result = 0
	if overallParity and not sectorParity: result = 2
	elif not overallParity or not sectorParity: result = 1

	return result

def main():
	bits = [
		0, 0, 0, 1,
		1, 1, 0, 1,
		1, 1, 1, 0,
		0, 0, 1, 0
	]

	match hammingError(bits):
		case 2:
			print("Mais que dois erros, abortar!")
		case 1:
			print("Apenas um erro detectado na posição: %s." %(hammingPos(bits)))
		case 0:
			print("Nenhum erro detectado.")

main()

def foo():
	list = [5,6,7,8,9]
	list2 = [(i, b) for (i, b) in enumerate(list)]
	print(list)
	print(list2)

	reduced = reduce(lambda x, y: x + y, list)
	print(reduced)

# foo()