#include <iostream>

using namespace std;
int main(){
    int i=0;
    for(;;){
        if(i<56){
            printf("%d\n",i);
        }else{
            break;
        }
        i++;
    }
    cout<<(-15<<2)<<endl;

    //printing fibonacci series. 
    int a=1,b=1;
    cout<<a<<endl<<b<<endl;
    for(int i=0;i<8;i++){
        int c=a+b;
        a=b;
        b=c;
        cout<<b<<endl; 
    }


    // Checking for the prime number.
    int number;
    cout<<"\n\n\t\tEnter the number to be checked : ";
    cin>>number;
    i=2;
    for(;i<=number/2;i++){
        if(number%i==0){
            cout<<"It is not a prime number.";
            break;
        }
    }
    if(i==number/2+1)
        cout<<"It is a prime number.";
    return 0;
}