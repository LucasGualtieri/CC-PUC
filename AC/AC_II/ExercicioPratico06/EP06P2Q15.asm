    # programa 15 (beq, bne, j) {
    #	int vetor[100];
    #       
    #	int soma = 0;
    #       
    #	for (int i = 0; i != 100; i++) {
    #		vetor[i] = 2 * i + 1;
    # 		soma += 2 * i + 1;
    #	}
    #       
    # }

    # Associa??es:

    # soma -> $s0
    # vetor -> $s1
    # i -> $s2

    # firstAddress -> $t0

    #inicio

.data   
soma:   .word   0
vetor:  .word   0x8

.text   
        .globl  main

main:   

    # $s0 = 0x10010000
    ori     $t0,    $zero,  0x1001
    sll     $t0,    $t0,    16

    lw      $s0,    0($t0)          # $s0 = soma;
    lw      $s1,    4($t0)          # $s1 = vetor;
    add     $s1,    $s1,    $t0     # $s1 = 3? endere?o

    or      $s2,    $zero,  $zero   # $s2 = 0;

    ori     $t1,    $zero,  100     # $t1 = 100;

for:    
    beq     $s2,    $t1,    end     # if ($s2 == 100) goto end;

    sll     $t2,    $s2,    2       # $t2 = 4 * i;
    add     $t2,    $t2,    $s1     # endereço de vetor[i]?

    sll     $s3,    $s2,    1       # $s3 = 2 * i;
    addi    $s3,    $s3,    1       # $s3 += 1;

    sw      $s3,    0($t2)          # vetor[i];
    add     $s0,    $s0,    $s3     # soma += $s3;

    addi    $s2,    $s2,    1       # = i++;
    j       for                     # goto for

end:    

    sw      $s0,    0($t0)

    #fim
