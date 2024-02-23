#ifndef ARVORE_HPP
#define ARVORE_HPP

#include "cliente.hpp"

class NoCliente {
  public:
    NoCliente();
  private:
    Cliente cliente; //tipoitem
    NoCliente* esq; //tipono
    NoCliente* dir;
    friend class ArvoreClientes;
};

class ArvoreClientes {
  public:
    ArvoreClientes();
    ~ArvoreClientes();

    void Insere(Cliente cliente);
    string Procura(int numConta);
    void Limpa();
    void Transferencia(int quantia, int numContaPagador, int numContBeneficiario);

    void PreOrdemNumConta(NoCliente *p); // imprime o item depois visita as arvores da esq depis dir 
    void InOrdemNumConta(NoCliente *p); // visita a arvore da esq, imprime o item e depois visita a sub arvore dir
    void PosOrdemNumConta(NoCliente *p); // visita a arvore da esq e dir e depois imprime o item

    Cliente PercorreIterativo(int numConta);
    void CaminhaNivel(); // visita os nós por nível usando uma fila aux

    void InsereRecursivo(NoCliente* &p, Cliente cliente);
    void ApagaRecursivo(NoCliente* p);
    
    NoCliente* raiz;
    NoCliente* getRaiz();
};

#endif