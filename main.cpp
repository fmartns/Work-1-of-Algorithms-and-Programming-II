#include <iostream>
#include "library.hpp"

using namespace std;

int main() {
    const int MAX_BOOKS = 10;
    const int MAX_USERS = 10;
    const int MAX_HISTORY = 10;

    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    BookHistory bookHistories[MAX_HISTORY];

    // Inicialize todas as estruturas de dados

    while (true) {
        cout << "Selecione uma opção:" << endl;
        cout << "1. Cadastrar Livro" << endl;
        cout << "2. Listar Livros" << endl;
        cout << "3. Cadastrar Usuário" << endl;
        cout << "4. Listar Usuários" << endl;
        cout << "5. Empréstimo de Livro" << endl;
        cout << "6. Devolução de Livro" << endl;
        cout << "7. Sair" << endl;

        int choice;
        cin >> choice;

        time_t currentDate = time(nullptr);

        switch (choice) {
            case 1:
                registerBooks(books, MAX_BOOKS);
                break;
            case 2:
                listBooks(books, MAX_BOOKS);
                break;
            case 3:
                registerUser(users, MAX_USERS);
                break;
            case 4:
                listUsers(users, MAX_USERS);
                break;
            case 5:
                loanBook(books, MAX_BOOKS, users, MAX_USERS, bookHistories, MAX_HISTORY, currentDate);
                break;
            case 6:
                returnBook(books, MAX_BOOKS, users, MAX_USERS, bookHistories, MAX_HISTORY, currentDate);
                break;
            case 7:
                cout << "Saindo do programa." << endl;
                return 0;
            default:
                cout << "Opção inválida. Por favor, tente novamente." << endl;
        }
    }

    return 0;
}
