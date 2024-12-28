#include <iostream>
using namespace std;

int decimal_to_binary(int number){
   if(number==0)    return 0;
   return (number%2)+10*decimal_to_binary(number/2);
}
int main(){ 
    // int number; //To store the decimal number
    // cout<<"Enter the decimail number : ";
    // cin>>number;
    // int binary_number=decimal_to_binary(number);
    // cout<<binary_number;


    for(int i=0;i<100;i++){
        cout<<i<<" =======> "<<decimal_to_binary(i)<<endl;
    }
    return 0;
}