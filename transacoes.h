#ifndef TRANSACOES_H
#define TRANSACOES_H

// --- Estruturas de Dados ---

// Estrutura para uma única transação (venda)
typedef struct {
    int id_transacao;
    int id_item;
    int quantidade;
    float total;
    char data[20];
} Transacao;

// Estrutura para o nó da pilha
typedef struct NoPilha {
    Transacao transacao;
    struct NoPilha* proximo;
} NoPilha;

// Estrutura para a pilha
typedef struct {
    NoPilha* topo;
} Pilha;

// --- Funcoes da Pilha ---

// Inicializa a pilha
void inicializar_pilha(Pilha* p);

// Adiciona uma transacao ao topo da pilha (push)
void empilhar_transacao(Pilha* p, Transacao t);

// Remove e retorna a transacao do topo da pilha (pop)
Transacao desempilhar_transacao(Pilha* p);

// Exibe a transacao que esta no topo da pilha, sem remove-la
Transacao topo_da_pilha(Pilha* p);

// Verifica se a pilha esta vazia
int pilha_esta_vazia(Pilha* p);

// Imprime todas as transacoes na pilha
void imprimir_pilha(Pilha* p);

#endif