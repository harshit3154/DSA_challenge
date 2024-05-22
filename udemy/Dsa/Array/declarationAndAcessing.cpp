#include <iostream>

using namespace std;
int main(){

    /*
    int ar[6];
    for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
        cout<<"\n\n\t\tThe "<<i+1<<" element of the array is : "<<ar[i];
    }

    cout<<endl<<endl<<endl<<endl;
    for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
        cout<<"\n\n\t\tThe "<<i+1<<" element of the array is : "<<i[ar];
    }
    */

//    char ar[6];
//     for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
//         cout<<"\n\n\t\tThe "<<i+1<<" element of the array is : "<<ar[i];
//     }

//     cout<<endl<<endl<<endl<<endl;
//     for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
//         cout<<"\n\n\t\tThe "<<i+1<<" element of the array is : "<<i[ar];


    int ar[6]={1,2,3,4,5,6};
    for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
        cout<<"\n\n\t\tThe "<<i+1<<" element of the array is : "<<ar[i];
    }

    cout<<endl<<endl<<endl<<endl;
    for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
        cout<<"\n\n\t\tThe "<<i+1<<" element of the array is : "<<i[ar];
    }

    cout<<endl<<endl<<endl<<endl;
    for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
        cout<<"\n\n\t\tThe "<<i+1<<" element of the array is : "<<*(ar+i);
    }

    cout<<endl<<endl<<endl<<endl;
    for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
        cout<<"\n\n\t\tThe address of "<<i+1<<" element of the array is : "<<&ar[i];
    }
    return 0;
}