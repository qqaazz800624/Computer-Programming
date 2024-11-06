#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 50
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

Contact phonebook[MAX_CONTACTS];
int contact_count = 0;

// Function prototypes
void addContact();
void listContacts();
void saveToFile();
void loadFromFile();
void resetContacts();

int main() {
    char command;

    while (1) {
        scanf(" %c", &command);

        switch (command) {
            case 'i':
                addContact();
                break;
            case 'l':
                listContacts();
                break;
            case 's':
                saveToFile();
                break;
            case 'o':
                loadFromFile();
                break;
            case 'c':
                resetContacts();
                break;
            case 'q':
                return 0;
        }
    }
    return 0;
}

void addContact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Phonebook is full.\n");
        return;
    }

    Contact new_contact;
    scanf("%s", new_contact.name);
    scanf("%s", new_contact.phone);
    scanf("%s", new_contact.email);

    phonebook[contact_count++] = new_contact;
}


void listContacts() {
    if (contact_count == 0) {
        printf("No data.\n");
        return;
    }
    int i;

    for (i = 0; i < contact_count; i++) {
        printf("#%d\n", i + 1);
        printf("Name: %s\n", phonebook[i].name);
        printf("Phone: %s\n", phonebook[i].phone);
        printf("Email: %s\n", phonebook[i].email);
    }
}


void saveToFile() {
    char filename[100];
    int i;
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", contact_count);
    for (i = 0; i < contact_count; i++) {
        fprintf(file, "%s\t%s\t%s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
    }

    fclose(file);
}

void loadFromFile() {
    char filename[100];
    scanf("%s", filename);
    int i;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return;
    }

    resetContacts(); 

    fscanf(file, "%d", &contact_count);
    for (i = 0; i < contact_count; i++) {
        fscanf(file, "%s %s %s", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
    }

    fclose(file);
}

void resetContacts() {
    contact_count = 0;
}
