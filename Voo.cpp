#include "Voo.h"
#include "Pessoa.h"
#include "Aeronave.h"
#include "Passageiro.h"
#include "Piloto.h"
#include <iostream>
#include <vector>

Voo::Voo(int c, const std::string& orig, const std::string& dest, double dist,
         const std::string& horaSaida, Aeronave* aeronave,
         Piloto* comando, Piloto* primeiroOficial): codigo(c), origem(orig), destino(dest),
            distancia(dist), horaSaidaPrevista(horaSaida), aeronaveAssociada(aeronave), comandante(comando), 
            primeiroOficial(primeiroOficial)  {}

int Voo::getCodigo() const {
    return codigo;
}

void Voo::setCodigo(int c) {
    codigo = c;
}

std::string Voo::getOrigem() const {
    return origem;
}

void Voo::setOrigem(const std::string& orig) {
    origem = orig;
}

std::string Voo::getDestino() const {
    return destino;
}

void Voo::setDestino(const std::string& dest) {
    destino = dest;
}

double Voo::getDistancia() const {
    return distancia;
}

void Voo::setDistancia(double dist) {
    distancia = dist;
}

std::string Voo::getHoraSaidaPrevista() const {
    return horaSaidaPrevista;
}

void Voo::setHoraSaidaPrevista(const std::string& horaSaida) {
    horaSaidaPrevista = horaSaida;
}

Aeronave* Voo::getAeronaveAssociada() const {
    return aeronaveAssociada;
}

void Voo::setAeronaveAssociada(Aeronave* aeronave) {
    aeronaveAssociada = aeronave;
}

Piloto* Voo::getComandante() const {
    return comandante;
}

void Voo::setComandante(Piloto* comando) {
    comandante = comando;
}

Piloto* Voo::getPrimeiroOficial() const {
    return primeiroOficial;
}

void Voo::setPrimeiroOficial(Piloto* primeiroOficial) {
    this->primeiroOficial = primeiroOficial;
}

std::vector<Passageiro*> Voo::getPassageiros() const {
    return passageiros;
}

void Voo::adicionarPassageiro(Pessoa* p) {
    if (aeronaveAssociada != nullptr) { // Verifica se a aeronave associada existe
        if (passageiros.size() < aeronaveAssociada->getCapacidade()) { //verifica capacidade da aeronave

            std::cout << "Passageiro " << p->getNome() << " adicionado ao voo " << codigo << "." << std::endl;
        } else {
            std::cout << "ERRO: Capacidade maxima da aeronave." << std::endl;
        }
    } else {
        std::cout << "ERRO: Nenhuma aeronave selecionada." << std::endl;
    }
}

void Voo::calcularEstimativas() {

}

void Voo::exibirPassageiros() const {
    std::cout << "=============================================" << std::endl;
    std::cout << "--- Passageiros do Voo " << codigo << " ---" << std::endl;
    if (passageiros.empty()) {
        std::cout << "Nenhum passageiro a bordo." << std::endl;
    } else {
        for (Passageiro* p : passageiros) { 
            std::cout << "Nome: " << p->getNome() << " , CPF: " << p->getCpf() <<", Bilhete: " << p->getnumeroDoBilhete() << std::endl;
        }
    }
    std::cout << "=============================================" << std::endl;
}