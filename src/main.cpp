#include "cliente.hpp"
#include "arvore.hpp"
#include <fstream>
#include <sstream>

using namespace std;

string tratamentoNome(string nome){
    char c;
    int t = nome.size();
    for(int i = 0; i < t; i++){
        if(c == '_'){
            nome[i] = ' ';
        }
    }
    return nome;
}

int main (){
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

    char opcao;
    cout << "Digite uma opção: "<< endl << "'g' para gerente" << endl << "'c' para cliente" << endl;
    cin >> opcao;

    int conta;
    string nome;
    switch (opcao)
    {
    case 'c':
        // numero conta
        cout << "Digite o numero da conta: ";
        cin >> conta;
        // achar o numero e dizer bem vindo fulano
        nome = arvore.Procura(conta);
        cout << "Bem vindo " << tratamentoNome(nome) << endl;
        // dar opcao de ver saldo e fazer transferencia
        break;

    case 'g':
        // chave de acesso
        // dar opcao de adicionar ou retirar cliente
        // dar opcao de ver saldo de um cliente x
        break;

    default:
        break;
    }

    //arvore.InOrdemNumConta(arvore.getRaiz());

    return 0;
}