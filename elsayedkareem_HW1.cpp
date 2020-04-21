
//Kareem El Sayed  21G Assignment Two 
#include<iostream>
using namespace std;
bool equivalent(int a[], int b[], int n){
  
  for(int offset = 0; offset < n; offset++){  // Starts by shifting the arrays
    if(a[0] == b[offset]){
    for(int i = 0; i < n; i++){   // Goes through both arrays 
       for(int j = 0; j < n; j++){  // Goes through both arrays again
       int tally = 0;  // Starts a count
       if(a[i % n] != b[(offset + i) % n])
       break;
       tally++; // Increment the count 
        
        
      if(i == n - 1 || tally == n){   
        return true;
       }
     
      }
     }
    }
  }
    return false;
 
}
int main(){
 cout<< boolalpha;
 
 int a1[5] = {1,2,3,4,5};
 int a2[5] = {3,4,5,1,2};
 
 cout<< equivalent(a1, a2, 5)<< endl; // true
 
 int b1[3] = {1,2,3};
 int b2[3] = {2,2,3};
 
 cout<< equivalent(b1, b2, 3)<< endl; // false
 
 int c1[4] = {2,3,4,1};
 int c2[4] = {1,4,3,2};
 
 cout<< equivalent(c1, c2, 4)<< endl; // false 
 
 int d1[4] = {3,2,3,1};
 int d2[4] = {3,1,3,2};
 
 cout<< equivalent(d1, d2, 4)<< endl; // true
 
 int e1[5] = {1,1,1,1,2};
 int e2[5] = {1,1,1,2,1};
 
 cout<< equivalent(e1,e2,4)<< endl; // true
 
 return 0;
}
