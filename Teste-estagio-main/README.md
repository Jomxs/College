# 🧠 Teste de Estágio 

## Instruções
- Realize o git clone deste repositório
- Responda as perguntas no próprio Readme.md
- Suba o código no repositório
- Insira a mensagem retornada do servidor
- Nos envie o link do seu repositório

### Parte 1 – Conceito 

Pesquise e explique com suas palavras:

- O que são WebSockets?

Os WebSockets servem para permitir uma comunicação em tempo real entre o frontend e o backend. Eles são úteis em situações onde o backend precisa notificar imediatamente o frontend sobre algo novo, como uma nova mensagem em um chat. Assim que o backend recebe essa nova informação, ele pode avisar o frontend, que por sua vez solicita os dados atualizados e exibe o conteúdo em tempo real para o usuário.

- Como funcionam?
Uma vez estabelecida a conexão WebSocket, o servidor e o cliente podem enviar dados livremente entre si, sem a necessidade de reabrir a conexão ou realizar novas requisições HTTP. Isso reduz a latência e o consumo de recursos, tornando a comunicação mais eficiente. Essa conexão única é reutilizada durante toda a sessão e permite uma troca constante de informações, o que melhora significativamente o desempenho em cenários que dependem de atualizações rápidas.

- Quando é melhor usar WebSockets em vez de uma API REST tradicional?

respostas instantâneas ao servidor. Isso inclui casos como chats, sistemas de notificação, plataformas de negociação, jogos online ou qualquer outro cenário onde os dados precisam ser atualizados com frequência e sem atraso. Enquanto APIs REST funcionam muito bem para operações pontuais e estruturadas, como criar, ler ou atualizar dados, elas não são ideais quando há necessidade de uma troca contínua e rápida.

### Parte 2 – Prática

Você deve criar um pequeno script que se conecta ao **servidor WebSocket** que criamos e descobrir **qual mensagem ele está enviando**.

#### ✅ O que você deve fazer:
1. Criar um pequeno código na linguagem que preferir
2. Estabelecer a conexão com o servidor WebSocket
3. Ler a mensagem recebida
  
URL do servidor: websocket-fh6l.onrender.com

### Parte 3 - 🔎 Desafio teórico: Comunicação em tempo real entre usuários
Você precisa projetar um sistema simples de mensagens em tempo real para usuários logados.

---

#### 🧩 Cenário

O sistema permite que usuários escolham um **nome de usuário** ao entrar.

As mensagens podem ser:

- **Públicas**: todos os usuários conectados recebem.
- **Privadas**: enviadas para um **usuário específico** (por exemplo: `/msg joao oi`).

Outros requisitos:

- Um mesmo usuário pode estar conectado em **vários dispositivos ou abas ao mesmo tempo**.
- Se um usuário **cair e voltar**, ele deve continuar recebendo as mensagens normalmente.

---

#### ❓ Sua tarefa (teórica)

1. Que tipo de tecnologia de comunicação você usaria para esse cenário?

2. Como garantiria o envio correto para:
   - Todos os usuários?
   - Apenas um usuário específico?
   - Todas as sessões abertas de um mesmo usuário?

3. Existe alguma ferramenta ou biblioteca que facilitaria esse tipo de comunicação?  
   Se sim, **qual?** E **por quê?**

---
#### ❗ MENSAGEM PARTE 2

 Olá mundo! LTIS 2025

#### ❗ RESPOSTA DA PARTE 3

Comunicação em tempo real:
A melhor opção seria o uso de WebSockets, pois eles mantêm uma conexão persistente, ideal para o envio imediato de mensagens entre cliente e servidor.

Mensagens para todos:
Para mensagens públicas, o servidor percorre todas as conexões ativas e envia a mensagem para cada uma delas.

Mensagem privada:
Quando uma mensagem privada é recebida (ex: /msg joao oi), o servidor consulta a lista de conexões associadas ao usuário de destino e envia a mensagem para todas elas.

Várias sessões do mesmo usuário:
Um mesmo usuário pode ter várias conexões (abas ou dispositivos). Todas essas conexões devem ser registradas no servidor para que todas recebam as mensagens. Assim, a mesma mensagem é entregue simultaneamente em todas as sessões do usuário.

Reconexão persistente:
Caso o usuário caia e volte, ele deve continuar recebendo mensagens normalmente. Para isso, é necessário armazenar conexões/sessões em uma estrutura persistente como Redis ou algum banco de dados, e reatribuí-las ao usuário ao reconectar.

Ferramentas:
Algumas ferramentas e bibliotecas que facilitam esse tipo de comunicação são:

Faye-websocket

Socket.IO

WebSockets Test

Apidog

Autobahn WebSocket

Postman

SockJS




#### 🎯 Objetivo

Entender se você consegue identificar os desafios da comunicação em tempo real e pensar em soluções viáveis e escaláveis para eles.


## Boa sorte! 💻

