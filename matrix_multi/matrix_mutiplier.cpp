#include <iostream>
using namespace std;

int main() {
    int m1[2][4]={
        {1,3,7,9},
        {6,4,2,1},
    },
    m2[4][3]={
        {1,2,1},
        {0,1,0},
        {1,1,2},
        {0,0,1},
    },
    multiResult[2][3],sum;
    
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            sum=0;
            for(int r=0;r<4;r++){
                sum+=m1[i][r]*m2[r][j];
            }
            multiResult[i][j]=sum;
        };
    }cout<<endl;

    for(int i=0;i<2;i++){
        cout<<"| ";
        for(int j=0;j<3;j++){
            cout<<multiResult[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }cout<<endl;
    return -1;
}