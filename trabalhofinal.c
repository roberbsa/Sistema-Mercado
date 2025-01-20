#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_CLIENTES 100
#define MAX_VENDAS 100


typedef struct {
    char nome[50];
    char categoria[30];
    int quantidade;
    float valor;
} Produto;

typedef struct {
    char nome[50];
    char rg[15];
    char cpf[15];
    char dataNascimento[11];
} Cliente;

typedef struct {
    char cpfCliente[15];
    char nomeProduto[50];
    int quantidadeVendida;
    float valorVenda;
} Venda;


void menuInicial(Produto *produtos, int *numProdutos, Cliente *clientes, int *numClientes, Venda *vendas, int *numVendas);
void menuProduto(Produto *produtos, int *numProdutos);
void menuCliente(Cliente *clientes, int *numClientes);
void menuVenda(Produto *produtos, int *numProdutos, Cliente *clientes, int *numClientes, Venda *vendas, int *numVendas);


void cadastrarProduto(Produto *produtos, int *numProdutos);
void consultarProduto(Produto *produtos, int numProdutos);
void editarProduto(Produto *produtos, int numProdutos);
void excluirProduto(Produto *produtos, int *numProdutos);
void listarProdutos(Produto *produtos, int numProdutos);
void salvarProdutos(Produto *produtos, int numProdutos);
void carregarProdutos(Produto *produtos, int *numProdutos);


void cadastrarCliente(Cliente *clientes, int *numClientes);
void consultarCliente(Cliente *clientes, int numClientes);
void editarCliente(Cliente *clientes, int numClientes);
void excluirCliente(Cliente *clientes, int *numClientes);
void listarClientes(Cliente *clientes, int numClientes);
void salvarClientes(Cliente *clientes, int numClientes);
void carregarClientes(Cliente *clientes, int *numClientes);


void realizarVenda(Produto *produtos, int *numProdutos, Cliente *clientes, int numClientes, Venda *vendas, int *numVendas);
void consultarCaixa(Venda *vendas, int numVendas);
void listarVendas(Venda *vendas, int numVendas);
void quantidadeProdutosVendidos(Venda *vendas, int numVendas);
void salvarVendas(Venda *vendas, int numVendas);
void carregarVendas(Venda *vendas, int *numVendas);


int main() {
    Produto produtos[MAX_PRODUTOS];
    Cliente clientes[MAX_CLIENTES];
    Venda vendas[MAX_VENDAS];
    int numProdutos = 0, numClientes = 0, numVendas = 0;

    carregarProdutos(produtos, &numProdutos);
    carregarClientes(clientes, &numClientes);
    carregarVendas(vendas, &numVendas);

    menuInicial(produtos, &numProdutos, clientes, &numClientes, vendas, &numVendas);

    salvarProdutos(produtos, numProdutos);
    salvarClientes(clientes, numClientes);
    salvarVendas(vendas, numVendas);

    return 0;
}

void menuInicial(Produto *produtos, int *numProdutos, Cliente *clientes, int *numClientes, Venda *vendas, int *numVendas) {
    int opcao;

    do {
        printf("\n=== MENU INICIAL ===\n");
        printf("1. Produtos\n");
        printf("2. Clientes\n");
        printf("3. Vendas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuProduto(produtos, numProdutos);
                break;
            case 2:
                menuCliente(clientes, numClientes);
                break;
            case 3:
                menuVenda(produtos, numProdutos, clientes, numClientes, vendas, numVendas);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

void menuProduto(Produto *produtos, int *numProdutos) {
    int opcao;
    do {
        printf("\n=== MENU PRODUTOS ===\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Consultar Produto\n");
        printf("3. Editar Produto\n");
        printf("4. Excluir Produto\n");
        printf("5. Listar Produtos\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, numProdutos);
                break;
            case 2:
                consultarProduto(produtos, *numProdutos);
                break;
            case 3:
                editarProduto(produtos, *numProdutos);
                break;
            case 4:
                excluirProduto(produtos, numProdutos);
                break;
            case 5:
                listarProdutos(produtos, *numProdutos);
                break;
            case 0:
                printf("Voltando ao menu inicial...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

void menuCliente(Cliente *clientes, int *numClientes) {
    int opcao;
    do {
        printf("\n=== MENU CLIENTES ===\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Consultar Cliente\n");
        printf("3. Editar Cliente\n");
        printf("4. Excluir Cliente\n");
        printf("5. Listar Clientes\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente(clientes, numClientes);
                break;
            case 2:
                consultarCliente(clientes, *numClientes);
                break;
            case 3:
                editarCliente(clientes, *numClientes);
                break;
            case 4:
                excluirCliente(clientes, numClientes);
                break;
            case 5:
                listarClientes(clientes, *numClientes);
                break;
            case 0:
                printf("Voltando ao menu inicial...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

void menuVenda(Produto *produtos, int *numProdutos, Cliente *clientes, int *numClientes, Venda *vendas, int *numVendas) {
    int opcao;
    do {
        printf("\n=== MENU VENDAS ===\n");
        printf("1. Realizar Venda\n");
        printf("2. Consultar Caixa\n");
        printf("3. Listar Vendas\n");
        printf("4. Quantidade de Produtos Vendidos\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizarVenda(produtos, numProdutos, clientes, *numClientes, vendas, numVendas);
                break;
            case 2:
                consultarCaixa(vendas, *numVendas);
                break;
            case 3:
                listarVendas(vendas, *numVendas);
                break;
            case 4:
                quantidadeProdutosVendidos(vendas, *numVendas);
                break;
            case 0:
                printf("Voltando ao menu inicial...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

void cadastrarProduto(Produto *produtos, int *numProdutos) {
    if (*numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("Nome do Produto: ");
    fflush(stdin);
    fgets(produtos[*numProdutos].nome, sizeof(produtos[*numProdutos].nome), stdin);
    produtos[*numProdutos].nome[strcspn(produtos[*numProdutos].nome, "\n")] = '\0';  
    fflush(stdin);
    printf("Categoria: ");
    fgets(produtos[*numProdutos].categoria, sizeof(produtos[*numProdutos].categoria), stdin);
    produtos[*numProdutos].categoria[strcspn(produtos[*numProdutos].categoria, "\n")] = '\0';  

    printf("Quantidade: ");
    scanf("%d", &produtos[*numProdutos].quantidade);
    getchar();  

    printf("Valor: ");
    scanf("%f", &produtos[*numProdutos].valor);
    getchar();  

    (*numProdutos)++;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos(Produto *produtos, int numProdutos) {
    printf("\n=== LISTA DE PRODUTOS ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Categoria: %s\n", produtos[i].categoria);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Valor: R$ %.2f\n", produtos[i].valor);
        printf("--------------------\n");
    }
}

void consultarProduto(Produto *produtos, int numProdutos) {
    char nome[50];
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            printf("\nProduto encontrado:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Categoria: %s\n", produtos[i].categoria);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Valor: R$ %.2f\n", produtos[i].valor);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void editarProduto(Produto *produtos, int numProdutos) {
    char nome[50];
    printf("Digite o nome do produto que deseja editar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            printf("\nEditando o produto:\n");
            printf("Novo nome (atual: %s): ", produtos[i].nome);
            scanf(" %[^\n]", produtos[i].nome);

            printf("Nova categoria (atual: %s): ", produtos[i].categoria);
            scanf(" %[^\n]", produtos[i].categoria);

            printf("Nova quantidade (atual: %d): ", produtos[i].quantidade);
            scanf("%d", &produtos[i].quantidade);

            printf("Novo valor (atual: R$ %.2f): ", produtos[i].valor);
            scanf("%f", &produtos[i].valor);

            printf("Produto atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void excluirProduto(Produto *produtos, int *numProdutos) {
    char nome[50];
    printf("Digite o nome do produto que deseja excluir: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < *numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            for (int j = i; j < *numProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*numProdutos)--;
            printf("Produto excluído com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void cadastrarCliente(Cliente *clientes, int *numClientes) {
    if (*numClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", clientes[*numClientes].nome);
    printf("RG: ");
    scanf(" %[^\n]", clientes[*numClientes].rg);
    printf("CPF: ");
    scanf(" %[^\n]", clientes[*numClientes].cpf);
    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf(" %[^\n]", clientes[*numClientes].dataNascimento);

    (*numClientes)++;
    printf("Cliente cadastrado com sucesso!\n");
}

void consultarCliente(Cliente *clientes, int numClientes) {
    char cpf[15];
    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            printf("Nome: %s\n", clientes[i].nome);
            printf("RG: %s\n", clientes[i].rg);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Data de Nascimento: %s\n", clientes[i].dataNascimento);
            return;
        }
    }
    printf("Cliente não encontrado!\n");
}

void editarCliente(Cliente *clientes, int numClientes) {
    char cpf[15];
    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            printf("Novo Nome: ");
            scanf(" %[^\n]", clientes[i].nome);
            printf("Novo RG: ");
            scanf(" %[^\n]", clientes[i].rg);
            printf("Nova Data de Nascimento (dd/mm/aaaa): ");
            scanf(" %[^\n]", clientes[i].dataNascimento);
            printf("Cliente editado com sucesso!\n");
            return;
        }
    }
    printf("Cliente não encontrado!\n");
}

void excluirCliente(Cliente *clientes, int *numClientes) {
    char cpf[15];
    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < *numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            for (int j = i; j < *numClientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            (*numClientes)--;
            printf("Cliente excluído com sucesso!\n");
            return;
        }
    }
    printf("Cliente não encontrado!\n");
}

void listarClientes(Cliente *clientes, int numClientes) {
    for (int i = 0; i < numClientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("RG: %s\n", clientes[i].rg);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Data de Nascimento: %s\n", clientes[i].dataNascimento);
        printf("-------------------------\n");
    }
}


void realizarVenda(Produto *produtos, int *numProdutos, Cliente *clientes, int numClientes, Venda *vendas, int *numVendas) {
    char cpf[15], nomeProduto[50];
    int quantidadeVendida;

    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);

    int clienteEncontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente não encontrado! Cadastre o cliente primeiro.\n");
        return;
    }

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nomeProduto);
    printf("Digite a quantidade: ");
    scanf("%d", &quantidadeVendida);

    for (int i = 0; i < *numProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            if (produtos[i].quantidade >= quantidadeVendida) {
                produtos[i].quantidade -= quantidadeVendida;
                vendas[*numVendas].quantidadeVendida = quantidadeVendida;
                vendas[*numVendas].valorVenda = produtos[i].valor * quantidadeVendida;
                strcpy(vendas[*numVendas].cpfCliente, cpf);
                strcpy(vendas[*numVendas].nomeProduto, nomeProduto);
                (*numVendas)++;
                printf("Venda realizada com sucesso!\n");
                return;
            } else {
                printf("Quantidade insuficiente em estoque!\n");
                return;
            }
        }
    }
    printf("Produto não encontrado!\n");
}

void consultarCaixa(Venda *vendas, int numVendas) {
    float totalCaixa = 0;
    for (int i = 0; i < numVendas; i++) {
        totalCaixa += vendas[i].valorVenda;
    }
    printf("Valor total em caixa: R$ %.2f\n", totalCaixa);
}

void listarVendas(Venda *vendas, int numVendas) {
    for (int i = 0; i < numVendas; i++) {
        printf("CPF do Cliente: %s\n", vendas[i].cpfCliente);
        printf("Nome do Produto: %s\n", vendas[i].nomeProduto);
        printf("Quantidade Vendida: %d\n", vendas[i].quantidadeVendida);
        printf("Valor da Venda: R$ %.2f\n", vendas[i].valorVenda);
        printf("-------------------------\n");
    }
}

void quantidadeProdutosVendidos(Venda *vendas, int numVendas) {
    int totalProdutosVendidos = 0;
    for (int i = 0; i < numVendas; i++) {
        totalProdutosVendidos += vendas[i].quantidadeVendida;
    }
    printf("Quantidade total de produtos vendidos: %d\n", totalProdutosVendidos);
}

void salvarProdutos(Produto *produtos, int numProdutos) {
    FILE *file = fopen("produtos.txt", "w");
    if (!file) {
        printf("Erro ao abrir arquivo de produtos para salvar.\n");
        return;
    }

    for (int i = 0; i < numProdutos; i++) {
        fprintf(file, "%s\n%s\n%d\n%f\n", produtos[i].nome, produtos[i].categoria, produtos[i].quantidade, produtos[i].valor);
    }

    fclose(file);
    printf("Produtos salvos com sucesso!\n");
}

void salvarClientes(Cliente *clientes, int numClientes) {
    FILE *file = fopen("clientes.txt", "w");
    if (!file) {
        printf("Erro ao abrir arquivo de clientes para salvar.\n");
        return;
    }

    for (int i = 0; i < numClientes; i++) {
        fprintf(file, "%s\n%s\n%s\n%s\n", clientes[i].nome, clientes[i].rg, clientes[i].cpf, clientes[i].dataNascimento);
    }

    fclose(file);
    printf("Clientes salvos com sucesso!\n");
}

void salvarVendas(Venda *vendas, int numVendas) {
    FILE *file = fopen("vendas.txt", "w");
    if (!file) {
        printf("Erro ao abrir arquivo de vendas para salvar.\n");
        return;
    }

    for (int i = 0; i < numVendas; i++) {
        fprintf(file, "%s\n%s\n%d\n%f\n", vendas[i].cpfCliente, vendas[i].nomeProduto, vendas[i].quantidadeVendida, vendas[i].valorVenda);
    }

    fclose(file);
    printf("Vendas salvas com sucesso!\n");
}


void carregarProdutos(Produto *produtos, int *numProdutos) {
    FILE *file = fopen("produtos.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo de produtos para carregar.\n");
        return;
    }

    while (fscanf(file, "%s\n%s\n%d\n%f\n", produtos[*numProdutos].nome, produtos[*numProdutos].categoria, &produtos[*numProdutos].quantidade, &produtos[*numProdutos].valor) != EOF) {
        (*numProdutos)++;
    }

    fclose(file);
    printf("Produtos carregados com sucesso!\n");
}

void carregarClientes(Cliente *clientes, int *numClientes) {
    FILE *file = fopen("clientes.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo de clientes para carregar.\n");
        return;
    }

    while (fscanf(file, "%s\n%s\n%s\n%s\n", clientes[*numClientes].nome, clientes[*numClientes].rg, clientes[*numClientes].cpf, clientes[*numClientes].dataNascimento) != EOF) {
        (*numClientes)++;
    }

    fclose(file);
    printf("Clientes carregados com sucesso!\n");
}

void carregarVendas(Venda *vendas, int *numVendas) {
    FILE *file = fopen("vendas.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo de vendas para carregar.\n");
        return;
    }

    while (fscanf(file, "%s\n%s\n%d\n%f\n", vendas[*numVendas].cpfCliente, vendas[*numVendas].nomeProduto, &vendas[*numVendas].quantidadeVendida, &vendas[*numVendas].valorVenda) != EOF) {
        (*numVendas)++;
    }

    fclose(file);
    printf("Vendas carregadas com sucesso!\n");
}