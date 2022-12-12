#include<stdio.h>
#include<stdlib.h>
#include "ordvetor.h"

VETORORD* VETORD_create(int n, COMP* compara){  //funcao para criar vetor, recebe 
    VETORORD * vetor = malloc(sizeof(VETORORD)); //alocar espaco na memoria para a estrutura do vetor
    vetor->N = n; //tamanho maximo do vetor
    vetor->P = 0; //numero de elementos no vetor
    vetor->elems = malloc(sizeof(void*)*n); 
    for(int i = 0; i < n; i++){
        vetor->elems[i] = NULL; //retirar o lixo de memoria do vetor
    }
    vetor->comparador = compara; //indicador de prioridade no vetor
    return vetor;
}

void VETORD_add(VETORORD* vetor, void* newelem){
    if(vetor->P < vetor-> N){
        if(vetor->P == 0){
            vetor->elems[0] = newelem;
        }
        else{
            int i;
            int p = vetor->P;
            vetor->elems[p] = newelem;
            for(i = p; i > 0; i++){
                if(vetor->comparador(vetor->elems[i-1], vetor->elems[i]) == -1){
                    void* aux = vetor->elems[i-1];
                    vetor->elems[i-1] = vetor->elems[i];
                    vetor->elems[i] = aux;
                }else break;
            }
        }
        vetor->P++; 
    }  
}

void* VETORD_remove(VETORORD* vetor){
    void * sal = vetor->elems[0];
    for(int i = 0; i < vetor->P; i++){
        vetor->elems[i] = vetor->elems[i+1];
    }
    vetor->P--;
    return sal;
}