#include <iostream>
#include <cstdlib>

using namespace std;

int steppingNumbers(int start, int end);
bool isSteppingNumber(int number);

int main(int argc, char const *argv[])
{
  int n, m;
  cout << "Start Range: ";
  cin >> n;
  cout << "End Range: ";
  cin >> m;

  int total = steppingNumbers(n, m);
  cout << "Total stepping numbers " << total << "\n";
}

// call the function isSteppingNumber for all numbers from the beginning to the end of the range
// counts the number if stepping numbers
// uses brute force
int steppingNumbers(int start, int end) {
  int count = 0;
  for (int i = start; i <= end; i++) {
    if (isSteppingNumber(i)) {
      cout << i << " ";
      count++;
    }
  }
  cout << "\n";

  return count;
}

// Check if the number is a stepping number
// Starting with the units place, we calculate the difference with the next digit. 
// If the difference is 1 then we proceed with dividing the number by 10

bool isSteppingNumber(int number) {
  int digit, next_digit, n;
  
  digit = next_digit = 0;
  n = number;

  // Units place
  digit = n % 10;
  n = n / 10;
  while(n) {
    next_digit = n % 10;
    if (abs(digit - next_digit) != 1) {
      return false;
    }
    digit = next_digit;
    n = n / 10;
  }
  return true;
}