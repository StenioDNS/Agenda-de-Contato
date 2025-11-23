#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100
typedef struct {
    char nome[50];
    char email[50];
    char telefone[20];
} Contato;

Contato agenda[MAX_CONTATOS];
int totalContatos = 0;
void adicionarContato() {
    if (totalContatos >= MAX_CONTATOS) {
        printf("\nAgenda cheia! Não é possível adicionar mais contatos.\n");
        return;
    }

    printf("\n---- CADASTRAR CONTATO ----\n");
    printf("Nome: ");
    scanf("%s", agenda[totalContatos].nome);

    printf("Email: ");
    scanf("%s", agenda[totalContatos].email);

    printf("Telefone: ");
    scanf("%s", agenda[totalContatos].telefone);

    totalContatos++;

    printf("\nContato cadastrado com sucesso!\n");
}

void listarContatos() {
    if (totalContatos == 0) {
        printf("\nNenhum contato cadastrado.\n");
        return;
    }

    printf("\n---- LISTA DE CONTATOS ----\n");

    for (int i = 0; i < totalContatos; i++) {
        printf("\nContato %d:\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("Email: %s\n", agenda[i].email);
        printf("Telefone: %s\n", agenda[i].telefone);
    }
}

void buscarContato() {
    char nomeBusca[50];
    printf("\nDigite o nome do contato que deseja buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(nomeBusca, agenda[i].nome) == 0) {
            printf("\n---- CONTATO ENCONTRADO ----\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Email: %s\n", agenda[i].email);
            printf("Telefone: %s\n", agenda[i].telefone);
            return;
        }
    }

    printf("\nContato não encontrado!\n");
}

void removerContato() {
    char nomeRemove[50];
    printf("\nDigite o nome do contato que deseja remover: ");
    scanf("%s", nomeRemove);

    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(nomeRemove, agenda[i].nome) == 0) {

            for (int j = i; j < totalContatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }

            totalContatos--;
            printf("\nContato removido com sucesso!\n");
            return;
        }
    }

    printf("\nContato não encontrado!\n");
}

int main() {
    int opcao;

    do {
        printf("\n===== AGENDA DE CONTATOS =====\n");
        printf("1 - Cadastrar novo contato\n");
        printf("2 - Listar todo os contatos\n");
        printf("3 - Buscar contato por nome\n");
        printf("4 - Remover Contato\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                listarContatos();
                break;
            case 3:
                buscarContato();
                break;
            case 4:
                removerContato();
                break;
            case 5:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    } while(opcao != 5);

    return 0;
}