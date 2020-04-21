//Kareem El Sayed 21G Assignment 3
#include <iostream>
using namespace std; 
void print(int b[8][8]){ //prints board
  for(int i = 0; i < 8; i++){
       for(int j = 0; j < 8; j++){
         cout<< b[i][j];
       }
       cout<< endl;
     }
     cout<< endl;
}
int main(){
  int b[8][8] = {0}; //8x8 2-D Array full of 0's
  int r, c = 0; 
  b[0][0] = 1; //place 1 = queen on the upper left
  
  nextCol:  //column label
     c++;
     if(c == 8) //passed the last column 
     goto print;
     r = -1; //moves back a row
     
nextRow:  //row label
     r++; //move to the next row
     if(r == 8) 
     goto backtrack;
     
     for (int i = 0; i < c; ++i)
      if (b[r][i] == 1) //row test
         goto nextRow;
   for (int i = 1; (r - i) >= 0 && (c - i) >= 0; ++i) 
      if (b[r-i][c-i] == 1) //up diagonal test
         goto nextRow;
   for (int i = 1; (r + i) < 8 && (c - i) >= 0; ++i)
      if (b[r+i][c-i] == 1) //down diagonal test
         goto nextRow;
   b[r][c] = 1;
   goto nextCol;

backtrack:  //backtrack label
   --c;  //goes back one column
   if (c == -1) //solution found
      return 0;
   for (r = 0; b[r][c] != 1; ++r);
   //starts at first row, keeps going till queen is not found
   b[r][c] = 0; //removes the queen
   goto nextRow;

print:  //print label
      static int numSolutions = 0;
      cout << "Solution #" << ++numSolutions << ":\n";
      print(b);
     goto backtrack;
}