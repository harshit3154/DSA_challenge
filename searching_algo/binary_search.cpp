#include <iostream>

using namespace std;

void binary_search(int*,int,int);
int main()
{
    int n,key,t;
    cout<<"\n\n\t\tEnter the number of element in the array : ";
    cin>>n;
    int *p=new int[n];
    for( int i=0;i<n;i++)
    {
        cout<<"\n\n\t\t\tEnter the "<<i+1<<" element of the array : ";
        cin>>p[i];
    }
    cout<<"\n\n\t\tEnter the number of testcases : ";
    cin>>t;
    while(t--)
    {
        cout<<"\n\n\t\tEnter the element to be searched in the array : ";
        cin>>key;
        binary_search(p,n,key);
    }
    return 0;
}

void binary_search(int* p,int n,int key)
{
    int l=0,h=n-1,flag=-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(p[mid]==key)
        {
            cout<<"\n\n\tThe element is present in the element at "<<mid+1<<" location and "<<mid<<" index.";
            flag=1;
            break;
        }
        else if(p[mid]>key)
        {
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
     if(flag==-1)
        cout<<"\n\n\tThe element is not present in the elment :";
}