#include <iostream>
#include "library.hpp"
#include <string>
#include <time.h>

using namespace std;

// Função de retorno ao menu, a fim de permitir que o usuário tenha um tempo de leitura.

void menuReturn(){
    char menu;
    bool left = false;
    while(!left){
        cout << "Digite 'Y' para voltar ao menu: ";
        cin >> menu;
        if(menu == 'y' || menu == 'Y') {
            break;
        }
    }
}

// Função para converter tempo de segundo para String

void printDate(time_t dateInSeconds) {
    struct tm * timeinfo;
    timeinfo = localtime(&dateInSeconds);
    cout << "Data: " << asctime(timeinfo);
}

// Função para registro de livro.

void registerBooks(Book books[], int bookSize){

    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "      ADICIONAR LIVRO" << endl;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;

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

    menuReturn();
}

// Função para listagem de livros.

void listBooks(Book books[], int bookSize){
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "       CATALOGO DE LIVROS" << endl;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    for(int i = 0; i < bookSize; i++){
        if (!books[i].title.empty() && !books[i].author.empty() && books[i].year != 0) {
            cout << "Informações do Livro (" << i+1 << ")" << endl;
            cout << "Id: " << books[i].id << endl;
            cout << "Titulo: " << books[i].title << endl;
            cout << "Autor: " << books[i].author << endl;
            cout << "Ano de Lançamento: " << books[i].year << endl;
            cout << "Unidades disponiveis: ";
            if(books[i].available > 0){
                cout << books[i].available << endl;
            } else {
                cout << "Indisponivel";
            }
            cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        }
    }

    menuReturn();
}

// Função para buscar livros por titulo.

void findBookTitle(Book books[], int bookSize) {
    string title;
    cout << "Digite o titulo: ";
    cin >> title;
    cout << "Buscando por livro com o título (" << title << ")..." << endl;
    bool found = false;
    for(int i = 0; i<bookSize; i++) {
        if(books[i].title == title) {
            found = true;
            cout << "Informações do Livro (" << i+1 << ")" << endl;
            cout << "Id: " << books[i].id << endl;
            cout << "Titulo: " << books[i].title << endl;
            cout << "Autor: " << books[i].author << endl;
            cout << "Ano de Lançamento: " << books[i].year << endl;
            cout << "Unidades disponiveis: " << endl;
            if(books[i].available > 0){
                cout << books[i].available << endl;
            } else {
                cout << "Indisponivel" << endl;
            }
        }
    }

    if(!found){
        cout << "Sem resultados para sua busca.";
    }

    menuReturn();
};

// Função para buscar livros por autor.

void findBookAuthor(Book books[], int bookSize) {
    string author;
    cout << "Digite o nome do autor: ";
    cin >> author;
    cout << "Buscando por livro com o autor (" << author << ")..." << endl;
    bool found = false;
    for(int i = 0; i<bookSize; i++) {
        if(books[i].author == author) {
            found = true;
            cout << "Informações do Livro (" << i+1 << ")" << endl;
            cout << "Id: " << books[i].id << endl;
            cout << "Titulo: " << books[i].title << endl;
            cout << "Autor: " << books[i].author << endl;
            cout << "Ano de Lançamento: " << books[i].year << endl;
            cout << "Unidades disponiveis: " << endl;
            if(books[i].available > 0){
                cout << books[i].available << endl;
            } else {
                cout << "Indisponivel" << endl;
            }
        }
    }

    if(!found){
        cout << "Sem resultados para sua busca.";
    }

    menuReturn();
};

// Função para buscar livros por ano.

void findBookYear(Book books[], int bookSize){
    int year;
    cout << "Digite o ano de lançamento: ";
    cin >> year;
    cout << "Buscando por livro lançados do ano (" << year << ")..." << endl;
    bool found = false;
    for(int i = 0; i<bookSize; i++) {
        if(books[i].year == year) {
            found = true;
            cout << "Informações do Livro (" << i+1 << ")" << endl;
            cout << "Id: " << books[i].id << endl;
            cout << "Titulo: " << books[i].title << endl;
            cout << "Autor: " << books[i].author << endl;
            cout << "Ano de Lançamento: " << books[i].year << endl;
            cout << "Unidades disponiveis: " << endl;
            if(books[i].available > 0){
                cout << books[i].available << endl;
            } else {
                cout << "Indisponivel" << endl;
            }
        }
    }

    if(!found){
        cout << "Sem resultados para sua busca.";
    }

    menuReturn();
};

// Função para registro de usuários.

void registerUser(User users[], int userSize){

    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "      ADICIONAR USUÁRIO" << endl;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;

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

// Função para listar todos os usuários.

void listUsers(User users[], int userSize){
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "      LISTAGEM DE USUÁRIOS" << endl;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    for(int i = 0; i < userSize; i++){
        if(!users[i].name.empty()){
            cout << "Informações do Usuário (" << i+1 << ")" << endl;
            cout << "Código: " << users[i].id << endl;
            cout << "Nome: " << users[i].name << endl;
            cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        }
    }
}

// Função para emprestimo de livros.

void loanBook(Book books[], int bookSize, User users[], int userSize, BookHistory bookHistories[], int historySize, time_t currentDate){
    cout << "Emprestimo de Livro" << endl;
    int bookId, userId;
    cout << "Informe o código de identificação do livro: " ;
    cin >> bookId;
    cout << "Informe o código de identificação do usuário: ";
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

    cout << "Livro emprestado com sucesso para o usuário " << users[userPosition].name << endl;

    menuReturn();
}

// Função para calcular multa.

float calculateFine(time_t currentDate, time_t returnDate) {

    const int secondsInDay = 60 * 60 * 24;
    const float finePerDay = 1.50;

    int daysLate = (currentDate - returnDate) / secondsInDay;

    if (daysLate <= 0) {
        return 0.0;
    }

    return daysLate * finePerDay;
}

// Função para devolução do livro.

void returnBook(Book books[], int bookSize, User users[], int userSize, BookHistory bookHistories[], int historySize, time_t currentDate, Fine fines[], int fineSize){
    int bookId, userId;
    cout << "Informe o código de identificação do livro: ";
    cin >> bookId;
    cout << "Informe o código de identificação do usuário: ";
    cin >> userId;

    bool found = false;
    int userPosition = -1; // Declarar userPosition aqui

    for(int i=0; i<userSize; i++){
        if(users[i].id == userId){
            userPosition = i;
            break;
        }
    }

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

            if(fine > 0.0){
                cout << "Gerada uma multa de R$ " << fine << " a pagar, por atraso." << endl;
                fines[i].user = users[userPosition]; // Corrigir a atribuição de usuário
                fines[i].rent = bookHistories[i];
                fines[i].value = fine; // Corrigir a atribuição do valor da multa
                fines[i].paid = false;
            } else {
                cout << "Devolução realizada sem multas." << endl;
            }

            found = true; // Indica que o registro correspondente foi encontrado
        }
    }

    if(!found) {
        cout << "Não foi possível encontrar um registro de empréstimo correspondente para este livro e usuário." << endl;
    }

    menuReturn();
}

// Função para encontrar livro por usuário.

void findBookPerUser(BookHistory bookHistories[], int historySize){
    string user;
    cout << "Digite o nome de usuário: ";
    cin >> user;
    cout << "Livros atualmente emprestados para o usuário " << user << ":" << endl;
    bool found = false;
    for(int i=0; i<historySize; i++){
        if(bookHistories[i].renter.name == user && bookHistories[i].returned == false){
            found = true;
            cout << "Livro: " << bookHistories[i].book.title << " (" << bookHistories[i].book.id << ")" << endl;
            cout << "Data de devolução: ";
            printDate(bookHistories[i].returnDate);
            cout << endl;
        }

        if(!found){
            cout << "Não há livros em posse do usuário.";
        }
    }

    menuReturn();
}

// Função para listar todas as multas.

void listFines(Fine fines[], int fineSize){
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "      LISTAGEM DE MULTAS" << endl;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    for(int i=0; i<fineSize; i++){
        if(!fines[i].user.name.empty()){
            cout << "Id. da Multa: " << fines[i].id << endl;
            cout << "Usuário Autuado: " << fines[i].user.name << endl;
            cout << "Fator gerador: " << fines[i].rent.book.title << endl;
            cout << "Valor: R$" << fines[i].value << endl;
            cout << "Status: ";
            if(fines[i].paid){
                cout << "Pago" << endl;
            } else {
                cout << "Em aberto" << endl;
            }
            cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        }
    }

    menuReturn();
}

// Função para listar as multas por usuários

void listFinesPerUser(Fine fines[], int fineSize){
    string user;
    cout << "Digite o nome de usuário: ";
    cin >> user;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "      MULTAS DE " << user << endl;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    bool found = false;
    for(int i=0; i <fineSize; i++){
        if(fines[i].user.name == user && !fines[i].user.name.empty()){
            found = true;
            cout << "Id. da Multa: " << fines[i].id << endl;
            cout << "Fator gerador: " << fines[i].rent.book.title << endl;
            cout << "Valor: R$" << fines[i].value << endl;
            cout << "Status: ";
            if(fines[i].paid){
                cout << "Pago" << endl;
            } else {
                cout << "Em aberto" << endl;
            }
            cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        }

        if(!found){
            cout << "Usuário não possui multas.";
        }

    }

    menuReturn();
}

// Função para dar baixa em multas.

void finesPayment(Fine fines[], int fineSize){
    int id;
    cout << "Digite o id da multa: ";
    cin >> id;
    bool found = false;
    for(int i = 0; i<fineSize; i++){
        if(fines[i].id == id && !fines[i].paid){ // Corrigir a comparação com o id e com o status de pagamento
            fines[i].paid = true;
            found = true;
            cout << "Baixa realizada com sucesso." << endl;
            break; // Adicionar um break para sair do loop após encontrar a multa
        }
    }

    if(!found){
        cout << "Multa não encontrada, ou já foi paga." << endl;
    }

    menuReturn();
}
