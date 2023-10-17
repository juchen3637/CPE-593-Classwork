#include <iostream>
using namespace std;

int main() { 
  int A[] = {15, 10, 25, 30}; 
  cout << A << endl; // Gives address
  cout << &A[0] << endl; // Gives address
  cout << *A << endl; // Gives value of pointer
  cout << A[0] << endl; // Gives value of pointer
}
