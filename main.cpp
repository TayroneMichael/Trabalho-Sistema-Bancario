// INF101 - Trabalho Etapa 1
// Sistema de Registro e Gestão de Contas Bancárias - BANCO INF101
// Nome: Tayrone Michael Martins Abreu
// Matrícula: 26690

#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX = 5;  // Define o limite máximo de contas cadastradas.

    // Cada vetor armazena uma informação das contas.
    // A mesma posição representa a mesma conta.
    int numeroConta[MAX];
    string nomeCliente[MAX];
    string cpf[MAX];
    int tipoConta[MAX];
    double saldo[MAX];
    bool contaAtiva[MAX];

    int totalContas = 0;  // Guarda a quantidade de contas cadastradas.
    int opcao;            // Armazena a opção escolhida no menu.
    int numeroBusca;      // Guarda o número da conta que será pesquisada.
    int pos;              // Guarda a posição da conta encontrada.

    do {
        // Exibe o menu principal do sistema.
        cout << "\n********************************" << endl;
        cout << "**        BANCO DO EMPRESÁRIO          **" << endl;
        cout << "********************************" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Verifica se o usuário digitou uma opção válida.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcao = 0;
        }

        // Procura a conta informada nas opções que precisam de uma conta.
        pos = -1;
        if (opcao >= 2 && opcao <= 5) {
            if (totalContas == 0) {
                cout << "\nNenhuma conta cadastrada ainda." << endl;
                opcao = -1;
            } else {
                cout << "\nDigite o numero da conta: ";
                cin >> numeroBusca;

                // Percorre as contas cadastradas procurando o número informado.
                for (int i = 0; i < totalContas; i++) {
                    if (numeroConta[i] == numeroBusca) {
                        pos = i;
                    }
                }

                // Se a posição continuar -1, a conta não foi encontrada.
                if (pos == -1) {
                    cout << "Conta nao encontrada!" << endl;
                    opcao = -1;
                }
            }
        }

        switch (opcao) {

        case 1: { // Cadastro de uma nova conta.
            if (totalContas == MAX) {
                cout << "\nLimite de " << MAX << " contas atingido!" << endl;
                break;
            }

            int novoNumero;
            bool repetido;

            cout << "\n--- Cadastro da conta " << totalContas + 1 << " de " << MAX << " ---" << endl;

            // Solicita um número positivo e verifica se ele já está cadastrado.
            do {
                repetido = false;
                cout << "Numero da conta: ";
                cin >> novoNumero;

                if (novoNumero <= 0) {
                    cout << "Erro: o numero deve ser maior que zero!" << endl;
                }

                // Verifica se o número informado já pertence a outra conta.
                for (int i = 0; i < totalContas; i++) {
                    if (numeroConta[i] == novoNumero) {
                        repetido = true;
                    }
                }

                if (repetido) {
                    cout << "Erro: esse numero de conta ja existe!" << endl;
                }

            } while (novoNumero <= 0 || repetido);

            numeroConta[totalContas] = novoNumero;

            // Limpa o caractere restante antes de usar getline.
            cin.ignore();

            cout << "Nome do titular: ";
            getline(cin, nomeCliente[totalContas]);

            cout << "CPF do titular: ";
            getline(cin, cpf[totalContas]);

            // Solicita um tipo de conta válido.
            do {
                cout << "Tipo da conta (1 = Corrente, 2 = Poupanca): ";
                cin >> tipoConta[totalContas];

                if (tipoConta[totalContas] != 1 && tipoConta[totalContas] != 2) {
                    cout << "Erro: digite 1 ou 2!" << endl;
                }

            } while (tipoConta[totalContas] != 1 && tipoConta[totalContas] != 2);

            // Solicita um saldo inicial que não seja negativo.
            do {
                cout << "Saldo inicial: R$ ";
                cin >> saldo[totalContas];

                if (saldo[totalContas] < 0) {
                    cout << "Erro: o saldo nao pode ser negativo!" << endl;
                }

            } while (saldo[totalContas] < 0);

            // Toda conta nova começa ativa.
            contaAtiva[totalContas] = true;

            totalContas++;  // Aumenta a quantidade de contas cadastradas.

            cout << "Conta cadastrada com sucesso!" << endl;
            break;
        }

        case 2: // Consulta os dados da conta encontrada.
            cout << "\n--- Dados da conta ---" << endl;
            cout << "Numero: " << numeroConta[pos] << endl;
            cout << "Titular: " << nomeCliente[pos] << endl;
            cout << "CPF: " << cpf[pos] << endl;

            // Mostra o tipo de conta de acordo com o valor armazenado.
            if (tipoConta[pos] == 1) {
                cout << "Tipo: Corrente" << endl;
            } else {
                cout << "Tipo: Poupanca" << endl;
            }

            cout << "Saldo: R$ " << saldo[pos] << endl;

            // Mostra se a conta está ativa ou desativada.
            if (contaAtiva[pos]) {
                cout << "Situacao: Ativa" << endl;
            } else {
                cout << "Situacao: Desativada" << endl;
            }
            break;

        case 3: // Verifica o saldo da conta.
            // O saldo só pode ser consultado se a conta estiver ativa.
            if (!contaAtiva[pos]) {
                cout << "\nA conta esta desativada. Ative-a para ver o saldo." << endl;
            } else {
                cout << "\nSaldo atual: R$ " << saldo[pos] << endl;
            }
            break;

        case 4: // Altera o tipo da conta.
            // Não permite alterar o tipo de uma conta desativada.
            if (!contaAtiva[pos]) {
                cout << "\nA conta esta desativada. Ative-a para alterar o tipo." << endl;
            } else {
                // Solicita um novo tipo válido para a conta.
                do {
                    cout << "Novo tipo (1 = Corrente, 2 = Poupanca): ";
                    cin >> tipoConta[pos];

                    if (tipoConta[pos] != 1 && tipoConta[pos] != 2) {
                        cout << "Erro: digite 1 ou 2!" << endl;
                    }

                } while (tipoConta[pos] != 1 && tipoConta[pos] != 2);

                cout << "Tipo alterado com sucesso!" << endl;
            }
            break;

        case 5: // Alterna entre conta ativa e desativada.
            contaAtiva[pos] = !contaAtiva[pos];

            if (contaAtiva[pos]) {
                cout << "\nConta ativada!" << endl;
            } else {
                cout << "\nConta desativada!" << endl;
            }
            break;

        case 6:
            cout << "\nEncerrando o sistema. Ate logo!" << endl;
            break;

        default:
            // Mostra uma mensagem quando a opção digitada não é válida.
            if (opcao != -1) {
                cout << "\nOpcao invalida! Tente novamente." << endl;
            }
            break;
        }

    } while (opcao != 6);  // Mantém o menu funcionando até o usuário escolher sair.

    return 0;
}

