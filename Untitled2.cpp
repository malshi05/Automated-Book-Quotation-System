#include <iostream>

#include <fstream>

#include <string>

#include <cstdlib>

#include <iomanip>


using namespace std;


const int MAX_USERS = 100; // Maximum number of users

const int MAX_BOOKS = 100; // Maximum number of books


struct User {

    string username;

    string password;

};


struct Book {

    int bookID;

    string bookName;

    string authorName;

    int noOfBooks;

};


class UserManagement {

private:

    User users[MAX_USERS];

    int numUsers;


public:

    UserManagement(); // Constructor to initialize the user array

    void registerUser();

    bool loginUser();

    void forgotPassword();

    bool userAuthentication();

};


UserManagement::UserManagement() {

    numUsers = 0;

}


void UserManagement::registerUser() {

    if (numUsers >= MAX_USERS) {

        cout << "Maximum number of users reached.\n";

        return;

    }


    cout << "\n\n\t\t\t\tUser Registration";

    cout << "\n\nEnter Username: ";

    cin >> users[numUsers].username;


    // Check if the username already exists

    for (int i = 0; i < numUsers; ++i) {

        if (users[i].username == users[numUsers].username) {

            cout << "\nUsername already exists. Please choose a different one.\n";

            return;

        }

    }


    cout << "Enter Password: ";

    cin >> users[numUsers].password;


    cout << "\nUser registration successful!\n";

    numUsers++;

}


bool UserManagement::loginUser() {

    cout << "\n\n\t\t\t\tUser Login";

    cout << "\n\nEnter Username: ";

    string inputUsername;

    cin >> inputUsername;


    cout << "Enter Password: ";

    string inputPassword;

    cin >> inputPassword;


    for (int i = 0; i < numUsers; ++i) {

        if (users[i].username == inputUsername && users[i].password == inputPassword) {

            cout << "\n.*.*.*.*..Login successful!..*.*.*.*\n";

            return true;

        }

    }


    cout << "\nLogin failed. Invalid username or password.\n";

    return false;

}


void UserManagement::forgotPassword() {

    cout << "\n\n\t\t\t\tForgot Password";

    cout << "\n\nEnter Username: ";

    string inputUsername;

    cin >> inputUsername;


    for (int i = 0; i < numUsers; ++i) {

        if (users[i].username == inputUsername) {

            cout << "Enter New Password: ";

            cin >> users[i].password;

            cout << "\nPassword reset successful!\n";

            return;

        }

    }


    cout << "\nUsername not found.\n";

}


bool UserManagement::userAuthentication() {

    int choice;

    do {

        cout << "\n\n\t\t\t\tUser registration Nethra Book Shop Kandy";

        cout << "\n\n1. Register User";

        cout << "\n2. Login";

        cout << "\n3. Forgot Password";

        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";

        cin >> choice;


        switch (choice) {

            case 1:

                registerUser();

                break;

            case 2:

                if (loginUser()) {

                    // Successfully logged in, return true

                    return true;

                }

                break;

            case 3:

                forgotPassword();

                break;

            case 4:

                cout << "\nExiting authentication system.\n";

                return false;

            default:

                cout << "\nInvalid choice. Please try again.\n";

        }


        system("pause");

        system("cls");

    } while (choice != 4);


    return false;

}


class BookShop {

private:

    Book books[MAX_BOOKS];

    int numBooks;


public:

    BookShop(); // Constructor to initialize the book arrays

    void displayMenu();

    void addBook();

    void displayBooks();

    void checkBook();

    void updateBook();

    void deleteBook();

    void getQuotation();

    void aboutBookShop();

    void displayHelp();

};


BookShop::BookShop() {

    numBooks = 0;

}


void BookShop::displayMenu() {

    cout << "\n\nWelcome to Nethra Book Shop Kandy";

    cout << "\n\nPress 1 to ADD BOOK";

    cout << "\nPress 2 to DISPLAY BOOKS";

    cout << "\nPress 3 to CHECK PARTICULAR BOOK";

    cout << "\nPress 4 to UPDATE BOOK";

    cout << "\nPress 5 to DELETE BOOK";

    cout << "\nPress 6 to GET QUOTATION";

    cout << "\nPress 7 for ABOUT NETHRA BOOK SHOP KANDY";

    cout << "\nPress 8 for HELP";

    cout << "\nPress 9 to EXIT\n";

}


void BookShop::addBook() {

    if (numBooks >= MAX_BOOKS) {

        cout << "Maximum number of books reached.\n";

        return;

    }


    cout << "\n\n\t\t\t\tADD BOOK";

    cout << "\n\nEnter Book ID: ";

    cin >> books[numBooks].bookID;


    // Check if the book ID already exists

    for (int i = 0; i < numBooks; ++i) {

        if (books[i].bookID == books[numBooks].bookID) {

            cout << "\nBook with ID " << books[numBooks].bookID << " already exists. Please enter a different ID.\n";

            return;

        }

    }


    cout << "Enter Book Name: ";

    cin.ignore(); // to consume the newline character left by previous input

    getline(cin, books[numBooks].bookName);


    cout << "Enter Author Name: ";

    getline(cin, books[numBooks].authorName);


    cout << "Enter No. of Books: ";

    cin >> books[numBooks].noOfBooks;


    cout << "\n\n.*.*.*.*..You have Successfully added a book..*.*.*.*.\n---------------------------------------------------------------------\n";

    numBooks++;

}


void BookShop::displayBooks() {

    cout << "\n\n\t\t\t\t\t\t\t\tAll BOOKS";

    cout << "\n\nBook ID\t\tBook\t\tAuthor\t\tNo. of Books\n\n";


    for (int i = 0; i < numBooks; ++i) {

        cout << books[i].bookID << "\t\t\t" << books[i].bookName << "\t\t\t" << books[i].authorName << "\t\t\t\t" << books[i].noOfBooks << "\n\n";

    }

    cout << "-------------------------------------------------------------";

    system("pause");

}


void BookShop::checkBook() {

    int checkID;

    cout << "\n\n\t\t\t\tCheck Particular Book";

    cout << "\n\nEnter Book ID to check: ";

    cin >> checkID;


    for (int i = 0; i < numBooks; ++i) {

        if (checkID == books[i].bookID) {

            system("cls");

            cout << "\n\n\t\t\t\tCheck Particular Book";

            cout << "\n\nBook ID : " << books[i].bookID;

            cout << "\nName : " << books[i].bookName;

            cout << "\nAuthor : " << books[i].authorName;

            cout << "\nNo. of Books : " << books[i].noOfBooks << endl << endl;

            return;

        }

    }


    cout << "\n\nBook ID Not Found...";

    system("pause");

}


void BookShop::updateBook() {

    int updateID;

    cout << "\n\n\t\t\t\tUpdate Book Record";

    cout << "\n\nEnter Book ID to update: ";

    cin >> updateID;


    for (int i = 0; i < numBooks; ++i) {

        if (updateID == books[i].bookID) {

            cout << "Enter new Book Name: ";

            cin.ignore(); // to consume the newline character left by previous input

            getline(cin, books[i].bookName);


            cout << "Enter new Author Name: ";

            getline(cin, books[i].authorName);


            cout << "Enter new No. of Books: ";

            cin >> books[i].noOfBooks;


            cout << "\n\n.*.*.*.*..Your Book is Updated Successfully.*.*.*.*..\n----------------------------------------------------------------\n";

            return;

        }

    }


    cout << "\n\nBook ID Not Found...";

}


void BookShop::deleteBook() {

    int deleteID;

    cout << "\n\n\t\t\t\tDelete a Book";

    cout << "\n\nEnter Book ID to delete: ";

    cin >> deleteID;


    for (int i = 0; i < numBooks; ++i) {

        if (deleteID == books[i].bookID) {

            for (int j = i; j < numBooks - 1; ++j) {

                books[j] = books[j + 1];

            }

            numBooks--;

            cout << "\n\n.*.*.*.*..Your Book is Deleted Successfully.*.*.*.*..\n-----------------------------------------------\n";

            return;

        }

    }


    cout << "\n\nBook ID Not Found...";

}


void BookShop::getQuotation() {

    int checkID;

    cout << "\n\n\t\t\t\tGet Quotation";

    cout << "\n\nEnter Book ID for Quotation: ";

    cin >> checkID;


    for (int i = 0; i < numBooks; ++i) {

        if (checkID == books[i].bookID) {

            system("cls");

            cout << "\n\n\t\t\t\tQuotation";

            cout << "\n\nBook ID : " << books[i].bookID;

            cout << "\nBook Name : " << books[i].bookName;

            cout << "\nAuthor Name : " << books[i].authorName;

            cout << "\nNo. of Books : " << books[i].noOfBooks;

            

            double price, discount;

            cout << "\nEnter Price per Book: LKR";

            cin >> price;

            cout << "Enter Discount (%): ";

            cin >> discount;


            double totalPrice = books[i].noOfBooks * price * (1 - discount / 100.0);


            cout << fixed << setprecision(2);

            cout << "\nTotal Price after Discount: LKR" << totalPrice << endl << endl;

            cout << "...Your quotation is ready to print...\n";

            cout << "*.*.*.*.*.Thank You.*.*.*.*.*.*";

            return;

        }

    }


    cout << "\n\nBook ID Not Found...";

    system("pause");

}


void BookShop::aboutBookShop() {

    system("cls");

    cout << "\n\n\t\t\t\tAbout Nethra Book Shop Kandy";

    cout << "\n\nWelcome to Nethra Book Shop, your go-to place for a wide range of books!";

    cout << "\nWe offer a diverse collection of books from various genres and authors.";

    cout << "\nExplore our collection, add books to your reading list, and enjoy the world of literature.";

    cout << "\nThank you for choosing Nethra Book Shop Kandy for your reading needs! Contact us - 077-1212121 email - nethrabookshop@gmail.com";

    cout << "\n\n\t\t\t\tHappy Reading!";

    system("pause");

}


void BookShop::displayHelp() {

    system("cls");

    cout << "\n\n\t\t\t\tHelp - Nethra Book Shop Kandy";

    cout << "\n\nThis software allows you to manage a bookstore with the following options:";

    cout << "\n\n1. ADD BOOK: Add a new book to the bookstore inventory.";

    cout << "\n2. DISPLAY BOOKS: View all books currently available in the bookstore.";

    cout << "\n3. CHECK PARTICULAR BOOK: Check details of a specific book by entering its ID.";

    cout << "\n4. UPDATE BOOK: Update details of an existing book by entering its ID.";

    cout << "\n5. DELETE BOOK: Delete a book from the bookstore inventory by entering its ID.";

    cout << "\n6. GET QUOTATION: Calculate the total price for a certain quantity of books with a discount.";

    cout << "\n7. ABOUT NETHRA BOOK SHOP KANDY: Learn more about the bookstore.";

    cout << "\n8. HELP: Display this help menu.";

    cout << "\n9. EXIT: Exit the program.";

    cout << "\n\nPress any key to return to the main menu...\n";

    system("pause");

}


int main() {

    UserManagement user;

    BookShop bookShop;


    if (user.userAuthentication()) {

        // Successfully authenticated user, proceed to the bookstore

        int choice;


        do {

            system("cls");

            bookShop.displayMenu();

            cout << "\nEnter your choice : ";

            cin >> choice;


            switch (choice) {

                case 1:

                    bookShop.addBook();

                    break;

                case 2:

                    bookShop.displayBooks();

                    break;

                case 3:

                    bookShop.checkBook();

                    break;

                case 4:

                    bookShop.updateBook();

                    break;

                case 5:

                    bookShop.deleteBook();

                    break;

                case 6:

                    bookShop.getQuotation();

                    break;

                case 7:

                    bookShop.aboutBookShop();

                    break;

               case 8:

                    bookShop.displayHelp(); // Display help menu

                    break;

                case 9:

                    cout << "\n.*.*.*.*..Exiting program. Goodbye! Have a Nice Day.*.*.*.*..\n";

                  

                    break;

                default:

                    cout << "\nInvalid choice. Please try again.\n";

            }


            system("pause");

        } while (choice != 9);

    }


    return 0;

}
