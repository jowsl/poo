#include <iostream>
#include "Aeronave.h" // Inclui a declaração da classe

using namespace std;

//construtor
Aeronave::Aeronave(int c, const std::string& m, int cap, double vm, double aut)
    : codigo(c), modelo(m), capacidade(cap), velocidadeMedia(vm), autonomia(aut) {}

// getters e setters
int Aeronave::getCodigo() const {
    return codigo;
}

void Aeronave::setCodigo(int c) {
    codigo = c;
}

std::string Aeronave::getModelo() const {
    return modelo;
}

void Aeronave::setModelo(const std::string& m) {
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