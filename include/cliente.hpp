#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente{
  public:

    int VerificarSaldo();
    void Sacar(int quantia);
    void Depositar(int quantia);
    void Transferencia(int quantia, int numConta);

    string nome;
    int numConta;
    int saldo;
};