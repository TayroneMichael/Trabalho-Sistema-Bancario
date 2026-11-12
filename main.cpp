// INF101 - Trabalho Etapa 2
// Sistema de Registro e Gestao de Contas Bancarias - BANCO INF101
// Nome: Tayrone Michael Martins Abreu
// Matricula: 26690

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
    const int MAX_CONTAS = 100;
    const int MAX_MOVIMENTACOES = 500;

    // Vetores de contas: a mesma posicao representa a mesma conta.
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS]; // 1 = Corrente | 2 = Poupanca
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];
    int quantidadeContas = 0;

    // Vetores do historico: a mesma posicao representa uma movimentacao.
    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES]; // D = deposito | S = saque
    double valorMovimentacao[MAX_MOVIMENTACOES];
    int quantidadeMovimentacoes = 0;

    int opcao;

    cout << fixed << setprecision(2);

    do {
        cout << "\n========================================" << endl;
        cout << "          BANCO DO EMPRESARIO" << endl;
        cout << "========================================" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Listar contas cadastradas" << endl;
        cout << "3 - Consultar conta" << endl;
        cout << "4 - Realizar deposito" << endl;
        cout << "5 - Realizar saque" << endl;
        cout << "6 - Realizar transferencia" << endl;
        cout << "7 - Exibir extrato" << endl;
        cout << "8 - Sair" << endl;
        cout << "Escolha uma opcao: ";

        cin >> opcao;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = 0;
        }

        switch (opcao) {
        case 1: {
            if (quantidadeContas == MAX_CONTAS) {
                cout << "\nLimite de " << MAX_CONTAS << " contas atingido!" << endl;
                break;
            }

            int novoNumero;
            bool repetido;

            cout << "\n--- Cadastro de conta ---" << endl;

            do {
                repetido = false;
                cout << "Numero da conta: ";
                cin >> novoNumero;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    novoNumero = 0;
                }

                if (novoNumero <= 0) {
                    cout << "Erro: o numero deve ser maior que zero!" << endl;
                }

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == novoNumero) {
                        repetido = true;
                    }
                }

                if (repetido) {
                    cout << "Erro: esse numero de conta ja existe!" << endl;
                }
            } while (novoNumero <= 0 || repetido);

            numeroConta[quantidadeContas] = novoNumero;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nome do titular: ";
            getline(cin, nomeCliente[quantidadeContas]);

            cout << "CPF do titular: ";
            getline(cin, cpf[quantidadeContas]);

            do {
                cout << "Tipo da conta (1 = Corrente, 2 = Poupanca): ";
                cin >> tipoConta[quantidadeContas];

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    tipoConta[quantidadeContas] = 0;
                }

                if (tipoConta[quantidadeContas] != 1 &&
                    tipoConta[quantidadeContas] != 2) {
                    cout << "Erro: digite 1 ou 2!" << endl;
                }
            } while (tipoConta[quantidadeContas] != 1 &&
                     tipoConta[quantidadeContas] != 2);

            do {
                cout << "Saldo inicial: R$ ";
                cin >> saldo[quantidadeContas];

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    saldo[quantidadeContas] = -1;
                }

                if (saldo[quantidadeContas] < 0) {
                    cout << "Erro: o saldo nao pode ser negativo!" << endl;
                }
            } while (saldo[quantidadeContas] < 0);

            contaAtiva[quantidadeContas] = true;
            quantidadeContas++;
            cout << "Conta cadastrada com sucesso!" << endl;
            break;
        }

        case 2: {
            if (quantidadeContas == 0) {
                cout << "\nNenhuma conta cadastrada." << endl;
                break;
            }

            cout << "\n--- Contas cadastradas ---" << endl;
            for (int i = 0; i < quantidadeContas; i++) {
                cout << "Numero: " << numeroConta[i]
                     << " | Titular: " << nomeCliente[i]
                     << " | Tipo: " << (tipoConta[i] == 1 ? "Corrente" : "Poupanca")
                     << " | Saldo: R$ " << saldo[i]
                     << " | Situacao: " << (contaAtiva[i] ? "Ativa" : "Desativada")
                     << endl;
            }
            break;
        }

        case 3: {
            int numeroBusca;
            int indice = -1;

            cout << "\nNumero da conta para consulta: ";
            cin >> numeroBusca;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Numero de conta invalido!" << endl;
                break;
            }

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numeroBusca) {
                    indice = i;
                    break;
                }
            }

            if (indice == -1) {
                cout << "Conta nao encontrada!" << endl;
                break;
            }

            cout << "\n--- Dados da conta ---" << endl;
            cout << "Numero: " << numeroConta[indice] << endl;
            cout << "Titular: " << nomeCliente[indice] << endl;
            cout << "CPF: " << cpf[indice] << endl;
            cout << "Tipo: " << (tipoConta[indice] == 1 ? "Corrente" : "Poupanca") << endl;
            cout << "Saldo: R$ " << saldo[indice] << endl;
            cout << "Situacao: " << (contaAtiva[indice] ? "Ativa" : "Desativada") << endl;
            break;
        }

        case 4: {
            int numeroBusca;
            int indice = -1;
            double valor;

            if (quantidadeMovimentacoes == MAX_MOVIMENTACOES) {
                cout << "\nLimite de movimentacoes atingido!" << endl;
                break;
            }

            cout << "\nNumero da conta para deposito: ";
            cin >> numeroBusca;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Numero de conta invalido!" << endl;
                break;
            }

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numeroBusca) {
                    indice = i;
                    break;
                }
            }

            if (indice == -1) {
                cout << "Conta nao encontrada!" << endl;
            } else if (!contaAtiva[indice]) {
                cout << "A conta esta desativada!" << endl;
            } else {
                cout << "Valor do deposito: R$ ";
                cin >> valor;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido!" << endl;
                } else if (valor <= 0) {
                    cout << "Erro: o valor deve ser maior que zero!" << endl;
                } else {
                    saldo[indice] += valor;
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;
                    quantidadeMovimentacoes++;
                    cout << "Deposito realizado com sucesso!" << endl;
                }
            }
            break;
        }

        case 5: {
            int numeroBusca;
            int indice = -1;
            double valor;

            if (quantidadeMovimentacoes == MAX_MOVIMENTACOES) {
                cout << "\nLimite de movimentacoes atingido!" << endl;
                break;
            }

            cout << "\nNumero da conta para saque: ";
            cin >> numeroBusca;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Numero de conta invalido!" << endl;
                break;
            }

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numeroBusca) {
                    indice = i;
                    break;
                }
            }

            if (indice == -1) {
                cout << "Conta nao encontrada!" << endl;
            } else if (!contaAtiva[indice]) {
                cout << "A conta esta desativada!" << endl;
            } else {
                cout << "Valor do saque: R$ ";
                cin >> valor;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido!" << endl;
                } else if (valor <= 0) {
                    cout << "Erro: o valor deve ser maior que zero!" << endl;
                } else if (valor > saldo[indice]) {
                    cout << "Saldo insuficiente!" << endl;
                } else {
                    saldo[indice] -= valor;
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;
                    quantidadeMovimentacoes++;
                    cout << "Saque realizado com sucesso!" << endl;
                }
            }
            break;
        }

        case 6: {
            int numeroOrigem;
            int numeroDestino;
            int indiceOrigem = -1;
            int indiceDestino = -1;
            double valor;

            // A transferencia ocupa dois espacos no historico: saida e entrada.
            if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
                cout << "\nNao ha espaco para registrar a transferencia!" << endl;
                break;
            }

            cout << "\nNumero da conta de origem: ";
            cin >> numeroOrigem;
            cout << "Numero da conta de destino: ";
            cin >> numeroDestino;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Numero de conta invalido!" << endl;
                break;
            }

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numeroOrigem) {
                    indiceOrigem = i;
                }
                if (numeroConta[i] == numeroDestino) {
                    indiceDestino = i;
                }
            }

            if (indiceOrigem == -1 || indiceDestino == -1) {
                cout << "Conta de origem ou destino nao encontrada!" << endl;
            } else if (indiceOrigem == indiceDestino) {
                cout << "A conta de origem deve ser diferente da conta de destino!" << endl;
            } else if (!contaAtiva[indiceOrigem] || !contaAtiva[indiceDestino]) {
                cout << "As duas contas devem estar ativas!" << endl;
            } else {
                cout << "Valor da transferencia: R$ ";
                cin >> valor;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valor invalido!" << endl;
                } else if (valor <= 0) {
                    cout << "Erro: o valor deve ser maior que zero!" << endl;
                } else if (valor > saldo[indiceOrigem]) {
                    cout << "Saldo insuficiente na conta de origem!" << endl;
                } else {
                    saldo[indiceOrigem] -= valor;
                    saldo[indiceDestino] += valor;

                    // Registra a saida na conta de origem.
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;
                    quantidadeMovimentacoes++;

                    // Registra a entrada na conta de destino.
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;
                    quantidadeMovimentacoes++;

                    cout << "Transferencia realizada com sucesso!" << endl;
                }
            }
            break;
        }

        case 7: {
            int numeroBusca;
            int indice = -1;
            bool possuiMovimentacao = false;

            cout << "\nNumero da conta para extrato: ";
            cin >> numeroBusca;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Numero de conta invalido!" << endl;
                break;
            }

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numeroBusca) {
                    indice = i;
                    break;
                }
            }

            if (indice == -1) {
                cout << "Conta nao encontrada!" << endl;
                break;
            }

            cout << "\n--- Extrato da conta " << numeroConta[indice] << " ---" << endl;
            cout << "Titular: " << nomeCliente[indice] << endl;

            for (int i = 0; i < quantidadeMovimentacoes; i++) {
                if (contaMovimentacao[i] == numeroConta[indice]) {
                    possuiMovimentacao = true;
                    if (tipoMovimentacao[i] == 'D') {
                        cout << "Deposito: R$ " << valorMovimentacao[i] << endl;
                    } else {
                        cout << "Saque: R$ " << valorMovimentacao[i] << endl;
                    }
                }
            }

            if (!possuiMovimentacao) {
                cout << "Nenhuma movimentacao registrada." << endl;
            }

            cout << "Saldo atual: R$ " << saldo[indice] << endl;
            break;
        }

        case 8:
            cout << "\nEncerrando o sistema. Ate logo!" << endl;
            break;

        default:
            cout << "\nOpcao invalida! Tente novamente." << endl;
            break;
        }
    } while (opcao != 8);

    return 0;
}