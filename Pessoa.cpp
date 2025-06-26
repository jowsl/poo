#include "Pessoa.h"

Pessoa::Pessoa(const string& nome) : nome(nome) {}

void Pessoa::setNome(const string& novoNome) {
    this->nome = novoNome;
}

string Pessoa::getNome() const {
    return this->nome;
}

void Pessoa::exibirDados() const {
    cout << "Nome: " << this->nome;
}
