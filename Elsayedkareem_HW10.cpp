// El Sayed Kareem 21G Assignment 11 (Recursion)
#include<iostream>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];


int calculateCost(int i, int j) {
	
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   
   // The Cost Matrix
   static int cost[NUM_ROWS][NUM_COLS] {};
   
   
   if(cost[i][j] != 0) return cost[i][j]; // Return cost after calculations 
   
   // Check for the base case.
   if (j == 0) {
      path[i][j] = to_string(i);
      return weight[i][j];
   }

   
   int up = calculateCost((NUM_ROWS - 1 + i) % NUM_ROWS, j - 1);
   int left = calculateCost(i, j - 1);
   int down = calculateCost((i + 1) % NUM_ROWS, j - 1);
   // Recursive call used to calculate the 3 
   
   int minCost = min(min(up,left),down); 
   
  
   
    if(minCost == up){ // Shortest path == up
	  	path[i][j] = path[(i + (NUM_ROWS - 1)) % NUM_ROWS][j - 1] + to_string(i);
	}
   
   
    else if(minCost == left){  // Case left is minimum
		path[i][j] = path[i][j - 1] + to_string(i);
	}

   
    else{  // Case down is minimun
    	path[i][j] = path[(i + 1) % NUM_ROWS][j - 1] + to_string(i);
	}
   
   
   cost[i][j] = minCost + weight[i][j]; // Stores the number in the matrix after calculations
   
   return cost[i][j];
}

int main() {
   int minRow = 0;
   
  
   
   for(int i = 1; i < NUM_ROWS; i ++){
		minRow = i;
   }
   // To check    
   cout << "The length of the shortest path is " << calculateCost(minRow, NUM_COLS - 1);
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS - 1] << ".";

   return 0;
}