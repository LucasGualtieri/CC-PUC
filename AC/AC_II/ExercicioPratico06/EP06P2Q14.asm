    # programa 14 (beq, bne, j) {
    #	Escreva um programa que leia um valor A da memória,
    #	identifique se o número ? par ou não.
    #	Um valor deve ser escrito na segunda
    #	posição livre da memória (0 para par e 1 para ímpar).
    # }

    # Associações:

    # A -> $s0
    # isEven -> $s1

    # firstAddress -> $t0

    #inicio

.data   
A:  .word   4

.text   
    .globl  main

main:

    # $s0 = 0x10010000
    ori     $t0,    $zero,  0x1001
    sll     $t0,    $t0,    16

    lw      $s0,    0($t0)          # $s0 = A;
    andi    $t1,    $s0,    1       # $t1 = "sinal" de $s1

    bne     $t1,    $zero,  else    # if (isEven($s0)) $s1 = 0; else goto else;

if: 
    or      $s1,    $zero,  $zero   # $s1 = 0;
    j       end                     # goto end

else:
    ori     $s1,    $zero,  1       # $s1 = 1;

end:

    sw      $s1,    4($t0)

    #fim
