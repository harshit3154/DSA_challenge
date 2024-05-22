#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int fib1(int n){
    int t0=0,t1=1,s=0;
    if(n<=1) return n;
    for(int i=1;i<n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

//Recurrsive O(2^n)
int fib3(int n){
    if(n<=1)    return n;
    return fib3(n-2)+fib3(n-1);
}


// Memorization O(n)
int fib2(int n,vector<int>& check){
    if(n<=1)    return n;
    if(check[n-2]==-1)    check[n-2]=fib2(n-2,check);
    if(check[n-1]==-1)    check[n-1]=fib2(n-1,check);
    return check[n-2]+check[n-1];
}
int main(){
    int n;
    char ch;
    do{
        cout<<"\n\n\t\tEnter the term you to find in the fibonacci series : ";
        cin>>n;
        vector<int> check(n,-1);
        cout<<"\n\n\t\tThe "<<n<<"term of fibonaci series is : "<<fib2(n-1,check);
        cout<<"\n\n\t\t\tDo you want to continue operation or not(y/n) : ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}