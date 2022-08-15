#include <iostream>
#include <cstdio>
#include "poison.h"

int main()
{
  using namespace std;
  
  cout << "Hello World!";
  char str[100];
  cout << "Enter a string: ";
  gets(str); // cannot compile because `gets` is block in "poison.h"
  cout << "You entered: " << str;
  return 0;
}
