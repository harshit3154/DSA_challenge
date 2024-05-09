#include <iostream>

using namespace std;

int reverse(int x){
	
	int rev=0;
	while(x!=0){
		
		if( rev>INT_MAX/10 || rev<INT_MIN/10 ){
			return 0;
		}
		
		
		rev=rev*10+x%10;
		
		x=x/10;
	}
	return rev;
}

int main(){
	cout<<reverse(-123);
	return 0;
}
