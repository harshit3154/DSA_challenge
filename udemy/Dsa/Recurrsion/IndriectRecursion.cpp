#include <iostream>

using namespace std;

void funA(int);

void funB(int x){
	if(x>0){
		funA(x/2);
		cout<<x<<endl;
	}
}


void funA(int x){
	if(x>0){
		cout<<x<<endl;
		funB(x-1);
	}
}

int main(){
	funA(15);
	return 0;
}
