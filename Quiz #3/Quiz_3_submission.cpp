#include <cstring>
#include <iostream>

using namespace std;

// Structure for a single contact
struct Contact {
  char firstName[50];
  char lastName[50];
  char phoneNumber[15];
  char email[100];
  struct Contact* next;
};

// Function to create a new contact and add it to the linked list, returning the
// new head
Contact* createAndAddContact(Contact* head) {
  if (head == NULL) {
    head = new Contact;
    cout << "Enter first name: ";
    cin >> head->firstName;
    cout << "Enter last name: ";
    cin >> head->lastName;
    cout << "Enter phone number: ";
    cin >> head->phoneNumber;
    cout << "Enter email: ";
    cin >> head->email;
    head->next = NULL;
    return head;
  }

  else {
    Contact* temp = new Contact;
    Contact* temp2 = new Contact;
    cout << "Enter first name: ";
    cin >> temp->firstName;
    cout << "Enter last name: ";
    cin >> temp->lastName;
    cout << "Enter phone number: ";
    cin >> temp->phoneNumber;
    cout << "Enter email: ";
    cin >> temp->email;
    temp->next = NULL;
    temp2 = head;
    head = temp;
    head->next = temp2;
    return head;
  }
}

// Function to display all contacts
void displayContacts(Contact* head) {
  Contact* temp = new Contact;
  temp = head;
  if (head == NULL) {
    cout << "The linked list is empty" << endl;
  }

  else {
    while (temp != NULL) {
      cout << "Contact: " << temp->firstName << " " << temp->lastName << " "
           << temp->phoneNumber << " " << temp->email << endl;
      temp = temp->next;
    }
  }
}

// Function to search for a contact by name
void searchContact(Contact* head, char* name) {
  Contact* temp = new Contact;
  temp = head;
  bool found = false;
  while (temp != NULL) {
    if (strcmp(temp->lastName, name) == 0 ||
        strcmp(temp->firstName, name) == 0) {
      cout << "Contact: " << temp->firstName << " " << temp->lastName << " "
           << temp->phoneNumber << " " << temp->email << endl;
      found = true;
    }
    temp = temp->next;
  }
  if (found == false) {
    cout << "Contact not found" << endl;
  }
}

int main() {
  Contact* contacts = nullptr;
  int choice;
  char searchName[50];

  while (true) {
    cout << "\nContact Management System\n";
    cout << "1. Add Contact\n";
    cout << "2. Display Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        contacts = createAndAddContact(contacts);
        break;
      case 2:
        displayContacts(contacts);
        break;
      case 3:
        cout << "Enter the name to search for a contact: ";
        cin >> searchName;
        searchContact(contacts, searchName);
        break;
      case 4:
        return 0;
      default:
        cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}