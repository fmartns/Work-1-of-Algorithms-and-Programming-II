#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <ctime>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int year;
    int available;
};

struct User {
    int id;
    string name;
};

struct BookHistory {
    Book book;
    User renter;
    time_t loanDate;
    time_t devolutionDate;
    time_t returnDate;
    bool returned;
};

struct Fine {
    int id;
    User user;
    BookHistory rent;
    float value;
    bool paid = false;
};

// Função de retorno ao menu, a fim de permitir que o usuário tenha um tempo de leitura.
void menuReturn();

// Função para converter tempo de segundo para String
void printDate(time_t dateInSeconds);

// Função para registro de livro.
void registerBooks(Book books[], int bookSize);

// Função para listagem de livros.
void listBooks(Book books[], int bookSize);

// Função para buscar livros por titulo.
void findBookTitle(Book books[], int bookSize);

// Função para buscar livros por autor.
void findBookAuthor(Book books[], int bookSize);

// Função para buscar livros por ano.
void findBookYear(Book books[], int bookSize);

// Função para registro de usuários.
void registerUser(User users[], int userSize);

// Função para listar todos os usuários.
void listUsers(User users[], int userSize);

// Função para emprestimo de livros.
void loanBook(Book books[], int bookSize, User users[], int userSize, BookHistory bookHistories[], int historySize, time_t currentDate);

// Função para calcular multa.
float calculateFine(time_t currentDate, time_t returnDate);

// Função para devolução do livro.
void returnBook(Book books[], int size, User users[], int userSize, BookHistory bookHistories[], int historySize, time_t currentDate, Fine fines[], int fineSize);

// Função para encontrar livro por usuário.
void findBookPerUser(BookHistory bookHistories[], int historySize);

// Função para listar todas as multas.
void listFines(Fine fines[], int fineSize);

// Função para listar as multas por usuários
void listFinesPerUser(Fine fines[], int fineSize);

// Função para dar baixa em multas.
void finesPayment(Fine fines[], int fineSize);

#endif