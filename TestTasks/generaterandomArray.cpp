// Написать функцию, принимающую на вход произвольное целочисленное значение и возвращающую массив, содержащий последовательность чисел от 1 до этого значения,
// в котором каждое число последовательности находится в заведомо случайной позиции.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateRandomArray(int *resultArray, int maxValue){
  vector<int> x(maxValue);
  for(int i = 0; i< maxValue; i++){
    x[i] = i+1;
  }
  srand(unsigned(time(0)));
  random_shuffle(x.begin(), x.end());
  for(int i = 0; i< maxValue; i++){
    resultArray[i] = x[i];
  }
}

int main(){
  int maxValue;
  cout<<"Введите максимальное число в последовательности: ";
  cin>>maxValue;
  int *resultArray = new int[maxValue];
  generateRandomArray(resultArray, maxValue);
  for(int i=0; i<maxValue;i++){
    cout<<resultArray[i]<<" ";
  }
  return 0;
}
