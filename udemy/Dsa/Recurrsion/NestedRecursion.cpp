#include <iostream>

using namespace std;

int fun(int n){
	if(n>100){
		return n;	
	}
	fun(fun(n+1));
	cout<<n<<endl;
	
}

int main(){
	fun(70);
	return 0;
}
