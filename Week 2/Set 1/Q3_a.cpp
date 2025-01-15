#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class PersonalInfo {
public:
    string name;
    string dob;
    string bloodGroup;
    float height;
    float weight;
    string address;
    string phoneNumber;

    PersonalInfo(string name, string dob, string bloodGroup, float height, float weight, string address, string phoneNumber) {
        this->name = name;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->height = height;
        this->weight = weight;
        this->address = address;
        this->phoneNumber = phoneNumber;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "DOB: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "-------------------------" << endl;
    }
};

class Database {
private:
    vector<PersonalInfo> records;

public:
    void buildMasterTable(vector<PersonalInfo> initialRecords) {
        records = initialRecords;
    }

    void listTable() {
        for (auto& record : records) {
            record.display();
        }
    }

    void insertEntry(PersonalInfo newRecord) {
        records.push_back(newRecord);
    }

    void editEntry(string nameToEdit, PersonalInfo updatedRecord) {
        for (auto& record : records) {
            if (record.name == nameToEdit) {
                record = updatedRecord;
                cout << "Record updated successfully!" << endl;
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void searchRecord(string nameToSearch) {
        for (auto& record : records) {
            if (record.name == nameToSearch) {
                record.display();
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void sortEntries() {
        sort(records.begin(), records.end(), [](PersonalInfo a, PersonalInfo b) {
            return a.name < b.name;
            });
        cout << "Records sorted by name!" << endl;
    }
};

int main() {
    Database db;

    // Sample records
    vector<PersonalInfo> initialRecords = {
        PersonalInfo("Alice", "1995-06-15", "A+", 5.5, 55.0, "123 Street, City", "1234567890"),
        PersonalInfo("Bob", "1992-03-22", "B+", 5.8, 70.0, "456 Avenue, Town", "9876543210")
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
            string name, dob, bloodGroup, address, phoneNumber;
            float height, weight;
            cout << "Enter Name: "; cin.ignore(); getline(cin, name);
            cout << "Enter DOB: "; getline(cin, dob);
            cout << "Enter Blood Group: "; getline(cin, bloodGroup);
            cout << "Enter Height: "; cin >> height;
            cout << "Enter Weight: "; cin >> weight;
            cin.ignore();
            cout << "Enter Address: "; getline(cin, address);
            cout << "Enter Phone Number: "; getline(cin, phoneNumber);

            db.insertEntry(PersonalInfo(name, dob, bloodGroup, height, weight, address, phoneNumber));
            break;
        }
        case 3: {
            string nameToEdit;
            cout << "Enter the name of the record to edit: ";
            cin.ignore();
            getline(cin, nameToEdit);

            string name, dob, bloodGroup, address, phoneNumber;
            float height, weight;
            cout << "Enter Updated Name: "; getline(cin, name);
            cout << "Enter Updated DOB: "; getline(cin, dob);
            cout << "Enter Updated Blood Group: "; getline(cin, bloodGroup);
            cout << "Enter Updated Height: "; cin >> height;
            cout << "Enter Updated Weight: "; cin >> weight;
            cin.ignore();
            cout << "Enter Updated Address: "; getline(cin, address);
            cout << "Enter Updated Phone Number: "; getline(cin, phoneNumber);

            db.editEntry(nameToEdit, PersonalInfo(name, dob, bloodGroup, height, weight, address, phoneNumber));
            break;
        }
        case 4: {
            string nameToSearch;
            cout << "Enter the name of the record to search: ";
            cin.ignore();
            getline(cin, nameToSearch);

            db.searchRecord(nameToSearch);
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
