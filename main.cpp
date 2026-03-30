#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_USERS = 50;

struct Book {
  int bookid;
  string title;
  string author;
  int year;
  bool isBorrowed;
};

struct Author {
  string name;
  int totalBooks; 
};

struct User {
  int userid;
  vector<int> borrowedBookIDs; 
};

void addbook();
void viewbooks();
void borrowbook();
void returnbook();

vector<Book> library;

int main() {
  int choice;
  do {
    cout<<endl<<"1. Add boook"
    <<endl<<"2. View Books"
    <<endl<<"3. Borrow Book"
    <<endl<<"4. Return Book"
    <<endl<<"5. Exit"
    <<endl<<"Enter your choice (1-5): ";
    cin>>choice;

    switch (choice) {
      case 1: 
        addbook();
      break;
      case 2:
        viewbooks();
      break;
      case 3:
        borrowbook();
      break;
      case 4:
        returnbook();
      break;
    }

  }while (choice != 5);
  
  cout<<"Exiting the program..."<<endl;
  

  return 0;
}



void addbook(){
  string inputline;

  if (library.size() >= MAX_BOOKS){
    cout<<"Library is full!"<<endl;
    return;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout<<"Enter the following: format: TITLE, AUTHOR, YEAR PUBLISHED: ";
  getline(cin, inputline);

  stringstream ss(inputline);
  string bookTitle, authorName, year;
  
  getline(ss, bookTitle, ',');
  getline(ss, authorName, ',');
  getline(ss, year);
  

  bookTitle.erase(0, bookTitle.find_first_not_of(" "));
  bookTitle.erase(bookTitle.find_last_not_of(" " +1 ));

  authorName.erase(0, authorName.find_first_not_of(" "));
  authorName.erase(authorName.find_last_not_of(" ") +1 );

  year.erase(0, year.find_first_not_of(" "));
  year.erase(year.find_last_not_of(" ") +1 );
  
  int yearPublished; //converts year from string to int

  try {
    yearPublished = stoi(year);
  }catch (...){
    cout<<"Invalid year input!"<<endl;
    return;
  }

  Book newBook{
    static_cast<int>(library.size() +1), bookTitle, authorName, yearPublished, false
  };
  library.push_back(newBook);

  cout<<"Book added successfully!"<<endl;
}

void viewbooks() {
    cout << "View Books not implemented yet." << endl;
}

void borrowbook() {
    cout << "Borrow Book not implemented yet." << endl;
}

void returnbook() {
    cout << "Return Book not implemented yet." << endl;
}