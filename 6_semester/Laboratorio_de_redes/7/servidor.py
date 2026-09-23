# José Carvalho Neto - 2026
import socket
import re
import secrets
import string

def verificar_senha(senha): #funcao para verificar a força da senha
    problemas = []

    if len(senha) < 8: # menor que 8 caracteres
        problemas.append("precisa ter pelo menos 8 caracteres")
    if not re.search(r"[A-Z]", senha): # um caractere maiúsculo
        problemas.append("precisa de pelo menos uma letra maiúscula")
    if not re.search(r"[a-z]", senha): # um caractere minúsculo
        problemas.append("precisa de pelo menos uma letra minúscula")
    if not re.search(r"[0-9]", senha): # um número
        problemas.append("precisa de pelo menos um número")
    if not re.search(r"[!@#$%^&*(),.?\":{}|<>_\-]", senha): # um símbolo especial
        problemas.append("precisa de pelo menos um símbolo (ex: !@#$%)")

    if not problemas:
        return "FORTE: sua senha atende a todos os critérios!" #mensagem de senha forte
    else:
        return "FRACA: sua senha " + "; ".join(problemas) #mensagem de senha fraca com os problemas encontrados

def gerar_senha_forte(tamanho=16): #esta função gera uma senha forte aleatória com base no tamanho fornecido
    alfabeto = string.ascii_letters + string.digits + "!@#$%^&*"
    senha = ''.join(secrets.choice(alfabeto) for _ n range(tamanho))
    return f"SENHA GERADA: {senha}"

def processar_comando(comando_completo): #processa o comando recebido do cliente e chama a função apropriada
    partes = comando_completo.split(":", 1)
    comando = partes[0].upper()

    if comando == "VERIFICAR": # verifica se o comando é para verificar a força da senha
        if len(partes) < 2:
            return "ERRO: use VERIFICAR:suasenha"
        return verificar_senha(partes[1])

    elif comando == "GERAR": # verifica se o comando é para gerar uma senha forte aleatória
        tamanho = 16
        if len(partes) > 1 and partes[1].isdigit():
            tamanho = int(partes[1])
        return gerar_senha_forte(tamanho)

    else:
        return "Comando não reconhecido. Use: VERIFICAR:senha | GERAR:tamanho"

servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
servidor.bind(('0.0.0.0', 9999))
servidor.listen(1)
print("--- SERVIDOR DE SENHAS AGUARDANDO CONEXÃO NA PORTA 9999 ---")

while True: # loop principal do servidor para aceitar conexões e processar comandos
    print("\nServidor pronto para comandos...")
    conn, addr = servidor.accept()

    comando_recebido = conn.recv(1024).decode()
    print(f"Solicitação [{comando_recebido}] vinda de {addr}")

    resposta = processar_comando(comando_recebido)
    conn.send(resposta.encode())

    conn.close()