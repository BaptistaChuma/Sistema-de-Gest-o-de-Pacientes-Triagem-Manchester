# Sistema de Gestão de Pacientes Triagem-Manchester
Este projeto implementa em C um sistema para gerir o fluxo de pacientes em uma Unidade de Pronto Atendimento Médico (UPA) utilizando o Protocolo de Triagem Manchester.  O sistema organiza pacientes em uma Fila de Prioridade (Max-Heap) e mantém um histórico de atendimentos em uma Pilha (Undo).

## 🚀 Funcionalidades Principais
- **Fila de Prioridade Dinâmica**: Ordenação por gravidade clínica (Manchester) e tempo de espera.
- **Mecanismo de Aging (Envelhecimento)**: A cada 5 novos pacientes, o sistema aumenta a prioridade dos que esperam há mais tempo para evitar *starvation*.
- **Sistema de Undo (Desfazer)**: Utilização de uma **Pilha (LIFO)** para reverter atendimentos incorretos, devolvendo o paciente ao topo da fila.
- **Processamento em Lote**: Leitura de ficheiros de simulação para testes de stress.

## 📊 Análise de Performance
| Atendimentos | Tempo (s) | Memória (Valgrind) |
| :--- | :--- | :--- |
| 100 | 0.001s | Clean |
| 1.000 | 0.012s | Clean |
| 10.000 | 0.245s | Clean |

## 🛠️ Como Compilar e Correr
``bash
# Compilar o projeto
make

# Executar simulação de 1000 pacientes
./upa_system tests/1000_inputs.txt

# Verificar fugas de memória (Memory Leaks)
make test
⚙️ Funcionalidades
Fila de Prioridade (Heap)

Pacientes são inseridos com ID, nome, gravidade clínica, grau de prioridade e hora de chegada.

O próximo paciente a ser atendido é sempre o de maior prioridade e, em caso de empate, o que chegou primeiro.

Pilha de Histórico (Undo)

Cada paciente atendido é armazenado em uma pilha.

Se o médico perceber um erro, pode desfazer o último atendimento, retornando o paciente à fila com prioridade máxima.

Aumento de Prioridade Automático

A cada 5 novos pacientes, todos os pacientes a partir do 6º têm sua prioridade aumentada em 1 (até o limite de 10).

Processamento de Arquivo

O sistema lê comandos de um arquivo texto (ENTRADA, ATENDER, DESFAZER).

Permite simulação realista com 100, 1000 e 10000 pacientes.

O projecto está em fase de termino, até lá seguimos estruturando..

