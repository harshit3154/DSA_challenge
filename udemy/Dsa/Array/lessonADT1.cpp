#include <iostream>

using namespace std;
struct array{
    // int* p;
    int p[25];
    int size;
    int length;
};

void display(struct array &arr){
    cout<<"\n\n\t\tThe element of the array are : ";
    for(int i=0;i<arr.length;i++)
        cout<<arr.p[i]<<"\t";
    cout<<endl<<endl<<endl;
}

void input(struct array &arr){
    cout<<"\n\n\tEnter the size of the array : ";
    cin>>arr.size;
    cout<<"\n\n\t\tEnter the number of element(length) you want to store in the array : ";
    cin>>arr.length;
    for(int i=0;i<arr.length;i++){
        cout<<"\n\n\tEnter the "<<i+1<<" th of the array arr : ";
        cin>>arr.p[i];
    }
}

void append(struct array &arr,int ele){
    if(arr.length>=arr.size){
        cout<<"\n\n\t\tCant append due to overflow in array.";
        return;
    }
    arr.p[arr.length]=ele;
    arr.length+=1;
}

void insert(struct array &arr,int index,int ele){
    if(index>=0&&index<=arr.length)
    {
        for(int i=arr.length;i>index;i--){
        arr.p[i]=arr.p[i-1];
        }
        arr.p[index]=ele;
    }
}

int main(){
    /*
        struct array ar;
        input(ar);
        display(ar);
    */
    
    struct array arr={{1,2,3,4,5,6,67,45,43,33,554,33},78,12};

    display(arr);

    insert(arr,-2,345);

    display(arr);

    return 0;
}