#include <iostream>
#include <math.h>


using namespace std;
void display(int ar[],int n){
    cout<<"\n\n\n\t\tThe element of the array are :\n\n\t\t\t ";
    for(int i=0;i<n;i++){
        cout<<ar[i]<<"\t";
    }
}
int main(){

    int ar[]={1,2,3,4,5,6,7,8,9,10,11};
    int length=sizeof(ar)/sizeof(ar[0]);
    int left=0;
    int right=length-1;
    display(ar,length);
    while(right>left){
        swap(ar[right--],ar[left++]);
    }
    display(ar,length);
    return 0;
}
