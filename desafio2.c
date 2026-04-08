#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char    dado;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
}

int isEmpty(Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, char c) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Erro: memória insuficiente.\n");
        exit(1);
    }
    novo->dado    = c;
    novo->proximo = p->topo;
    p->topo       = novo;
}

char pop(Pilha *p) {
    if (isEmpty(p)) return '\0';
    No   *removido = p->topo;
    char  valor    = removido->dado;
    p->topo        = removido->proximo;
    free(removido);
    return valor;
}

int main(void) {
    char original[256];
    Pilha p;

    printf("Digite a string: ");
    scanf("%255[^\n]", original);

    inicializar(&p);

    for (int i = 0; original[i] != '\0'; i++) {
        push(&p, original[i]);
    }

    printf("String invertida: ");
    while (!isEmpty(&p)) {
        printf("%c", pop(&p));
    }
    printf("\n");

    return 0;
}
