#include "cliente.hpp"

int Cliente::VerificarSaldo(){
    return saldo;
}

void Cliente::Sacar(int quantia){
    saldo = saldo - quantia;
}

void Cliente::Depositar(int quantia){
    saldo = saldo + quantia;
}

void Cliente::ImprimeNome(){
    cout << this->nome << endl;
}

void Cliente::ImprimeSaldo(){
    cout << this->saldo << endl;
}

void InsertionSort(vector<Cliente>& listaClientes){
    int tamanho = listaClientes.size();
    int j;

    for(int i = 1; i < tamanho; i++){
        int chave = listaClientes[i].numConta;
        j = i - 1;

        while(j >=0 && listaClientes[j].numConta > chave){
            listaClientes[j + 1].numConta = listaClientes[j].numConta;
            j = j - 1;
        }

        listaClientes[j + 1].numConta = chave;
    }
}
