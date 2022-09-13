// Testing cin and cout

#include <iostream>
using namespace std;

int main(void)
{
  int someInteger = 0;
  cin >> someInteger;

  // Now sending the value of someInteger to cmd line
  cout << "The value of someInteger is: " << someInteger << endl;
  return 0;
}

