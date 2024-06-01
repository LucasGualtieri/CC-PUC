# programa 9 (lw e sw) {
#	int x1 = 15;
#	int x2 = 25;
#	int x3 = 13;
#	int x4 = 17;
#	int soma = -1;
#	soma = x1 + x2 + x3 + x4;
# }

# Associações:
# x1   ->  $s0
# x2   ->  $s1
# x3   ->  $s2
# x4   ->  $s3
# soma ->  $s4

# firstAddress -> $t0
# offset       -> $t1

#inicio

.data
x1: .word 15
x2: .word 25
x3: .word 13
x4: .word 17
soma: .word -1

.text
.globl main
main:

# $t0 = 0x10010000
ori $t0, $zero, 0x1001 # $t0 = 0x00001001
sll $t0, $t0, 16       # $t0 = 0x10010000

or $t1, $zero, $t0 # $t1 = $t0

# $s0 = x1
lw $s0, 0($t1)
addi $t1, $t1, 4 # $t1 += 4 (bytes)

# $s1 = x2
lw $s1, 0($t1)
addi $t1, $t1, 4 # $t1 += 4 (bytes)

# $s2 = x3
lw $s2, 0($t1)
addi $t1, $t1, 4 # $t1 += 4 (bytes)

# $s3 = x4
lw $s3, 0($t1)
addi $t1, $t1, 4 # $t1 += 4 (bytes)

# $s4 = soma
lw $s4, 0($t1)

add $t2, $zero, $s0 # $t2 = 0 + $s0;
add $t2, $t2, $s1 # $t2 += $s1;
add $t2, $t2, $s2 # $t2 += $s2;
add $t2, $t2, $s3 # $t2 += $s3;

sw $t2, 0($t1) # soma = x1 + x2 + x3 + x4

#fim