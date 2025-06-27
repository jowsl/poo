#include "Voo.h"
#include "Pessoa.h"
#include "Aeronave.h"
#include "Passageiro.h"
#include "Piloto.h"
#include <iostream>
#include <vector>

using namespace std;


Voo::Voo(const string& c, const string& orig, const string& dest, double dist,
         const string& horaSaida, Aeronave* aeronave, Piloto* comando, 
         Piloto* primeiroOficial):
            codigo(c), origem(orig), destino(dest), distancia(dist),
            horaSaidaPrevista(horaSaida), aeronaveAssociada(aeronave), 
            comandante(comando), primeiroOficial(primeiroOficial)  {
                this->calcularEstimativas(); // horaChegadaPrevista é atualizada    
            }

string Voo::getCodigo() const {
    return codigo;
}

void Voo::setCodigo(const string& c) {
    codigo = c;
}

string Voo::getOrigem() const {
    return origem;
}

void Voo::setOrigem(const string& orig) {
    origem = orig;
}

string Voo::getDestino() const {
    return destino;
}

void Voo::setDestino(const string& dest) {
    destino = dest;
}

double Voo::getDistancia() const {
    return distancia;
}

void Voo::setDistancia(double dist) {
    distancia = dist;
}

string Voo::getHoraSaidaPrevista() const {
    return horaSaidaPrevista;
}

void Voo::setHoraSaidaPrevista(const string& horaSaida) {
    horaSaidaPrevista = horaSaida;
}

string Voo::getHoraChegadaPrevista() const {
    return horaChegadaPrevista;
}

void Voo::setHoraChegadaPrevista(const string& horaChegada) {
    horaChegadaPrevista = horaChegada;
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

vector<Passageiro*> Voo::getPassageiros() const {
    return passageiros;
}

void Voo::adicionarPassageiro(Passageiro* p) {
    if (this->aeronaveAssociada != nullptr) { // Verifica se a aeronave associada existe
        if (passageiros.size() < aeronaveAssociada->getCapacidade()) { //verifica capacidade da aeronave
            passageiros.push_back(p);
            cout << "Passageiro " << p->getNome() << " adicionado ao voo " << codigo << "." << endl;
        } else {
            cout << "ERRO: Capacidade maxima da aeronave." << endl;
        }
    } else {
        cout << "ERRO: Nenhuma aeronave selecionada." << endl;
    }
}

void Voo::calcularEstimativas() {

    if (this->aeronaveAssociada == nullptr) {
        // Se não houver aeronave
        this->numeroDeEscalasEstimado = 0;
        this->tempoDeVooEstimado = 0.0;
        cout << "ERRO: Nenhuma aeronave associada ao voo." << endl;
        return;
    }
    
    // Verifica se a autonomia é válida para evitar divisão por zero.
    if (this->aeronaveAssociada->getAutonomia() > 0) {
        //calculo de escalas
        this->numeroDeEscalasEstimado = static_cast<int>(this->distancia / this->aeronaveAssociada->getAutonomia());
    } else {
        this->numeroDeEscalasEstimado = 0;
    }

    //------       tempo de voo puro
    double tempoPuroDeVoo = this->distancia / this->aeronaveAssociada->getVelocidadeMedia();

    this->tempoDeVooEstimado = tempoPuroDeVoo + this->numeroDeEscalasEstimado; //cada escala = 1hora

    int horasTotais = static_cast<int>(this->tempoDeVooEstimado);
    int minutos = static_cast<int>((this->tempoDeVooEstimado - horasTotais) * 60);
       
    //------ Hora de chegada prevista
    //Pegar a hora e minuto da string "HH:MM" de saída
    size_t pos = this->horaSaidaPrevista.find(':');
     int horasSaida = stoi(this->horaSaidaPrevista.substr(0, pos));
    int minutosSaida = stoi(this->horaSaidaPrevista.substr(pos + 1));

    //Pegar a duração do voo em horas e minutos
    int horasDuracao = static_cast<int>(this->tempoDeVooEstimado);
    int minutosDuracao = static_cast<int>((this->tempoDeVooEstimado - horasDuracao) * 60);
    int minutosFinais = minutosSaida + minutosDuracao;
    int horasFinais = horasSaida + horasDuracao;
    //corrigindo valores
    horasFinais = horasFinais + minutosFinais / 60; // horas adicionais que vieram dos minutos
    minutosFinais = minutosFinais % 60; // Pega o resto dos minutos
    horasFinais = horasFinais % 24;  // Pega o resto das horas (para voos que cruzam a meia-noite)


    //formatando correto para deixar em string
    string horasFormatada = "";
    if (horasFinais < 10) {
        horasFormatada += "0" + to_string(horasFinais);
    } 
    horasFormatada += std::to_string(horasFinais);
    
    horasFormatada += ":";
    
    if (minutosFinais < 10) {
        horasFormatada += "0";
    }
    horasFormatada += std::to_string(minutosFinais);
    
    this->horaChegadaPrevista = horasFormatada; //salvando na variável correta.

    cout << "====================================" << endl;
    cout << "Estimativas para o voo " << this->codigo << " calculadas:" << endl;
    cout << " -> Escalas necessarias: " << this->numeroDeEscalasEstimado << endl;
    cout << " -> Tempo total de viagem: " << horasTotais << " horas e " << minutos << " minutos." << endl;
    cout << " -> Hora de chegada prevista: " << horasFinais << ":" << minutosFinais << endl;
    cout << "====================================" << endl;
}

void Voo::exibirPassageiros() const {
    cout << "=============================================" << endl;
    cout << "--- Passageiros do Voo " << codigo << " ---" << endl;
    if (passageiros.empty()) {
        cout << "Nenhum passageiro a bordo." << endl;
    } else {
        for (Passageiro* p : passageiros) { 
            cout << "Nome: " << p->getNome() << " , CPF: " << p->getCpf() <<", Bilhete: " << p->getnumeroDoBilhete() << endl;
        }
    }
    cout << "=============================================" << endl;
}

void Voo::exibirDados() const {
 cout << "\n==========================================" << endl;
    cout << "  DETALHES DO VOO: " << this->codigo << endl;
    cout << "==========================================" << endl;
    cout << "Origem: " << this->origem << "\tDestino: " << this->destino << endl;
    cout << "Distância: " << this->distancia << " milhas" << endl;
    cout << "Saída Prevista: " << this->horaSaidaPrevista << "\tChegada Prevista: " << this->horaChegadaPrevista << endl;
    cout << "Tempo Estimado: " << this->tempoDeVooEstimado << " horas\tEscalas: " << this->numeroDeEscalasEstimado << endl;

    // Detalhes da Aeronave 
    if (this->aeronaveAssociada != nullptr) {
        cout << "\n--- Aeronave ---\n";
        this->aeronaveAssociada->exibirDados(); // Delegando a tarefa para a classe Aeronave
    } else {
        cout << "\n--- Aeronave: Nenhuma aeronave associada. ---\n";
    }

    // --- Detalhes da Tripulação ---
    if (this->comandante != nullptr) {
        cout << "\n--- Comandante ---\n";
        this->comandante->exibirDados(); // Delegando para a classe Piloto
    }
    if (this->primeiroOficial != nullptr) {
        cout << "\n--- Primeiro Oficial ---\n";
        this->primeiroOficial->exibirDados(); // Delegando para a classe Piloto
    }

    // Lista de Passageiros 
    cout << "\n--- Passageiros a Bordo (" << this->passageiros.size() << ") ---\n";
    if (this->passageiros.empty()) {
        cout << "Nenhum passageiro embarcado." << endl;
    } else {
        for (const Passageiro* p : this->passageiros) {
            if (p != nullptr) {
                p->exibirDados(); // Delegando para a classe Passageiro
                cout << "---" << endl;
            }
        }
    }
    cout << "==========================================" << endl;
}
