#include <iostream>

using namespace std;

// declaring linear search function.

void linear_search(int*,int,int);
int main(){
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

        linear_search(p,n,key);
        
    }
    return 0;
}


// defining linear search function.

void linear_search(int *p,int n,int key)
{
    int flag=-1;
    for(int i=0;i<n;i++)
        {
            if(key==p[i]){
                cout<<"\n\n\tThe element is present in the element at "<<i+1<<" location and "<<i<<" index.";
                flag=1;
            }
        }
        if(flag==-1)
            cout<<"\n\n\tThe element is not present in the elment :";
}