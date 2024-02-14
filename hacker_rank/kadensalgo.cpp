#include <iostream>
using namespace std;
long long maxSubarraySum(int*,int);
int main()
{
    int ar[]={1,2,3,-2,5};
    int size=sizeof(ar)/sizeof(ar[0]);
    cout<<"The size of the array is : "<<size;
    cout<<"\n\n\t\tThe maximum sum of continuous subarray is : "<<maxSubarraySum(ar,size);
    return 0;
}

long long maxSubarraySum(int *arr,int n)
{
    long long sum=0;
        long long max_sum=arr[0];
        for( int i=0 ; i<n; i++)
        {
            sum+=arr[i];
            max_sum=max(sum,max_sum);
            if(sum<0)
                sum=0;
        }
        return max_sum;
}