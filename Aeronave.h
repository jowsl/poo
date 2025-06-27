// Arquivo: Aeronave.h

#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>

class Aeronave {
private:
    std::string codigo;
    std::string modelo;
    int capacidade;
    double velocidadeMedia; // em milhas por hora
    double autonomia;       // em milhas

public:
    // Declaração do construtor
    Aeronave(const std::string& c, const std::string& m, int cap, double vm, double aut);

    // Declarações dos métodos "get" e "set"
    std::string getCodigo() const;
    void setCodigo(int c);

    std::string getModelo() const;
    void setModelo(const std::string& m);

    int getCapacidade() const;
    void setCapacidade(int cap);

    double getVelocidadeMedia() const;
    void setVelocidadeMedia(double vm);

    double getAutonomia() const;
    void setAutonomia(double aut);

    void exibirDados() const;
};

#endif
