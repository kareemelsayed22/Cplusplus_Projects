// El Sayed Kareem 21G Assignment 10 
#include<iostream>
#include<vector>
using namespace std;
int main(){
   vector<int> t[3]; 
   int n, candidate,to, from, move=0;
    cout<<"Please enter any number of rings to move: ";
    cin>>n;
    cout<<endl;
    //intitialize the 3 towers
        for(int k=n+1;k>=1;k--)
          t[0].push_back(k);
          t[1].push_back(n+1);
          t[2].push_back(n+1);
          // initialize towers and candidate
          
          if(n%2==0)
          {
             from=0 ;
             to=2 ;
             candidate=1 ;          
          }
          else
          {
            from=0;
            to=1;
            candidate=1;
          }
          
          
         while( t[1].size()<n+1){ //rings to transfer to tower B = t[1]
                      
    cout<<"move number "<<++move<<": Transfer ring "<<candidate<<" from tower "<<  char(from+65)<<" to tower "<<char(to+65)<<endl;
             //move the disks around
            // the top of the “from” tower to the “to” tower
           //Remove the ring
            t[from].pop_back();
            t[to].push_back(candidate);
          //get next “from tower” It’s not the most recent “to” – so which is it?
            int A1, A2, x[5]={2,0,1,2,0}; 
                for(int i=1;i<4;i++)
                  {  if(to==x[i])
                    {  A1= x[i-1];
                       A2= x[i+1];        
                           }
                      }// A1 and A2, "from"
                      
                      if(t[A1].back() < t[A2].back() )
                          from=A1;
                      else
                          from=A2;
                                  
                    for(int i=1;i<4;i++)
                      {  if(n%2!=0){
                            if(from==x[i])
                            {    if(t[from].back() < t[x[i+1]].back()  )     
                                 to=x[i+1]   ;
                              else
                                 to= x[i-1]   ;
                                          
                            }
                           } 
                           else {
                           if(from==x[i])
                           {  if(t[from].back() < t[x[i-1]].back()  )     
                                 to=x[i-1]   ;
                              else
                                 to= x[i+1]   ;
                                          
                            }     
                         }//ends 
                      }//else finds "to"
       
                  
                  candidate= t[from].back() ; 
              }
          
          
          return 0;
}