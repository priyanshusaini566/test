#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// ===================== Book Class =====================
class Book {
private:
    int bookID;
    string title;
    string author;
    string ISBN;
    bool isIssued;
    string issuedTo;
    time_t issueDate;

public:
    // Constructor
    Book() : bookID(0), title(""), author(""), ISBN(""), isIssued(false), issuedTo("") {}

    Book(int id, string t, string a, string isbn)
        : bookID(id), title(t), author(a), ISBN(isbn), isIssued(false), issuedTo("") {}

    // Getters
    int getBookID() const { return bookID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    bool getIssuedStatus() const { return isIssued; }
    string getIssuedTo() const { return issuedTo; }

    // Setters
    void setBookID(int id) { bookID = id; }
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setISBN(string isbn) { ISBN = isbn; }

    // Issue book to a member
    void issueBook(string memberName) {
        if (!isIssued) {
            isIssued = true;
            issuedTo = memberName;
            time(&issueDate);
            cout << "\nBook \"" << title << "\" issued successfully to " << memberName << "!\n";
        } else {
            cout << "\nBook \"" << title << "\" is already issued to " << issuedTo << ".\n";
        }
    }

    // Return book
    void returnBook() {
        if (isIssued) {
            cout << "\nBook \"" << title << "\" returned successfully by " << issuedTo << "!\n";
            isIssued = false;
            issuedTo = "";
            issueDate = 0;
        } else {
            cout << "\nBook \"" << title << "\" was not issued.\n";
        }
    }

    // Display book details
    void displayBook() const {
        cout << "\n+------------------------------------------+\n";
        cout << "  Book ID      : " << bookID << "\n";
        cout << "  Title        : " << title << "\n";
        cout << "  Author       : " << author << "\n";
        cout << "  ISBN         : " << ISBN << "\n";
        cout << "  Status       : " << (isIssued ? "Issued to " + issuedTo : "Available") << "\n";
        cout << "+------------------------------------------+\n";
    }
};

// ===================== Member Class =====================
class Member {
private:
    int memberID;
    string name;
    string email;
    string phone;
    vector<int> borrowedBooks;  // Stores book IDs of borrowed books
    static const int MAX_BOOKS = 5;  // Maximum books a member can borrow

public:
    // Constructor
    Member() : memberID(0), name(""), email(""), phone("") {}

    Member(int id, string n, string e, string p)
        : memberID(id), name(n), email(e), phone(p) {}

    // Getters
    int getMemberID() const { return memberID; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    vector<int> getBorrowedBooks() const { return borrowedBooks; }
    int getBorrowedCount() const { return borrowedBooks.size(); }

    // Setters
    void setMemberID(int id) { memberID = id; }
    void setName(string n) { name = n; }
    void setEmail(string e) { email = e; }
    void setPhone(string p) { phone = p; }

    // Check if member can borrow more books
    bool canBorrow() const {
        return borrowedBooks.size() < MAX_BOOKS;
    }

    // Add a borrowed book
    void addBorrowedBook(int bookID) {
        if (canBorrow()) {
            borrowedBooks.push_back(bookID);
            cout << "  Book ID " << bookID << " added to " << name << "'s borrowed list.\n";
        } else {
            cout << "\n" << name << " has reached the maximum borrowing limit (" << MAX_BOOKS << " books).\n";
        }
    }

    // Remove a returned book
    void removeBorrowedBook(int bookID) {
        for (size_t i = 0; i < borrowedBooks.size(); i++) {
            if (borrowedBooks[i] == bookID) {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                cout << "  Book ID " << bookID << " removed from " << name << "'s borrowed list.\n";
                return;
            }
        }
        cout << "  Book ID " << bookID << " was not found in " << name << "'s borrowed list.\n";
    }

    // Display member details
    void displayMember() const {
        cout << "\n+------------------------------------------+\n";
        cout << "  Member ID    : " << memberID << "\n";
        cout << "  Name         : " << name << "\n";
        cout << "  Email        : " << email << "\n";
        cout << "  Phone        : " << phone << "\n";
        cout << "  Books Borrowed: " << borrowedBooks.size() << "/" << MAX_BOOKS << "\n";
        if (!borrowedBooks.empty()) {
            cout << "  Borrowed Book IDs: ";
            for (size_t i = 0; i < borrowedBooks.size(); i++) {
                cout << borrowedBooks[i] << " ";
            }
            cout << "\n";
        }
        cout << "+------------------------------------------+\n";
    }
};

// ===================== Library Class (Inherits nothing, manages everything) =====================
class Library {
private:
    string libraryName;
    string address;
    vector<Book> books;
    vector<Member> members;
    int nextBookID;
    int nextMemberID;

public:
    // Constructor
    Library(string name, string addr)
        : libraryName(name), address(addr), nextBookID(1), nextMemberID(1) {}

    // Get library info
    string getLibraryName() const { return libraryName; }
    string getAddress() const { return address; }

    // ========== Book Management ==========

    // Add a new book
    void addBook() {
        string title, author, isbn;
        cout << "\n--- Add New Book ---\n";
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter ISBN: ";
        getline(cin, isbn);

        Book newBook(nextBookID, title, author, isbn);
        books.push_back(newBook);
        cout << "\nBook added successfully! Book ID: " << nextBookID << "\n";
        nextBookID++;
    }

    // Remove a book by ID
    void removeBook() {
        int id;
        cout << "\n--- Remove Book ---\n";
        cout << "Enter Book ID to remove: ";
        cin >> id;

        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getBookID() == id) {
                if (books[i].getIssuedStatus()) {
                    cout << "\nCannot remove book \"" << books[i].getTitle() << "\" - it is currently issued.\n";
                    return;
                }
                cout << "\nBook \"" << books[i].getTitle() << "\" removed successfully!\n";
                books.erase(books.begin() + i);
                return;
            }
        }
        cout << "\nBook with ID " << id << " not found.\n";
    }

    // Search book by ID or Title
    void searchBook() {
        int choice;
        cout << "\n--- Search Book ---\n";
        cout << "1. Search by Book ID\n";
        cout << "2. Search by Title\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].getBookID() == id) {
                    books[i].displayBook();
                    return;
                }
            }
            cout << "\nBook with ID " << id << " not found.\n";
        } else if (choice == 2) {
            string title;
            cout << "Enter Title (or part of it): ";
            cin.ignore();
            getline(cin, title);
            bool found = false;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].getTitle().find(title) != string::npos) {
                    books[i].displayBook();
                    found = true;
                }
            }
            if (!found) {
                cout << "\nNo books found with title containing \"" << title << "\".\n";
            }
        } else {
            cout << "\nInvalid choice!\n";
        }
    }

    // Display all books
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "\nNo books in the library.\n";
            return;
        }
        cout << "\n========== All Books in Library ==========\n";
        for (size_t i = 0; i < books.size(); i++) {
            books[i].displayBook();
        }
        cout << "\nTotal Books: " << books.size() << "\n";
    }

    // Display available books only
    void displayAvailableBooks() const {
        bool found = false;
        cout << "\n========== Available Books ==========\n";
        for (size_t i = 0; i < books.size(); i++) {
            if (!books[i].getIssuedStatus()) {
                books[i].displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "\nNo books available currently.\n";
        }
    }

    // ========== Member Management ==========

    // Add a new member
    void addMember() {
        string name, email, phone;
        cout << "\n--- Add New Member ---\n";
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Phone: ";
        getline(cin, phone);

        Member newMember(nextMemberID, name, email, phone);
        members.push_back(newMember);
        cout << "\nMember added successfully! Member ID: " << nextMemberID << "\n";
        nextMemberID++;
    }

    // Remove a member by ID
    void removeMember() {
        int id;
        cout << "\n--- Remove Member ---\n";
        cout << "Enter Member ID to remove: ";
        cin >> id;

        for (size_t i = 0; i < members.size(); i++) {
            if (members[i].getMemberID() == id) {
                if (members[i].getBorrowedCount() > 0) {
                    cout << "\nCannot remove member \"" << members[i].getName()
                         << "\" - they have " << members[i].getBorrowedCount()
                         << " books to return first.\n";
                    return;
                }
                cout << "\nMember \"" << members[i].getName() << "\" removed successfully!\n";
                members.erase(members.begin() + i);
                return;
            }
        }
        cout << "\nMember with ID " << id << " not found.\n";
    }

    // Search member by ID or Name
    void searchMember() {
        int choice;
        cout << "\n--- Search Member ---\n";
        cout << "1. Search by Member ID\n";
        cout << "2. Search by Name\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            cout << "Enter Member ID: ";
            cin >> id;
            for (size_t i = 0; i < members.size(); i++) {
                if (members[i].getMemberID() == id) {
                    members[i].displayMember();
                    return;
                }
            }
            cout << "\nMember with ID " << id << " not found.\n";
        } else if (choice == 2) {
            string name;
            cout << "Enter Name (or part of it): ";
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (size_t i = 0; i < members.size(); i++) {
                if (members[i].getName().find(name) != string::npos) {
                    members[i].displayMember();
                    found = true;
                }
            }
            if (!found) {
                cout << "\nNo members found with name containing \"" << name << "\".\n";
            }
        } else {
            cout << "\nInvalid choice!\n";
        }
    }

    // Display all members
    void displayAllMembers() const {
        if (members.empty()) {
            cout << "\nNo members registered.\n";
            return;
        }
        cout << "\n========== All Members ==========\n";
        for (size_t i = 0; i < members.size(); i++) {
            members[i].displayMember();
        }
        cout << "\nTotal Members: " << members.size() << "\n";
    }

    // ========== Issue/Return Operations ==========

    // Issue a book to a member
    void issueBook() {
        int bookID, memberID;
        cout << "\n--- Issue Book ---\n";
        cout << "Enter Book ID: ";
        cin >> bookID;
        cout << "Enter Member ID: ";
        cin >> memberID;

        // Find book
        Book* bookPtr = nullptr;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getBookID() == bookID) {
                bookPtr = &books[i];
                break;
            }
        }

        if (bookPtr == nullptr) {
            cout << "\nBook with ID " << bookID << " not found.\n";
            return;
        }

        if (bookPtr->getIssuedStatus()) {
            cout << "\nBook \"" << bookPtr->getTitle() << "\" is already issued.\n";
            return;
        }

        // Find member
        Member* memberPtr = nullptr;
        for (size_t i = 0; i < members.size(); i++) {
            if (members[i].getMemberID() == memberID) {
                memberPtr = &members[i];
                break;
            }
        }

        if (memberPtr == nullptr) {
            cout << "\nMember with ID " << memberID << " not found.\n";
            return;
        }

        // Check if member can borrow
        if (!memberPtr->canBorrow()) {
            cout << "\n" << memberPtr->getName() << " cannot borrow more books (limit reached).\n";
            return;
        }

        // Issue book
        bookPtr->issueBook(memberPtr->getName());
        memberPtr->addBorrowedBook(bookID);
    }

    // Return a book
    void returnBook() {
        int bookID, memberID;
        cout << "\n--- Return Book ---\n";
        cout << "Enter Book ID: ";
        cin >> bookID;
        cout << "Enter Member ID: ";
        cin >> memberID;

        // Find book
        Book* bookPtr = nullptr;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getBookID() == bookID) {
                bookPtr = &books[i];
                break;
            }
        }

        if (bookPtr == nullptr) {
            cout << "\nBook with ID " << bookID << " not found.\n";
            return;
        }

        if (!bookPtr->getIssuedStatus()) {
            cout << "\nBook \"" << bookPtr->getTitle() << "\" was not issued.\n";
            return;
        }

        // Find member
        Member* memberPtr = nullptr;
        for (size_t i = 0; i < members.size(); i++) {
            if (members[i].getMemberID() == memberID) {
                memberPtr = &members[i];
                break;
            }
        }

        if (memberPtr == nullptr) {
            cout << "\nMember with ID " << memberID << " not found.\n";
            return;
        }

        // Verify the book was issued to this member
        vector<int> borrowed = memberPtr->getBorrowedBooks();
        bool found = false;
        for (size_t i = 0; i < borrowed.size(); i++) {
            if (borrowed[i] == bookID) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nBook ID " << bookID << " was not issued to Member ID " << memberID << ".\n";
            return;
        }

        // Return book
        bookPtr->returnBook();
        memberPtr->removeBorrowedBook(bookID);
    }

    // ========== Display Library Info ==========
    void displayLibraryInfo() const {
        cout << "\n============================================\n";
        cout << "        " << libraryName << "\n";
        cout << "        " << address << "\n";
        cout << "============================================\n";
        cout << "  Total Books      : " << books.size() << "\n";
        cout << "  Total Members    : " << members.size() << "\n";
        int issuedCount = 0;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getIssuedStatus()) issuedCount++;
        }
        cout << "  Books Issued     : " << issuedCount << "\n";
        cout << "  Books Available  : " << books.size() - issuedCount << "\n";
        cout << "============================================\n";
    }
};

// ===================== Main Menu =====================
void displayMainMenu() {
    cout << "\n============================================\n";
    cout << "         LIBRARY MANAGEMENT SYSTEM          \n";
    cout << "============================================\n";
    cout << "  1.  Add Book\n";
    cout << "  2.  Remove Book\n";
    cout << "  3.  Search Book\n";
    cout << "  4.  Display All Books\n";
    cout << "  5.  Display Available Books\n";
    cout << "  6.  Add Member\n";
    cout << "  7.  Remove Member\n";
    cout << "  8.  Search Member\n";
    cout << "  9.  Display All Members\n";
    cout << "  10. Issue Book\n";
    cout << "  11. Return Book\n";
    cout << "  12. Display Library Info\n";
    cout << "  13. Exit\n";
    cout << "============================================\n";
    cout << "  Enter your choice: ";
}

// ===================== Main Function =====================
int main() {
    Library library("City Central Library", "123 Knowledge Street, Booktown");

    cout << "\n============================================\n";
    cout << "   WELCOME TO THE LIBRARY MANAGEMENT SYSTEM\n";
    cout << "============================================\n";

    // Add some default data for demonstration
    Book defaultBook1(1, "The Great Gatsby", "F. Scott Fitzgerald", "978-0-7432-7356-5");
    Book defaultBook2(2, "To Kill a Mockingbird", "Harper Lee", "978-0-06-112008-4");
    Book defaultBook3(3, "1984", "George Orwell", "978-0-452-28423-4");
    Book defaultBook4(4, "Pride and Prejudice", "Jane Austen", "978-0-14-143951-8");
    Book defaultBook5(5, "The Catcher in the Rye", "J.D. Salinger", "978-0-316-76948-0");

    Member defaultMember1(1, "Alice Johnson", "alice@email.com", "555-0101");
    Member defaultMember2(2, "Bob Smith", "bob@email.com", "555-0102");
    Member defaultMember3(3, "Charlie Brown", "charlie@email.com", "555-0103");

    // Note: For simplicity, we're not adding defaults to library vectors here
    // since the Library class manages its own next IDs.
    // In a full implementation, we'd handle this differently.

    int choice;
    do {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.removeBook();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.displayAllBooks();
                break;
            case 5:
                library.displayAvailableBooks();
                break;
            case 6:
                library.addMember();
                break;
            case 7:
                library.removeMember();
                break;
            case 8:
                library.searchMember();
                break;
            case 9:
                library.displayAllMembers();
                break;
            case 10:
                library.issueBook();
                break;
            case 11:
                library.returnBook();
                break;
            case 12:
                library.displayLibraryInfo();
                break;
            case 13:
                cout << "\nThank you for using the Library Management System!\n";
                cout << "Goodbye!\n\n";
                break;
            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 13.\n";
        }
    } while (choice != 13);

    return 0;
}

