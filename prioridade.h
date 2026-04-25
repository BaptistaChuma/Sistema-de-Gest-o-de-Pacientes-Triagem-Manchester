// prioridade.c (Lógica Principal)
#include "prioridade.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    Paciente *paciente;
    struct Node *next;
} Node;

struct FilaPrioridade {
    Node *head;
    int total_pacientes;
};

// Função de comparação Sênior: Prioridade > Tempo de Chegada
int comparar_pacientes(Paciente *a, Paciente *b) {
    if (a->grau_prioridade < b->grau_prioridade) return -1;
    if (a->grau_prioridade > b->grau_prioridade) return 1;
    return difftime(a->hora_chegada, b->hora_chegada);
}

void inserir_na_fila(FilaPrioridade *f, Paciente *p) {
    Node *novo = malloc(sizeof(Node));
    novo->paciente = p;
    
    // Lógica de inserção ordenada
    Node **curr = &(f->head);
    while (*curr && comparar_pacientes((*curr)->paciente, p) <= 0) {
        curr = &((*curr)->next);
    }
    novo->next = *curr;
    *curr = novo;
    f->total_pacientes++;

    // Regra de Aging: A cada 5 novos, aumenta prioridade do 6º em diante
    if (f->total_pacientes % 5 == 0) {
        Node *temp = f->head;
        for (int i = 0; temp != NULL; i++, temp = temp->next) {
            if (i >= 5 && temp->paciente->grau_prioridade > 0) {
                temp->paciente->grau_prioridade--; // Aumenta a prioridade (diminui o valor)
            }
        }
    }
}
#endif