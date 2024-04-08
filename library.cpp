#include <iostream>
#include "library.hpp"
#include <string>
#include <time.h>

using namespace std;

// Função de retorno ao menu, a fim de permitir que o usuário tenha um tempo de leitura.
void menuReturn(){
    char menu;
    while(true){
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
    cout << asctime(timeinfo);
}

// Função para registro de livro.
void registerBooks(Book books[], int bookSize){
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "      ADICIONAR LIVRO" << endl;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    int id, year, available;
    string title, author;
    cout << "Titulo: ";
    cin.ignore();
    getline(cin, title);
    cout << "Autor: ";
    cin.ignore();
    getline(cin, author);
    cout << "Ano de Lançamento: ";
    cin >> year;
    cout << "Unidades disponiveis: ";
    cin >> available;
    Book book;
    for(int i=0; i<bookSize; i++){
        if(!books[i].title.empty()){
            id = i + 2;
        }
    }
    book.id = id;
    book.title = title;
    book.author = author;
    book.year = year;
    book.available = available;
    cout << "Livro cadastrado com sucesso.\nCódigo de identificação do livro: " << id << endl;

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
            cout << "Informações do Livro (" << books[i].id << ")" << endl;
            cout << "Titulo: " << books[i].title << endl;
            cout << "Autor: " << books[i].author << endl;
            cout << "Ano de Lançamento: " << books[i].year << endl;
            cout << "Unidades disponiveis: ";
            if(books[i].available > 0){
                cout << books[i].available << endl;
            } else {
                cout << "Indisponivel" << endl;
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
    cin.ignore();
    getline(cin, title);
    cout << "Buscando por livros com o título " << title << "..." << endl;
    bool found = false;
    for(int i = 0; i<bookSize; i++) {
        if(books[i].title == title) {
            found = true;
            cout << "Informações do Livro (" << i+1 << ")" << endl;
            cout << "Id: " << books[i].id << endl;
            cout << "Titulo: " << books[i].title << endl;
            cout << "Autor: " << books[i].author << endl;
            cout << "Ano de Lançamento: " << books[i].year << endl;
            cout << "Unidades disponiveis: ";
            if(books[i].available > 0){
                cout << books[i].available << endl;
            } else {
                cout << "Indisponivel" << endl;
            }
        }
    }

    if(!found){
        cout << "Sem resultados para sua busca." << endl;
    }

    menuReturn();
};

// Função para buscar livros por autor.
void findBookAuthor(Book books[], int bookSize) {
    string author;
    cout << "Digite o nome do autor: ";
    cin.ignore();
    getline(cin, author);
    cout << "Buscando por livros do autor " << author << "..." << endl;
    bool found = false;
    for(int i = 0; i<bookSize; i++) {
        if(books[i].author == author) {
            found = true;
            cout << "Informações do Livro (" << books[i].id << ")" << endl;
            cout << "Titulo: " << books[i].title << endl;
            cout << "Autor: " << books[i].author << endl;
            cout << "Ano de Lançamento: " << books[i].year << endl;
            cout << "Unidades disponiveis: ";
            if(books[i].available > 0){
                cout << books[i].available << endl;
            } else {
                cout << "Indisponivel" << endl;
            }
        }
    }

    if(!found){
        cout << "Sem resultados para sua busca." << endl;
    }

    menuReturn();
};

// Função para buscar livros por ano.
void findBookYear(Book books[], int bookSize){
    int year;
    cout << "Digite o ano de lançamento: ";
    cin >> year;
    cout << "Buscando por livros lançados no ano " << year << "..." << endl;
    bool found = false;
    for(int i = 0; i<bookSize; i++) {
        if(books[i].year == year) {
            found = true;
            cout << "Informações do Livro (" << books[i].id << ")" << endl;
            cout << "Titulo: " << books[i].title << endl;
            cout << "Autor: " << books[i].author << endl;
            cout << "Ano de Lançamento: " << books[i].year << endl;
            cout << "Unidades disponiveis: ";
            if(books[i].available > 0){
                cout << books[i].available << endl;
            } else {
                cout << "Indisponivel" << endl;
            }
        }
    }

    if(!found){
        cout << "Sem resultados para sua busca." << endl;
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
    
    cout << "Nome: ";
    cin.ignore();
    getline(cin, name);
    
    bool nameInUse;
    
    do {
        nameInUse = false;
        for(int i=0; i <userSize; i++){
            if(users[i].name == name){
                nameInUse = true;
                cout << "Nome de usuário em uso." << endl;
                cout << "Escolha outro nome de usuário: ";
                cin >> name;
                break;
            }
        }
    } while(nameInUse);
    
    User user;
    
    for(int i=0; i<userSize; i++){
        if(!users[i].name.empty()){
            id = i + 2;
        }
    }
    
    user.id = id;
    user.name = name;

    for(int i = 0; i < userSize; i++){
        if(users[i].name.empty()){
            users[i] = user;
            break;
        }
    }

    cout << "Usuário cadastrado com sucesso.\nCódigo de identificação do usuário: " << id << endl;
    
    menuReturn();
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
    
    menuReturn();
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
    
    if(books[bookPosition].available > 0){
        
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
        
    } else {
        cout << "Todas os exemplares deste livro estão locados no momento." << endl;
    }
    
    menuReturn();
}

// Função para calcular multa.
float calculateFine(time_t currentDate, time_t returnDate, float finePerDay) {

    const int secondsInDay = 60 * 60 * 24;

    int daysLate = (currentDate - returnDate) / secondsInDay;

    if (daysLate <= 0) {
        return 0.0;
    }

    return daysLate * finePerDay;
}

// Função para devolução do livro.
void returnBook(Book books[], int bookSize, User users[], int userSize, BookHistory bookHistories[], int historySize, time_t currentDate, Fine fines[], int fineSize, float finePerDay){
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

            float fine = calculateFine(currentDate, bookHistories[i].returnDate, finePerDay);

            if(fine > 0.0){

                cout << "Gerada uma multa de R$ " << fine << " a pagar, por atraso." << endl;

                int fineId = 0;
                for(int k=0; k<fineSize; k++){
                    if(fines[k].user.name.empty()){
                        fineId = k+1;
                        break;
                    }
                }

                fines[i].id = fineId;
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

// Função para listar todos os emprestimos.
void listBookHistory(BookHistory bookHistories[], int historySize){
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "    HISTORICO DE EMPRESTIMOS" << endl;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    for(int i=0; i<historySize; i++){
        if(!bookHistories[i].book.title.empty()){
            cout << "Livro: " << bookHistories[i].book.title << endl;
            cout << "Usuário: " << bookHistories[i].renter.name << endl;
            cout << "Data de Emprestimo: ";
            printDate(bookHistories[i].loanDate);
            cout << "Prazo para Devolução: "; 
            printDate(bookHistories[i].returnDate);
            if(bookHistories[i].returned){
                cout << "Data de Devolução: ";
                printDate(bookHistories[i].devolutionDate);   
            }
            cout << "Status: ";
            if(bookHistories[i].returned){
                cout << "Devolvido" << endl;
            } else {
                cout << "Em posse do usuário" << endl;
            }
            cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        }
    }
    
    menuReturn();
}

// Função para encontrar livro por usuário.
void findBookPerUser(BookHistory bookHistories[], int historySize, User users[], int userSize){
    int id;
    cout << "Digite o ID do usuário: ";
    cin >> id;
    bool foundBook = false;
    bool foundUser = false;
    
    for(int i=0; i<userSize; i++){
        if(users[i].id == id){
            foundUser = true;
        }
    }
    
    if(!foundUser){
        cout << "Usuário não encontrado." << endl;
    } else {
            cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << "        EMPRESTIMOS POR USUÁRIO "  << endl;
            cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        for(int i=0; i<historySize; i++){
            if(bookHistories[i].renter.id == id && bookHistories[i].returned == false){
                foundBook = true;
                cout << "Livro: " << bookHistories[i].book.title << " (" << bookHistories[i].book.id << ")" << endl;
                cout << "Data de devolução: ";
                printDate(bookHistories[i].returnDate);
                cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            }

            if(!foundBook){
                cout << "Não há livros em posse do usuário." << endl;
                break;
            }
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
            cout << "Fato gerador: " << fines[i].rent.book.title << endl;
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
void listFinesPerUser(Fine fines[], int fineSize, User users[], int userSize){
    int id;
    cout << "Digite o ID do usuário: ";
    cin >> id;
    bool foundUser = false;
    
    for(int i=0; i<userSize; i++){
        if(users[i].id == id){
            foundUser = true;
            break;
        }
    }
    
    if(!foundUser){
        cout << "Usuário não encontrado." << endl;
    } else {
            cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << "        MULTAS POR USUÁRIO "  << endl;
            cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            bool found = false;
            for(int i=0; i <fineSize; i++){
                if(fines[i].user.id == id && !fines[i].user.name.empty()){
                    found = true;
                    cout << "Id. da Multa: " << fines[i].id << endl;
                    cout << "Fato gerador: " << fines[i].rent.book.title << endl;
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
                    cout << "Usuário não possui multas." << endl;
                    break;
                }
        
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
        if(fines[i].id == id && !fines[i].paid){
            fines[i].paid = true;
            found = true;
            cout << "Baixa realizada com sucesso." << endl;
            break;
        }
    }

    if(!found){
        cout << "Multa não encontrada, ou já foi paga." << endl;
    }

    menuReturn();
}

// Estatisticas
void statistics(BookHistory bookHistories[], int historySize){
    int loans = 0;
    
    for(int i=0; i<historySize; i++){
        if(!bookHistories[i].book.title.empty()){
            loans = loans + 1;
        }
    }
    
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "          ESTATISTICAS" << endl;
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Emprestimos realizados: " << loans << endl;
    
    menuReturn();
}