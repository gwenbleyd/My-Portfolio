// Написать функцию, принимающую на вход произвольное целочисленное значение и возвращающую строку, содержащую его представление в
// двоичной системе исчисления.

#include <iostream>

using namespace std;

void numberAsBinary(char * result, unsigned int number){
  static int i;
  i = 0;
  if (number != 1) {
    numberAsBinary(result, number/2);
  }
  result[i] = (number %2) + '0';
  i++;
}

int main() {
  unsigned int number;
  char *result = new char[11];
  cout<<"Введите число: "<<endl;
  cin>>number;
  numberAsBinary(result, number);
  cout<<"Двоичное число: "<<result<<endl;
  delete [] result;
  return 0;
}
