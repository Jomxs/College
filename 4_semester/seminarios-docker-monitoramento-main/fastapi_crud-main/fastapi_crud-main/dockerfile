FROM python:3.8-slim

# Instalar dependências de sistema para compilar pacotes Python
RUN apt-get update && apt-get install -y build-essential libffi-dev

# Atualizar pip para a versão mais recente
RUN pip install --upgrade pip

# Copiar os arquivos do projeto
COPY . .

# Instalar as dependências do projeto
RUN pip install -r requirements.txt

EXPOSE 5000

CMD ["python3", "main.py"]