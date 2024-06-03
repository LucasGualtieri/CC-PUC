# programa 11 (lw e sw) {
#	int x = 100000;
#	int z = 200000;
#	int y = 0;
#	y = x – z + 300000;
# }

# Associações:
# x   ->  $s0
# z   ->  $s1
# y   ->  $s2

# firstAddress -> $t0
# offset       -> $t1

#inicio

.data
x: .word 100000
z: .word 200000
y: .word 0

.text
.globl main
main:

# $t0 = 0x10010000
ori $t0, $zero, 0x1001 # $t0 = 0x00001001
sll $t0, $t0, 16       # $t0 = 0x10010000

or $t1, $zero, $t0 # $t1 = $t0

lw $s0, 0($t1) # $s0 = x
addi $t1, $t1, 4 # $t1 += 4 (bytes)

lw $s1, 0($t1) # $s1 = z
addi $t1, $t1, 4 # $t1 += 4 (bytes)

lw $s2, 0($t1) # $s2 = y

# y = x – z + 300000;

sub $t2, $s0, $s1 # $t2 = x - z;
 # $t3 = 300.000
addi $t3, $zero, 18750 # $t0 = 18.750;
sll $t3, $t3, 4 # x *= 2^4;

add $t2, $t2, $t3 # $t2 += $t3;

sw $t2, 0($t1)

#fim
