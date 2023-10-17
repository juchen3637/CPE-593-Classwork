#include <iostream>
#include <string>

using namespace std;

int main() {
  int a = 0;
  int b = 0;
  string character = "";
  bool temp = true;

while (temp == true) {
  if (a <=15 & a >= 1 & a % 2 == 1) {
    temp = false;
  } else {
    cout << "Please enter a odd integer between 1 and 15" << endl;
    cin >> a;
  }
}

temp = true;

while (temp == true) {
  if (b <= 17 & b >= 3 & b > a & b % 2 == 1) {
    temp = false;
  } else {
    cout << "Please enter a odd integer between 3 and 17 and is larger than the "
            "previous integer"
         << endl;
    cin >> b;
  }
}
  cout << "Please enter a character to generate the trapezoid" << endl;
  cin >> character;

  int height = (b - a) / 2;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < height - i; j++) {
      cout << " ";
    }
    for (int j = 0; j < a + 2 * i; j++) {
      cout << character;
    }
    cout << endl;
  }

  for (int i = 0; i < b; i++) {
    cout << character;
  }
}