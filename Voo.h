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
    std::string codigo;
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
    Voo(const std::string& c, const std::string& orig, const std::string& dest, double dist,
        const std::string& horaSaida, Aeronave* aeronave,
        Piloto* comando, Piloto* primeiroOficial);

    // getters e setters
    std::string getCodigo() const;
    std::string getOrigem() const;
    std::string getDestino() const;
    double getDistancia() const;
    std::string getHoraSaidaPrevista() const;
    std::string getHoraChegadaPrevista() const;
    Aeronave* getAeronaveAssociada() const;
    Piloto* getComandante() const;
    Piloto* getPrimeiroOficial() const;
    void setCodigo(const std::string& c);
    void setOrigem(const std::string& orig);
    void setDestino(const std::string& dest);
    void setDistancia(double dist);
    void setHoraSaidaPrevista(const std::string& horaSaida);
    void setHoraChegadaPrevista(const std::string& horaChegada);
    void setAeronaveAssociada(Aeronave* aeronave);
    void setComandante(Piloto* comando);
    void setPrimeiroOficial(Piloto* primeiroOficial);
    std::vector<Passageiro*> getPassageiros() const;
    
    // metodos
    void adicionarPassageiro(Passageiro* p);
    void calcularEstimativas();
    void exibirDados() const;
    void exibirPassageiros() const;
    void removerPassageiro(Passageiro *p); //Fazer
    void serializar(); //Fazer

        
};

#endif
