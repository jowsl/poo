#include "GerenciadorVoos.h"
#include <iostream>
#include <string>
#include <vector>

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
    cin >> matricula;
    cout << "Digite as horas de voo: ";
    cin >> horasDeVoo;
    cout << "Digite o nome completo: ";
    cin.ignore(1000, '\n');
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
    cin >> codigo;
    cout << "Digite a cidade de origem: ";
    cin >> origem;
    cout << "Digite a cidade de destino: ";
    cin >> destino;
    cout << "Digite a distância do voo (em milhas): ";
    cin >> distancia;
    cout << "Digite a hora de saída prevista (HH:MM): ";
    cin >> horaSaida;

    // Escolher a Aeronave 
    cout << "\nAeronaves disponíveis:" << endl;
    for (size_t i = 0; i < this->aeronaves.size(); ++i) {
        cout << "[" << i << "] " << aeronaves[i]->getModelo()
             << " (Código: " << aeronaves[i]->getCodigo() << ")" << endl;
        cout << endl;
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
    cout << endl;
    int indiceComandante;
    cout << "Escolha o COMANDANTE pelo número: ";
    cin >> indiceComandante;

    if (indiceComandante < 0 || indiceComandante >= pilotos.size()) {
        cout << endl << "ERRO: Índice de piloto inválido." << endl;
        return;
    }
    Piloto* comandanteEscolhido = this->pilotos[indiceComandante];

    // Escolher o Primeiro Oficial (Co-piloto) 
    int indiceCoPiloto;
    cout << "Escolha o PRIMEIRO OFICIAL pelo número: ";
    cin >> indiceCoPiloto;
    // Validacao das escolhas dos Pilotos
    if (indiceCoPiloto < 0 || indiceCoPiloto >= pilotos.size()) {
        cout << endl << "ERRO: Índice de piloto inválido." << endl;
        return;
    }
    if (indiceCoPiloto == indiceComandante) {
        cout << endl << "ERRO: O primeiro oficial não pode ser o mesmo que o comandante." << endl;
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
        cout << endl << "ERRO: É necessário ter pelo menos um voo e um passageiro cadastrados." << endl;
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
        cout << endl << "ERRO: Índice de voo inválido." << endl;
        return;
    }

    // Listar e escolher o Passageiro 
    for (size_t i = 0; i < this->passageiros.size(); ++i) {
        cout <<endl;
        cout << "\nPassageiros disponíveis:" << endl;
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
    // vai verificar a capacidade e imprimir a mensagem de sucesso ou erro.
    vooEscolhido->adicionarPassageiro(passageiroEscolhido);

}


void GerenciadorVoos::listarPassageirosDeVoo() const {
     cout << "\n--- Listar Passageiros de um Voo ---" << endl;
    if (voos.empty()) {
        cout << "Nenhum voo cadastrado para listar passageiros." << endl;
        return;
    }
    
    for (Voo* vooAtual : voos)
    {
        cout<< "Voo " << vooAtual->getCodigo() << endl;
    }
    
    cout << endl;

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
            cout << "--------------------" << endl;
        }
    }
