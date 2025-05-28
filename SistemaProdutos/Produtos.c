#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Item{
    char nome[30];
    float valorUnitario;
    int quantidade;

};

struct ListaCompras{
    float valorTotal;
    int capacidadeEstoque;
    int tamanhoAtual;
    struct Item *p;
};

int inicializarLista(struct ListaCompras *lista){
    lista->capacidadeEstoque = 5;
    lista->valorTotal = 0.0;
    lista->tamanhoAtual = 0;
    lista->p = malloc(lista->capacidadeEstoque * sizeof(struct Item));
    if(lista-> == NULL){
        printf("ERROR NA ALOCACAO DINAMICA");
        return 1;
    }

}

void adicionarItem(struct ListaCompras *lista,char nomeP[],float valorUnitarioP, int quantidadeP){

}
int main(void){






return 0;
}
