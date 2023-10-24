#include <cstring>
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
string data[MAX_SIZE];
int front = 0;
int rear = -1;

bool isFull() {
  if (rear == MAX_SIZE - 1) {
    return true;
  }
  return false;
}
bool isEmpty() {
  if (front > rear) {
    return true;
  }
  return false;
}

void enqueue(string customerName) {
  if (rear == MAX_SIZE - 1) {
    cout << "Sorry we are full, you cannot book a ticket right now" << endl;
  } else {
    rear++;
    data[rear] = customerName;
    cout << "Reservation successful!" << endl;
  }
}

void dequeue() {
  if (front > rear) {
    cout << "Sorry we have no reservations to cancel" << endl;
  } else {
    front++;
    cout << "Reservation cancelled!" << endl;
  }
}

void display() {
  if (front > rear) {
    cout << "Sorry we have no reservations to display" << endl;
  }
  for (int i = front; i <= rear; i++) {
    cout << data[i] << endl;
  }
}

void cancelReservation(string customerName) {
  if (front > rear) {
    cout << "Sorry we have no reservations to cancel" << endl;
  }
  for (int i = front; i <= rear; i++) {
    if (data[i] == customerName) {
      for (int j = i; j < rear; j++) {
        data[j] = data[j + 1];
      }
      rear--;
      cout << "Reservation cancelled for " << customerName << endl;
    } else {
      cout << "Sorry we could not find your reservation" << endl;
    }
  }
}

bool checkAvailability(string customerName) {
  if (front > rear) {
    cout << "Sorry we have no reservations to check" << endl;
  }
  for (int i = front; i <= rear; i++) {
    if (data[i] == customerName) {
      cout << "Reservation found for " << customerName << endl;
      return true;
    }
  }
  cout << "Reservation not found for " << customerName << endl;
  return false;
}

void clearQueue() {
  front = 0;
  rear = -1;
  cout << "All reservations cleared!" << endl;
}

int getQueueSize() { return rear - front + 1; }

void peekFront() { cout << "Customer at front: " << data[front] << endl; }

void peekRear() { cout << "Customer at rear: " << data[rear] << endl; }

int main() {
  int choice;
  string customerName;
  cout << "Welcome to the Movie Theater Ticket Booking System!" << endl;
  do {
    cout << "\n1. Book a ticket\n2. Cancel a reservation\n3. Display "
            "reservations\n ";
    cout << "4. Check availability\n5. Clear all reservations\n6. Get queue "
            "size\n ";
    cout << "7. Peek at front\n8. Peek at rear\n9. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter customer name: ";
        cin >> customerName;
        enqueue(customerName);
        break;
      case 2:
        cout << "Enter customer name to cancel: ";
        cin >> customerName;
        cancelReservation(customerName);
        break;
      case 3:
        display();
        break;
      case 4:
        cout << "Enter customer name to check availability: ";
        cin >> customerName;
        checkAvailability(customerName);
        break;
      case 5:
        clearQueue();
        break;
      case 6:
        cout << "Queue size: " << getQueueSize() << " reservations." << endl;
        break;
      case 7:
        peekFront();
        break;
      case 8:
        peekRear();
        break;
      case 9:
        cout << "Exiting the program. Thank you!" << endl;
        break;
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 9);
  return 0;
}