#include <iostream>
#include <cmath>
using namespace std;


bool okay(int q[], int c) {
   for(int i =0; i < c; i++) //each i from 0 to c-1
      if (q[i] == q[c] || abs(c-i) == abs(q[c]-q[i]))
          //bc theres a queen on row, we cant put another on this row, we need to go to next row loop
         return false;
   return true;
}
void print(int q[]) {
   static int sol_num = 0;
   cout << "Solution # " << ++sol_num << ": ";
  for(int i = 0; i < 8; i++) //for loop to match array with board
    cout << q[i]; //current array showing which column has queen (1)
     cout << "\n";
}
int main() {
   int q[8] = {}; //array initializes to 0
   int c = 0; //first row first col

    while (c >= 0) {
      c++;
      if(c == 8){ //if we pass last column (7 is last) then print
         print(q);
         c--; //backtrack
      }
     
      else
        q[c] = -1; //else move to one before the first row (restarts)
     
        while (c >= 0) {
         q[c]++; //move to the next row
         if(q[c] == 8) c--; //if we reach last column (or pass col 7), then it backtracks
         else if(okay(q, c)) //else ok method is called  to see if the queen in column c (true or false)
             //tru = restarts loop
          break;
      }
   }
   return 0;
}
