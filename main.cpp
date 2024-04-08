#include <iostream>
#include "library.hpp"

using namespace std;

int main() {
    
    // Definir valor da multa por dia de atraso.
    float finePerDay = 1.50;
    
    const int MAX_BOOKS = 1000;
    const int MAX_USERS = 1000;
    const int MAX_HISTORY = 1000;
    const int MAX_FINE = 1000;

    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    Fine fines[MAX_FINE];
    BookHistory bookHistories[MAX_HISTORY];
    
    // Livros com IDs fixos
    books[0] = {1, "A Chave de Vidro", "Raymond Chandler", 1942, 1};
    books[1] = {2, "O Senhor dos Anéis", "J.R.R. Tolkien", 1954, 8};
    books[2] = {3, "Cem Anos de Solidão", "Gabriel García Márquez", 1967, 3};
    books[3] = {4, "Orgulho e Preconceito", "Jane Austen", 1813, 10};
    books[4] = {5, "O Grande Gatsby", "F. Scott Fitzgerald", 1925, 6};
    books[5] = {6, "1984", "George Orwell", 1949, 7};
    books[6] = {7, "Crime e Castigo", "Fyodor Dostoevsky", 1866, 4};

    // Usuários com IDs fixos
    users[0] = {1, "Alice"};
    users[1] = {2, "Bob"};
    users[2] = {3, "Charlie"};
    users[3] = {4, "David"};
    users[4] = {5, "Eva"};
    users[5] = {6, "Frank"};
    users[6] = {7, "Grace"};

    // Inicialize todas as estruturas de dados

    while (true) {
        cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "        BIBLIOTECA UNIVALI" << endl;
        cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "Selecione uma opção:" << endl;
        cout << "(1) Livros" << endl;
        cout << "(2) Usuários" << endl;
        cout << "(3) Emprestimos" << endl;
        cout << "(4) Multas" << endl;
        cout << "(5) Estatisticas" << endl;
        cout << "(6) Sair" << endl;
        cout << "Digite o número correspondente a opção: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                cout << "               LIVROS" << endl;
                cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                cout << "Selecione uma opção:" << endl;
                cout << "(1) Cadastro de Livros" << endl;
                cout << "(2) Livros cadastrados" << endl;
                cout << "(3) Buscar livros" << endl;
                cout << "(4) Retornar ao menu anterior" << endl;
                cout << "Digite o número correspondente a opção: ";
                cin >> choice;
                switch(choice){
                    case 1:
                        registerBooks(books, MAX_BOOKS);
                        break;
                    case 2:
                        listBooks(books, MAX_BOOKS);
                        break;
                    case 3:
                        cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                        cout << "              BUSCADOR" << endl;
                        cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                        cout << "Parametro de busca:" << endl;
                        cout << "(1) Titulo" << endl;
                        cout << "(2) Autor" << endl;
                        cout << "(3) Ano" << endl;
                        cout << "(4) Retornar ao menu anterior" << endl;
                        cout << "Digite o número correspondente a opção: ";
                        cin >> choice;
                        switch(choice){
                            case 1:
                                findBookTitle(books, MAX_BOOKS);
                                break;
                            case 2:
                                findBookAuthor(books, MAX_BOOKS);
                                break;
                            case 3:
                                findBookYear(books, MAX_BOOKS);
                                break;
                            case 4:
                                break;
                            default:
                                cout << "Opção inválida. Por favor, tente novamente." << endl;
                        }
                        break;
                    default:
                        cout << "Opção inválida. Por favor, tente novamente." << endl;
                }
                break;
            case 2:
                cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                cout << "              USUÁRIOS" << endl;
                cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                cout << "Selecione uma opção:" << endl;
                cout << "(1) Cadastro de Usuários" << endl;
                cout << "(2) Usuários cadastrados" << endl;
                cout << "(3) Consultar empréstimos por usuário" << endl;
                cout << "(4) Consultar multas por usuário" << endl;
                cout << "(5) Retornar ao menu anterior" << endl;
                cout << "Digite o número correspondente a opção: ";
                cin >> choice;
                switch(choice){
                    case 1:
                        registerUser(users, MAX_USERS);
                        break;
                    case 2:
                        listUsers(users, MAX_USERS);
                        break;
                    case 3:
                        findBookPerUser(bookHistories, MAX_HISTORY, users, MAX_USERS);
                        break;
                    case 4:
                        listFinesPerUser(fines, MAX_FINE, users, MAX_USERS);
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Opção inválida. Por favor, tente novamente." << endl;
                }
                break;
            case 3:
                cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                cout << "             EMPRESTIMOS" << endl;
                cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                cout << "Selecione uma opção:" << endl;
                cout << "(1) Emprestimo" << endl;
                cout << "(2) Devolução" << endl;
                cout << "(3) Listar emprestimos" << endl;
                cout << "(4) Retornar ao menu anterior" << endl;
                cout << "Digite o número correspondente a opção: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        loanBook(books, MAX_BOOKS, users, MAX_USERS, bookHistories, MAX_HISTORY, time(nullptr));
                        break;
                    case 2:
                        returnBook(books, MAX_BOOKS, users, MAX_USERS, bookHistories, MAX_HISTORY, time(nullptr), fines, MAX_FINE, finePerDay);
                        break;
                    case 3:
                        listBookHistory(bookHistories, MAX_HISTORY);
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Opção inválida. Por favor, tente novamente." << endl;
                }
                break;
            case 4:
                cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                cout << "             MULTAS" << endl;
                cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                cout << "Selecione uma opção:" << endl;
                cout << "(1) Listar multas" << endl;
                cout << "(2) Baixar multa" << endl;
                cout << "(3) Retornar ao menu anterior" << endl;
                cout << "Digite o número correspondente a opção: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        listFines(fines, MAX_FINE);
                        break;
                    case 2:
                        finesPayment(fines, MAX_FINE);
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Opção inválida. Por favor, tente novamente." << endl;
                }
                break;
            case 5:
                statistics(bookHistories, MAX_HISTORY);
                break;
            case 6:
                cout << "Programa finalizado com sucesso." << endl;
                return 0;
            default:
                cout << "Opção inválida. Por favor, tente novamente." << endl;
        };
    }

    return 0;
}