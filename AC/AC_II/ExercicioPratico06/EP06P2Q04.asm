# programa 4 (sll, srl e sra) {
#	x = 3;
#	y = 4;
#	z = (15 * x + 67 * y) * 4;
# }

# Associações:
#x -> $s0
#y -> $s1
#z -> $s2

#inicio
.text
.globl main
main:

addi $s0, $zero, 3 # x = 3;
addi $s1, $zero, 4 # y = 4;

# z = ((15 * x) + (67 * y)) * 4;
# $t0 = 15 * x;
sll $t0, $s0, 4 # $t0 = x * 2^4
sub $t0, $t0, $s0 # $t0 -= x;

# $t1 = 67 * y;
add $t1, $s1, $s1 # $t1 = y + y ou 2y;
add $t2, $t1, $s1 # $t2 = $t1 + y ou 3y;
sll $t1, $t1, 5   # $t1 = $t1 * 2^5
add $t1, $t1, $t2 # $t1 = $t1 + $t2 ou 67y;

add $t3 $t0, $t1 # $t3 = $t0 + $t1;

# z = $t0 + $t1
sll $s2, $t3, 2 # z = $t3 * 2^2;

#fim
