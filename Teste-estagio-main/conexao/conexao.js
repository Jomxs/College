const socket = new WebSocket('wss://websocket-fh6l.onrender.com');

socket.onopen = () => {
  console.log('Conectado ao servidor WebSocket!');
  socket.send('Cliente conectado');
};

socket.onmessage = (event) => {
  console.log('Mensagem recebida: ', event.data);
  document.getElementById('mensagem').textContent = `Mensagem recebida: ${event.data}`;
};

socket.onerror = (error) => {
  console.error('Erro na conexão WebSocket:', error);
};

socket.onclose = () => {
  console.warn('Conexão WebSocket encerrada');
};