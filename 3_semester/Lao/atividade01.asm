.data
    S1: .asciiz "Tres porquinhos construiram casas. Um fez de palha, outro de madeira e o ultimo de tijolos. O lobo soprou e destruiu as duas primeiras, mas nao conseguiu derrubar a de tijolos. Os porquinhos se salvaram."
    nao_encontrou: .asciiz "\nNao encontrou"
    usuario: .asciiz "Digite um caracter: "
    resultado: .asciiz "\nTexto depois:\n"
    antes: .asciiz "\nTexto antes:\n"

.text
main:
    la $a0, usuario        
    li $v0, 4
    syscall
    
    li $v0, 12
    syscall
    
    move $t2, $v0
    la $a1, S1
    
    la $a0, antes
    li $v0, 4
    syscall

    la $a0, S1              
    li $v0, 4
    syscall

    move $a0, $t2
    la $a1, S1
    jal encontra_char   
    
    beq $v0, $zero, nao     

    la $a0, resultado
    li $v0, 4
    syscall
    
    la $a0, S1              
    li $v0, 4
    syscall
    
    j fim                  

nao:
    la $a0, nao_encontrou
    li $v0, 4
    syscall

fim:
    li $v0, 10
    syscall  

encontra_char:
    li $v0, 0               

loop:
    lb $t0, 0($a1)          
    beq $t0, $zero, sai_loop 

    beq $t0, $a0, substitui 
    
    addi $a1, $a1, 1        
    j loop

substitui:

    li $t1, 32              
    sub $t0, $t0, $t1       
    sb $t0, 0($a1)          

    li $v0, 1               
    addi $a1, $a1, 1        
    j loop

sai_loop:
    jr $ra                  
