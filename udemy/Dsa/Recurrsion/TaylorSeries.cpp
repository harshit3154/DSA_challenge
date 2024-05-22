#include <iostream>

using namespace std;

double Taylor1(int x,int n){
	static double p=1,f=1;
	double r;
	if(n==0)	return 1;
	r=Taylor1(x,n-1);
	p=p*x;
	f=f*n;
	return r+(double)p/f;
}

double Taylor2(int x,int n){
	static double s=1;
	if(n==0)	return s;
	s=1+(x/(double)n)*s;
	return Taylor2(x,n-1);
}

double Taylor3(int x,int n){
	double s=1;
	for(int i=n;i>0;i--){
		s=1.0+(double)x/i*s;
	}
	return s;
}

int main(){
	cout<<endl<<Taylor1(2,10)<<endl;
	cout<<endl<<Taylor2(2,10)<<endl;
	cout<<endl<<Taylor3(2,10);
	return 0;
}
