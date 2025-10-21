# fastapi_crud
Projeto de API feito em fastapi utilizando banco de dados sqlalchemy e python jose(JWT)

🛠️ Ferramentas: [FastAPI](https://fastapi.tiangolo.com/) - [SQLAlchemy](https://www.sqlalchemy.org/) - [Asyncio](https://docs.python.org/pt-br/3/library/asyncio.html) - [python-jose](https://python-jose.readthedocs.io/en/latest/) 

Instrucoes para Execução da API:

Criar uma env:
python3 -m venv env

Ativar a env:
source env/bin/activate

Instalar as dependencias:
pip install -r requirements.txt

criação do Banco de Dados
python criar_tabelas.py

Start na aplicação:
python main.py

Para rodar em container docker

 docker build -t fastapi-crud .
 docker run -d --name fastapi-crud -p 8000:8000 fastapi-crud