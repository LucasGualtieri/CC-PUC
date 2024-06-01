# programa 3 (add, addi, sub, lógicas) {
# 	x = 3;
# 	y = 4;
# 	z = (15 * x + 67 * y) * 4;
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
add $t0, $s0, $s0 # $t0 = x + x ou 2x;
add $t0, $t0, $t0 # $t0 = $t0 + $t0 ou 4x;
add $t0, $t0, $t0 # $t0 = $t0 + $t0 ou 8x;
add $t0, $t0, $t0 # $t0 = $t0 + $t0 ou 16x;
sub $t0, $t0, $s0 # $t0 -= x;

# $t1 = 67 * y;
add $t1, $s1, $s1 # $t1 = y + y ou 2y;
add $t2, $t1, $s1 # $t2 = $t1 + y ou 3y;
add $t1, $t1, $t1 # $t1 = $t1 + $t1 ou 4y;
add $t1, $t1, $t1 # $t1 = $t1 + $t1 ou 8y;
add $t1, $t1, $t1 # $t1 = $t1 + $t1 ou 16y;
add $t1, $t1, $t1 # $t1 = $t1 + $t1 ou 32y;
add $t1, $t1, $t1 # $t1 = $t1 + $t1 ou 64y;
add $t1, $t1, $t2 # $t1 = $t1 + $t2 ou 67y;

add $t3 $t0, $t1 # $t3 = $t0 + $t1;

# z = $t0 + $t1
add $t3, $t3, $t3 # $t3 *= 2;
add $s2, $t3, $t3 # z = $t3 * 2;

#fim
