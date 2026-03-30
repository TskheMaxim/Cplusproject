#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Book {
  int bookid;
  string title;
  string author;
  bool isBorrowed;
};

struct User {
  int userid;
  vector<int> borrowedBookIDs; 
};

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

  }while (choice != 5);

  return 0;
}