// Kareem El Sayed 21G Assignment 7
#include<iostream>
using namespace std;
bool ok(int q[], int c){
  int mp[3][3] = {0, 2, 1, // man prefernce 
                  0, 2, 1,
                  1, 2, 0};
  int wp[3][3] = {2, 1, 0, // woman prefernce
                  0, 1, 2,
                  2, 0, 1};
    for(int i = 0; i < c; i++){
    // q[c] = new woman, i = current man
       if(q[c] == q[i]) // new woman assigned some man 
       return false;
       }
    for(int i = 0; i < c; i++){ // loop to check prefernce 
      if(mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i])
        return false;
      if(wp[q[c]][i] < wp[q[c]][c] && mp[i][q[c]] < mp[i][q[i]])
        return false;
    }
  return true;
}  
void backtrack(int &c){
  c--;
  if(c == -1) exit(0);
}

void print(int q[]){
  static int solutions = 0;
  
  cout<<"Match # "<< ++solutions << endl <<"man\twoman"<< endl;
  
  for(int i = 0; i < 3; i++){
    cout<< i << "\t" << q[i] << endl;
    }
  cout<< endl;
}

/*
int main(){
  int q[3] = {0};
  q[0] = 0;
  int c = 0;
  while(true){
    c++;
    if(c == 3){
      print(q);
      backtrack(c);
    }
    else q[c] = -1;
    while(true){
      q[c]++;
      if(q[c] == 3)
        backtrack(c);
      else if(ok(q,c)) break;
    }
  }
  return 0;
} */

int main() {
    int q[3] = {0};
    q[0] = 0;
    int c = 1;
    
    while(c > -1){
      if(c == 3){
        print(q);
        backtrack(c);
      }
    if (q[c] == 3){
      backtrack(c);
    }
    else if(ok(q, c)){
      c++;
      if(c < 3) q[c] = 0;
    }
    else{
      q[c]++;
    }
  }
}
  
