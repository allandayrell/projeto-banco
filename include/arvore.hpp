#ifndef ARVORE_HPP
#define ARVORE_HPP

#include "cliente.hpp"
class NoCliente {
public:
    NoCliente();
private:
    Cliente cliente;
    NoCliente* esq;
    NoCliente* dir;
    friend class ArvoreClientes;
};

NoCliente::NoCliente() {
    esq = nullptr;
    dir = nullptr;
}

class ArvoreClientes {
public:
    ArvoreClientes();
    ~ArvoreClientes();
    void Insere(Cliente cliente);
    // Outros métodos necessários para manipular a árvore de clientes
private:
    void InsereRecursivo(NoCliente* &p, Cliente cliente);
    void ApagaRecursivo(NoCliente* p);
    // Outros métodos privados necessários para manipular a árvore de clientes
    NoCliente* raiz;
};

#endif