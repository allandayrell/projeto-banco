#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Cliente{
  public:

    int VerificarSaldo();
    void Sacar(int quantia);
    void Depositar(int quantia);
    void Transferencia(int quantia, int numContaPagador, int numContBeneficiario);

    void ImprimeNome();
    void ImprimeSaldo();

    string nome;
    int numConta;
    int saldo;
};

void InsertionSort(vector<Cliente>& listaClientes);

#endif