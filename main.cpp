#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tarefas {
    int id;
    string descricao;
    string status;
} ;

void exibirMenu();
void addTarefa(vector<Tarefas>& lista);
void listTarefas(vector<Tarefas>& lista);

vector<Tarefas> Lista;

int main() {
    int opcao = 0; 

    cout << "Bem-vindo ao Task Manager!" << '\n';

    do {
        exibirMenu();
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                addTarefa(Lista);
                break;
            case 2:
                listTarefas(Lista);
                break;
            case 3:
                cout << "Saindo do programa..." << '\n';
                break;
            default:
                cout << "Opção inválida, tente novamente." << '\n';
        }
    } while (opcao != 3);

return 0;   

}

void exibirMenu() {
    cout << "\n=== TASK MANAGER ===" << '\n';
    cout << "1. Adicionar Task" << '\n';
    cout << "2. Listar Tasks" << '\n';
    cout << "3. Sair" << '\n';
    cout << "" <<'\n';
}

void addTarefa(vector<Tarefas>& Lista) {    
    Tarefas novaTarefa;
    novaTarefa.id = Lista.size() + 1;
    novaTarefa.status = "Não iniciada";
    cout << "Digite a descrição da tarefa: ";
    getline(cin, novaTarefa.descricao);
    Lista.push_back(novaTarefa);
    cout << "Tarefa adicionada com sucesso.\n";
    
    int optionadd;
    do {
    cout << "1. Adicionar outra Task" << '\n';
    cout << "2. Listar Tasks" << '\n';
    cout << "3. Voltar ao menu inicial" << '\n';
    cin >> optionadd;
    cin.ignore();
    switch (optionadd) {
        case 1:
            addTarefa(Lista);
            break;
        case 2:
            listTarefas(Lista);
            break;
        case 3:
            break;
        default:
            cout << "Opção inválida, tente novamente." << '\n';
    }
} while (optionadd !=3);
}

void listTarefas(vector<Tarefas>& lista) {
    cout << "Total de tarefas: " << Lista.size() << '\n';

    cout << "\n=== Tarefas ===" << '\n';
    for (int i = 0; i < Lista.size(); i++) {
        cout << "[" << Lista[i].id << "] "
        << Lista[i].descricao << '\n'
        << "Status: " << Lista[i].status << '\n';
        }
    
}