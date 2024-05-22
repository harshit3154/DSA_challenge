#include <iostream>

using namespace std;

void display(int ar[3][4],int r,int c){

    cout<<"\n\n\t\t\tThe element of the array are : ";

    for(int i=0;i<r;i++){
        cout<<"\n\n\t\t\t\t";
        for(int j=0;j<c;j++){
            cout<<ar[i][j]<<"\t";
        }
    }

}

void display2(int *ar[3],int r,int c){

    cout<<"\n\n\t\t\tThe element of the array are : ";

    for(int i=0;i<r;i++){
        cout<<"\n\n\t\t\t\t";
        for(int j=0;j<c;j++){
            cout<<ar[i][j]<<"\t";
        }
    }

}

void display(int **ar,int r,int c){

    cout<<"\n\n\t\t\tThe element of the array are : ";

    for(int i=0;i<r;i++){
        cout<<"\n\n\t\t\t\t";
        for(int j=0;j<c;j++){
            cout<<ar[i][j]<<"\t";
        }
    }

}

int main(){

    int ar[3][4]={{1,2,3,4},{2,4,3,5},{5,6,7,8}};
    display(ar,3,4);

    int *a[3];
    for(int i=0;i<3;i++){
        a[i]=new int[4];
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            a[i][j]=j;
        }
    }
    display(a,3,4);


    int **arr;
    arr=new int*[3];
    for(int i=0;i<3;i++){
        arr[i]=new int[3];
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            arr[i][j]=9;
        }
    }

    display(arr,3,4);
}