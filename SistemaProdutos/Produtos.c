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
    struct Item *p;
};

void inicializarLista(struct ListaCompras *lista){
    lista->p = NULL;
    lista->capacidadeEstoque = 0;
    lista->valorTotal = 0.0;
}

int main(void){






return 0;
}
