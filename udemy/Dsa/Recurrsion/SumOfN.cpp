#include <iostream>

using namespace std;

int sumN(int n){
	if(n>0)
		return n+sumN(n-1);
	return 0;
}

int main(){
	cout<<sumN(7);
	return 0;
}
