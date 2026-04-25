#include <stdio.h>
#include <time.h>
#include "prioridade.h"
#include "historico.h"

void processar_simulacao(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return;

    clock_t start = clock();
    char comando[10];
    
    // Exemplo de loop de leitura
    while (fscanf(file, "%s", comando) != EOF) {
        if (strcmp(comando, "ENTRADA") == 0) {
            // ler dados e chamar inserir_na_fila
        } else if (strcmp(comando, "ATENDER") == 0) {
            // remover da fila e dar push na pilha
        } else if (strcmp(comando, "DESFAZER") == 0) {
            // pop da pilha e re-inserir na fila com prioridade máxima
        }
    }

    clock_t end = clock();
    double cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Arquivo: %s | Tempo: %f s\n", filename, cpu_time);
    
    fclose(file);
}
