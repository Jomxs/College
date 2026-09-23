#ifndef TABSIMB_H
#define TABSIMB_H

#include <string.h>
#include "tipos.h"

#define MAX 1000
struct symbol {
	char nome[50];
	int tam;
	int tipo;
	float valor;
	int num_param;
	int escopo;
	int ativo;
};
int offset=0;
int proximo_elem=0;
struct symbol Tabela[MAX];

int escopo_atual = 0;

void entra_escopo(){
	escopo_atual++;
}

void sai_escopo(){
	int i;
	for(i=0; i<proximo_elem; i++)
		if(Tabela[i].escopo == escopo_atual)
			Tabela[i].ativo = 0;
	escopo_atual--;
}

int procura(char *nome) {
int i;	
	for(i=proximo_elem-1; i>=0; i--) 
	  if(Tabela[i].ativo && Tabela[i].escopo <= escopo_atual && strcmp(Tabela[i].nome,nome)==0)
	     return i; 
	return -1;     
}
int insere(char *nome) {
int i,pos;
struct symbol aux;	
	pos = procura(nome);
	if (pos != -1 && Tabela[pos].escopo == escopo_atual)
		return pos;
	strcpy(aux.nome,nome);
	aux.escopo = escopo_atual;
	aux.ativo = 1;
	Tabela[proximo_elem]=aux;
	Tabela[proximo_elem].tipo = -1;
	return proximo_elem++;	     
}

int set_type(int pos, int tipo){
	if(pos >= proximo_elem)
		return -1;
	Tabela[pos].tipo = tipo;
	//printf("Pos %d tipo %d\n",pos,tipo);
	Tabela[pos].tam = get_tam_tipo(tipo);
	offset+=Tabela[pos].tam;
	return 1;
}

int set_num_param(int pos, int num_param){
	if(pos >= proximo_elem)
		return -1;
	Tabela[pos].num_param = num_param;
	return 1;
}

int param_args_diferentes(int pos_func, int num_args){
	if(pos_func >= proximo_elem)
		return 1;
	if(Tabela[pos_func].num_param != num_args)
		return 1;
	return 0;
}

char nome[50];
char *obtemNome(int pos) {
	strcpy(nome,Tabela[pos].nome);
	return nome;
}
void imprime() {
int i;
	printf("\nTABELA DE SIMBOLOS\n");	
	for(i=0; i<proximo_elem; i++) 	
	   printf("%d - %s\n",i,Tabela[i].nome);
}

#endif