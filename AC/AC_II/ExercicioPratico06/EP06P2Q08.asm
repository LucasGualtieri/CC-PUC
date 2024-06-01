# programa 8 (reg-reg lógicas e sll, srl e sra) {
#	$8  = 0x12345678
#	$9  = 0x12
#	$10 = 0x34
#	$11 = 0x56
#	$12 = 0x78
# }

# Associações:
#$8  ->  $s0
#$9  ->  $s1
#$10 ->  $s2
#$11 ->  $s3
#$12 ->  $s4

#inicio
.text
.globl main
main:

# $8 = 0x12345678;
ori $t0, $zero, 0x1234 # $t0 = 0x00001234
sll $t0, $t0, 16       # $t0 = 0x12340000
ori $s0, $t0, 0x5678   # $s0 = 0x12345678

# $9 = 0x12
srl $s1, $s0, 24

# $10 = 0x34
sll $t1, $s0, 8  # $t1 = 0x34567800
srl $s2, $t1, 24 # $s2 = 0x00000034

# $11 = 0x56
sll $t2, $s0, 16 # $t2 = 0x56780000
srl $s3, $t2, 24 # $s3 = 0x00000056

# $12 = 0x78
sll $t3, $s0, 24 # $t3 = 0x78000000
srl $s4, $t3, 24 # $s4 = 0x00000078

#fim