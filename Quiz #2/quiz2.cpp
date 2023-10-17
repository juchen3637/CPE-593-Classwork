#include <iostream>

using namespace std;

struct node {
  int data;
  struct node* link;
};

struct node* addToEmpty(struct node* head, int data) {
  node *temp = new node;
  temp->data = data;
  temp->link = NULL;
  head = temp;
  return head;
}

struct node* addAtEnd(struct node* head, int data) {
  node *temp = new node;
  temp = head;
  while (temp->link != NULL) {
    temp = temp->link;
  }
  node *temp2 = new node;
  temp2->data = data;
  temp2->link = NULL;
  temp->link = temp2;
  return head;
}

void print(struct node* head) { 
  node* temp = new node; 
  temp = head;
  // while (temp->link != NULL) {
  //   cout << temp->data << " ";
  //   temp = temp->link;
  // }
  // cout << temp->data << endl;
  if (head == NULL) {
    cout << "List is empty" << endl;
  }

  else {
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->link;
    }
  }
}

struct node* addAtHead(struct node* head, int data) { 
  node* temp = new node;
  node* temp2 = new node;
  temp->data = data;
  temp->link = NULL;
  temp2 = head;
  head = temp;
  head->link = temp2;
  return head;
}

int sizeOfList(struct node* head) {
  node* temp = new node;
  temp = head;
  int size = 0;
  while (temp != NULL) {
    size++;
    temp = temp->link;
  }
  return size;
}

struct node* addAtPosition(struct node* head, int data, int pos, int size) {

}

int main() { 
  struct node* head = NULL;
  int value;
  cout << "Enter a integer value to be added to the empty list: ";
  cin >> value;
  head = addToEmpty(head, value);
  cout << "Enter a integer value to be added to the list: ";
  cin >> value;
  head = addAtEnd(head, value);
  cout << "Enter a integer value to be added to the list: ";
  cin >> value;
  head = addAtEnd(head, value);
  cout << "Enter a integer value to be added to beginning of list: ";
  cin >> value;
  head = addAtHead(head, value);
  cout << "The elements of the list are: ";
  print(head);
  int size = sizeOfList(head);
  cout << "The size of the list is: " << size << endl;

  return 0;
}

// head = (struct node*)malloc(sizeof(struct node)); 