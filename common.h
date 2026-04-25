// include/common.h
typedef enum {
    EMERGENCIA = 0,       // Vermelho - Prioridade máxima
    MUITO_URGENTE = 1,    //Laranja
    URGENTE = 2,          //Amarelo
    POUCO_URGENTE = 3,    //Verde
    NAO_URGENTE = 4       //Azul
} Gravidade;

typedef struct {
    int id;
    char nome[100];
    Gravidade gravidade;
    int grau_prioridade; // Usado para o ajuste a cada 5 pacientes e crit´rios de desenpenhos e Aging
    time_t hora_chegada;
    time_t hora_atendimento;
} Paciente;
#endif