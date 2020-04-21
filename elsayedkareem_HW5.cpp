// Kareem El Sayed 21G Assignment 6
#include<iostream>
using namespace std;

bool ok(int qcross[], int c){
  static int adj[8][5] = {
    {-1}, // box0
    {0, -1}, // box1
    {0, -1}, // box2
    {0, 1, 2, -1},   // box3
    {0, 1, 3, -1},  // box4
    {1, 4, -1}, // box5
    {2, 3, 4, -1},  // box6
    {3, 4, 5, 6, -1}, // box7
  };
  
  
  for (int i = 0; i < c; i++)  // checks if number is placed
        if (qcross[i] == qcross[c]) return false;
    
    for(int i = 0; adj[c][i] != -1; i++){
      if(abs(qcross[c] - qcross[adj[c][i]]) < 2)
      return false; // adjacent box test
      
      
    
    }
    return true; 
}
void backtrack(int qcross[], int &c){
    qcross[c] = 0; // restart at 0
    c--;
    if(c < 0) return;
    qcross[c]++;
    if(qcross[c] == 8)
    backtrack(qcross, c); // repeat function
}   
void print(int qcross[]) {
		 cout << "  "<< qcross[0] << ' ' << qcross[1] << '\n'
		 << qcross[2] << ' ' << qcross[3] << ' ' << qcross[4] << ' ' << qcross[5] << "\n  "
		 << qcross[6] << ' ' << qcross[7] << endl << endl;
}
int main(){
  int qcross[8] = {0};
  qcross[0] = 0;
  int c = 0;
  int answers = 0;
  while(c >= 0)
  {
    if(c == 8)
    {
      answers++;
      print(qcross);
      backtrack(qcross, c);
      }
    else if(qcross[c] == 8) backtrack(qcross, c);
    else if(ok(qcross, c) == true) c++;
    else qcross[c]++;
    }
  cout<< answers << endl;  
}