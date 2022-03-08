#include <iostream>
#include <cmath>
using namespace std;

bool okay(int q[], int c) {
    static int a[8][5] = { //helper array that tells us which part of the array must be compared to our number
        {-1},
        {0,-1},
        {1,-1},
        {0,1,2,-1},
        {1,2,3,-1},
        {2,4,-1},
        {0,3,4,-1},
        {3,4,5,6,-1},
    };
    
    for(int i = 0; i < c; i++) //check if the number in position c has already been used
      if(q[c] == q[i])
      return false;
    
    for(int i = 0; a[c][i] != -1; i++)///check if the number in position c has already been used
      if(abs(q[c] - q[a[c][i]]) == 1)// consecutive numbers must be one apart
      return false;
    
    return true;
}

void print(int q[], int cap) { //this will print each answer
    // array in the cross begins  top to bottom
    //then left to right, beginning of left = zero and next box, at the top left=one
    static int sol = 0;
    cout << " Solution number: " << ++sol << endl;
    cout << " " << q[1] << q[4] << endl;
    cout << q[0] << q[2] << q[5] << q[7] << endl;
    cout << " " << q[3] << q[6] << endl;
    return;
}

int main() {
    // main method of 1d queen
    int q[8] = {};
    int c = 0;
    q[c]=1; //#1 is position 0
    
   while (c >= 0) { // End the loop if you backtrack from the first column
      c++; //Move to the next position c
      if(c == 8){ //you have passed the last position, print and backtrack
         print(q, c); //prints solution
         c--;//backtracking
      }
      else //else move num to 0, which is one num smaller than 1
        q[c] = -1;
      while (c >= 0) {
         q[c]++;
         if(q[c] == 8)
            c--; // backtrack to previous position
         else if(okay(q, c)) // else if number is ok break, go to next position c
          break;
      }
   }
   return 0;
}
