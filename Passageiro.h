#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
#include "Pessoa.h"

using namespace std;

class Passageiro : public Pessoa {
private: 
    string cpf;
    string numeroDoBilhete;

public:
    Passageiro(const string& nome, const string& cpf, const string& nBilhete);
    
    string getCpf() const;
    string getnumeroDoBilhete() const;
    
    void setCpf(const string& novoCpf);
    void setnumeroDoBilhete(const string& novoBilhete);
    
    void exibirDados() const override;
    string serializar() const override;
};

#endif // PASSAGEIRO_H
