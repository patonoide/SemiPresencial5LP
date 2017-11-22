/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Asus
 *
 * Created on 21 de Novembro de 2017, 14:40
 */

#include <stdio.h>
#include <stdlib.h>

#include "cabecalho.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int opcao = 0;
    int valor;
    Arvore * a;
    Nodo * t;
    Nodo * b;
    a = treeVazia();
    b = a->raiz;
    do {
        printf("\nDigite a opcao desejada de acordo com o menu\n 1-Inserir elemento na arvore. \n 2-Excluir o elemento da arvore.\n 3-Imprimir a arvore.\n 4-Minimo \n 5-Maximo \n 6-Predecessor \n 7-Sucessor\n 0-Sair\nOpcao:");
        scanf("%i", &opcao);

        switch (opcao) {
            case 1:
            {
                printf("Informe o valor a ser inserido:");
                scanf("%i", &valor);
                t = busca(b, valor);
                if (t == NULL) {
                    b = insere(b, valor);
                    printf("Valor inserido com sucesso!!!");
                } else {

                    printf("Valor ja inserido com sucesso!!!");
                }


                break;
            }
            case 2:
            {
                printf("Informe o valor a ser excluido:");
                scanf("%i", &valor);
                t = busca(b, valor);
                if (t == NULL) {
                    printf("Valor nao encontrado na arvore!!!");
                } else {
                    b = excluir(b, valor);
                    printf("Valor excluido com sucesso!!!");
                }
                break;
            }
            case 3:
            {
                printf("Informe a ordem para impressao:\n 1-Pre ordem\n 2-In ordem\n 3-Pos ordem\n Opcao:");
                scanf("%i", &valor);
                if (valor == 1) {
                    preOrdem(b);
                } else if (valor == 2) {
                    inOrdem(b);
                } else {
                    posOrdem(b);
                }
                break;
            }
            case 4:
            {
                t = Min(b);
                valor = t->info;
                printf("\nO menor numero e: %d", valor);
                break;
            }
            case 5:
            {
                t = max(b);
                valor = t->info;
                printf("\nO maior numero e: %d", valor);
                break;
            }

            case 6:
            {
                t = pre(b);
                valor = t->info;
                printf("\nO maior numero e: %d", valor);
                break;
            }
            case 7:
            {
                t = suc(b);
                valor = t->info;
                printf("\nO maior numero e: %d", valor);
                break;

            }
            case 8:
            {
                
            }
            case 0:
            {
                printf("Indo embora...\n...\nTchau o/\n");
                break;
            }
            default:
            {
                printf("Opcao invalida!!!");
                break;
            }
        }

    } while (opcao != 0);




    return (EXIT_SUCCESS);
}

