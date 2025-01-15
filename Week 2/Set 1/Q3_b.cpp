#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Book {
public:
    int accessionNumber;
    string authorName;
    string title;
    int publicationYear;
    double cost;

    Book(int accessionNumber, string authorName, string title, int publicationYear, double cost) {
        this->accessionNumber = accessionNumber;
        this->authorName = authorName;
        this->title = title;
        this->publicationYear = publicationYear;
        this->cost = cost;
    }

    void display() {
        cout << "Accession Number: " << accessionNumber << endl;
        cout << "Author Name: " << authorName << endl;
        cout << "Title: " << title << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "Cost: " << cost << endl;
        cout << "-------------------------" << endl;
    }
};

class LibraryDatabase {
private:
    vector<Book> records;

public:
    void buildMasterTable(vector<Book> initialRecords) {
        records = initialRecords;
    }

    void listTable() {
        for (auto& record : records) {
            record.display();
        }
    }

    void insertEntry(Book newBook) {
        records.push_back(newBook);
    }

    void editEntry(int accessionNumberToEdit, Book updatedBook) {
        for (auto& record : records) {
            if (record.accessionNumber == accessionNumberToEdit) {
                record = updatedBook;
                cout << "Record updated successfully!" << endl;
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void searchRecord(int accessionNumberToSearch) {
        for (auto& record : records) {
            if (record.accessionNumber == accessionNumberToSearch) {
                record.display();
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void sortEntries() {
        sort(records.begin(), records.end(), [](Book a, Book b) {
            return a.accessionNumber < b.accessionNumber;
            });
        cout << "Records sorted by accession number!" << endl;
    }
};

int main() {
    LibraryDatabase db;

    // Sample records
    vector<Book> initialRecords = {
        Book(1001, "Author A", "Title A", 2005, 250.50),
        Book(1002, "Author B", "Title B", 2010, 300.75)
    };

    db.buildMasterTable(initialRecords);

    int choice;
    do {
        cout << "\n1. List Table" << endl;
        cout << "2. Insert New Entry" << endl;
        cout << "3. Edit Entry" << endl;
        cout << "4. Search Record" << endl;
        cout << "5. Sort Entries" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            db.listTable();
            break;
        case 2: {
            int accessionNumber, publicationYear;
            string authorName, title;
            double cost;
            cout << "Enter Accession Number: "; cin >> accessionNumber;
            cin.ignore();
            cout << "Enter Author Name: "; getline(cin, authorName);
            cout << "Enter Title: "; getline(cin, title);
            cout << "Enter Publication Year: "; cin >> publicationYear;
            cout << "Enter Cost: "; cin >> cost;

            db.insertEntry(Book(accessionNumber, authorName, title, publicationYear, cost));
            break;
        }
        case 3: {
            int accessionNumberToEdit;
            cout << "Enter the accession number of the record to edit: ";
            cin >> accessionNumberToEdit;

            int accessionNumber, publicationYear;
            string authorName, title;
            double cost;
            cout << "Enter Updated Accession Number: "; cin >> accessionNumber;
            cin.ignore();
            cout << "Enter Updated Author Name: "; getline(cin, authorName);
            cout << "Enter Updated Title: "; getline(cin, title);
            cout << "Enter Updated Publication Year: "; cin >> publicationYear;
            cout << "Enter Updated Cost: "; cin >> cost;

            db.editEntry(accessionNumberToEdit, Book(accessionNumber, authorName, title, publicationYear, cost));
            break;
        }
        case 4: {
            int accessionNumberToSearch;
            cout << "Enter the accession number of the record to search: ";
            cin >> accessionNumberToSearch;

            db.searchRecord(accessionNumberToSearch);
            break;
        }
        case 5:
            db.sortEntries();
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
