#include "cliente.hpp"
#include "arvore.hpp"

using namespace std;

int main (){
    vector<Cliente> Clientes;
    ArvoreClientes arvore;
    Cliente cliente;
    string entrada;
    int n;

    cout << "digite n" << endl;
    cin >> n;
    Clientes.resize(n);

    while(getline(cin, entrada)){
        if(entrada.empty()){
            break;
        }

        cin >> cliente.nome >> cliente.numConta >> cliente.saldo;
        arvore.Insere(cliente);
    }

    cout << "digite " << n << " nomes" << endl;

    for (int i = 0; i < n; i++) {
        cin >> Clientes[i].nome;
    }

    for(int i = 0; i < n; i++){
        cout << Clientes[i].nome << endl;
    }

}