#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
using namespace std;

class Pessoa {
protected:
    string nome;

public:
    Pessoa(const string& nome);

    void setNome(const string& novoNome);
    string getNome() const;
    
    virtual void exibirDados() const;
    virtual string serializar() const = 0;
};

#endif 
