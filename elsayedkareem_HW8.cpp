//Kareem El Sayed 21G Assignment 9
#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int c){
  for(int i = 0; i < c; i++){
    if(q[i] == q[c] || abs(q[i] - q[c]) == (c - i))
    return false;
  }
  return true;
}
int nqueens(int n){
  int *q = new int[n];
  q[0] = 0;
  int c = 0, solution = 0;
  while(c >= 0){
      c++;
      if (c == n){
        solution++;
        c--;
      }
      else 
        q[c] = -1;
      
      while(c >= 0){
        ++q[c];
        if (q[c]==n){
          --c;
        }
        else if(ok(q,c))
          break;
    
      }
  }
  delete[]q;
  return solution;
}

int main(){
  int n;
  cout << "Please enter a number for n: " << endl;
  cin >> n;
  for(int i = 1; i <= n; i++){
     cout<<"There are "<< nqueens(i) << " solutions to the "<< i <<" queens problem."<<"\n";
  }
  
return 0;

  
}
  