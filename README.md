# Atividade Avaliativa 2 — Pilha Dinâmica e Manipulação de Strings

Repositório com os dois desafios da Atividade Avaliativa 2 da disciplina de Estruturas de Dados.

---

## 📁 Estrutura do Repositório

```
.
├── desafio1.c   # Verificador de expressão balanceada (pilha dinâmica)
├── desafio2.c   # Inversão de string com pilha dinâmica
└── README.md
```

---

## ⚙️ Como Compilar e Executar

```bash
# Desafio 1
gcc -Wall -o desafio1 desafio1.c && ./desafio1

# Desafio 2
gcc -Wall -o desafio2 desafio2.c && ./desafio2
```

---

## 🧱 Estrutura da Pilha (comum aos dois desafios)

Ambos os programas implementam a mesma pilha dinâmica do zero, sem bibliotecas prontas.

```
         TOPO
          ↓
        ┌────┐
        │ c  │ → próximo nó → ... → NULL
        └────┘
```

A pilha é composta por dois tipos:

```c
typedef struct No {
    char dado;         // valor armazenado
    struct No *proximo; // ponteiro para o nó abaixo
} No;

typedef struct {
    No *topo;          // ponteiro para o topo da pilha
} Pilha;
```

### Operações implementadas

| Função       | O que faz                                              |
|--------------|--------------------------------------------------------|
| `inicializar`| Define `topo = NULL` (pilha vazia)                    |
| `isEmpty`    | Retorna `1` se `topo == NULL`, `0` caso contrário      |
| `push`       | Aloca um novo nó e o coloca no topo                    |
| `pop`        | Remove e retorna o valor do topo, liberando a memória  |

---

## 📝 Desafio 1 — Expressão Balanceada (`desafio1.c`)

### Objetivo
Receber uma string com `(`, `)`, `{`, `}`, `[`, `]` e verificar se os símbolos estão corretamente balanceados.

### Como funciona

O algoritmo percorre a string caractere por caractere:

- Se for um símbolo de **abertura** (`(`, `[`, `{`) → **empilha**.
- Se for um símbolo de **fechamento** (`)`, `]`, `}`) → **desempilha** e verifica se o par é correspondente.
- Se a pilha estiver vazia quando tentar fechar, ou o par não bater → **inválido**.
- Ao final, se a pilha estiver vazia → **válido**. Caso contrário, sobram aberturas sem fechamento → **inválido**.

### Fluxo visual (exemplo: `{[()]}`)

```
Char   Ação          Pilha (topo → base)
────   ────────────  ───────────────────
{      push          { 
[      push          [ {
(      push          ( [ {
)      pop → (  ✅   [ {
]      pop → [  ✅   {
}      pop → {  ✅   (vazia)

Pilha vazia ao final → VÁLIDA ✅
```

### Exemplos de saída

```
Digite a expressão: {[()]}
Expressão VÁLIDA: os símbolos estão balanceados.

Digite a expressão: {[(])}
Expressão INVÁLIDA: os símbolos NÃO estão balanceados.

Digite a expressão: ((()
Expressão INVÁLIDA: os símbolos NÃO estão balanceados.
```

---

## 📝 Desafio 2 — Inversão de String com Pilha (`desafio2.c`)

### Objetivo
Receber uma string e retorná-la invertida, usando **apenas** a pilha — sem vetor auxiliar e sem funções prontas.

### Como funciona

A inversão explora a propriedade **LIFO** (Last In, First Out) da pilha:

1. Percorre a string do início ao fim, empilhando cada caractere.
2. Desempilha um a um, imprimindo — o último caractere entra e sai primeiro, produzindo a inversão.

### Fluxo visual (exemplo: `"DADO"`)

```
Empilhando:          Desempilhando (saída):
push('D')            pop() → 'O'
push('A')            pop() → 'D'
push('D')            pop() → 'A'
push('O')            pop() → 'D'

Resultado: "ODAD"
```

### Exemplos de saída

```
Digite a string: Estruturas
String invertida: saruturtsE

Digite a string: Hello World
String invertida: dlroW olleH

Digite a string: 12345
String invertida: 54321
```

### Por que funciona sem vetor auxiliar?
A pilha **é** a estrutura de armazenamento. A string invertida nunca existe como um bloco de memória — ela é construída caractere por caractere diretamente na saída, via `pop`.

---

## 👥 Integrantes

| Nome Completo | Usuário GitHub |
|---------------|----------------|
|  André Felipe            |    Lipe0505    |
|  Erick Sartori           |                |

---

## 📬 Entrega

- **Data (ADS):** 08/04 até 19h
- **Data (ES):** 10/04 até 19h
- **E-mail para:** joao.vsantos@unicesumar.edu.br
- **Título:** `Trabalho Estruturas de dados ADSIS3S`
- **CC:** gabriel.pjesus@unicesumar.edu.br e todos os integrantes
