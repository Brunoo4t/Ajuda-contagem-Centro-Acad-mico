#include <stdio.h>
#include "transacoes.h" // Incluindo o cabecalho da nossa biblioteca

int main() {
    Pilha minhas_transacoes; // 1. Declara a variavel da pilha
    inicializar_pilha(&minhas_transacoes); // 2. Chama a funcao de inicializacao

    // 3. Verifica se a pilha esta vazia, o que deve ser verdade neste ponto
    if (pilha_esta_vazia(&minhas_transacoes)) {
        printf("A pilha de transacoes esta zerada e pronta para uso!\n");
    }

    // A partir daqui, o programa estaria esperando por novas vendas
    printf("Aguardando novas transacoes...\n");

    return 0;
}