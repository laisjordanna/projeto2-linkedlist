//
// Created by laisj on 07/10/2026.
//

#include <iostream>
using namespace std;

struct No {
    string nome;
    int idade;
    string cidade;
    string ingresso;
    No *proximo;
    No *anterior;
};

void inserirComprador(No *&head, No *novoNo) {
    novoNo->proximo = NULL;
    if (head == NULL) {
        novoNo->anterior = NULL;
        head = novoNo;
        return;
    }

    No *aux = head;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novoNo;
    novoNo->anterior = aux;
}

void cadastrarComprador(No *&head) {
    No *novo = new No;
    cout << "nome: ";
    cin >> novo->nome;
    cout << "idade: ";
    cin >> novo->idade;
    cout << "cidade: ";
    cin >> novo->cidade;
    cout << "ingresso: ";
    cin >> novo->ingresso;

    inserirComprador(head, novo);
    cout << "cadastrado realizado" << endl;
}

bool buscar(No *head, string nome) {
    No *p = head;
    while (p != NULL) {
        if (p->nome == nome) {
            return true;
        }
        p = p->proximo;
    }
    return false;
}

void remover(No *&head, string nome) {
    if (head == NULL) {
        cout << "nao ha compradores cadastrados" << endl;
        return;
    }

    No *temp = head;
    while (temp != NULL) {
        if (temp->nome == nome) {
            if (temp->anterior == NULL) {
                head = temp->proximo;
            } else {
                temp->anterior->proximo = temp->proximo;
            }

            if (temp->proximo != NULL) {
                temp->proximo->anterior = temp->anterior;
            }

            delete temp;
            cout << "comprador " << nome << " removido" << endl;
            return;
        }
        temp = temp->proximo;
    }

    cout << "comprador nao encontrado" << endl;
}

void printList(No *head) {
    if (head == NULL) {
        cout << "nenhum comprador cadastrado" << endl;
        return;
    }

    No *atual = head;
    int i = 1;
    while (atual != NULL) {
        cout << "comprador " << i << endl;
        cout << "nome: " << atual->nome << endl;
        cout << "idade: " << atual->idade << endl;
        cout << "cidade: " << atual->cidade << endl;
        cout << "ingresso: " << atual->ingresso << endl;
        cout << endl;
        atual = atual->proximo;
        i++;
    }
}

void printListInversa(No *head) {
    if (head == NULL) {
        cout << "nenhum comprador cadastrado" << endl;
        return;
    }

    No *atual = head;
    int i = 1;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
        i++;
    }

    while (atual != NULL) {
        cout << "comprador " << i;
        cout << "nome: " << atual->nome << endl;
        cout << "idade: " << atual->idade << endl;
        cout << "cidade: " << atual->cidade << endl;
        cout << "ingresso: " << atual->ingresso << endl;
        cout << endl;
        atual = atual->anterior;
        i--;
    }
}

int main() {
    No *head = NULL;

    int opcao = -1;
    string nome;

    while (opcao != 0) {
        cout << "\n1 - cadastrar comprador" << endl;
        cout << "2 - buscar comprador" << endl;
        cout << "3 - excluir comprador" << endl;
        cout << "4 - ver compradores (ordem de cadastro)" << endl;
        cout << "5 - ver compradores (ordem inversa)" << endl;
        cout << "0 - sair" << endl;
        cout << "opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            cadastrarComprador(head);
        } else if (opcao == 2) {
            cout << "nome: ";
            cin >> nome;
            if (buscar(head, nome)) {
                cout << "comprador encontrado" << endl;
            } else {
                cout << "comprador nao encontrado" << endl;
            }
        } else if (opcao == 3) {
            cout << "nome: ";
            cin >> nome;
            remover(head, nome);
        } else if (opcao == 4) {
            printList(head);
        } else if (opcao == 5) {
            printListInversa(head);
        }
    }
    return 0;
}
