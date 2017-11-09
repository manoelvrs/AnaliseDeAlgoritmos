#include <stdlib.h>
#include <stdio.h>

struct no{
    int v;
    struct no *direita;
    struct no *esquerda;
};

int insere(struct no** raiz, int v);
int busca(struct no** ptrRaiz, int v);
struct no** arv_inicializa();
int main() {
    struct no** ptrRaiz;
    ptrRaiz = arv_inicializa();

    insere(ptrRaiz,8);
    insere(ptrRaiz,7);
    insere(ptrRaiz,9);
    insere(ptrRaiz,5);
    insere(ptrRaiz,6);

    if (busca(ptrRaiz, 15)) printf("Encontrado\n");
    else printf("Não Encontrado \n");
}

int insere(struct no** raiz, int v){ 
    if(raiz == NULL){
       printf("Não inicializada\n");
        return 0;
    }
    if(*raiz == NULL){
        struct no* ptrAux = (struct no*)malloc(sizeof(struct no));
        ptrAux->direita = NULL;
        ptrAux->esquerda = NULL;
        ptrAux->v = v;
        *raiz = ptrAux;

        return 1;
    }
    else{
        if(v == (*raiz)->v) return 0;

        else if(v > (*raiz)->v){
           return insere(&((*raiz)->direita), v);
       }
        else if(v < (*raiz)->v){
           return insere(&((*raiz)->esquerda), v);
       }
    }

}

int busca(struct no** ptrRaiz, int v){ 
    if(*ptrRaiz == NULL){
        return 0;
    }
    if((*ptrRaiz)->v == v) return 1;
    else if((*ptrRaiz)->v > v) return busca(&((*ptrRaiz)->esquerda), v );
    else return (busca(&((*ptrRaiz)->direita), v));
}

int arv_vazia(struct no** ptrRaiz){ // verifica vazia

    if(ptrRaiz == NULL || *ptrRaiz == NULL){
       printf("Árvore vazia!\n");
        return 1;
    }
    printf("Árvore não vazia!\n");
    return 0;
}
struct no** arv_inicializa(){
    struct no** ptrAux = (struct no**)malloc(sizeof(struct no*));
    if(ptrAux != NULL){ *ptrAux = NULL;}
    //*ptrAux = NULL;
    return ptrAux;
}
