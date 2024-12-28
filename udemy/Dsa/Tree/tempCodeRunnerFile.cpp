#include <iostream>

using namespace std;
int main() {
    int *nums=new int[490];
    int x;
    int i=0;
    cout<<"\n\n\n\t\t\tEnter the element : ";
    while(cin>>x){
        cout<<"\n\n\n\t\t\tEnter the element : ";
        nums[i++]=x;
    }

    cout<<"\n\n\n\t\tThe element of the array are : ";
    for( int i=0; i<8; i++){
        cout<<"\t"<<nums[i];
    }
}
