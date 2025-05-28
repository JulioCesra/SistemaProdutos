#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Item{
    int id;
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
    if(lista->p == NULL){
        printf("ERROR NA ALOCACAO DINAMICA");
        return 1;
    }

}

int adicionarItem(struct ListaCompras *lista,int idP,char nomeP[],float valorUnitarioP, int quantidadeP){
    if(lista->tamanhoAtual == lista->capacidadeEstoque){
        lista->capacidadeEstoque *= 2;
        lista->p = realloc(lista->p,lista->capacidadeEstoque * sizeof(struct Item));
        if(lista ->p == NULL){
            printf("ERROR NA ALOCACAO DINAMICA");
            return 1;
        }
    }
    lista->p[lista->tamanhoAtual].id = idP;
    strcpy(lista->p[lista->tamanhoAtual].nome,nomeP);
    lista->p[lista->tamanhoAtual].quantidade = quantidadeP;
    lista->p[lista->tamanhoAtual].valorUnitario = valorUnitarioP;
    lista->valorTotal += valorUnitarioP * quantidadeP;
    lista->tamanhoAtual ++;
}

int removerItem(struct ListaCompras *lista,int idRemover){
    if(lista->p == NULL){
        printf("ERROR NA ALOCACAO DINAMICA");
        return 1;
    }

    int index = -1;
    for(int i = 0; i < lista->tamanhoAtual; i ++){
        if(lista->p[i].id == idRemover){
            index = i;
            break;
        }
    }

    lista->valorTotal -= lista->p[index].quantidade * lista->p[index].valorUnitario;
    lista->p = realloc(lista->p, (lista->capacidadeEstoque - 1) * sizeof(struct Item));
    lista->tamanhoAtual --;
    return 0;
}
int mostrarRelatorio(struct ListaCompras *lista){
    if(lista->p == NULL){
        printf("ERROR NA ALOCACAO DINAMICA");
        return 1;
    }

    for(int i = 0; i < lista->tamanhoAtual; i ++){
        printf("ID: %d\n",lista->p[i].id);
        printf("NOME DO PRODUTO: %s\n",lista->p[i].nome);
        printf("QUANTIDADE: %d\n",lista->p[i].quantidade);
        printf("PRECO: %.2f\n",lista->p[i].valorUnitario);
        printf("VALOR TOTAL: %.2f\n",lista->valorTotal);
        printf("\n\n");
    }
}
int main(void){
    struct ListaCompras lista;
    inicializarLista(&lista);
    adicionarItem(&lista,1,"Feijao",1.21,20);
    adicionarItem(&lista,2,"Arroz",1.32,21);
    mostrarRelatorio(&lista);
    removerItem(&lista,1);
    mostrarRelatorio(&lista);
    free(lista.p);



return 0;
}
