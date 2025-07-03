#include "GerenciadorVoos.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

// Construtor vazio
GerenciadorVoos::GerenciadorVoos() {}

// Destrutor para limpar a memória
GerenciadorVoos::~GerenciadorVoos() {
    for (auto p : aeronaves) delete p;
    for (auto p : pilotos) delete p;
    for (auto p : passageiros) delete p;
    for (auto p : voos) delete p;
}

void GerenciadorVoos::cadastrarAeronave() { // Cadastra a Aeronave
    string codigo, modelo;
    int capacidade;
    float velocidade, autonomia;

    cout << "\n--- Cadastro de Aeronave ---" << endl;
    cout << "Digite o código: ";
    cin >> codigo;
    cout << "Digite a capacidade de passageiros: ";
    cin >> capacidade;
    cout << "Digite a velocidade média (em milhas/h): ";
    cin >> velocidade;
    cout << "Digite a autonomia de voo (em milhas): ";
    cin >> autonomia;
    cout << "Digite o modelo: ";
    cin.ignore(1000, '\n'); // Limpa o buffer antes de ler a linha
    getline(cin, modelo);

    this->aeronaves.push_back(new Aeronave(codigo, modelo, capacidade, velocidade, autonomia));

    cout << "Aeronave '" << modelo << "' cadastrada com sucesso! " << endl;
}

void GerenciadorVoos::cadastrarPiloto() {
    string nome, matricula, breve;
    int horasDeVoo;

    cout << "\n--- Cadastro de Piloto ---" << endl;
    cout << "Digite a matrícula: ";
    getline(cin, matricula);
    cout << "Digite as horas de voo: ";
    cin >> horasDeVoo;
    cout << "Digite o nome completo: ";
    cin.ignore(1000, '\n'); // Limpa o buffer antes de ler a linha
    getline(cin, nome);
    cout << "Digite o brevê do piloto: ";
    getline(cin, breve);

    this->pilotos.push_back(new Piloto(nome, matricula, breve, horasDeVoo));

    cout << "O piloto '" << nome << "' foi cadastrado com sucesso!" << endl;
}

void GerenciadorVoos::cadastrarPassageiro() {
    string nome, cpf, bilhete;

    cout << "\n--- Cadastro de Passageiro ---" << endl;
    cout << "Digite o CPF: ";
    cin >> cpf;
    cout << "Digite o número do bilhete: ";
    cin >> bilhete;
    cout << "Digite o nome completo: ";
    cin.ignore(1000, '\n'); // Limpa o buffer
    getline(cin, nome); // Pega o nome completo

    this->passageiros.push_back(new Passageiro(nome, cpf, bilhete));

    cout << "Passageiro '" << nome << "' cadastrado com sucesso!" << endl;
}

void GerenciadorVoos::criarVoo() {
        cout << "\n--- Criação de Voo ---" << endl;
    if (pilotos.size() < 2 || aeronaves.empty()) {
        cout << "ERRO: É necessário ter pelo menos dois pilotos e uma aeronave cadastrados." << endl;
        return;
    }

    // Coletar dados do voo 
    string codigo, origem, destino, horaSaida;
    double distancia;

    cout << "Digite o código do voo: ";
    getline(cin, codigo);
    cout << "Digite a cidade de origem: ";
    getline(cin, origem);
    cout << "Digite a cidade de destino: ";
    getline(cin, destino);
    cout << "Digite a distância do voo (em milhas): ";
    cin >> distancia; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite a hora de saída prevista (HH:MM): ";
    getline(cin, horaSaida);

    // Escolher a Aeronave 
    cout << "\nAeronaves disponíveis:" << endl;
    for (size_t i = 0; i < this->aeronaves.size(); ++i) {
        cout << "[" << i << "] " << aeronaves[i]->getModelo()
             << " (Código: " << aeronaves[i]->getCodigo() << ")" << endl;
    }
    int indiceAeronave;
    cout << "Escolha a aeronave pelo número: ";
    cin >> indiceAeronave;

    // Valida escolha da aeronava
    if (indiceAeronave < 0 || indiceAeronave >= aeronaves.size()) {
        cout << "ERRO: Índice de aeronave inválido." << endl;
        return;
    }
    Aeronave* aeronaveEscolhida = this->aeronaves[indiceAeronave];

    // Escolher o Comandante 
    cout << "\nPilotos disponíveis:" << endl;
    for (size_t i = 0; i < this->pilotos.size(); ++i) {
        cout << "[" << i << "] " << pilotos[i]->getNome()
             << " (Matrícula: " << pilotos[i]->getMatricula() << ")" << endl;
    }
    int indiceComandante;
    cout << "Escolha o COMANDANTE pelo número: ";
    cin >> indiceComandante;

    if (indiceComandante < 0 || indiceComandante >= pilotos.size()) {
        cout << "\nERRO: Índice de piloto inválido." << endl;
        return;
    }
    Piloto* comandanteEscolhido = this->pilotos[indiceComandante];

    // Escolher o Primeiro Oficial (Co-piloto) 
    int indiceCoPiloto;
    cout << "Escolha o PRIMEIRO OFICIAL pelo número: ";
    cin >> indiceCoPiloto;
    // Validacao das escolhas dos Pilotos
    if (indiceCoPiloto < 0 || indiceCoPiloto >= pilotos.size()) {
        cout << "\nERRO: Índice de piloto inválido." << endl;
        return;
    }
    if (indiceCoPiloto == indiceComandante) {
        cout << "\nERRO: O primeiro oficial não pode ser o mesmo que o comandante." << endl;
        return;
    }
    Piloto* coPilotoEscolhido = this->pilotos[indiceCoPiloto];

    // Criar o Voo e adicionar à lista 
    Voo* novoVoo = new Voo(codigo, origem, destino, distancia, horaSaida, aeronaveEscolhida, comandanteEscolhido, coPilotoEscolhido);
    
    this->voos.push_back(novoVoo);

    cout << "\nVoo " << codigo << " de " << origem << " para " << destino << " criado com sucesso!" << endl;
}

void GerenciadorVoos::embarcarPassageiroVoo() {
     cout << "\n--- Embarcar Passageiro em Voo ---" << endl;
    if (voos.empty() || passageiros.empty()) {
        cout << "\nERRO: É necessário ter pelo menos um voo e um passageiro cadastrados." << endl;
        return;
    }

    // Listar e escolher o Voo 
    cout << "\nVoos disponíveis:" << endl;
    for (size_t i = 0; i < this->voos.size(); ++i) {
        cout << "[" << i << "] Voo " << voos[i]->getCodigo()
             << " (" << voos[i]->getOrigem() << " -> " << voos[i]->getDestino() << ")" << endl;
    }

    int indiceVoo;
    cout << "\nEscolha o voo pelo número: ";
    cin >> indiceVoo;

    // Validação da escolha do voo
    if (indiceVoo < 0 || indiceVoo >= voos.size()) {
        cout << "\nERRO: Índice de voo inválido." << endl;
        return;
    }

    // Listar e escolher o Passageiro 
    for (size_t i = 0; i < this->passageiros.size(); ++i) {
        cout << "[" << i << "] " << passageiros[i]->getNome()
             << " (CPF: " << passageiros[i]->getCpf() << ")" << endl;
    }

    int indicePassageiro;
    cout << "\nEscolha o passageiro pelo número: ";
    cin >> indicePassageiro;

    // Validação da escolha do passageiro
    if (indicePassageiro < 0 || indicePassageiro >= passageiros.size()) {
        cout << "ERRO: Índice de passageiro inválido." << endl;
        return;
    }

    // Associar os objetos escolhidos 
    Voo* vooEscolhido = this->voos[indiceVoo];
    Passageiro* passageiroEscolhido = this->passageiros[indicePassageiro];

    // Chama o método da classe Voo para adicionar o passageiro.
    // A própria função 'adicionarPassageiro' (que você já fez)
    // vai verificar a capacidade e imprimir a mensagem de sucesso ou erro.
    vooEscolhido->adicionarPassageiro(passageiroEscolhido);

}


void GerenciadorVoos::listarPassageirosDeVoo() const {
     cout << "\n--- Listar Passageiros de um Voo ---" << endl;
    if (voos.empty()) {
        cout << "Nenhum voo cadastrado para listar passageiros." << endl;
        return;
    }

    string codigo;
    cout << "Digite o código do voo que deseja listar os passageiros: ";
    cin >> codigo;
    
    Voo* vooEncontrado = nullptr;

    // Encontra o voo na lista de voos
    for (Voo* voo : this->voos) {
        if (voo->getCodigo() == codigo) {
            vooEncontrado = voo;
            break;
        }
    }

    // Com o voo foi encontrado, processa a lista de passageiros
    if (vooEncontrado != nullptr) {
        cout << "\n--- Passageiros do Voo " << vooEncontrado->getCodigo() << " ---" << endl;

        // Pega o vetor de passageiros diretamente do objeto Voo
        vector<Passageiro*> listaDePassageiros = vooEncontrado->getPassageiros();
        
        if (listaDePassageiros.empty()) {
            cout << "Nenhum passageiro embarcado neste voo." << endl;
        } else {
            // Percorre a lista de passageiros e chama o exibirDados de cada um
            for (const Passageiro* p : listaDePassageiros) {
                p->exibirDados(); 
                cout << "--------------------" << endl;
            }
        }
    } else {
        cout << "ERRO: Voo com o código '" << codigo << "' não foi encontrado." << endl;
    }
}
    
    void GerenciadorVoos::listarVoos() const {
        cout << "\n--- Lista de Voos Cadastrados ---" << endl;
        if (voos.empty()) {
            cout << "Nenhum voo cadastrado." << endl;
            return;
        }
    
        for (const Voo* voo : this->voos) {
            voo->exibirDados();
        }
    }

// função que vai salvar os .CSV de aeronaves, pessoas e voos
// A função percorre os vetores de aeronaves, pilotos, passageiros e voos,
// e escreve os dados em arquivos CSV separados. Cada tipo de dado tem seu próprio arquivo como pedido no pdf.
void GerenciadorVoos::salvarDados() {
    //AERONAVE
    ofstream arquivoAeronaves("aeronaves.csv");
    if (arquivoAeronaves.is_open()) {
        for (const Aeronave* aeronave : this->aeronaves) {
            arquivoAeronaves << aeronave->getCodigo() << ","
                             << aeronave->getModelo() << ","
                             << aeronave->getCapacidade() << ","
                             << aeronave->getVelocidadeMedia() << ","
                             << aeronave->getAutonomia() << endl;
        }
        arquivoAeronaves.close();
        cout << "Dados de aeronaves salvos em aeronaves.csv" << endl;
    }

    //PESSOAS - que no caso são passageiros e pilotos
    ofstream arquivoPessoas("pessoas.csv");
    if (arquivoPessoas.is_open()) {
        for (const Piloto* piloto : this->pilotos) {
            arquivoPessoas << "PILOTO,"
                           << piloto->getNome() << ","
                           << piloto->getMatricula() << ","
                           << piloto->getBreve() << ","
                           << piloto->getHorasDeVoo() << endl;
        }
        for (const Passageiro* passageiro : this->passageiros) {
            arquivoPessoas << "PASSAGEIRO,"
                           << passageiro->getNome() << ","
                           << passageiro->getCpf() << ","
                           << passageiro->getnumeroDoBilhete() << endl;
        }
        arquivoPessoas.close();
        cout << "Dados de pessoas salvos em pessoas.csv" << endl;
    }

    // VOOS
    ofstream arquivoVoos("voos.csv");
    if (arquivoVoos.is_open()) {
        for (const Voo* voo : this->voos) {
            arquivoVoos << voo->getCodigo() << ","
                        << voo->getOrigem() << ","
                        << voo->getDestino() << ","
                        << voo->getDistancia() << ","
                        << voo->getHoraSaidaPrevista() << ","
                        << voo->getAeronaveAssociada()->getCodigo() << ","
                        << voo->getComandante()->getMatricula() << ","
                        << voo->getPrimeiroOficial()->getMatricula();

            //CPFs dos passageiros, separados por ';'
            for (const Passageiro* passageiro : voo->getPassageiros()) {
                arquivoVoos << ";" << passageiro->getCpf();
            }
            arquivoVoos << endl;
        }
        arquivoVoos.close();
        cout << "Dados de voos salvos em voos.csv" << endl;
    }
}


// funções auxiliares para encontrar objetos específicos
// Essas funções percorrem os vetores de aeronaves, pilotos e passageiros em busca do dado especificado.
Aeronave* GerenciadorVoos::encontrarAeronave(const string& codigo) {
    for (Aeronave* aeronave : this->aeronaves) {
        if (aeronave->getCodigo() == codigo) {
            return aeronave;
        }
    }
    return nullptr; // caso n encontre, null
}

Piloto* GerenciadorVoos::encontrarPiloto(const string& matricula) {
    for (Piloto* piloto : this->pilotos) {
        if (piloto->getMatricula() == matricula) {
            return piloto;
        }
    }
    return nullptr; // caso n encontre, null
}

Passageiro* GerenciadorVoos::encontrarPassageiro(const string& cpf) {
    for (Passageiro* passageiro : this->passageiros) {
        if (passageiro->getCpf() == cpf) {
            return passageiro;
        }
    }
    return nullptr;
}

// função para carregar os .CSV de aeronaves, pessoas e voos e 'reconstruir' os objetos
void GerenciadorVoos::carregarDados() {
    string linha, campo;
    
    // Carregar aeronaves
    ifstream arquivoAeronaves("aeronaves.csv");
    while (getline(arquivoAeronaves, linha)) {
            stringstream ss(linha);
            string codigo, modelo;
            int capacidade;
            double velocidade, autonomia;

            getline(ss, codigo, ',');
            getline(ss, modelo, ',');
            ss >> capacidade; ss.ignore(); // Lê o número e ignora a vírgula
            ss >> velocidade; ss.ignore();
            ss >> autonomia;

            this->aeronaves.push_back(new Aeronave(codigo, modelo, capacidade, velocidade, autonomia));
        }
        arquivoAeronaves.close();
    
    ifstream arquivoPessoas("pessoas.csv");
    if (arquivoPessoas.is_open()) {
        while (std::getline(arquivoPessoas, linha)) {
            std::stringstream ss(linha);
            std::vector<std::string> campos;
            while(std::getline(ss, campo, ',')) {
                campos.push_back(campo);
            } 

            if (campos[0] == "PILOTO") {
                // ordem aqui é PILOTO, nome, matricula, breve, horas
                this->pilotos.push_back(new Piloto(campos[1], campos[2], campos[3], std::stoi(campos[4])));
            } else if (campos[0] == "PASSAGEIRO") {
                // ordem dos dados PASSAGEIRO, nome, cpf, bilhete 
                this->passageiros.push_back(new Passageiro(campos[1], campos[2], campos[3]));
            }
        }
        arquivoPessoas.close();
    }

    // Agora os voos
    ifstream arquivoVoos("voos.csv");
    if (arquivoVoos.is_open()) {
        while (getline(arquivoVoos, linha)) {
            stringstream ss(linha);
            string codigoVoo, origem, destino, horaSaida;
            double distancia;
            string codAeronave, matComandante, matOficial_e_CPFs, listaCPFs;

            getline(ss, codigoVoo, ',');
            getline(ss, origem, ',');
            getline(ss, destino, ',');
            ss >> distancia; ss.ignore();
            getline(ss, horaSaida, ',');
            getline(ss, codAeronave, ',');
            getline(ss, matComandante, ',');
            // O resto da linha são os CPFs separados por ';', então lemos o resto tipo isso : mat123;cpf1;cpf2
            getline(ss, matOficial_e_CPFs); 

            // Agora, encontramos os ponteiros usando as funções auxiliares
            Aeronave* ptrAeronave = encontrarAeronave(codAeronave);
            Piloto* ptrComandante = encontrarPiloto(matComandante);
            
            // Separar a matrícula do oficial da lista de CPFs
            // apenas um detalhe para não precisar refazer o salvarDados.
            size_t pos_primeiro_ponto_virgula = matOficial_e_CPFs.find(';');
            Piloto* ptrOficial = nullptr;
            if(pos_primeiro_ponto_virgula != string::npos){
                ptrOficial = encontrarPiloto(matOficial_e_CPFs.substr(0, pos_primeiro_ponto_virgula));
                listaCPFs = matOficial_e_CPFs.substr(pos_primeiro_ponto_virgula + 1);   
            } else { // Caso não haja passageiros
                ptrOficial = encontrarPiloto(matOficial_e_CPFs);
            }
            
            Voo* novoVoo = new Voo(codigoVoo, origem, destino, distancia, horaSaida, ptrAeronave, ptrComandante, ptrOficial);

            // Agora, processamos a lista de passageiros
            stringstream ssCPFs(listaCPFs);
            string cpf;
            while (getline(ssCPFs, cpf, ';')) {
                Passageiro* ptrPassageiro = encontrarPassageiro(cpf);
                if (ptrPassageiro) {
                    novoVoo->adicionarPassageiro(ptrPassageiro);
                }
            }
                this->voos.push_back(novoVoo);
            
        }
    }
    arquivoVoos.close();
}