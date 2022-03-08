#include<iostream>
#include<cmath>
using namespace std;
bool okay(int q[8][8]){ // Initialize the board to 0
    //find where the queens and runs tests
    for(int c=7;c>0;c--){
        int r=0;
        //finds queens
        while (q[r][c]!=1){
            r++;
        }
        //row test
        for(int i=1;i<=c;i++){
            if(q[r][c-i]==1)return false;
        }
        //up diagonal test
        for(int i=1;(r-i)>=0&&(c-i)>=0;i++){
            if(q[r-i][c-i]==1)return false;
        }
        //down diagonal test
        for(int i=1; (r+i)<8 && (c-i)>=0;i++){
            if(q[r+i][c-i]==1)return false;
        }
    }
    return true;
}
void print(int q[8][8]){
    static int sol_num=0;
    sol_num++;
    cout<<"solution #"<<sol_num<<":"<<endl;
    for(int r=0;r<8;r++){ //for loop to move along row
        for(int c=0;c<8;c++){ //for loop to move along col
            cout<<q[r][c] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
     int q[8][8]={0}; //array initializes to 0
        for(int i0=0;i0<8;i0++){
            for(int i1=0;i1<8;i1++){
                for(int i2=0;i2<8;i2++){
                    for(int i3=0;i3<8;i3++){
                        for(int i4=0;i4<8;i4++){
                            for(int i5=0;i5<8;i5++){
                                for(int i6=0;i6<8;i6++){
                                     for(int i7=0;i7<8;i7++){
                                             q[i0][0]=1;
                                             q[i1][1]=1;
                                             q[i2][2]=1;
                                             q[i3][3]=1;
                                             q[i4][4]=1;
                                             q[i5][5]=1;
                                             q[i6][6]=1;
                                             q[i7][7]=1;
                                             if(okay(q)){
                                                print(q);
                                             }
                                             q[i0][0]=0;
                                             q[i1][1]=0;
                                             q[i2][2]=0;
                                             q[i3][3]=0;
                                             q[i4][4]=0;
                                             q[i5][5]=0;
                                             q[i6][6]=0;
                                             q[i7][7]=0;
                                     }
                                }
                            }
                        }
                    }
                }
            }
                                            
        }
    return 0;
}
