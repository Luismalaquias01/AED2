#include <stdio.h>
#include <string.h>


struct Contato {
    char nome[20];
    char endereco[50];
    char telefone[11];
    char cpf[11];
    char cnpj[20];
};

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int total_contatos; 

    printf("Quantidade total de contatos desejados: ");
    scanf("%d", &total_contatos);
    limpar_buffer();

    struct Contato contatos[total_contatos];
    
    for (int i = 0; i < total_contatos; i++) {
 =

        printf("\nDigite o nome: ");
        fgets(contatos[i].nome, sizeof(contatos[i].nome), stdin);
        contatos[i].nome[strcspn(contatos[i].nome, "\n")] = '\0';

        printf("Digite o endereco: ");
        fgets(contatos[i].endereco, sizeof(contatos[i].endereco), stdin);
        contatos[i].endereco[strcspn(contatos[i].endereco, "\n")] = '\0';

        printf("Digite o telefone: ");
        fgets(contatos[i].telefone, sizeof(contatos[i].telefone), stdin);
        contatos[i].telefone[strcspn(contatos[i].telefone, "\n")] = '\0';

        char tipo;
        printf("Digite F para CPF, J para CNPJ, ou A para ambos: ");
        scanf(" %c", &tipo); 

        switch (tipo) {
            case 'A':
                limpar_buffer();
                printf("Digite o CPF: ");
                fgets(contatos[i].cpf, sizeof(contatos[i].cpf), stdin);
                contatos[i].cpf[strcspn(contatos[i].cpf, "\n")] = '\0';

                printf("Digite o CNPJ: ");
                fgets(contatos[i].cnpj, sizeof(contatos[i].cnpj), stdin);
                contatos[i].cnpj[strcspn(contatos[i].cnpj, "\n")] = '\0';
                break;

            case 'F':
                limpar_buffer();
                printf("Digite o CPF: ");
                fgets(contatos[i].cpf, sizeof(contatos[i].cpf), stdin);
                contatos[i].cpf[strcspn(contatos[i].cpf, "\n")] = '\0';
                break;

            case 'J':
                limpar_buffer();
                printf("Digite o CNPJ: ");
                fgets(contatos[i].cnpj, sizeof(contatos[i].cnpj), stdin);
                contatos[i].cnpj[strcspn(contatos[i].cnpj, "\n")] = '\0';
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    printf("\nContatos registrados:\n");
    for (int i = 0; i < total_contatos; i++) {
        printf("\n--- Contato %d ---\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Endereco: %s\n", contatos[i].endereco);
        printf("Telefone: %s\n", contatos[i].telefone);

        printf("Escolha uma opção:\n");
        printf("1 - Exibir CPF\n");
        printf("2 - Exibir CNPJ\n");
        printf("3 - Exibir ambos\n");
        int opcao;
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1:
                printf("CPF: %s\n", contatos[i].cpf[0] ? contatos[i].cpf : "Não informado");
                break;
            case 2:
                printf("CNPJ: %s\n", contatos[i].cnpj[0] ? contatos[i].cnpj : "Não informado");
                break;
            case 3:
                printf("CPF: %s\n", contatos[i].cpf[0] ? contatos[i].cpf : "Não informado");
                printf("CNPJ: %s\n", contatos[i].cnpj[0] ? contatos[i].cnpj : "Não informado");
                break;
            default:
                printf("Opção inválida!\n");
                break;
            
        }
    }
    limpar_buffer();

    return 0;
}
