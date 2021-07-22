#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nostr{
    int val;
    struct nostr *prox;
}no;

void imprime(no *le){
    no *p;
    for (p = le->prox; p != NULL; p = p->prox)
      printf ("%d\n", p->val);
}

void insere (int x, no *p){
   no *nova;
   nova = malloc (sizeof (no));
   nova->val = x;
   nova->prox = p->prox;
   p->prox = nova;
}

no* seleciona_impares(no *lista){
    no *lista_impar, *aux;
    lista_impar = malloc (sizeof (no));
    aux = malloc (sizeof (no));
    if(lista == NULL){
        return NULL;
    }
    aux = lista;
    while (aux != NULL){
        if (aux->val % 2 != 0){
            insere(aux->val, lista_impar);
        }
        aux = aux->prox;
    }
    return lista_impar;
}

int main(){
    int i;
    no *lista_original, *lista_impar;

    lista_original = malloc (sizeof (no));
    lista_impar = malloc (sizeof (no));
    
    for(i=0; i<10; i++){
        insere(i, lista_original);
    }

    printf("\nLista original: \n");
    imprime(lista_original);

    lista_impar = seleciona_impares(lista_original);

    printf("\nLista impar: \n");
    imprime(lista_impar);

    return(0);
}