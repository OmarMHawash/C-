#include<iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
int* selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    int * array = new int[n];
    array = arr;
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    }
    return array;
}
int main(){
    int size;
    cout<<"enter array size: ";
    cin>>size;
    int * arr = new int[size];

    cout<<"enter array numbers:\n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"your array is:\n";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;

    cout<<"your sorted array is:\n";
    int * sorted_arr = new int[size];
    sorted_arr=selectionSort(arr,size);
    // could not make it work!
    // delete[] arr;
    for(int i=0;i<size;i++){
        cout<<sorted_arr[i]<<", ";
    }
    cout<<endl;
    float median;
    cout<<"the median is: ";
    if(size % 2 == 0){
        median = (float) (((float)sorted_arr[size/2]+sorted_arr[(size/2)-1])/2);
    }else{
        median = sorted_arr[(size/2)];
    }
    cout<<median<<endl;
    // could not make it work!
    // delete[] sorted_arr;
    return -1;
}