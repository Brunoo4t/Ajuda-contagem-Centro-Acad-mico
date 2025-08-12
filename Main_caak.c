#include <stdio.h>
#include "transacoes.h"

int main() {
    Pilha minhas_transacoes;
    inicializar_pilha(&minhas_transacoes);

    // --- Empilhando algumas transacoes ---
    Transacao t1 = {1, 101, 2, 8.0, "12/08/2025"};
    Transacao t2 = {2, 205, 1, 3.5, "12/08/2025"};
    Transacao t3 = {3, 101, 3, 12.0, "12/08/2025"};

    printf("Registrando transações...\n");
    empilhar_transacao(&minhas_transacoes, t1);
    empilhar_transacao(&minhas_transacoes, t2);
    empilhar_transacao(&minhas_transacoes, t3);

    imprimir_pilha(&minhas_transacoes);

    // --- Verificando o topo da pilha ---
    Transacao topo = topo_da_pilha(&minhas_transacoes);
    printf("\nTransacao no topo da pilha: ID %d (Total: %.2f)\n",
           topo.id_transacao, topo.total);

    // --- Desempilhando a ultima transacao ---
    printf("\nDesfazendo a ultima transacao...\n");
    Transacao ultima_transacao = desempilhar_transacao(&minhas_transacoes);
    printf("Transacao removida: ID %d | Total: %.2f\n",
           ultima_transacao.id_transacao, ultima_transacao.total);

    imprimir_pilha(&minhas_transacoes);

    return 0;
}