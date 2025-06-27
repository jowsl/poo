#include <iostream>
#include "Aeronave.h" // Inclui a declaração da classe

using namespace std;

//construtor
Aeronave::Aeronave(const string& c, const string& m, int cap, double vm, double aut)
    : codigo(c), modelo(m), capacidade(cap), velocidadeMedia(vm), autonomia(aut) {}

// getters e setters
string Aeronave::getCodigo() const {
    return codigo;
}

void Aeronave::setCodigo(int c) {
    codigo = c;
}

string Aeronave::getModelo() const {
    return modelo;
}

void Aeronave::setModelo(const string& m) {
    modelo = m;
}

int Aeronave::getCapacidade() const {
    return capacidade;
}

void Aeronave::setCapacidade(int cap) {
    capacidade = cap;
}

double Aeronave::getVelocidadeMedia() const {
    return velocidadeMedia;
}

void Aeronave::setVelocidadeMedia(double vm) {
    velocidadeMedia = vm;
}

double Aeronave::getAutonomia() const {
    return autonomia;
}

void Aeronave::setAutonomia(double aut) {
    autonomia = aut;
}

void Aeronave::exibirDados() const {
    cout << "Código da Aeronave: " << this->codigo << endl;
    cout << "Modelo: " << this->modelo << endl;
    cout << "Capacidade: " << this->capacidade << " passageiros" << endl;
    cout << "Velocidade Média: " << this->velocidadeMedia << " milhas/h" << endl;
    cout << "Autonomia: " << this->autonomia << " milhas" << endl;
}
