#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente{
  public:

    int VerificarSaldo();
    void Sacar(int quantia);
    void Depositar(int quantia);
    void Transferencia(int quantia, int numContaPagador, int numContBeneficiario);

    string nome;
    int numConta;
    int saldo;
};

void InsertionSort(vector<Cliente>& listaClientes);

#endif