#ifndef TIPOS_H
#define TIPOS_H

#include "sint.h"
#include "stdio.h"

int retorna_maior_tipo(int tipo1, int tipo2){
	if(tipo1 == FLOAT || tipo2 == FLOAT)
        return FLOAT;
    if(tipo1 == INT || tipo2 == INT)
        return INT;
    if(tipo1 == CHAR || tipo2 == CHAR)
        return CHAR;
    return 0;
}

int get_tam_tipo(int tipo){
    /* TODO: retornar o tamanho em bytes associado a cada tipo primitivo suportado */
    if(tipo == INT) return 4;
    if(tipo == FLOAT) return 4;
    if(tipo == CHAR) return 1;
    return 0;
}

int tipos_inconsistentes_atrib(int tipo1, int tipo2){
    /* TODO: verificar se tipos fonte e destino são compatíveis segundo a hierarquia de conversões implícitas */
    if(tipo2 == FLOAT && tipo1 != FLOAT)
        return 1;
    if(tipo2 == INT && tipo1 == CHAR)
        return 1;
    return 0;
}

#endif