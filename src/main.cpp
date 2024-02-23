#include "cliente.hpp"
#include "arvore.hpp"
#include <fstream>
#include <sstream>

using namespace std;

string tratamentoNomeImpressao(string nome){
    char c;
    int t = nome.size();
    for(int i = 0; i < t; i++){
        c = nome[i];
        if(c == '_'){
            nome[i] = ' ';
        }
    }
    return nome;
}

int main (int argc, char* argv[]) {
    ArvoreClientes arvore;
    Cliente cliente;
    string entrada;
    int numClientes = 0;

    string listaParaArvore = "listaClientes.txt";

    ifstream arquivo(listaParaArvore);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << endl;
        return 1;
    }

    string linha;
    while (getline(arquivo, linha)) {
        // Cria um stringstream a partir da linha
        istringstream iss(linha);

        // Extrai os dados da linha
        if (iss >> cliente.nome >> cliente.numConta >> cliente.saldo) {
           arvore.Insere(cliente);
           numClientes += 1;
        } else {
            cerr << "Erro ao extrair dados da linha: " << linha << endl;
        }
    }
    arquivo.close();

    char opcao, opcao2;
    cout << "Digite uma opção: "<< endl << "'g' para gerente" << endl << "'c' para cliente" << endl;
    cin >> opcao;

    int conta, valorTransferencia, contaTransferencia;
    int chaveAcesso;
    string nome;
    switch (opcao)
    {
    case 'c':
        // numero conta
        // erro: numero não encontrado
        // erro: não inserir um número
        cout << "Digite o numero da conta: ";
        cin >> conta;
        // achar o numero e dizer bem vindo fulano
        cliente = arvore.PercorreIterativo(conta);
        cout << "Bem vindo " << tratamentoNomeImpressao(cliente.nome) << endl;
        // erro: opção inválida
        cout << "'s' para checar saldo;" << endl << "'t' para transferencia" << endl << "'f' para terminar operacao" << endl;
        cin >> opcao2;

        while(opcao2 != 'f'){
            switch (opcao2)
            {
            case 's':
                cout << cliente.VerificarSaldo() << endl;
                break;

            case 't':
                cout << "Digite o numero da conta beneficiaria: ";
                // erro: conta não encontrada
                // erro: não foi digitado um int
                cin >> contaTransferencia;
                cout << "Digite o valor da transferencia: ";
                 // erro: conta não encontrada
                // erro: não foi digitado um int
                cin >> valorTransferencia;

                arvore.Transferencia(valorTransferencia, conta, contaTransferencia);

                break;
            
            default:
                break;
            }
            // erro: opção inválida
            cout << "'s' para checar saldo;" << endl << "'t' para transferencia" << endl << "'f' para terminar operacao" << endl;
            cin >> opcao2;    

        }
        

    case 'g':
        cout << "Informar chave de acesso: ";
        // erro: chave de acesso inválida
        cin >> chaveAcesso;

        if(chaveAcesso == 123){
            // erro: opção não válida
            cout << "'i' para inserir um cliente novo." << endl << "'r' para retirar um cliente." << endl <<"'c' para informações de um cliente" << endl << "'f' para finalizar operação." << endl;

            cin >> opcao2;
            while(opcao2 != 'f'){
                
                switch (opcao2)
                {
                case 'i':
                // erro: numconta ja cadastrado
                // erro: saldo ou numConta negativo
                // erro: nome não é char ou saldo e numConta não é int
                    cout << "Informar dados do cliente. 'nome' 'numConta' 'saldo'" << endl;
                    cin >> cliente.nome >> cliente.numConta >> cliente.saldo;
                    arvore.Insere(cliente);
                    break;

                case 'r':
                // erro: não informar int
                // erro: numero negativo
                    cout << "Informar o número da conta do cliente. ";
                    cin >> cliente.numConta;
                    break;

                case 'c':
                // erro: formato errado
                // erro: saldo ou numConta negativo
                    cout << "Informar o número da conta do cliente. ";
                    cin >> conta;
                    cliente = arvore.PercorreIterativo(conta);
                    cout << "Número conta: " << cliente.numConta << endl << "Nome cliente: " << tratamentoNomeImpressao(cliente.nome) << endl << "Saldo: " << cliente.saldo << endl << endl;

                    break;
                
                default:
                    break;
                }

                // erro: opção não válida
                cout << "'i' para inserir um cliente novo." << endl << "'r' para retirar um cliente." << endl <<"'c' para informações de um cliente" << endl << "'f' para finalizar operação." << endl;
                cin >> opcao2;
            }
        }
        else{
            cout << "Chave de acesso inválida." << endl;
        }
        break;

    default:
        break;
    }

    //arvore.InOrdemNumConta(arvore.getRaiz());

    return 0;

    //arrumar arquvos para sacar e depositar
}