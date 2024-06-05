# programa 13 (beq, bne, j) {
#	Escreva um programa que leia um valor A da memória,
#	identifique se o número é negativo ou
#	não e encontre o seu módulo. O valor deverá ser reescrito sobre A.
# }

# Associações:

# A -> $s0

# firstAddress -> $t0

#inicio

.data
A: .word -5

.text
.globl main
main:

# $s0 = 0x10010000
ori $t0, $zero, 0x1001
sll $t0, $t0, 16

lw $s0 0($t0) # $s0 = A;
sra $t1, $s0, 31 # $t1 = "sinal" de $s1

beq $t1, $zero end # if ($t1 == 0) goto end; else A = abs(A);
sub, $s0, $zero, $s0 # $t2 = abs($s1);

end:

sw $s0, 0($t0)

#fim
