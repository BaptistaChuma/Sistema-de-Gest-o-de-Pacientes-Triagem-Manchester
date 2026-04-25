#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "prioridade.h"
#include "historico.h"
#include "common.h"

// Protótipo da função de limpeza para o Valgrind ficar feliz
void limpar_sistema(FilaPrioridade *f, Pilha *p);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo_de_teste.txt>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    FilaPrioridade *fila = criar_fila();
    Pilha *pilha = criar_pilha();
    
    char comando;
    clock_t start = clock();

    while (fscanf(file, " %c", &comando) != EOF) {
        if (comando == 'E') {
            Paciente *novo = malloc(sizeof(Paciente));
            fscanf(file, "%d \"%[^\"]\" %u %ld", 
                   &novo->id, novo->nome, (unsigned int*)&novo->gravidade, &novo->hora_chegada);
            
            // O grau_prioridade inicial é a própria gravidade
            novo->grau_prioridade = (int)novo->gravidade;
            inserir_na_fila(fila, novo);

        } else if (comando == 'A') {
            Paciente *atendido = remover_da_fila(fila);
            if (atendido) {
                atendido->hora_atendimento = time(NULL);
                push_historico(pilha, atendido);
                // printf("Atendendo: %s\n", atendido->nome);
            }

        } else if (comando == 'D') {
            Paciente *errado = pop_historico(pilha);
            if (errado) {
                // Regra Sênior: Volta ao início com prioridade máxima (0)
                errado->grau_prioridade = -1; // Menor que EMERGENCIA (0) garante topo absoluto
                inserir_na_fila(fila, errado);
                // printf("Desfeito atendimento de: %s\n", errado->nome);
            }
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n--- Relatorio de Performance ---\n");
    printf("Arquivo: %s\n", argv[1]);
    printf("Tempo total: %.4f segundos\n", time_spent);
    printf("-------------------------------\n");

    fclose(file);
    limpar_sistema(fila, pilha); // Liberação de memória
    return 0;
}

void limpar_sistema(FilaPrioridade *f, Pilha *p) {
    // Implementar a liberação de cada nó e de cada Paciente* // para garantir que o Valgrind retorne "0 errors".
}