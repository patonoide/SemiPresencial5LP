/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cabecalho.h"          
#include <stdio.h>
#include <stdlib.h>

Arvore * treeVazia() {
    Arvore * a = NULL;

    a = (Arvore *) malloc(sizeof (Arvore));
    a->raiz = NULL;
    a->tamanho = 0;
}

Nodo * insere(Nodo * a, int valor) {
    if (a == NULL) {
        a = (Nodo *) malloc(sizeof (Nodo));
        a->info = valor;
        a->dir = NULL;
        a->esq = NULL;
    } else {
        if (valor < a->info) {

            a->esq = insere(a->esq, valor);
        } else {

            a->dir = insere(a->dir, valor);
        }
    }
    return a;
}

Nodo * excluir(Nodo * a, int valor) {
    Nodo * temp;
    Nodo * filhote;
    if (a == NULL) {
        printf("\nElemento nao encontrado");
    } else if (valor < a->info) {
        a->esq = excluir(a->esq, valor);
    } else if (valor > a->info) {
        a->dir = excluir(a->dir, valor);
    } else if (a->esq && a->dir) {
        temp = Min(a->dir);
        a->info = temp->info;
        a->dir = excluir(a->dir, a->info);
    } else {
        temp = a;
        if (a->esq == NULL) {
            filhote = a->dir;
        }
        if (a->dir == NULL) {
            filhote = a->esq;
        }
        free(a);
        return filhote;
    }
    return a;


}

Nodo * max(Nodo * nodo) {


    while (nodo->dir != NULL) {
        nodo = nodo->dir;
    }
    return nodo;
}

Nodo * suc(Nodo * a) {
    if (a->dir != NULL) {
        return Min(a->dir);
    } else {
        return a;
    }

}

Nodo * pre(Nodo * a) {

    if (a->esq != NULL) {
        return max(a->esq);
    } else {
        return a;
    }



}

Nodo * Min(Nodo * nodo) {


    while (nodo->esq != NULL) {
        nodo = nodo->esq;
    }
    return nodo;
}

Nodo * busca(Nodo * a, int valor) {
    if (a == NULL) {
        return NULL;
    } else if (a->info > valor) {
        return busca(a->esq, valor);
    } else if (a->info < valor) {
        return busca(a->dir, valor);
    } else {
        return a;
    }
}

void preOrdem(Nodo* a) {
    if (a == NULL) {
        printf("<>");
    }
    if (a != NULL) {
        printf("<%i", a->info);
        preOrdem(a->esq);

        preOrdem(a->dir);
        printf(">");
    }
}

void inOrdem(Nodo* a) {
    if (a == NULL) {
        printf("<>");
    }
    if (a != NULL) {

        inOrdem(a->esq);
        printf("<%i", a->info);
        inOrdem(a->dir);
        printf(">");
    }
}

void posOrdem(Nodo* a) {
    if (a == NULL) {
        printf("<>");
    }
    if (a != NULL) {

        posOrdem(a->esq);
        printf(">");
        posOrdem(a->dir);

        printf("<%i", a->info);
    }
}