.data
    msg_input: .asciiz "Digite o primeiro octeto do endereco IPv4: "
    classe_a: .asciiz "Classe A\n"
    classe_b: .asciiz "Classe B\n"
    classe_c: .asciiz "Classe C\n"
    classe_invalida: .asciiz "Classe invalida\n"

.text
.globl main

main:
    # Exibe mensagem de entrada
    li $v0, 4
    la $a0, msg_input
    syscall

    # Tenta ler número inteiro (entrada do usuário)
    li $v0, 5
    syscall

    
    bltz $v0, erro              # número negativo → erro
    li $t1, 223
    bgt $v0, $t1, erro          # maior que 223 → erro

    move $t0, $v0  # $t0 recebe o octeto

    # Classe A: 0–127
    li $t1, 128
    blt $t0, $t1, print_a

    # Classe B: 128–191
    li $t1, 192
    blt $t0, $t1, print_b

    # Classe C: 192–223
    li $t1, 224
    blt $t0, $t1, print_c

    # Fora do intervalo → erro
    j erro

print_a:
    li $v0, 4
    la $a0, classe_a
    syscall
    j fim

print_b:
    li $v0, 4
    la $a0, classe_b
    syscall
    j fim

print_c:
    li $v0, 4
    la $a0, classe_c
    syscall
    j fim

erro:
    li $v0, 4
    la $a0, classe_invalida
    syscall

fim:
    li $v0, 10
    syscall
