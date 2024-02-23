#include "arvore.hpp"

ArvoreClientes::ArvoreClientes(){
    raiz = NULL;
}

ArvoreClientes::~ArvoreClientes(){
    Limpa();
}

NoCliente* ArvoreClientes::getRaiz(){
    return raiz;
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


string ArvoreClientes::Procura(int numConta){
    Cliente x;
    x = PercorreIterativo(numConta);
    return x.nome;

}

Cliente ArvoreClientes::PercorreIterativo(int numConta) {
    NoCliente* raiz = this->getRaiz();
    
    stack<NoCliente*> pilha;
    pilha.push(raiz);

    while (!pilha.empty()) {
        NoCliente* atual = pilha.top();
        pilha.pop();

        if (atual != nullptr) {
            if (atual->cliente.numConta == numConta) {
                return atual->cliente;
            }

            // Empilha o nó da direita antes do nó da esquerda para manter a ordem correta
            pilha.push(atual->dir);
            pilha.push(atual->esq);
        }
    }

    // Retorna um cliente especial marcado como não encontrado
    return Cliente{"", -1, -1};
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

void ArvoreClientes::Transferencia(int quantia, int numContaPagador, int numContBeneficiario){
    Cliente pagador, beneficiario;
    pagador = PercorreIterativo(numContaPagador);
    beneficiario = PercorreIterativo(numContBeneficiario);

    if(beneficiario.numConta == -1){
        cout << "Cliente não encontrado." << endl;
        return; 
    }

    else if(pagador.saldo < quantia){
        cout << "Saldo insuficiente." << endl;
    }

    else{
        pagador.Sacar(quantia);
        beneficiario.Depositar(quantia);
    }
}

void ArvoreClientes::PreOrdemNumConta(NoCliente *p){
    if(p!=NULL){
        p->cliente.ImprimeNome();
        PreOrdemNumConta(p->esq);
        PreOrdemNumConta(p->dir);
    }
}

void ArvoreClientes::InOrdemNumConta(NoCliente *p){
    if(p!=NULL){
        InOrdemNumConta(p->esq);
        p->cliente.ImprimeNome();
        InOrdemNumConta(p->dir);
    }
}

void ArvoreClientes::PosOrdemNumConta(NoCliente *p){
    if(p!=NULL){
        PosOrdemNumConta(p->esq);
        PosOrdemNumConta(p->dir);
        p->cliente.ImprimeNome();
    }
}

void ArvoreClientes::CaminhaNivel(){

}

NoCliente::NoCliente() {
  esq = nullptr;
  dir = nullptr;
}