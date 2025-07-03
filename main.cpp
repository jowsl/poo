#include <iostream>
#include "GerenciadorVoos.h"
#include <limits>

using namespace std;

void printaMenu() {
    cout << "\n======= SISTEMA DE CONTROLE DE VOOS =======" << endl;
    cout << "1. Cadastrar aeronave" << endl;
    cout << "2. Cadastrar piloto" << endl;
    cout << "3. Cadastrar passageiro" << endl;
    cout << "4. Criar voo" << endl;
    cout << "5. Embarcar passageiro em voo" << endl;
    cout << "6. Listar voos" << endl;
    cout << "7. Listar passageiros de um voo" << endl;
    cout << "8. Salvar ou Carregar dados" << endl;
    cout << "9. Sair" << endl;
    cout << "===========================================" << endl;
    cout << "Escolha uma opção: ";
}

int main() {
    GerenciadorVoos sistema;
    int opcao = 0;
    int salvarCarregar = 0;

    do {
        printaMenu();
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Validação de entrada para caso o usuário digitar um texto
        if (cin.fail()) {
            cout << "\nERRO: Entrada inválida. Por favor, digite apenas números." << endl;
            cin.clear(); // Limpa o erro
            cin.ignore(1000, '\n'); // Descarta a entrada inválida (versão simples)
            opcao = 0; 
        }

        switch (opcao) {
            case 1:
                sistema.cadastrarAeronave();
                break;
            case 2:
                sistema.cadastrarPiloto();
                break;
            case 3:
                sistema.cadastrarPassageiro();
                break;
            case 4:
                sistema.criarVoo();
                break;
            case 5:
                sistema.embarcarPassageiroVoo();
                break;
            case 6:
                sistema.listarVoos();
                break;
            case 7:
                sistema.listarPassageirosDeVoo();
                break;
            case 8:
                cout << "\n1. Para salvar os dados. \n2. Para carregar os dados." << endl;
                cout << "===========================================" << endl;
                cout << "Escolha uma opção: ";
                cin >> salvarCarregar;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (salvarCarregar)
                {
                    case 1:
                        sistema.salvarDados();
                        cout << "Dados salvos com sucesso!" << endl;
                        break;
                    case 2:
                        sistema.carregarDados();
                        cout << "Dados carregados com sucesso!" << endl;
                        break;
                    default:
                        cout << "Opção inválida. Tente novamente." << endl;
                }
                break;
            case 9:
                cout << "\nSaindo do sistema. Obrigado!" << endl;
                break;
            default:
                if (opcao != 0) {
                    cout << "\nERRO: Opção inválida. Tente novamente." << endl;
                }
                break;
        }

    } while (opcao != 9);

    return 0;
}
