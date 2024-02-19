#include "arvore.hpp"

ArvoreClientes::ArvoreClientes(){
    raiz = NULL;
}

ArvoreClientes::~ArvoreClientes(){
    Limpa();
}

void ArvoreClientes::Insere(Cliente cliente){
    InsereRecursivo(raiz, cliente);
}

void ArvoreClientes::InsereRecursivo(NoCliente* &p, Cliente cliente){
    if(p==NULL){
        p = new NoCliente();
        p->cliente = cliente;
    }
    else{
        if(cliente.numConta < p->cliente.numConta)
        InsereRecursivo(p->esq, cliente);
    else
        InsereRecursivo(p->dir, cliente);
    }
}

void ArvoreClientes::Limpa(){
    ApagaRecursivo(raiz);
    raiz = NULL;
}

void ArvoreClientes::ApagaRecursivo(NoCliente *p){
    if(p!=NULL){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

void ArvoreClientes::PreOrdem(NoCliente *p){
    if(p!=NULL){
        p->cliente.ImprimeNome();
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void ArvoreClientes::InOrdem(NoCliente *p){
    if(p!=NULL){
        PreOrdem(p->esq);
        p->cliente.ImprimeNome();
        PreOrdem(p->dir);
    }
}

void ArvoreClientes::PosOrdem(NoCliente *p){
    if(p!=NULL){
        PreOrdem(p->esq);
        PreOrdem(p->dir);
        p->cliente.ImprimeNome();
    }
}

void ArvoreClientes::CaminhaNivel(){

}

NoCliente::NoCliente() {
  esq = nullptr;
  dir = nullptr;
}