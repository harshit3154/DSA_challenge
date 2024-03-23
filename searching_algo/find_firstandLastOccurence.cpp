#include <iostream>
#include <vector>

using namespace std;
int first_occurence(vector<int>&,int&,int&);
int second_occurence(vector<int>&,int&,int&);
int main()
{
    vector<int> v;
    int n,t,ele;
    cout<<"\n\n\t\tEnter the number of testcases : ";
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>ele;
        for( int i=0;i<n;i++)
        {
            cin>>ele;
            v.push_back(ele);
        }
        cout<<endl<<first_occurence(v,n,ele);
        cout<<endl<<second_occurence(v,n,ele);
    }
    return 0;
}
int first_occurence(vector<int> &v,int &n,int &key)
{
    int h=n-1,l=0,ans=-1;
    int mid=l+(h-l)/2;
    while(l<=h){
        if(v.at(mid)==key){
            ans=mid;
            h=mid-1;
        }
        else if(v.at(mid)<key){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
        mid=h+(l-h)/2;
    }
    return ans;
}

int second_occurence(vector<int> &v,int &n,int &key)
{
    int h=n-1,l=0,ans=-1;
    int mid=l+(h-l)/2;
    while(l<=h){
        if(v.at(mid)==key){
            ans=mid;
            l=mid+1;
        }
        else if(v.at(mid)<key){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
        mid=h+(l-h)/2;
    }
    return ans;
}

