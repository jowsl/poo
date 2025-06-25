// Arquivo: Aeronave.h

#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>

class Aeronave {
private:
    int codigo;
    std::string modelo;
    int capacidade;
    double velocidadeMedia; // em milhas por hora
    double autonomia;       // em milhas

public:
    // Declaração do construtor
    Aeronave(int c, const std::string& m, int cap, double vm, double aut);

    // Declarações dos métodos "get" e "set"
    int getCodigo() const;
    void setCodigo(int c);

    std::string getModelo() const;
    void setModelo(const std::string& m);

    int getCapacidade() const;
    void setCapacidade(int cap);

    double getVelocidadeMedia() const;
    void setVelocidadeMedia(double vm);

    double getAutonomia() const;
    void setAutonomia(double aut);
};

#endif