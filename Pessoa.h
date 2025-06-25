#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
protected: // Usamos 'protected'
    std::string nome;

public:
    // Construtor
    Pessoa(const std::string& nome);

    // Destrutor virtual: ESSENCIAL para herança!
    // Garante que o destrutor correto (de Piloto ou Passageiro) seja chamado.
    virtual ~Pessoa() = default;

    // Métodos Get
    std::string getNome() const;

    // Método virtual puro: torna a classe abstrata.
    // Obriga as classes filhas a implementarem sua própria versão deste método.
    virtual void exibirDetalhes() const = 0;
};

#endif // PESSOA_H