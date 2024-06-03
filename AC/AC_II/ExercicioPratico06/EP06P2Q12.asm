# programa 12 (lw e sw) {
#	int a = 5;
#	int* b = &a;
#	int** c = &b;
#	int*** d = &c;
#	***d = (***d) * 2;
# }

# Associações:
# a   ->  $s0
# b   ->  $s1
# c   ->  $s2
# d   ->  $s3

# firstAddress -> $t0
# offset       -> $t1

#inicio

.data
a: .word 5
b: .word 0x10010000
c: .word 0x10010004
d: .word 0x10010008

.text
.globl main
main:

# $t0 = 0x10010000
ori $t0, $zero, 0x1001 # $t0 = 0x00001001;
sll $t0, $t0, 16       # $t0 = 0x10010000;

or $t1, $zero, $t0 # $t1 = $t0;

lw $s0, 0xC($t1) # $s0 = d;
lw $s1, 0($s0) # $s1 = c;
lw $s2, 0($s1) # $s2 = b;
lw $s3, 0($s2) # $s3 = a;

add $s3, $s3, $s3 # $s3 = 2 * $s3 ou 2a;

sw $s3, 0($s2) # ***d = (***d) * 2;

#fim
