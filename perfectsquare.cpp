#include <iostream>
using namespace std;
int perfectsquare(int x){
  int i = 1;
  while(!(x % 100)/10 % 2 == 1 && (x % 10) % 2 == 1){ 
    i+=1;
    int x = i * i;
    return x;
  }
}
int main(){
  int x;
  cout<< perfectsquare(x)<< endl; // Replace x with a number 


return 0;
}