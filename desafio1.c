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
    novo->dado     = c;
    novo->proximo  = p->topo;
    p->topo        = novo;
}

char pop(Pilha *p) {
    if (isEmpty(p)) return '\0';
    No   *removido = p->topo;
    char  valor    = removido->dado;
    p->topo        = removido->proximo;
    free(removido);
    return valor;
}

void liberar(Pilha *p) {
    while (!isEmpty(p)) pop(p);
}

int corresponde(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

int balanceada(const char *expr) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&p) || !corresponde(pop(&p), c)) {
                liberar(&p);
                return 0;
            }
        }

    }

    int resultado = isEmpty(&p);
    liberar(&p);
    return resultado;
}

int main(void) {
    char expr[256];

    printf("Digite a expressão: ");
    scanf("%255s", expr);

    if (balanceada(expr)) {
        printf("Expressão VÁLIDA: os símbolos estão balanceados.\n");
    } else {
        printf("Expressão INVÁLIDA: os símbolos NÃO estão balanceados.\n");
    }

    return 0;
}
