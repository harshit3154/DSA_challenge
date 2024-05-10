#include <iostream>

using namespace std;

int PowerOpt(int m,int n){
	if(n==0)
		return 1;
	else if(n%2==0)
		return PowerOpt(m*m,n/2);
	else if(n%2!=0)
		return m*PowerOpt(m*m,(n-1)/2);
}

int Power(int m,int n){
	if(n==1)	return m;
	return m*Power(m,n-1);
}

int main(){
	cout<<PowerOpt(2,23);
	return 0;
}
