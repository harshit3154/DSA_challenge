#include <iostream>

using namespace std;

int main(){

    int ar[6]={1,2,3,4,5,6};
    int *p=ar;

    // cout<<endl<<sizeof(*p);
    // cout<<endl<<sizeof(p[0]);


    cout<<endl<<endl<<endl<<endl;
    for(int i=0;i<6;i++){
        cout<<"\n\n\t\tThe "<<i+1<<" element of the array is : "<<*(p+i);
    }


    int *q=new int[10];
    int i=0;
    for(;i<6;i++){
        q[i]=p[i];
    }
    for(;i<10;i++){
        q[i]=i;}

    delete []p;
    p=q;
    q=NULL;

     cout<<endl<<endl<<endl<<endl;
    for(int i=0;i<10;i++){
        cout<<"\n\n\t\tThe "<<i+1<<" element of the array is : "<<*(p+i);
    }

    
    
    return 0;
}