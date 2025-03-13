.data  
arquivo_origem:   .asciiz "arquivo_origem.txt"      # nome do arquivo origem
arquivo_destino:  .asciiz "arquivo_destino.txt"     # nome do arquivo destino
buffer: .space 1024  # espaço para armazenar até 1024 bytes lidos do arquivo de origem

.text
.globl main

main:
  # Abre o arquivo de origem para leitura
  li   $v0, 13            # chamada de sistema para abrir arquivo
  la   $a0, arquivo_origem # nome do arquivo origem
  li   $a1, 0             # abrir para leitura
  li   $a2, 0             # modo ignorado
  syscall                 # chama o sistema para abrir o arquivo de origem
  move $s0, $v0           # salva o descritor de arquivo de origem em $s0

  # Abre o arquivo de destino para escrita
  li   $v0, 13            # chamada de sistema para abrir arquivo
  la   $a0, arquivo_destino # nome do arquivo destino
  li   $a1, 1             # abrir para escrita
  li   $a2, 0             # modo ignorado
  syscall                 # chama o sistema para abrir o arquivo de destino
  move $s1, $v0           # salva o descritor de arquivo de destino em $s1

# Loop para copiar dados do arquivo de origem para o arquivo de destino
loop:
  # Lê até 1024 bytes do arquivo de origem
  li   $v0, 14            # chamada de sistema para ler arquivo
  move $a0, $s0           # descritor do arquivo de origem
  la   $a1, buffer        # buffer para armazenar dados lidos
  li   $a2, 1024          # lê até 1024 bytes
  syscall                 # lê os dados do arquivo

  move $t0, $v0           # $t0 = número de bytes lidos

  # Se não houver dados lidos (fim do arquivo), sai do loop
  beq  $t0, $zero, done   # se o número de bytes lidos for 0, termina

  # Escreve os dados lidos no arquivo de destino
  li   $v0, 15            # chamada de sistema para escrever no arquivo
  move $a0, $s1           # descritor do arquivo de destino
  la   $a1, buffer        # buffer com os dados lidos
  move $a2, $t0           # número de bytes a serem escritos
  syscall                 # escreve os dados no arquivo de destino

  j    loop               # repete o loop para ler e escrever mais dados

# Fecha os arquivos
done:
  li   $v0, 16            # chamada de sistema para fechar arquivo
  move $a0, $s0           # descritor do arquivo de origem
  syscall                 # fecha o arquivo de origem

  li   $v0, 16            # chamada de sistema para fechar arquivo
  move $a0, $s1           # descritor do arquivo de destino
  syscall                 # fecha o arquivo de destino

  # Fim do programa
  li   $v0, 10            # chamada de sistema para terminar o programa
  syscall
.data  
arquivo_origem:   .asciiz "arquivo_origem.txt"      # nome do arquivo origem
arquivo_destino:  .asciiz "arquivo_destino.txt"     # nome do arquivo destino
buffer: .space 1024  # espaço para armazenar até 1024 bytes lidos do arquivo de origem

.text
.globl main

main:
  # Abre o arquivo de origem para leitura
  li   $v0, 13            # chamada de sistema para abrir arquivo
  la   $a0, arquivo_origem # nome do arquivo origem
  li   $a1, 0             # abrir para leitura
  li   $a2, 0             # modo ignorado
  syscall                 # chama o sistema para abrir o arquivo de origem
  move $s0, $v0           # salva o descritor de arquivo de origem em $s0

  # Abre o arquivo de destino para escrita
  li   $v0, 13            # chamada de sistema para abrir arquivo
  la   $a0, arquivo_destino # nome do arquivo destino
  li   $a1, 1             # abrir para escrita
  li   $a2, 0             # modo ignorado
  syscall                 # chama o sistema para abrir o arquivo de destino
  move $s1, $v0           # salva o descritor de arquivo de destino em $s1

# Loop para copiar dados do arquivo de origem para o arquivo de destino
loop:
  # Lê até 1024 bytes do arquivo de origem
  li   $v0, 14            # chamada de sistema para ler arquivo
  move $a0, $s0           # descritor do arquivo de origem
  la   $a1, buffer        # buffer para armazenar dados lidos
  li   $a2, 1024          # lê até 1024 bytes
  syscall                 # lê os dados do arquivo

  move $t0, $v0           # $t0 = número de bytes lidos

  # Se não houver dados lidos (fim do arquivo), sai do loop
  beq  $t0, $zero, done   # se o número de bytes lidos for 0, termina

  # Escreve os dados lidos no arquivo de destino
  li   $v0, 15            # chamada de sistema para escrever no arquivo
  move $a0, $s1           # descritor do arquivo de destino
  la   $a1, buffer        # buffer com os dados lidos
  move $a2, $t0           # número de bytes a serem escritos
  syscall                 # escreve os dados no arquivo de destino

  j    loop               # repete o loop para ler e escrever mais dados

# Fecha os arquivos
done:
  li   $v0, 16            # chamada de sistema para fechar arquivo
  move $a0, $s0           # descritor do arquivo de origem
  syscall                 # fecha o arquivo de origem

  li   $v0, 16            # chamada de sistema para fechar arquivo
  move $a0, $s1           # descritor do arquivo de destino
  syscall                 # fecha o arquivo de destino

  # Fim do programa
  li   $v0, 10            # chamada de sistema para terminar o programa
  syscall
