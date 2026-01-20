#include <stdio.h>    // comunicação com o usuário
#include <stdlib.h>   // funções do sistema
#include <locale.h>   // idioma
#include <string.h>   // manipulação de strings

// ================= FUNÇÃO REGISTRO =================
int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file = fopen(arquivo, "w");
    if (file == NULL)
    {
        printf("Erro ao criar o arquivo!\n");
        return 0;
    }

    fprintf(file, "%s,", cpf);
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    printf("\nCadastro realizado com sucesso!\n");
    system("pause");

    return 0;
}

// ================= FUNÇÃO CONSULTA =================
int consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Não foi possível localizar o usuário!\n");
        system("pause");
        return 0;
    }

    printf("\nEssas são as informações do usuário:\n");

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("%s\n", conteudo);
    }

    fclose(file);
    system("pause");

    return 0;
}

// ================= FUNÇÃO DELETAR =================
int deletar()
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0)
    {
        printf("Usuário removido com sucesso!\n");
    }
    else
    {
        printf("Usuário não encontrado!\n");
    }

    system("pause");
    return 0;
}

// ================= FUNÇÃO PRINCIPAL =================
int main()
{
    int opcao = 0;
    char senhadigitada[10];

    setlocale(LC_ALL, "Portuguese");

    printf("### Cartório da EBAC ###\n\n");
    printf("Login de administrador\n\nDigite a senha: ");
    scanf("%s", senhadigitada);

    if (strcmp(senhadigitada, "admin") == 0)
    {
        while (1)
        {
            system("cls");

            printf("### Cartório da EBAC ###\n\n");
            printf("1 - Registrar usuário\n");
            printf("2 - Consultar usuário\n");
            printf("3 - Deletar usuário\n");
            printf("0 - Sair\n\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);

            system("cls");

            switch (opcao)
            {
                case 1:
                    registro();
                    break;

                case 2:
                    consulta();
                    break;

                case 3:
                    deletar();
                    break;

                case 0:
                    printf("Encerrando o sistema...\n");
                    return 0;

                default:
                    printf("Opção inválida!\n");
                    system("pause");
                    break;
            }
        }
    }
    else
    {
        printf("Senha incorreta!\n");
        system("pause");
    }

    return 0;
}
