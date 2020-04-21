// Kareem El Sayed 21G Assignment 4
#include<iostream>
#include<cstdlib> // abs value function support
using namespace std;
void print(int q[8]){
  for(int i = 0; i < 8; i++){
    cout<< q[i];
  }
  cout<< endl;
}

int main(){
  int q[8]{0}, c = 0;
  q[c] = 0;
nextCol: 
    ++c; // advance in columns
    if(c == 8) // solutions are found from 0 to 7
      goto print; 
      q[c] = -1; // otherwise start at the top of the column 
    
nextRow: 
    ++q[c];  // advance in rows
    if(q[c] == 8) // tried all rows in current column, didnt work
      goto backtrack;
    
    for(int i = 0; i < c; i++){
      if(q[i] == q[c] || (c - i) == abs(q[c] - q[i]))
         goto nextRow; // if conflict exists
    }
      goto nextCol; // no conflict exists
      
      
backtrack: 
    --c; // goes back one column
    if(c == -1) // all possible solutions found
      return 0;
    goto nextRow;
    
print:
    static int answers = 0;
  
    cout<<"Answer #" << ++answers << ":\n";
     print(q); // prints board
    goto backtrack;
    
}