//Kareem EL Sayed 21G Assignment 8
#include<iostream>
#include<cmath> // needed for abs value()
using namespace std;
bool ok(int q[], int c){
   for (int i = 0; i < c; i++)
      if (q[c] == q[i] || c - i == abs(q[c] - q[i]))
         return false; // if conflict exists
   return true;
}
void print(int q[]) {

   static int solution = 0;

   int i, j, k, l;

   typedef char box[5][7];   

   box bb, wb, *board[8][8];  


   for (i=0; i<5; i++)

      for (j=0; j<7; j++) {

         bb[i][j] = ' ';

         wb[i][j] = char(219);

      }

   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},

                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},

                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},

                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},

                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };

               

   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },

                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },

                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },

                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },

                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };


   for(i=0; i<8; i++)

      for(j=0; j<8; j++)

         if((i+j)%2 == 0)

            board[i][j] = &wb;

         else

            board[i][j] = &bb;

   for(i=0; i<8; i++)

      if((i+q[i])%2 == 0)

         board[q[i]][i] = &bq;

      else

         board[q[i]][i] = &wq;



   cout << "Solution #" << ++solution << ":\n ";

   for (i=0; i<7*8; i++)

      cout << '_';

   cout << "\n";


   for (i=0; i<8; i++)      

      for (k=0; k<5; k++) {     

         cout << char(179);

         for (j=0; j<8; j++)    

            for (l=0; l<7; l++) 

              

               cout << (*board[i][j])[k][l];

         cout << char(179) << "\n";

      }
    
     cout << " ";

   for (i=0; i<7*8; i++)

      cout << char(196);

   cout << "\n\n";

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