// El Sayed Kareem, 21 G Assignment 12
// Rat class i.e. a class for rational numbers
#include <iostream>
#include <cmath>
using namespace std;

class Rat{
private:
   int n;
   int d;
   
public:
   // All Constructors
   
   // Default constructor
   Rat(){
      n=0;  // Numerator 
      d=1;  // Denomenator
   }
   
   // Constructor for 2 parameters 
   Rat(int i, int j){
      n=i;
      d=j;
   }
   
   // Conversion constructor
   Rat(int i){
      n=i;
      d=1;
   }
   
   
   int getN(){ return n;}
   int getD(){ return d;}
   
   void setN(int i){ n=i;}
   void setD(int i){ d=i;}
   
   
   Rat operator+(Rat r){
      Rat t;
      t.n = n * r.d + d * r.n;
      t.d = d * r.d;
      simplify(t);
      return t;
   }
   
   
   Rat operator-(Rat r){
      Rat t;
      t.n = n * r.d - d * r.n; //Numerator
      t.d = d * r.d; //Denominator
      simplify(t);
      return t;
   }
   
   Rat operator*(Rat r){
      Rat t;
      t.n = n * r.n; 
      t.d = d * r.d;
      simplify(t);
      return t;
   }
   
   Rat operator/(Rat r){
      Rat t;
      t.n = n * r.d;
      t.d = d * r.n;
      simplify(t);
      return t;
   }
   
   
  
   void simplify(Rat &t) {
        int theGCD = t.gcd(t.getN(), t.getD());
        t.n /= theGCD;
        t.d /= theGCD;
    }
   
   void improperFraction(Rat &t) {
        if (t.getN() > t.getD()) {
            t.n%=t.d;
        }
    }
      
   // Calculates the GCD 
   int gcd(int n, int d){
      return d == 0 ? n : gcd(d, n%d);
   }

   
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
}; 




ostream& operator<<(ostream& os, Rat r){
   
   if(r.n==r.d)
   	os<<1;
   		   
   else if(r.n%r.d == 0)
    os<<(r.n)/(r.d);  
	
   else if(r.n == 0)
   	os<<0;	 	
   	
   else if(r.n>r.d){
   	int whole;
   	int partial;
   	whole = r.n/r.d;
   	partial = r.n - (whole) * r.d;
   	os<<whole<< " " <<partial << "/" << r.d;
   }	
   
   else
   	os<<r.n<<"/"<<r.d;
      
   return os;
}


istream& operator>>(istream& is, Rat& r){
   is >> r.n >> r.d;
   return is;
}

int main() {
   Rat r1(5, 2), r2(3, 2);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   r2 = r1 * r2;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   
   return 0;
}