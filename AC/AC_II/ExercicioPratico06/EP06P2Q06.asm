# programa 6 (sll, srl e sra) {
#	x = INT_MAX;
#	y = 300000;
#	z = x - 4y;
# }

# Associações:
#x -> $s0
#y -> $s1
#z -> $s2

#inicio
.text
.globl main
main:

# y = 300.000;
addi $t0, $zero, 18750 # $t0 = 18.750;
sll $s1, $t0, 4 # x = $t0 * 2^4;

# x = 0x7FFFFFFF;
# addi $t0, $zero, -1 # $t0 = -1;
# srl $s0, $t0, 1 # x = $t0 >> 1;
ori $t0, $zero, 0x7FFF # $t0 = 0x00007FFF
sll $t0, $t0, 16 # $t0 <<= 4 ou $t0 = 0x7FFF0000
ori $s0, $t0, 0xFFFF # $x = $t0 | 0x0000FFFF

# z = x - 4 * y;
sll $t0, $s1, 2 # $t0 = y * 2^2;
sub $s2, $s0, $t0 # z = x - $t0;

#fim
