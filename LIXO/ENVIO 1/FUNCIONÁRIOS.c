#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

typedef struct {
    char nome[100];
    int id;
    char cargo[50];
    float salario;
} Funcionario;

void cadastrar_funcionarios(Funcionario funcionarios[], int *total);
void exibir_funcionarios_com_salario_acima(Funcionario funcionarios[], int total, float valor);
float calcular_media_salarial(Funcionario funcionarios[], int total);
void exibir_funcionario(const Funcionario *f);

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int total_funcionarios = 0;
    int opcao;

    do {
        printf("\n=== Sistema de gerenciamento de funcionarios ===\n");
        printf("1. Cadastrar Funcionarios\n");
        printf("2. Mostrar funcionarios com Salario acima de um valor\n");
        printf("3. Calcular e exibir a media dos salarios\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                cadastrar_funcionarios(funcionarios, &total_funcionarios);
                break;
            case 2: {
                float valor;
                printf("Informe o valor do salario: ");
                scanf("%f", &valor);
                exibir_funcionarios_com_salario_acima(funcionarios, total_funcionarios, valor);
                break;
            }
            case 3: {
                float media = calcular_media_salarial(funcionarios, total_funcionarios);
                if (total_funcionarios > 0)
                    printf("Media dos salarios: %.2f\n", media);
                else
                    printf("Nenhum funcionario cadastrado.\n");
                break;
            }
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Função para cadastrar funcionários
void cadastrar_funcionarios(Funcionario funcionarios[], int *total) {
    int quantidade;

    if (*total >= MAX_FUNCIONARIOS) {
        printf("Limite maximo de funcionarios atingido!\n");
        return;
    }

    printf("Quantos funcionarios deseja cadastrar? (Disponivel: %d): ", MAX_FUNCIONARIOS - *total);
    scanf("%d", &quantidade);
    getchar();

    if (*total + quantidade > MAX_FUNCIONARIOS) {
        printf("Erro: Voce pode cadastrar no maximo %d funcionarios.\n", MAX_FUNCIONARIOS - *total);
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Cadastro do Funcionario %d ---\n", *total + 1);

        printf("Nome: ");
        fgets(funcionarios[*total].nome, sizeof(funcionarios[*total].nome), stdin);
        funcionarios[*total].nome[strcspn(funcionarios[*total].nome, "\n")] = '\0';

        printf("ID do Funcionario: ");
        scanf("%d", &funcionarios[*total].id);
        getchar();

        printf("Cargo: ");
        fgets(funcionarios[*total].cargo, sizeof(funcionarios[*total].cargo), stdin);
        funcionarios[*total].cargo[strcspn(funcionarios[*total].cargo, "\n")] = '\0';

        printf("Salario: ");
        scanf("%f", &funcionarios[*total].salario);
        getchar();

        (*total)++;
    }

    printf("Funcionarios cadastrados com sucesso!\n");
}

// Função para exibir funcionários com salário acima de um valor x
void exibir_funcionarios_com_salario_acima(Funcionario funcionarios[], int total, float valor) {
    if (total == 0) {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }

    int encontrados = 0;
    printf("\nFuncionarios com salario acima de %.2f:\n", valor);
    for (int i = 0; i < total; i++) {
        if (funcionarios[i].salario > valor) {
            exibir_funcionario(&funcionarios[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum funcionario encontrado com salario acima de %.2f.\n", valor);
    }
}

// Função para calcular a média dos salários
float calcular_media_salarial(Funcionario funcionarios[], int total) {
    if (total == 0) return 0.0;

    float soma = 0.0;
    for (int i = 0; i < total; i++) {
        soma += funcionarios[i].salario;
    }
    return soma / total;
}

// Função auxiliar para exibir informações de um funcionário
void exibir_funcionario(const Funcionario *f) {
    printf("\nNome: %s\n", f->nome);
    printf("ID: %d\n", f->id);
    printf("Cargo: %s\n", f->cargo);
    printf("Salario: %.2f\n", f->salario);
}
