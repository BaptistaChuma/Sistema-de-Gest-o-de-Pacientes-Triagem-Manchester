#include "prioridade.h"
#include "historico.h"

void limpar_sistema(FilaPrioridade *f, Pilha *p) {
    // 1. Limpar a Fila de Prioridade
    Node *curr_f = f->head;
    while (curr_f != NULL) {
        Node *next = curr_f->next;
        free(curr_f->paciente); // Liberta a estrutura do Paciente
        free(curr_f);           // Liberta o nó da lista
        curr_f = next;
    }
    free(f);

    // 2. Limpar a Pilha (Histórico)
    StackNode *curr_p = p->top;
    while (curr_p != NULL) {
        StackNode *next = curr_p->next;
        // Nota: Se o paciente já foi libertado na fila, cuidado para não fazer double-free.
        // Mas como os pacientes na pilha saíram da fila, eles ainda precisam ser libertados aqui.
        free(curr_p->paciente); 
        free(curr_p);
        curr_p = next;
    }
    free(p);
    
    printf("\n[Sênior Log] Memória libertada com sucesso. Valgrind pronto.\n");
}