#include <stdio.h>
#include <stdlib.h>
#include "arvoreLLRB.h"

int main()
{
    arvoreLLRB *raiz;
    int x;

    x = insere_arvoreLLRB(raiz, 150);
    x = insere_arvoreLLRB(raiz, 110);
    x = insere_arvoreLLRB(raiz, 100);
    x = insere_arvoreLLRB(raiz, 130);
    x = insere_arvoreLLRB(raiz, 120);
    x = insere_arvoreLLRB(raiz, 140);
    x = insere_arvoreLLRB(raiz, 160);

    remove_arvoreLLRB(raiz, 100);

    return 0;
}
