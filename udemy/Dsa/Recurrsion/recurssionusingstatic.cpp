#include <iostream>
using namespace std;


int fun(int x){
	static int y=5;
	if(x>0){
		cout<<y<<endl;
		y+=fun(x-1);
	}
	return y;
}
int main(){
	fun(5);
	return 0;
}
