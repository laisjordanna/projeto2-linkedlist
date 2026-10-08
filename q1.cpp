//
// Created by laisj on 07/10/2026.
//

#include <iostream>
using namespace std;

struct No {
    string especie;
    string nome;
    string alimentacao;
    string pais;
    int idade;
    No* proximo;
};

int tamanho(No *head) {
    int contador = 0;
    while (head != NULL) {
        contador++;
        head = head->proximo;
    }
    return contador;
}

void inserirAnimal(No *&head, No *novoNo) {
    novoNo->proximo = NULL;
    if (head == NULL) {
        head = novoNo;
        return;
    }

    No *aux = head;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novoNo;
}

void cadastrarAnimal(No *&head) {
    if (tamanho(head) == 5) {
        cout << "nao ha espaco no habitat" << endl;
        return;
    }

    No *novo = new No;
    cout << "especie do animal: ";
    cin >> novo->especie;
    cout << "nome do animal: ";
    cin >> novo->nome;
    cout << "alimentacao: ";
    cin >> novo->alimentacao;
    cout << "pais de origem: ";
    cin >> novo->pais;
    cout << "idade: ";
    cin >> novo->idade;

    inserirAnimal(head, novo);
}

int escolherHabitat() {
    int tipo;
    cout << "1-aquatico, 2-terrestre, 3-voador: ";
    cin >> tipo;

    if (tipo < 1 || tipo > 3) {
        cout << "habitat invalido" << endl;
        return -1;
    }
    return tipo -1;
}

bool buscar(No *head, string nome) {
    No *atual = head;
    while (atual != NULL) {
        if (atual->nome == nome) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

void remover(No *&head, string nome) {
    if (head == NULL) {
        cout << "nao ha animais no habitat" << endl;
        return;
    }
    No *temp = head;
    No *anterior = NULL;

    while (temp != NULL) {
        if (temp->nome == nome) {
            if (anterior == NULL) {
                head = head->proximo;
            } else {
                anterior->proximo = temp->proximo;
            }
            delete temp;
            cout << "remocao do animal " << nome << "concluida" << endl;
            return;
        }
        anterior = temp;
        temp = temp->proximo;
    }

    cout << "animal nao encontrado" << endl;
}

void printList(No *head) {
    if (head == NULL) {
        cout << "nenhum cadastro realizado" << endl;
    }

    No *atual = head;
    int i = 1;
    while (atual != NULL) {
        cout << "animal " << atual->especie << endl;
        cout << "nome: " << atual->nome << endl;
        cout << "alimentacao: " << atual->alimentacao << endl;
        cout << "pais de origem: " << atual->pais << endl;
        cout << "idade: " << atual->idade << endl;
        cout << endl;
        atual = atual->proximo;
        i++;
    }
}

int main() {
    No *habitats[3] = {NULL, NULL, NULL};
    string tiposDeHabitat[3] = {"aquatico", "tterrestre", "voador"};

    int opcao = -1;
    int habitat;
    string nome;

    while (opcao != 0) {
        cout << "\n1 - cadastrar animal" << endl;
        cout << "2 - ver um habitat" << endl;
        cout << "3 - buscar animal" << endl;
        cout << "4 - remover animal" << endl;
        cout << "0 - sair" << endl;
        cout << "opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            habitat = escolherHabitat();
            if (habitat != -1) {
                cadastrarAnimal(habitats[habitat]);
            }
        } else if (opcao == 2) {
            habitat = escolherHabitat();
            if (habitat != -1) {
                cout << "\n" << tiposDeHabitat[habitat] << ":" << endl;
                printList(habitats[habitat]);
            }
        } else if (opcao == 3) {
            cout << "nome: ";
            cin >> nome;
            bool achou = false;
            for (int i = 0; i < 3; i++) {
                if (buscar(habitats[i], nome)) {
                    cout << "animal encontrado no habitat " << tiposDeHabitat[i] << endl;
                    achou = true;
                }
            }
            if (!achou) {
                cout << "animal nao encontrado" << endl;
            }
        } else if (opcao == 4) {
            habitat = escolherHabitat();
            if (habitat != -1) {
                cout << "nome: ";
                cin >> nome;
                remover(habitats[habitat], nome);
            }
        }
    }
    return 0;
}