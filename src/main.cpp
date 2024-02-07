#include "cliente.hpp"

using namespace std;



int main (){
    vector<Cliente> Clientes;
    int n;

    cout << "digite n" << endl;
    cin >> n;
    Clientes.resize(n);

    cout << "digite " << n << " nomes" << endl;

    for (int i = 0; i < n; i++) {
        cin >> Clientes[i].nome;
    }

    for(int i = 0; i < n; i++){
        cout << Clientes[i].nome << endl;
    }

}