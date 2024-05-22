#include <iostream>
#include <math.h>


using namespace std;
void display(int ar[],int n){
    cout<<"\n\n\n\tThe element of the array are :\n\n\t\t ";
    for(int i=0;i<n;i++){
        cout<<ar[i]<<"\t";
    }
}
int main(){

    int ar[12]={1,2,3,4,5,6,7,8,9,10,11},ele;
    int length=sizeof(ar)/sizeof(ar[0]);
    int index=length-1;
    cout<<"\n\n\tThe length of the array is : "<<length;
    cout<<"\n\n\tThe sizeof(ar) is : "<<sizeof(ar);
    display(ar,length);
    cout<<"\n\n\t\tEnter the element you want to enter:";
    cin>>ele;
    while(ar[index]>ele){
    	cout<<"Inside loop";
    	display(ar,length);
    	ar[index+1]=ar[index--];
	}
	ar[index+1]=ele;
    display(ar,length);
    return 0;
}
