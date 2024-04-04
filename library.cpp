#include <iostream>
#include "library.hpp"
#include <string>
#include <time.h>

using namespace std;

void registerBooks(Book books[], int bookSize){

    cout << "-----------------------------------" << endl;
    cout << "Adicionando um novo livro." << endl;
    cout << "-----------------------------------" << endl;

    int id, year, available;
    string title, author;

    cout << "Código de Identificação: ";
    cin >> id;
    cout << "Titulo: ";
    cin >> title;
    cout << "Autor: ";
    cin >> author;
    cout << "Ano de Lançamento: ";
    cin >> year;
    cout << "Unidades disponiveis: ";
    cin >> available;
    Book book;
    book.id = id;
    book.title = title;
    book.author = author;
    book.year = year;
    book.available = available;
    cout << "Livro cadastrado com sucesso." << endl;

    // Encontrar a primeira posição livre no array
    for(int i = 0; i < bookSize; i++){
        if(books[i].title.empty()){
            books[i] = book;
            break;
        }
    }

}

void listBooks(Book books[], int bookSize){
    cout << "-----------------------------------" << endl;
    cout << "Catalogo de Livros" << endl;
    cout << "-----------------------------------" << endl;
    for(int i = 0; i < bookSize; i++){
        if (!books[i].title.empty() && !books[i].author.empty() && books[i].year != 0) {
            cout << "Informações do Livro (" << i+1 << ")" << endl;
            cout << "Id: " << books[i].id << endl;
            cout << "Titulo: " << books[i].title << endl;
            cout << "Autor: " << books[i].author << endl;
            cout << "Ano de Lançamento: " << books[i].year << endl;
            if(books[i].available > 0){
                cout << "Unidades disponiveis: " << books[i].available << endl;
            } else {
                cout << "Todas as unidades locadas";
            }
            cout << "===================================" << endl;
        }
    }
}

Book findBookTitle(Book books[], int bookSize, string title) {
    cout << "Buscando por livro com o título (" << title << ")..." << endl;
    for(int i = 0; i<bookSize; i++) {
        if(books[i].title == title) {
            return books[i];
        }
    }
    throw runtime_error("Livro não encontrado");
};

Book findBookAuthor(Book books[], int bookSize, string author){
    cout << "Buscando por livro com o autor (" << author << ")...";
    for(int i=0; i<bookSize; i++){
        if(books[i].author == author){
            return books[i];
        }
    }
    throw runtime_error("Livro não encontrado");
};

Book findBookYear(Book books[], int bookSize, int year){
    cout << "Buscando por livro lançados no ano (" << year << ")...";
    for(int i=0; i<bookSize; i++){
        if(books[i].year == year){
            return books[i];
        }
    }
    throw runtime_error("Livro não encontrado");
};

void registerUser(User users[], int userSize){
    cout << "Adicionando um novo usuário. Preencha as informações na sequencia que forem solicitadas." << endl;
    int id;
    string name;
    cout << "Matricula: ";
    cin >> id;
    cout << "Nome: ";
    cin >> name;
    User user;
    user.id = id;
    user.name = name;

    // Encontrar a primeira posição livre no array
    for(int i = 0; i < userSize; i++){
        if(users[i].name.empty()){
            users[i] = user;
            break;
        }
    }
}

void listUsers(User users[], int userSize){
    cout << "-----------------------------------" << endl;
    cout << "Listagem de usuários" << endl;
    cout << "-----------------------------------" << endl;
    for(int i = 0; i < userSize; i++){
        if(!users[i].name.empty()){
            cout << "Informações do Usuário (" << i+1 << ")" << endl;
            cout << "Código: " << users[i].id << endl;
            cout << "Nome: " << users[i].name << endl;
            cout << endl; // Adicionando um espaço entre os usuários
        }
    }
}

void loanBook(Book books[], int bookSize, User users[], int userSize, BookHistory bookHistories[], int historySize, time_t currentDate){
    cout << "Emprestimo de Livro" << endl;
    int bookId, userId;
    cout << "Informe o código de identificação do livro: " << endl;
    cin >> bookId;
    cout << "Informe o código de identificação do usuário: " << endl;
    cin >> userId;

    bool bookValid = false;
    int bookPosition;
    bool userValid = false;
    int userPosition;

    for(int i=0; i<bookSize; i++){
        if(books[i].id == bookId){
            bookValid = true;
            bookPosition = i;
            break;
        }
    }

    for(int i=0; i<userSize; i++){
        if(users[i].id == userId){
            userValid = true;
            userPosition = i;
            break;
        }
    }

    if(bookValid == false){
        cout << "Livro não encontrado." << endl;
        return;
    }

    if(userValid == false){
        cout << "Usuário não encontrado." << endl;
        return;
    }

    // Atualizar unidades disponiveis
    books[bookPosition].available = books[bookPosition].available - 1;

    time_t returnDate;
    cout << "Digite a data de retorno prevista (DD MM AAAA): ";
    int day, month, year;
    cin >> day >> month >> year;

    tm dueDate = {0};
    dueDate.tm_year = year - 1900;
    dueDate.tm_mon = month - 1;
    dueDate.tm_mday = day;
    returnDate = mktime(&dueDate);

    for (int i = 0; i < historySize; i++) {
        if (bookHistories[i].book.title.empty()) {
            bookHistories[i].book = books[bookPosition];
            bookHistories[i].renter = users[userPosition];
            bookHistories[i].loanDate = currentDate;
            bookHistories[i].returnDate = returnDate;
            bookHistories[i].returned = false;
            break;
        }
    }

    cout << "Livro emprestado com sucesso para o usuário " << users[userPosition].name << ". Data de devolução: " << ctime(&returnDate) << endl;
}

float calculateFine(time_t currentDate, time_t returnDate) {

    const int secondsInDay = 60 * 60 * 24;
    const float finePerDay = 1.50;

    int daysLate = (currentDate - returnDate) / secondsInDay;

    if (daysLate <= 0) {
        return 0.0;
    }

    return daysLate * finePerDay;
}

void returnBook(Book books[], int bookSize, User users[], int userSize, BookHistory bookHistories[], int historySize, time_t currentDate) {
    int bookId, userId;
    cout << "Informe o código de identificação do livro: " << endl;
    cin >> bookId;
    cout << "Informe o código de identificação do usuário: " << endl;
    cin >> userId;

    bool found = false;

    for(int i=0; i<historySize; i++){
        if(bookHistories[i].renter.id == userId && bookHistories[i].book.id == bookId && bookHistories[i].returned == false ){
            bookHistories[i].returned = true;
            bookHistories[i].devolutionDate = currentDate;

            for(int j=0; j<bookSize; j++){
                if(books[j].id == bookId){
                    books[j].available = books[j].available + 1;
                    break;
                }
            }

            float fine = calculateFine(currentDate, bookHistories[i].returnDate);

            cout << currentDate << endl;
            cout << bookHistories[i].returnDate << endl;

            if(fine > 0.0){
                cout << "Usuário possui uma multa de R$ " << fine << " a pagar, por atraso." << endl;
                Fine fine;
                fine.user = users[bookId];
                fine.rent = bookHistories[i];
                fine.value = calculateFine(currentDate, bookHistories[i].returnDate);
            } else {
                cout << "Você não tem multas pendentes." << endl;
            }

            found = true; // Indica que o registro correspondente foi encontrado
        }
    }

    if(!found) {
        cout << "Não foi possível encontrar um registro de empréstimo correspondente para este livro e usuário." << endl;
    }
}

User findBookPerUser(BookHistory bookHistories[], int historySize, string user){
    cout << "Buscando por livro emprestado pelo usuário (" << user << ")..." << endl;
    bool found = false;
    for(int i=0; i<historySize; i++){
        if(bookHistories[i].renter.name == user && bookHistories[i].returned == false){
            return bookHistories[i].renter;
            found = true;
        }

        if(!found){
            throw runtime_error("Nenhum livro encontrado para este usuário.");
        }
    }
}