#ifndef GERENCIADORVOOS_H
#define GERENCIADORVOOS_H

#include "Aeronave.h"
#include "Piloto.h"
#include "Passageiro.h"
#include "Voo.h"
#include <vector>

using namespace std;

class GerenciadorVoos {
private:
    vector<Aeronave*> aeronaves;
    vector<Piloto*> pilotos;
    vector<Passageiro*> passageiros;
    vector<Voo*> voos;

public:
    GerenciadorVoos();
    ~GerenciadorVoos(); // Destrutor

    // Em GerenciadorVoos.h, dentro de public:
    void cadastrarAeronave();
    void cadastrarPiloto();
    void cadastrarPassageiro();
    void criarVoo();
    void embarcarPassageiroVoo();
    void listarVoos() const;
    void listarPassageirosDeVoo() const;
    void salvarDados();
    void carregarDados();
    Aeronave* encontrarAeronave(const string&);
    Piloto* encontrarPiloto(const string&);
    Passageiro* encontrarPassageiro(const string&);
};

#endif 
