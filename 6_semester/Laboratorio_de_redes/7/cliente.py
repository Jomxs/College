import socket

def menu():
    print("\n--- VERIFICADOR DE SENHA ---")
    print("1 - Verificar força da senha")
    print("2 - Gerar senha forte aleatória")
    print("3 - Sair")
    return input("Escolha uma opção: ")

while True:
    opcao = menu()

    if opcao == "1":
        senha = input("Digite a senha: ")
        comando = f"VERIFICAR:{senha}"
    elif opcao == "2":
        tamanho = input("Tamanho da senha (Enter para padrão de 16): ")
        comando = f"GERAR:{tamanho}" if tamanho.strip() else "GERAR"
    elif opcao == "3":
        break
    else:
        print("Opção inválida.")
        continue

    c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    c.connect(('127.0.0.1', 9999))

    c.send(comando.encode())
    resultado = c.recv(1024).decode()

    print(f"\n>>> {resultado}")
    c.close()