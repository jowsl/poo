#include "Piloto.h"

Piloto::Piloto(const string& nome, const string& matricula, const string& breve, int horasDeVoo)
    : Pessoa(nome), matricula(matricula), breve(breve), horasDeVoo(horasDeVoo) {}

void Piloto::setMatricula(const string& novaMatricula) {
    this->matricula = novaMatricula;
}

string Piloto::getMatricula() const {
    return this->matricula;
}

void Piloto::setBreve(const string& novoBreve) {
    this->breve = novoBreve;
}

string Piloto::getBreve() const {
    return this->breve;
}

void Piloto::setHorasDeVoo(int novasHoras) {
    this->horasDeVoo = novasHoras;
}

int Piloto::getHorasDeVoo() const {
    return this->horasDeVoo;
}

void Piloto::exibirDados() const {
    Pessoa::exibirDados();
    cout << "Matricula: " << this->matricula << endl;
    cout << "Breve: " << this->breve << endl;
    cout << "Horas de voo: " << this->horasDeVoo << endl;
}

string Piloto::serializar() const {
    string resultado = "PILOTO," + this->nome + "," + this->matricula 
                     + "," + this->breve + "," + to_string(this->horasDeVoo);
    return resultado;
}
