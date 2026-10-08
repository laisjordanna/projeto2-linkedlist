//
// Created by laisj on 07/10/2026.
//

#include <iostream>
using namespace std;

struct No {
    string nome;
    int id;
    No *proximo;
};

bool buscar(No *head, int id) {
    if (head == NULL) {
        return false;
    }

    No *atual = head;
    do {
        if (atual->id == id) {
            return true;
        }
        atual = atual->proximo;

    } while (atual != head);

    return false;
}

void inserirJogadores(No *&head, No *&vez, No *novoNo) {
    if (head == NULL) {
        novoNo->proximo = novoNo;
        head = novoNo;
        vez = novoNo;
        return;
    }

    No *aux = head;
    while (aux->proximo != head) {
        aux = aux->proximo;
    }
    aux->proximo = novoNo;
    novoNo->proximo = head;
}

void cadastrarJogador(No *&head, No *&vez) {
    No *novo = new No;
    cout << "nome: ";
    cin >> novo->nome;
    cout << "identificador: ";
    cin >> novo->id;

    if (buscar(head, novo->id)) {
        cout << "ja existe um jogador com esse identificador" << endl;
        delete novo;
        return;
    }

    inserirJogadores(head, vez, novo);
    cout << "jogador cadastrado" << endl;
}

void remover(No *&head, No *&vez, int id) {
    
}

int main() {}