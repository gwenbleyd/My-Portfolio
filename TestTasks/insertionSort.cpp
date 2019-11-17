// Написать функцию, принимающую в качестве параметра массив неупорядоченных целых чисел выполняющую его сортировку

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(int *resultArray, int maxValue){
  for(int i = 1; i < maxValue; i++){
    for(int j = i; j>0 && resultArray[j-1] > resultArray[j]; j--){
      int tmp = resultArray[j-1];
      resultArray[j-1] = resultArray[j];
      resultArray[j] = tmp;
    }
  }
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


int main() {
  srand(unsigned(time(0)));
  int maxValue;
  cout<<"Количество элементов: ";
  cin>>maxValue;
  int *resultArray = new int[maxValue];
  generateRandomArray(resultArray, maxValue);
  insertionSort(resultArray, maxValue);
  for(int i = 0; i < maxValue; i++){
    cout<<resultArray[i]<<" ";
  }
  return 0;
}
