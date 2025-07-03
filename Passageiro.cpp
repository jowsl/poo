#include "Passageiro.h"
#include <iostream>

Passageiro::Passageiro(const string& nome, const string& cpf, const string& nBilhete)
    : Pessoa(nome), cpf(cpf), numeroDoBilhete(nBilhete) {}

    string Passageiro::getCpf() const {
        return this->cpf;
    }
    
    string Passageiro::getnumeroDoBilhete() const {
        return this->numeroDoBilhete;
    }
    
    void Passageiro::setnumeroDoBilhete(const string& novoBilhete) {
        this->numeroDoBilhete = novoBilhete;
    }
    
    void Passageiro::setCpf(const string& novoCpf) {
        this->cpf = novoCpf;
    }

void Passageiro::exibirDados() const {
    Pessoa::exibirDados(); // Chama a versão da classe base para exibir o nome
    cout << "  CPF: " << this->cpf << endl;
    cout << "Número do Bilhete: " << this->numeroDoBilhete << endl;
}

string Passageiro::serializar() const {
    string resultado;
    resultado = "PASSAGEIRO, " + this->nome + ", " + this->cpf + ", " + this->numeroDoBilhete;
    return resultado;
}
