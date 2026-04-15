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
    exibirMenu();
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

void addTarefa() {
    cout << "Digite a descrição da tarefa: ";
    Tarefas novaTarefa = {Lista.size() + 1, novaTarefa.descricao, "Não iniciada"};
    getline(cin, novaTarefa.descricao);
    Lista.push_back(novaTarefa);
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