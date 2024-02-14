#include <iostream>

using namespace std;

void sentinial_search(int*,int,int);
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
        sentinial_search(p,n,key);
    }
    return 0;
}

void sentinial_search(int* p,int n,int key)
{
    int i=0,ele=p[n-1];
    p[n-1]=key;
    while(p[i]==key)
        i++;
    
    if(i<n-1 || p[n-1]==key)
    {
        cout<<"\n\n\tThe element is present in the element at "<<i+1<<" location and "<<i<<" index.";
    }
    else{
        cout<<"\n\n\tThe element is not present in the elment :";
    }
}