#include<iostream>
using namespace std;

int main(){
  char arr[] = {'b','f','a','z','m','g'};
  int count = 1; // Size of the array used
  char temp;
   
  for(int j = 0;j < count;++j){
    for(int i = 1;i < 6;++i){
      // if the previous character is of greater value, swap the two
      if(arr[i-1] > arr[i]){
        temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
      }
    }
    count--;
  }

  // Print the assorted array
  for(int i=0;i<6;i++){
    cout<<arr[i]<<"\t";
  }
  
  cout << endl;
  
  return 0;
}