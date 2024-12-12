#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define MAX_CONTACTS 50

class Contact {
    public:
        string name;
        string phone;
        string email;

        Contact(){
            name = "";
            phone = "";
            email = "";
        }

        Contact(string name, string phone, string email){
            this->name = name;
            this->phone = phone;
            this->email = email;
        }
};

class Phonebook{
    private:
        vector<Contact> contacts;

    public:
        void addContact(){
            if (contacts.size() >= MAX_CONTACTS){
                cout << "Phonebook is full." << endl;
                return;
            }

            string name, phone, email;
            cin >> name >> phone >> email;
            contacts.push_back(Contact(name, phone, email));
        } 

        void listContacts(){
            if (contacts.empty()){
                cout << "No data." << endl;
                return;
            }

            size_t i;
            for (i=0; i<contacts.size(); i++){
                cout << "#" << i+1 << endl;
                cout << "Name: " << contacts[i].name << endl;
                cout << "Phone: " << contacts[i].phone << endl;
                cout << "Email: " << contacts[i].email << endl;
            }
        }

        void saveToFile(){
            string filename;
            cin >> filename;

            ofstream file(filename.c_str());
            if (!file){
                cout << "Failed to open file for writing." << endl;
                return;
            }

            size_t i;
            file << contacts.size() << endl;
            for (i=0; i<contacts.size(); i++){
                file << contacts[i].name << "\t" << contacts[i].phone << "\t" << contacts[i].email << endl;
            }
            file.close();
        }

        void resetContacts(){
            contacts.clear();
        }

        void loadFromFile(){
            string filename;
            cin >> filename;

            ifstream file(filename.c_str());
            if (!file){
                cout << "Failed to open file for reading." << endl;
                return;
            }

            resetContacts();

            size_t count; 
            file >> count;
            file.ignore();
            size_t i;

            for (i=0; i<count; i++){
                string name, phone, email;
                file >> name >> phone >> email;
                contacts.push_back(Contact(name, phone, email));
            }

            file.close();
        }
};

int main() {
    Phonebook phonebook;
    char command;
    while (1){
        cin >> command;
        switch (command){
            case 'i':
                phonebook.addContact();
                break;
            case 'l':
                phonebook.listContacts();
                break;
            case 's':
                phonebook.saveToFile();
                break;
            case 'c':
                phonebook.resetContacts();
                break;
            case 'o':
                phonebook.loadFromFile();
                break;
            case 'q':
                return 0;
        }
    }
    
    return 0;
}
