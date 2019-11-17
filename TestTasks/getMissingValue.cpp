// Определить недостающее число в неупорядоченной последовательности целых чисел.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMissingValue(const int *array, int maxValue){
  int sumAllNumber;
  int sumNumber = 0;
  sumAllNumber = (maxValue*(maxValue +1)/2);
  for(int i = 0; i < maxValue - 1; i++){
    sumNumber += array[i];
  }
  return sumAllNumber - sumNumber;
}

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
  int lastNumber;
  cout<<"Введите максимальное число в последовательности: ";
  cin>>maxValue;
  int *resultArray = new int[maxValue];
  generateRandomArray(resultArray, maxValue);
  for(int i=0; i<maxValue;i++){
    cout<<resultArray[i]<<" ";
  }
  cout<<endl;
  lastNumber = getMissingValue(resultArray, maxValue);
  cout<<"Послднее число в последовательности: "<<lastNumber<<endl;
  return 0;
}
