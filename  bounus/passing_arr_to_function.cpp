#include <iostream>
using namespace std;

int sumAll(int a[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += a[i];

	}
	return sum;
}

int main() {
    int A[5] = { 1,2,3,4,5 }; //sum=15
	int m[3][4] = {
         {1,2,3,4},
         {1,2,3,4},
         {1,2,3,4 } }; //sum=30
    cout<<sumAll(A,5)<<endl;

    int sum2=0;

    for(int i=0;i<3;i++){
        sum2+=sumAll(m[i],4);
    }
    cout<<sum2<<endl;
    return 0;
}