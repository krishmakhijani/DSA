#include <iostream>
#include <queue>
using namespace std;

int NumberOfCarries(int num1, int num2) {
  int carry = 0;
  int count = 0;
  while (num1 > 0 || num2 > 0) {
    int digit1 = num1 % 10;
    int digit2 = num2 % 10;
    int sum = digit1 + digit2 + carry;
    carry = sum / 10;
    if (carry > 0) {
      count++;
    }
    num1 /= 10;
    num2 /= 10;

}

  return count;
}

int main() {
  int num1, num2;
  cout << "Num 1: ";
  cin >> num1;
  cout << "Num 2: ";
  cin >> num2;

  int carries = NumberOfCarries(num1, num2);

  cout << " " << carries << endl;

  return 0;
}
