# programa 10 (lw e sw) {
#	int x = 5;
#	int z = 7;
#	int y = 0;
#	y = 127 * x – 65 * z + 1;
# }

# Associações:
# x   ->  $s0
# y   ->  $s1
# z   ->  $s2

# firstAddress -> $t0
# offset       -> $t1

#inicio

.data
x: .word 5
z: .word 7
y: .word 0

.text
.globl main
main:

# $t0 = 0x10010000
ori $t0, $zero, 0x1001 # $t0 = 0x00001001
sll $t0, $t0, 16       # $t0 = 0x10010000

or $t1, $zero, $t0 # $t1 = $t0

# $s0 = x
lw $s0, 0($t1)
addi $t1, $t1, 4 # $t1 += 4 (bytes)

# $s2 = z
lw $s2, 0($t1)
addi $t1, $t1, 4 # $t1 += 4 (bytes)

# $s1 = y
lw $s1, 0($t1)

# y = 127 * x – 65 * z + 1;

# $t2 = 127 * x;
# $t2 = x * ceil(2^(log2(127)));
# $t2 = x * 2^7;
sll $t2, $s0, 7 # $t2 = x * 128;
sub $t2, $t2, $s0

# $t3 = 65 * z;
sll $t3, $s2, 6 # $t3 = z * 64;
add $t3, $t3, $s2 # $t3 += z;

# $t4 = $t2 - $t3 + 1;
sub $t4, $t2, $t3 # $t4 = $t2 - $t3;
addi $t4, $t4, 1 # $t4 += 1;

sw $t4, 0($t1)

#fim
