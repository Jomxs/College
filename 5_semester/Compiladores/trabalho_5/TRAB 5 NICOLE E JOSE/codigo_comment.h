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

void Funct(struct no* Funct, int Id, struct no Comandos) {
	create_cod(&Funct->code);
	sprintf(instrucao, "%s:\n", obtemNome(Id));
	insert_cod(&Funct->code, instrucao);
	if (Comandos.code) insert_cod(&Funct->code, Comandos.code);
	if (strcmp(obtemNome(Id), "main") == 0) {
		sprintf(instrucao, "\tli $v0, 10\n");						// 4. Se for main, adicionar li $v0,10 e syscall para terminar o programa
		insert_cod(&Funct->code, instrucao);
		sprintf(instrucao, "\tsyscall\n");
		insert_cod(&Funct->code, instrucao);
	} else {
		sprintf(instrucao, "\tjr $ra\n");   						// 5. Se não for main, adicionar jr $ra para retornar
		insert_cod(&Funct->code, instrucao);
	}
}

// TODO: Implementar adiciona_argumentos
// Esta função deve gerar código para passar argumentos para uma função:
// 1. Para cada argumento na lista Args, mover o valor do registrador temporário
//    do argumento para o registrador do parâmetro correspondente

void adiciona_argumentos(char **code, int id, struct ids Args){
	int i;
	for(i=0; i<Args.tam; i++){
		getName(Args.ids[i], reg1);								// 2. Use getName para obter os nomes dos registradores
		sprintf(instrucao, "\tmove $a%d,%s\n", i, reg1);			// 3. Use move para copiar os valores
		insert_cod(code, instrucao);
  (void)code; (void)id; (void)Args; // Evitar warnings
	}
}
														// TODO: Implementar Call
void Call(struct no* Call, int Id, struct ids Args) {	// Esta função deve gerar código para chamar uma função com argumentos:
	create_cod(&Call->code);							// 1. Criar código vazio
	Call->place = newTemp();							// 2. Adicionar código para passar argumentos (chamar adiciona_argumentos)
	sprintf(instrucao, "\tjal %s\n", obtemNome(Id));	// 3. Adicionar jal <nome_da_funcao>
	insert_cod(&Call->code, instrucao);
	getName(Call->place, reg1);							// 4. Criar um temporário para armazenar o valor de retorno
	sprintf(instrucao, "\tmove %s,$v0\n", reg1);		// 5. Mover $v0 (valor de retorno) para o temporário
	insert_cod(&Call->code, instrucao);					// 6. Atualizar Call->place com o temporário criado
	(void)Id; (void)Args; // Evitar warnings
}

// TODO: Implementar Call_blank
// Similar a Call, mas para funções sem argumentos
void Call_blank(struct no* Call, int Id) {
	create_cod(&Call->code);
	Call->place = newTemp();
	sprintf(instrucao, "\tjal %s\n", obtemNome(Id));
	insert_cod(&Call->code, instrucao);
	getName(Call->place, reg1);
	sprintf(instrucao, "\tmove %s, $v0\n", reg1);
	insert_cod(&Call->code, instrucao);
}

																				// TODO: Implementar Atrib
void Atrib(struct no *Atrib, int var_pos, struct no $3) {						// Esta função deve gerar código para atribuição:
	create_cod(&Atrib->code);
	if ($3.code) insert_cod(&Atrib->code,$3.code);								// 1. Inserir o código da expressão ($3.code)
	if (var_pos >= 0) {															// 2. Se var_pos >= 0 (variável normal):
		int offset = get_var_offset(var_pos);									//    - Obter o offset da variável usando get_var_offset
		char *nome_var = obtemNome(var_pos);									//    - Obter o nome da variável usando obtemNome
		getName($3.place, reg1);												//    - Obter o nome do registrador origem usando getName($3.place, ...)
		sprintf(instrucao, "\tsw %s, %d($sp) # %s\n", reg1, offset, nome_var); 	//    - Gerar sw <reg_origem>,<offset>($sp) # <nome_variavel>
		insert_cod(&Atrib->code, instrucao);
	} else {																	// 3. Se var_pos < 0 (temporário):
		getName(var_pos, reg1);													//    - Obter nomes dos registradores origem e destino
		getName($3.place, reg2);												//    - Obter nomes dos registradores origem e destino
		sprintf(instrucao, "\tmove %s, %s\n", reg1, reg2);						//    - Gerar move <reg_destino>,<reg_origem>
		insert_cod(&Atrib->code, instrucao);
	}
}
													// TODO: Implementar Li
void Li(struct no *Exp, int num) {					// Esta função deve gerar código para carregar um valor imediato:
	create_cod(&Exp->code);							// 1. Criar código vazio
	Exp->place = newTemp();							// 2. Criar um novo temporário (newTemp) e armazenar em Exp->place
	getName(Exp->place, reg1);						// 3. Obter o nome do temporário usando getName
	sprintf(instrucao,"\tli %s, %d\n", reg1, num);	// 4. Gerar li <reg_temporario>,<num>
	insert_cod(&Exp->code,instrucao);
}
																			// TODO: Implementar Lw
void Lw(struct no *Exp, int var_pos) {										// Esta função deve gerar código para carregar uma variável da memória:
	create_cod(&Exp->code);													// 1. Criar código vazio
	Exp->place = newTemp();													// 2. Criar um novo temporário (newTemp) e armazenar em Exp->place
	int offset = get_var_offset(var_pos);									// 3. Obter o offset da variável usando get_var_offset
	char *nome_var = obtemNome(var_pos);									// 4. Obter o nome da variável usando obtemNome
	getName(Exp->place, reg1);												// 5. Obter o nome do temporário usando getName
	sprintf(instrucao, "\tlw %s, %d($sp) # %s\n", reg1, offset, nome_var); 	// 6. Gerar lw <reg_temporario>,<offset>($sp) # <nome_variavel>
	insert_cod(&Exp->code, instrucao);
}
																				// TODO: Implementar ExpAri
void ExpAri(char *operacao, struct no *Exp, struct no Exp1, struct no Exp2) { 	// Esta função deve gerar código para operações aritméticas (add, sub, mul, div, or, and):
	Exp->place = newTemp();														// 1. Criar um novo temporário para o resultado (Exp->place)
	create_cod(&Exp->code);														// 2. Criar código vazio
	insert_cod(&Exp->code, Exp1.code);											// 3. Inserir código de Exp1 e Exp2
	insert_cod(&Exp->code, Exp2.code);											// 3. Inserir código de Exp1 e Exp2
	getName(Exp->place, reg1);													// 4. Obter nomes dos registradores usando getName
	getName(Exp1.place, reg2);													// 4. Obter nomes dos registradores usando getName
	getName(Exp2.place, reg_temp);
	sprintf(instrucao, "%s, %s, %s, %s\n", operacao, reg1, reg2, reg_temp);		// 5. Gerar <operacao> <reg_resultado>,<reg_exp1>,<reg_exp2>	
	insert_cod(&Exp->code, instrucao);
}

void ExpRel(char *branch, struct no *Exp, struct no Exp1, struct no Exp2) { 
	Exp->place = newTemp(); 												// 1. Criar um novo temporário para o resultado (Exp->place)
	create_cod(&Exp->code); 												// 2. Criar código vazio
	insert_cod(&Exp->code, Exp1.code); 										// 3. Inserir código de Exp1 e Exp2
	insert_cod(&Exp->code, Exp2.code);										// 3. Inserir código de Exp1 e Exp2
	getName(Exp->place, reg1); 												// 4. Obter nomes dos registradores
	getName(Exp1.place, reg2); 												// 4. Obter nomes dos registradores
	getName(Exp2.place, reg_temp);
	sprintf(instrucao, "\tli %s, 1\n", reg1); 								// 5. Gerar li <reg_resultado>,1 (assumir verdadeiro)
	insert_cod(&Exp->code, instrucao);
	int lbl = newLabel(); 													// 6. Criar um novo label
	sprintf(instrucao, "\t%s %s,%s,L%d\n", branch, reg2, reg_temp, lbl); 	// 7. Gerar <branch> <reg_exp1>,<reg_exp2>,L<label> (pula se verdadeiro)
	insert_cod(&Exp->code, instrucao);
	sprintf(instrucao, "\tli %s, 0\n", reg1); 								// 8. Gerar li <reg_resultado>,0 (se chegou aqui, é falso)
	insert_cod(&Exp->code, instrucao);
	sprintf(instrucao, "L%d:\n", lbl); 										// 9. Gerar L<label>: (label de destino)
	insert_cod(&Exp->code, instrucao);
}


void If(struct no *If_cmd, struct no Exp, struct no Compound) 		// TODO: Implementar If
{  																	// Esta função deve gerar código para if sem else:
	create_cod(&If_cmd->code); 										// 1. Criar código vazio
	if (Exp.code) insert_cod(&If_cmd->code, Exp.code); 				// 2. Inserir código da expressão (Exp.code)
	getName(Exp.place, reg1); 										// 3. Obter nome do registrador da expressão
	int lbl = newLabel(); 											// 4. Criar um novo label
	sprintf(instrucao, "\tbeq %s,0,L%d\n", reg1, lbl); 				// 5. Gerar beq <reg_exp>,0,L<label> (pula se falso)
	insert_cod(&If_cmd->code, instrucao); 							// 6. Inserir código do bloco (Compound.code)
	if (Compound.code) insert_cod(&If_cmd->code, Compound.code); 	// 7. Gerar L<label>: (label de destino)
	sprintf(instrucao, "L%d:\n", lbl);
	insert_cod(&If_cmd->code, instrucao);
	(void)Exp; (void)Compound; 										// Evitar warnings
}
																																												
void IfElse(struct no *If_cmd, struct no Exp, struct no Compound1, struct no Compound2) 	// TODO: Implementar IfElse
{  																							// Esta função deve gerar código para if-else:
	create_cod(&If_cmd->code);																// 1. Criar código vazio
	if (Exp.code) insert_cod(&If_cmd->code, Exp.code);										// 2. Inserir código da expressão
	getName(Exp.place, reg1);																// 3. Obter nome do registrador da expressão
	int aux_label = newLabel();																// 4. Criar label para o else (aux_label)
	sprintf(instrucao, "\tbeq %s,0,L%d\n", reg1, aux_label);								// 5. Gerar beq <reg_exp>,0,L<aux_label> (pula para else se falso)
	insert_cod(&If_cmd->code, instrucao);													
	if (Compound1.code) insert_cod(&If_cmd->code, Compound1.code);							// 6. Inserir código do bloco if (Compound1.code)
	int label_fim = newLabel();																// 7. Criar label para o fim (newLabel)
	sprintf(instrucao, "\tj L%d\n", label_fim);												// 8. Gerar j L<label_fim> (pula para o fim)
	insert_cod(&If_cmd->code, instrucao);
	sprintf(instrucao, "L%d:\n", aux_label);												// 9. Gerar L<aux_label>: (início do else)
	insert_cod(&If_cmd->code, instrucao);
	if (Compound2.code) insert_cod(&If_cmd->code, Compound2.code);							// 10. Inserir código do bloco else (Compound2.code)
	sprintf(instrucao, "L%d:\n", label_fim);												// 11. Gerar L<label_fim>: (fim do if-else)
	insert_cod(&If_cmd->code, instrucao);
	(void)Exp; (void)Compound1; (void)Compound2; // Evitar warnings
}

void While(struct no *While_cmd, struct no Exp, struct no Compound) 	// TODO: Implementar While
{  																		// Esta função deve gerar código para while:
	create_cod(&While_cmd->code);										// 1. Criar código vazio
	int aux_label_1 = newLabel(); 										// 2. Criar label para o início do loop (aux_label_1)			
	sprintf(instrucao, "L%d:\n", aux_label_1);							// 3. Gerar L<aux_label_1>: (início do loop)				
	insert_cod(&While_cmd->code, instrucao);									
	if (Exp.code) insert_cod(&While_cmd->code, Exp.code);				// 4. Inserir código da expressão		
	getName(Exp.place, reg1);											// 5. Obter nome do registrador da expressão
	int aux_label_2 = newLabel();										// 6. Criar label para sair do loop (aux_label_2)
	sprintf(instrucao, "\tbeq %s, 0, L%d\n", reg1, aux_label_2);		// 7. Gerar beq <reg_exp>,0,L<aux_label_2> (sai se falso)
	insert_cod(&While_cmd->code, instrucao);
	if (Compound.code) insert_cod(&While_cmd->code, Compound.code);		// 8. Inserir código do bloco (Compound.code)
	sprintf(instrucao, "\tj L%d\n", aux_label_1);						// 9. Gerar j L<aux_label_1> (volta para o início)
	insert_cod(&While_cmd->code, instrucao);
	sprintf(instrucao, "L%d:\n", aux_label_2);							// 10. Gerar L<aux_label_2>: (fim do loop)
	insert_cod(&While_cmd->code, instrucao);				
	(void)Exp; (void)Compound; // Evitar warnings
}

void DoWhile(struct no *While_cmd, struct no Exp, struct no Compound) 	// TODO: Implementar DoWhile
{  																		// Esta função deve gerar código para do-while:
	create_cod(&While_cmd->code);										// 1. Criar código vazio
	int aux_label_1 = newLabel();										// 2. Criar label para o início do loop (aux_label_1)
	sprintf(instrucao, "L%d:\n", aux_label_1);							// 3. Gerar L<aux_label_1>: (início do loop)
	insert_cod(&While_cmd->code, instrucao);							// 4. Inserir código do bloco (Compound.code)
	if (Exp.code) insert_cod(&While_cmd->code, Exp.code);				// 5. Inserir código da expressão
	getName(Exp.place, reg1);											// 6. Obter nome do registrador da expressão
	int aux_label_2 = newLabel();										// 7. Criar label para sair do loop (aux_label_2)
	sprintf(instrucao, "\tbeq %s, 0, L%d\n", reg1, aux_label_2);		// 8. Gerar beq <reg_exp>,0,L<aux_label_2> (sai se falso)
	insert_cod(&While_cmd->code, instrucao);
	sprintf(instrucao, "\tj L%d\n", aux_label_1);						// 9. Gerar j L<aux_label_1> (volta para o início)
	insert_cod(&While_cmd->code, instrucao);
	sprintf(instrucao, "L%d:\n", aux_label_2);							// 10. Gerar L<aux_label_2>: (fim do loop)
	insert_cod(&While_cmd->code, instrucao);
	(void)Exp; (void)Compound; // Evitar warnings
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

