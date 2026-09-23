#include "semantic.h"
#include "listacodigo.h"

int temp=-1;
int newTemp() {
	return temp--;
}

void freeTemp() {
	temp++;
}
int label = 0;
int newLabel() {
	return ++label;
}

char reg1[5];
char reg2[5];
char reg_temp[5];
void getName(int num, char *name) {
  if (num >= 0 ) {
    sprintf(name,"$s%d",num);
  }
  else 
    sprintf(name,"$t%d",-(num+1));
}

// TODO: Implementar Funct
// Esta função deve gerar o código para uma função:
// 1. Criar o código vazio
// 2. Adicionar o label da função (nome da função seguido de :)
// 3. Inserir o código dos comandos da função
// 4. Se for main, adicionar li $v0,10 e syscall para terminar o programa
// 5. Se não for main, adicionar jr $ra para retornar
void Funct(struct no* Funct, int Id, struct no Comandos) {
	create_cod(&Funct->code);
	sprintf(instrucao, "%s:\n", obtemNome(Id));
	insert_cod(&Funct->code, instrucao);
	if (Comandos.code) insert_cod(&Funct->code, Comandos.code);
	if (strcmp(obtemNome(Id), "main") == 0) {
		sprintf(instrucao, "\tli $v0,10\n");
		insert_cod(&Funct->code, instrucao);
		sprintf(instrucao, "\tsyscall\n");
		insert_cod(&Funct->code, instrucao);
	} else {
		sprintf(instrucao, "\tjr $ra\n");
		insert_cod(&Funct->code, instrucao);
	}
}

// TODO: Implementar adiciona_argumentos
// Esta função deve gerar código para passar argumentos para uma função:
// 1. Para cada argumento na lista Args, mover o valor do registrador temporário
//    do argumento para o registrador do parâmetro correspondente
// 2. Use getName para obter os nomes dos registradores
// 3. Use move para copiar os valores
void adiciona_argumentos(char **code, int id, struct ids Args){
	int i;
	for (i = 0; i < Args.tam; i++) {
		int param_id = Tabela[id].arg_list[i];
		char reg_param[10];
		getName(param_id, reg_param);
		getName(Args.ids[i], reg1);
		sprintf(instrucao, "\tmove %s,%s\n", reg_param, reg1);
		insert_cod(code, instrucao);
	}
}

// TODO: Implementar Call
// Esta função deve gerar código para chamar uma função com argumentos:
// 1. Criar código vazio
// 2. Adicionar código para passar argumentos (chamar adiciona_argumentos)
// 3. Adicionar jal <nome_da_funcao>
// 4. Criar um temporário para armazenar o valor de retorno
// 5. Mover $v0 (valor de retorno) para o temporário
// 6. Atualizar Call->place com o temporário criado
void Call(struct no* Call, int Id, struct ids Args) {
	create_cod(&Call->code);
	Call->place = newTemp();
	adiciona_argumentos(&Call->code, Id, Args);
	sprintf(instrucao, "\tjal %s\n", obtemNome(Id));
	insert_cod(&Call->code, instrucao);
	getName(Call->place, reg1);
	sprintf(instrucao, "\tmove %s,$v0\n", reg1);
	insert_cod(&Call->code, instrucao);
}

// TODO: Implementar Call_blank
// Similar a Call, mas para funções sem argumentos
void Call_blank(struct no* Call, int Id) {
	create_cod(&Call->code);
	Call->place = newTemp();
	sprintf(instrucao, "\tjal %s\n", obtemNome(Id));
	insert_cod(&Call->code, instrucao);
	getName(Call->place, reg1);
	sprintf(instrucao, "\tmove %s,$v0\n", reg1);
	insert_cod(&Call->code, instrucao);
}

// TODO: Implementar Atrib
// Esta função deve gerar código para atribuição:
// 1. Inserir o código da expressão ($3.code)
// 2. Se var_pos >= 0 (variável normal):
//    - Obter o offset da variável usando get_var_offset
//    - Obter o nome da variável usando obtemNome
//    - Obter o nome do registrador origem usando getName($3.place, ...)
//    - Gerar sw <reg_origem>,<offset>($sp) # <nome_variavel>
// 3. Se var_pos < 0 (temporário):
//    - Obter nomes dos registradores origem e destino
//    - Gerar move <reg_destino>,<reg_origem>
void Atrib(struct no *Atrib, int var_pos, struct no $3) {
	create_cod(&Atrib->code);
	if ($3.code) insert_cod(&Atrib->code,$3.code);
	if (var_pos >= 0) {
		int offset = get_var_offset(var_pos);
		char *nome_var = obtemNome(var_pos);
		getName($3.place, reg1);
		sprintf(instrucao, "\tsw %s,%d($sp)\t# %s\n", reg1, offset, nome_var);
		insert_cod(&Atrib->code, instrucao);
	} else {
		getName(var_pos, reg1);
		getName($3.place, reg2);
		sprintf(instrucao, "\tmove %s,%s\n", reg1, reg2);
		insert_cod(&Atrib->code, instrucao);
	}
}

// TODO: Implementar Li
// Esta função deve gerar código para carregar um valor imediato:
// 1. Criar código vazio
// 2. Criar um novo temporário (newTemp) e armazenar em Exp->place
// 3. Obter o nome do temporário usando getName
// 4. Gerar li <reg_temporario>,<num>
void Li(struct no *Exp, int num) {
	create_cod(&Exp->code);
	Exp->place = newTemp();
	getName(Exp->place, reg1);
	sprintf(instrucao,"\tli %s,%d\n", reg1, num);
	insert_cod(&Exp->code,instrucao);
}

// TODO: Implementar Lw
// Esta função deve gerar código para carregar uma variável da memória:
// 1. Criar código vazio
// 2. Criar um novo temporário (newTemp) e armazenar em Exp->place
// 3. Obter o offset da variável usando get_var_offset
// 4. Obter o nome da variável usando obtemNome
// 5. Obter o nome do temporário usando getName
// 6. Gerar lw <reg_temporario>,<offset>($sp) # <nome_variavel>
void Lw(struct no *Exp, int var_pos) {
	create_cod(&Exp->code);
	Exp->place = newTemp();
	int offset = get_var_offset(var_pos);
	char *nome_var = obtemNome(var_pos);
	getName(Exp->place, reg1);
	sprintf(instrucao, "\tlw %s,%d($sp)\t# %s\n", reg1, offset, nome_var);
	insert_cod(&Exp->code, instrucao);
}

// TODO: Implementar ExpAri
// Esta função deve gerar código para operações aritméticas (add, sub, mul, div, or, and):
// 1. Criar um novo temporário para o resultado (Exp->place)
// 2. Criar código vazio
// 3. Inserir código de Exp1 e Exp2
// 4. Obter nomes dos registradores usando getName
// 5. Gerar <operacao> <reg_resultado>,<reg_exp1>,<reg_exp2>


void ExpAri(char *operacao, struct no *Exp, struct no Exp1, struct no Exp2) {
	Exp->place = newTemp();
	create_cod(&Exp->code);
	insert_cod(&Exp->code, Exp1.code);
	insert_cod(&Exp->code, Exp2.code);
	getName(Exp->place, reg1);
	getName(Exp1.place, reg2);
	getName(Exp2.place, reg_temp);
	sprintf(instrucao, "\t%s %s,%s,%s\n", operacao, reg1, reg2, reg_temp);
	insert_cod(&Exp->code, instrucao);
}

// TODO: Implementar ExpRel
// Esta função deve gerar código para operações relacionais (bgt, blt, etc):
// 1. Criar um novo temporário para o resultado (Exp->place)
// 2. Criar código vazio
// 3. Inserir código de Exp1 e Exp2
// 4. Obter nomes dos registradores
// 5. Gerar li <reg_resultado>,1 (assumir verdadeiro)
// 6. Criar um novo label
// 7. Gerar <branch> <reg_exp1>,<reg_exp2>,L<label> (pula se verdadeiro)
// 8. Gerar li <reg_resultado>,0 (se chegou aqui, é falso)
// 9. Gerar L<label>: (label de destino)
void ExpRel(char *branch, struct no *Exp, struct no Exp1, struct no Exp2) { 
	Exp->place = newTemp();
	create_cod(&Exp->code);
	if (Exp1.code) insert_cod(&Exp->code, Exp1.code);
	if (Exp2.code) insert_cod(&Exp->code, Exp2.code);
	getName(Exp1.place, reg1);
	getName(Exp2.place, reg2);
	getName(Exp->place, reg_temp);
	sprintf(instrucao, "\tli %s,1\n", reg_temp);
	insert_cod(&Exp->code, instrucao);
	int l = newLabel();
	sprintf(instrucao, "\t%s %s,%s,L%d\n", branch, reg1, reg2, l);
	insert_cod(&Exp->code, instrucao);
	sprintf(instrucao, "\tli %s,0\n", reg_temp);
	insert_cod(&Exp->code, instrucao);
	sprintf(instrucao, "L%d:\n", l);
	insert_cod(&Exp->code, instrucao);
}

// TODO: Implementar If
// Esta função deve gerar código para if sem else:
// 1. Criar código vazio
// 2. Inserir código da expressão (Exp.code)
// 3. Obter nome do registrador da expressão
// 4. Criar um novo label
// 5. Gerar beq <reg_exp>,0,L<label> (pula se falso)
// 6. Inserir código do bloco (Compound.code)
// 7. Gerar L<label>: (label de destino)
void If(struct no *If_cmd, struct no Exp, struct no Compound) 
{  
	create_cod(&If_cmd->code);
	if (Exp.code) insert_cod(&If_cmd->code, Exp.code);
	getName(Exp.place, reg1);
	int l = newLabel();
	sprintf(instrucao, "\tbeq %s,0,L%d\n", reg1, l);
	insert_cod(&If_cmd->code, instrucao);
	if (Compound.code) insert_cod(&If_cmd->code, Compound.code);
	sprintf(instrucao, "L%d:\n", l);
	insert_cod(&If_cmd->code, instrucao);
}

// TODO: Implementar IfElse
// Esta função deve gerar código para if-else:
// 1. Criar código vazio
// 2. Inserir código da expressão
// 3. Obter nome do registrador da expressão
// 4. Criar label para o else (aux_label)
// 5. Gerar beq <reg_exp>,0,L<aux_label> (pula para else se falso)
// 6. Inserir código do bloco if (Compound1.code)
// 7. Criar label para o fim (newLabel)
// 8. Gerar j L<label_fim> (pula para o fim)
// 9. Gerar L<aux_label>: (início do else)
// 10. Inserir código do bloco else (Compound2.code)
// 11. Gerar L<label_fim>: (fim do if-else)
void IfElse(struct no *If_cmd, struct no Exp, struct no Compound1, struct no Compound2) 
{  
	create_cod(&If_cmd->code);
	if (Exp.code) insert_cod(&If_cmd->code, Exp.code);
	getName(Exp.place, reg1);
	int aux_label = newLabel();
	sprintf(instrucao, "\tbeq %s,0,L%d\n", reg1, aux_label);
	insert_cod(&If_cmd->code, instrucao);
	if (Compound1.code) insert_cod(&If_cmd->code, Compound1.code);
	int label_fim = newLabel();
	sprintf(instrucao, "\tj L%d\n", label_fim);
	insert_cod(&If_cmd->code, instrucao);
	sprintf(instrucao, "L%d:\n", aux_label);
	insert_cod(&If_cmd->code, instrucao);
	if (Compound2.code) insert_cod(&If_cmd->code, Compound2.code);
	sprintf(instrucao, "L%d:\n", label_fim);
	insert_cod(&If_cmd->code, instrucao);
}

// TODO: Implementar While
// Esta função deve gerar código para while:
// 1. Criar código vazio
// 2. Criar label para o início do loop (aux_label_1)
// 3. Gerar L<aux_label_1>: (início do loop)
// 4. Inserir código da expressão
// 5. Obter nome do registrador da expressão
// 6. Criar label para sair do loop (aux_label_2)
// 7. Gerar beq <reg_exp>,0,L<aux_label_2> (sai se falso)
// 8. Inserir código do bloco (Compound.code)
// 9. Gerar j L<aux_label_1> (volta para o início)
// 10. Gerar L<aux_label_2>: (fim do loop)
void While(struct no *While_cmd, struct no Exp, struct no Compound) 
{  
	create_cod(&While_cmd->code);
	int aux_label_1 = newLabel();
	sprintf(instrucao, "L%d:\n", aux_label_1);
	insert_cod(&While_cmd->code, instrucao);
	if (Exp.code) insert_cod(&While_cmd->code, Exp.code);
	getName(Exp.place, reg1);
	int aux_label_2 = newLabel();
	sprintf(instrucao, "\tbeq %s,0,L%d\n", reg1, aux_label_2);
	insert_cod(&While_cmd->code, instrucao);
	if (Compound.code) insert_cod(&While_cmd->code, Compound.code);
	sprintf(instrucao, "\tj L%d\n", aux_label_1);
	insert_cod(&While_cmd->code, instrucao);
	sprintf(instrucao, "L%d:\n", aux_label_2);
	insert_cod(&While_cmd->code, instrucao);
}

// TODO: Implementar DoWhile
// Esta função deve gerar código para do-while:
// 1. Criar código vazio
// 2. Criar label para o início do loop (aux_label_1)
// 3. Gerar L<aux_label_1>: (início do loop)
// 4. Inserir código do bloco (Compound.code)
// 5. Inserir código da expressão
// 6. Obter nome do registrador da expressão
// 7. Criar label para sair do loop (aux_label_2)
// 8. Gerar beq <reg_exp>,0,L<aux_label_2> (sai se falso)
// 9. Gerar j L<aux_label_1> (volta para o início)
// 10. Gerar L<aux_label_2>: (fim do loop)
void DoWhile(struct no *While_cmd, struct no Exp, struct no Compound) 
{  
	create_cod(&While_cmd->code);
	int aux_label_1 = newLabel();
	sprintf(instrucao, "L%d:\n", aux_label_1);
	insert_cod(&While_cmd->code, instrucao);
	if (Compound.code) insert_cod(&While_cmd->code, Compound.code);
	if (Exp.code) insert_cod(&While_cmd->code, Exp.code);
	getName(Exp.place, reg1);
	int aux_label_2 = newLabel();
	sprintf(instrucao, "\tbeq %s,0,L%d\n", reg1, aux_label_2);
	insert_cod(&While_cmd->code, instrucao);
	sprintf(instrucao, "\tj L%d\n", aux_label_1);
	insert_cod(&While_cmd->code, instrucao);
	sprintf(instrucao, "L%d:\n", aux_label_2);
	insert_cod(&While_cmd->code, instrucao);
}

void Println(struct no *Print, struct no Exp) {
char name_reg[10];
	create_cod(&Print->code);
	getName(Exp.place,name_reg);
	
	sprintf(instrucao,"\tli $v0, 1\n");
	insert_cod(&Print->code,instrucao);
	
	sprintf(instrucao,"\tmove $a0,%s\n", name_reg);
	insert_cod(&Print->code,instrucao);

	sprintf(instrucao,"\tsyscall\n");
	insert_cod(&Print->code,instrucao);

	sprintf(instrucao,"\tli $v0,11\n"); 
	insert_cod(&Print->code,instrucao);

   	sprintf(instrucao,"\tli $a0,'\\n'\n"); 
	insert_cod(&Print->code,instrucao);

    sprintf(instrucao,"\tsyscall\n"); 
	insert_cod(&Print->code,instrucao);
}

