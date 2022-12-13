#include<stdio.h>
#include<stdlib.h>
#include "ordvetor.h"

VETORORD* VETORD_create(int n, COMP* compara){  //criar vetor; recebe seu tamanho e o parametro de comparacao entre os elementos
    VETORORD * vetor = malloc(sizeof(VETORORD)); //alocar espaco na memoria para a estrutura do vetor
    vetor->N = n; //tamanho maximo do vetor
    vetor->P = 0; //numero de elementos no vetor
    vetor->elems = malloc(sizeof(void*)*n); //alocar espaco para os elementos do vetor
    for(int i = 0; i < n; i++){
        vetor->elems[i] = NULL; //retirar o lixo de memoria do vetor
    }
    vetor->comparador = compara; //indicador de prioridade no vetor
    return vetor; //retornar o vetor criado
}

void VETORD_add(VETORORD* vetor, void* newelem){ //adicionar elementos; recebe o vetor e o novo elemento
    if(vetor->P < vetor-> N){ //vetor nao esta cheio
        if(vetor->P == 0){ //vetor esta vazio
            vetor->elems[0] = newelem; //inserir elemento na primeira posicao
        }
        else{
            int i; //iterador
            int p = vetor->P; //receber o numero de elems atual do vetor
            vetor->elems[p] = newelem; //inserir o elem novo na ultima posicao
            for(i = p; i > 0; i++){ //iterar pelo vetor para ordenar
                if(vetor->comparador(vetor->elems[i-1], vetor->elems[i]) == -1){ //se o primeiro elem eh maior que o segundo 
                    void* aux = vetor->elems[i-1]; //aux recebe o maior
                    vetor->elems[i-1] = vetor->elems[i]; //troca o segundo com o primeiro
                    vetor->elems[i] = aux; //ordenado de forma crescente
                }else break;
            }
        }
        vetor->P++; //aumentar o tam do vetor sempre que um elem for adicionado
    }  
}

void* VETORD_remove(VETORORD* vetor){ //remover; recebe o vetor e remove o seu primeiro elemento
    void * lixo = vetor->elems[0]; //guarda o elem a ser removido
    for(int i = 0; i < vetor->P; i++){ //iterar pelo vetor
        vetor->elems[i] = vetor->elems[i+1]; //elem da pos anterior recebe o da pos da frente
    }
    vetor->P--; //diminuir o tam do vetor
    return lixo; //retorna o que foi removido
}