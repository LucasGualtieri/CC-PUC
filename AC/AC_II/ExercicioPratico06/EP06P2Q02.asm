# programa 2 (add, addi, sub, lógicas) {
# 	x = 1;
# 	y = 5 * x + 15;
# }

# Associações:
#x -> $s0
#y -> $s1

#inicio
.text
.globl main
main:

addi $s0, $zero, 1 # x = 1;

# y = 5 * x + 15;
add $t0, $s0, $s0 # t0 = x + x ou 2x;
add $t0, $t0, $t0 # t0 = t0 + t0 ou 4x;
add $t0, $t0, $s0 # t0 += x;
addi $t1, $t0, 15 # y = $t0 + x;

#fim
