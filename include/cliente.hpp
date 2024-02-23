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

    void ImprimeNome();
    void ImprimeSaldo();

    string nome;
    int numConta;
    int saldo;
};


#endif