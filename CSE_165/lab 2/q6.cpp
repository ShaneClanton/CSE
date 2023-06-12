#include <bitset>
#include <iostream>

using namespace std;

int getBit(int n, int index) {
  return (n >> index) & 1;
}

int setBit(int n, int index) {
  return n | (1 << index);
}

int clearBit(int n, int index) {
  return n & ~(1 << index);
}

int main() {
  int n, index;
  cout << "Please enter a decimal number and a postion index: ";
  cin >> n >> index;
  cout << endl;
  cout << "Original binary representation: " << bitset<8>(n) << '\n';
  cout << "Bit at position " << index << ": " << getBit(n, index) << '\n';
  cout << "Number after setting bit at position " << index << ": " << bitset<8>(setBit(n, index)) << '\n';
  cout << "Number after clearing bit at position " << index << ": " << bitset<8>(clearBit(n, index)) << '\n';
  return 0;
}
