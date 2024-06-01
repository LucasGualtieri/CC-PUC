# programa 5 (sll, srl e sra) {
#	x = 100000;
#	y = 200000;
#	z = x + y;
# }

# Associações:
#x -> $s0
#y -> $s1
#z -> $s2

#inicio
.text
.globl main
main:

# y = 200.000;
addi $t0, $zero, 25000 # $t0 = 25.000;
sll $s1, $t0, 3 # x = $t0 * 2^3;

# x = 100.000;
#srl $s0, $s1, 1 # x = $t0 / 2;
addi $t0, $zero, 12500 # $t0 = 25.000;
sll $s0, $t0, 3 # x = $t0 * 2^2;

add $s2, $s0, $s1 # z = x + y;

#fim
