/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cabecalho.h
 * Author: Asus
 *
 * Created on 21 de Novembro de 2017, 14:40
 */
struct nodo {
    struct nodo * pai;
    struct nodo * dir;
    struct nodo * esq;
    int info;
};
typedef struct nodo Nodo;

struct arv {
    
    struct nodo * raiz;
    int tamanho;
};
typedef struct arv Arvore;

Nodo * Min(Nodo * nodo);
Nodo * pre(Nodo * a);
Nodo * suc(Nodo * a);
Nodo * max(Nodo * nodo);
Nodo * excluir(Nodo * a, int valor);
Nodo * insere(Nodo * a, int valor);
Arvore * treeVazia();
Nodo * busca(Nodo * a, int valor);
void preOrdem(Nodo* a);
void inOrdem(Nodo* a);
void posOrdem(Nodo* a);