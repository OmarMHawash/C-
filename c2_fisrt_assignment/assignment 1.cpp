#include<iostream>
#include<stdlib.h>
using namespace std;

void doIt1(int arr[],int arrLength,int checkNum){
    int CN=0;
    for(int i=0;i<arrLength;i++){
            if(arr[i]==checkNum){
                cout<<checkNum<<" is in the array of numbers"<<endl;
                CN++;
                break;
            }
        }
    if(!CN){
        cout<<"the number you entered is not in the array"<<endl;
    }
}

void magicMat(int arr[3][3]){
    int sumR,sumC,sumD1=0,sumD2=0,sumRC=0;
    for(int i=0;i<3;i++){
        sumR=0,sumC=0;
        for(int j=0;j<3;j++){
            sumR+=arr[i][j];
            sumC+=arr[j][i];
        }
        if(sumR==sumC){
            sumRC+=1;
        }
        sumD1+=arr[i][i];
        sumD2+=arr[2-i][2-i];
    }
    if(sumRC==3 && sumD1==sumD2){
        cout<<"The matrix is a magic matrix with a magic constant: "<<sumD1<<endl;
    }else{
        cout<<"no magic happend in the matrix :("<<endl;
    }
}

void printMat(int arr[3][3],int x,int y){
    for(int i=0;i<3;i++){
            cout<<"| ";
            for(int j=0;j<3;j++){
                if(y==i && x==j){
                    cout<<"_ ";
                }else if(arr[i][j]){
                    cout<<arr[i][j]<<" ";
                }else{
                    cout<<"- ";
                }
            }
            cout<<"|"<<endl;
        }
}

int main(){
    int q;
    cout<<"Question 1 or 2 ?"<<endl;
    cin>>q;
    system ("clear");
    if(q==1){
        int arrLength,checkNum;
        cout<<"please enter array size:"<<endl;
        cin>>arrLength;
        system ("clear");
        int arr[arrLength];
        cout<<"enter "<<arrLength<<" integers:"<<endl;
        for(int i=0;i<arrLength;i++){
            int input;
            cin>>arr[i];
        }

        cout<<"enter the integer to search for:"<<endl;
        cin>>checkNum;
        system("clear");
        doIt1(arr,arrLength,checkNum);
        cout<<endl;
    }else{
        int x,y=0;
        int arr[3][3]= {0};
        for(int i=0;i<3;i++){
            x=0;
            for(int j=0;j<3;j++){
                system ("clear");
                printMat(arr,x,y);
                cin>>arr[i][j];
                x++;
                if(i==2 && j==2){
                    system ("clear");
                    printMat(arr,x,y);
                }
            }
            y++;
        }
        magicMat(arr);
        cout<<endl;
    }
    
    
    return -1;
}