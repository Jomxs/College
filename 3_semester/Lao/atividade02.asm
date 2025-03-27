.data
    origem: .asciiz "Qualquer texto a ser copiado"
.text
main:
    # imprime string origem
    la $a0, origem      
    li $v0, 4      
    syscall
    
    # imprime '/'
    li $a0, 47     
    li $v0, 11      
    syscall
    
    la $a0, origem      
    jal MEMCOPY  #faz a copia entre blocos

    # imprime o conteúdo da área destino
    move $a0, $v0  
    li $v0, 4      
    syscall

    li $v0, 10
    syscall # feito!

# Procedimento de cópia do conteúdo de memória (string de origem) para uma 
# área de memória alocada dinamicamente.
# Parâmetro de entrada: $a0 deve conter o endereço dos dados de origem
# Valor de retorno: $v0 conterá o endereço dos dados de destino da cópia 
MEMCOPY:  
     move  $t0, $a0
     move $t2, $a0
     li $t3
 LO: lb $t1, $zero sai
     beq $t1, $zero, sai
     addi $t2, $t2, 1
     addi $t3, $t3, 1
     J L0
sai:
     addi $t3, $t3, 1
     move $a0, $t3
     
     li $v0, 9
     syscall
     
     move $t1, $v0
     add $t3, $zero, $zero
     add $t4, $t0, $t3
 L1: add $t4, $t0, $t3
     lb $t5, 0($t4)
     beq $t5, $zero, out
     add $t6, $t1, $t3
     ab $t5, 0($t6)
     addi $t3, $t3, 1
     j  L1
out:
     jr   $ra     # termina o procedimento