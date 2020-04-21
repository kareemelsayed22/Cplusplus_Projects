//Kareem EL Sayed 21G Assignment 5
#include<iostream>
#include<cmath> // needed for abs value()
using namespace std;
bool ok(int q[], int c){
   for (int i = 0; i < c; i++)
      if (q[c] == q[i] || c - i == abs(q[c] - q[i]))
         return false; // if conflict exists
   return true;
}
void print(int q[]){ // prints the array
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
  for (int i=0; i < 8 ; i++){
    cout<< q[i];
  }
     cout << endl;
}

void backtrack(int q[], int &c){
  c--; // go back a column
  if (c == -1) return; 
  q[c]++; // increment in rows
  if (q[c] == 8) backtrack(q, c); // all rows tried
}

int main(){
  int q[8] = {};
  int c = 0;  
  
  while (c > -1)
  {
    if (c == 8) // solution is found 
    {
      print(q); // goto print function()
      backtrack(q, c); // goto backtrack()
    }
    else if (q[c] == 8) // row is 8
    {
      backtrack(q, c); // goto backtrack()
    }
    else if (ok(q, c)) // goto ok function()
    {
      c++; // goto next column
      if (c < 8)q[c] = 0; // make sure we are starting fresh
    }
    else // goto next row
    {
      q[c]++;
    }
    
  }
  

}