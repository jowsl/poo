// Atributos (privados):
// codigo (int), origem (string), destino (string), distancia (double).
// horaSaidaPrevista (string ou um tipo de dado de tempo).
// aeronaveAssociada (um ponteiro para um objeto Aeronave: Aeronave*).
// comandante e primeiroOficial (ponteiros para objetos Piloto: Piloto*).
// passageiros (aqui você usará a STL! Um std::vector<Passageiro*> é perfeito para isso).

#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>
#include "Aeronave.h"
#include "Pessoa.h"
#include "Passageiro.h"
#include "Piloto.h"

class Voo {
private:
    int codigo;
    std::string origem;
    std::string destino;
    double distancia; // em milhas
    std::string horaSaidaPrevista;
    std::string horaChegadaPrevista;
    double tempoDeVooEstimado; // em horas
    int numeroDeEscalasEstimado; // número de escalas do voo.
    Aeronave* aeronaveAssociada; //* Ponteiro para um objeto Aeronave
    Piloto* comandante; // * para o comandante
    Piloto* primeiroOficial; // * para o oficial 
    std::vector<Passageiro*> passageiros; // Vetor de pointers para Passageiro

public:
    // Construtor
    Voo(int c, const std::string& orig, const std::string& dest, double dist,
        const std::string& horaSaida, Aeronave* aeronave,
        Piloto* comando, Piloto* primeiroOficial);

    // getters e setters
    int getCodigo() const;
    void setCodigo(int c);
    std::string getOrigem() const;
    void setOrigem(const std::string& orig);
    std::string getDestino() const;
    void setDestino(const std::string& dest);
    double getDistancia() const;
    void setDistancia(double dist);
    std::string getHoraSaidaPrevista() const;
    void setHoraSaidaPrevista(const std::string& horaSaida);
    Aeronave* getAeronaveAssociada() const;
    void setAeronaveAssociada(Aeronave* aeronave);
    Piloto* getComandante() const;
    void setComandante(Piloto* comando);
    Piloto* getPrimeiroOficial() const;
    void setPrimeiroOficial(Piloto* primeiroOficial);
    std::vector<Passageiro*> getPassageiros() const;
    void adicionarPassageiro(Pessoa* p);
    void calcularEstimativas() ;
    void exibirPassageiros() const;
    std::string getHoraChegadaPrevista() const;
};
#endif // VOO_H