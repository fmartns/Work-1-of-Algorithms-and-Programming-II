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
    User user;
    BookHistory rent;
    double value;
};

void registerBooks(Book books[], int bookSize);
void listBooks(Book books[], int bookSize);
Book findBookTitle(Book books[], int bookSize, string title);
Book findBookAuthor(Book books[], int bookSize, string author);
Book findBookYear(Book books[], int bookSize, int year);
void registerUser(User users[], int userSize);
void listUsers(User users[], int userSize);
User findUser(User users[], int userSize);
void loanBook(Book books[], int bookSize, User users[], int userSize, BookHistory bookHistories[], int historySize, time_t currentDate);
float calculateFine(time_t currentDate, time_t returnDate);
void returnBook(Book books[], int size, User users[], int userSize, BookHistory bookHistories[], int historySize, time_t currentDate);

#endif
