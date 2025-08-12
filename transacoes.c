#include <stdio.h>
#include <stdlib.h>
#include "transacoes.h"

// Inicializa a pilha, definindo o topo como NULL
void inicializar_pilha(Pilha* p) {
    p->topo = NULL;
}

// Verifica se a pilha esta vazia
int pilha_esta_vazia(Pilha* p) {
    return (p->topo == NULL);
}

// Adiciona uma nova transacao no topo da pilha
void empilhar_transacao(Pilha* p, Transacao t) {
    // 1. Aloca memória para o novo no
    NoPilha* novo_no = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo_no == NULL) {
        printf("Erro: Não foi possível alocar memória para o nó.\n");
        return;
    }

    // 2. Atribui a transacao ao no
    novo_no->transacao = t;

    // 3. O proximo no sera o antigo topo da pilha
    novo_no->proximo = p->topo;

    // 4. O novo no se torna o topo da pilha
    p->topo = novo_no;
}

// Remove e retorna a transacao do topo da pilha
Transacao desempilhar_transacao(Pilha* p) {
    if (pilha_esta_vazia(p)) {
        printf("Erro: A pilha de transacoes esta vazia.\n");
        // Retorna uma transacao "vazia" para indicar o erro
        Transacao transacao_vazia = {-1, -1, 0, 0.0, ""};
        return transacao_vazia;
    }

    // 1. Armazena o no do topo
    NoPilha* no_a_remover = p->topo;

    // 2. Armazena a transacao a ser retornada
    Transacao transacao_removida = no_a_remover->transacao;

    // 3. Atualiza o topo da pilha para o proximo no
    p->topo = no_a_remover->proximo;

    // 4. Libera a memoria do no removido
    free(no_a_remover);

    return transacao_removida;
}

// Retorna a transacao do topo, sem remove-la
Transacao topo_da_pilha(Pilha* p) {
    if (pilha_esta_vazia(p)) {
        printf("A pilha de transacoes esta vazia.\n");
        Transacao transacao_vazia = {-1, -1, 0, 0.0, ""};
        return transacao_vazia;
    }
    return p->topo->transacao;
}

// Imprime todas as transacoes na pilha, do topo para a base
void imprimir_pilha(Pilha* p) {
    if (pilha_esta_vazia(p)) {
        printf("A pilha de transacoes esta vazia.\n");
        return;
    }

    NoPilha* atual = p->topo;
    printf("\n--- Transacoes (Topo para Base) ---\n");
    while (atual != NULL) {
        printf("ID Transacao: %d | ID Item: %d | Quantidade: %d | Total: %.2f | Data: %s\n",
               atual->transacao.id_transacao,
               atual->transacao.id_item,
               atual->transacao.quantidade,
               atual->transacao.total,
               atual->transacao.data);
        atual = atual->proximo;
    }
    printf("------------------------------------\n");
}