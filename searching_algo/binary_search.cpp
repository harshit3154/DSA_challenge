#include <iostream>

using namespace std;
int main()
{
    int n,ele,t;
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
        int flag=-1;
        cout<<"\n\n\t\tEnter the element to be searched in the array : ";
        cin>>ele;
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(p[mid]==ele)
            {
                cout<<"\n\n\tThe element is present in the element at "<<mid+1<<" location and "<<mid<<" index.";
                flag=1;
                break;
            }
            else if(p[mid]>ele)
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
    return 0;
}