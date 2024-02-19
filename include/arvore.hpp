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
    void Limpa();
    void PreOrdem(NoCliente *p); // imprime o item depois visita as arvores da esq depis dir 
    void InOrdem(NoCliente *p); // visita a arvore da esq, imprime o item e depois visita a sub arvore dir
    void PosOrdem(NoCliente *p); // visita a arvore da esq e dir e depois imprime o item
    void CaminhaNivel(); // visita os nós por nível usando uma fila aux

    void InsereRecursivo(NoCliente* &p, Cliente cliente);
    void ApagaRecursivo(NoCliente* p);
    
    NoCliente* raiz;
};

#endif