#include <iostream>
using namespace std;
int main(){
    long double p=200000;
    for(int i=0;i<40;i++){
        long double si=p*8/100;
        p+=si+200000;
        cout<<"\n\n\t\tThe amount for the "<<i+1<<"year is : "<<p;
    }
    return 0;
}