#include <iostream>
#include <cstring>

using namespace std;

struct Contact {
  char firstName[50];
  char lastName[50];
  char phoneNumber[15];
  char email[100];
};

Contact stack[100];
int top = 0;

void pushContact(Contact newContact) {
  stack[top] = newContact;
  top++;
}

void displayContacts() {
  for (int i = top - 1; i >= 0; i--) {
    cout << "Contact: " << stack[i].firstName << " " << stack[i].lastName << " "
         << stack[i].phoneNumber << " " << stack[i].email << endl;
  }
}

void searchContact(char* searchName) {
  for (int i = top - 1; i >= 0; i--) {
    if (strcmp(stack[i].firstName, searchName) == 0 ||
        strcmp(stack[i].lastName, searchName) == 0) {
      cout << "Contact: " << stack[i].firstName << " " << stack[i].lastName << " "
           << stack[i].phoneNumber << " " << stack[i].email << endl;
    }
  }
}

void popContact() { 
  if(top == 0) {
    cout << "Your contact list is empty" << endl;
  }

  else {
    cout << "Deleted contact: " << stack[top - 1].firstName << " " << stack[top - 1].lastName << " "
         << stack[top - 1].phoneNumber << " " << stack[top - 1].email << endl;
    top--;
  }
}

int main() {
  int choice;
  char searchName[50];
  Contact newContact;

  while (true) {
    cout << "\nContact Management System\n";
    cout << "1. Add Contact\n";
    cout << "2. Display Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Delete Most Recent Contact\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter first name: ";
        cin >> newContact.firstName;
        cout << "Enter last name: ";
        cin >> newContact.lastName;
        cout << "Enter phone number: ";
        cin >> newContact.phoneNumber;
        cout << "Enter email: ";
        cin >> newContact.email;
        pushContact(newContact);
        break;
      case 2:
        displayContacts();
        break;
      case 3:
        cout << "Enter the name to search for a contact: ";
        cin >> searchName;
        searchContact(searchName);
        break;
      case 4:
        popContact();
        break;
      case 5:
        return 0;
      default:
        cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}