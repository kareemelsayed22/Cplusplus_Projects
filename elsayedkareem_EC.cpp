// El Sayed Kareem, 21 G Assignment 13
#include <cstdlib>
#include <iostream>
using namespace std;

int k, n;


bool ok(int a[], int b, int s){
    
    int r = a[b]/s, c = a[b]%s, cr, cc;

    for(int i=0; i<b; i++){ 
        cr = a[i]/s;
        cc = a[i]%s;

        
        if(abs(r-cr)==abs(c-cc)) return false;
    }

    return true;
};

void backtrack(int &bishop, int count){
    bishop--;
    if(bishop==-1){
        cout << "Number of solutions: " << count ;
        exit(1);
    }
};

int main(){
    while(true){

        
        cout << "Enter value of n: ";
        cin >> n;
        cout << "Enter value of k: ";
        cin >> k;
        if(n<0) break;

        
        int* a = new int[k];
        int count = 0, b = 0, t;
        a[b] = 0;

        while(true){ 
            while(b<k){ 
                while(a[b]<n*n){
                    if(ok(a,b,n)) break;
                    else a[b]++;
                }

                if(a[b]==n*n){
                    backtrack(b, count);
                    a[b]++;
                    continue;
                }

                else{
                    t = a[b];
                    b++;
                    a[b] = t;
                }
            }
            count++;
            backtrack(b, count);
            a[b]++;
        }
    }
    return 0;
}

