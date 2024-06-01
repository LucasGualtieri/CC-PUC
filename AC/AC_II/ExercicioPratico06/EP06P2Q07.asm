# programa 7 (reg-reg lógicas e sll, srl e sra) {
#	$s0 = 0xFFFFFFFF
# }

# Associações:
#$8 -> $s0

#inicio
.text
.globl main
main:

ori $t0, $zero, 0x01
sll $t0, $t0, 31 # $t0 <<= 31 ou $t0 = #0x8000000
sra $s0, $t0, 31 # $8 = $t0 >> 31 ou $s0 = 0xFFFFFFFF

#fim
