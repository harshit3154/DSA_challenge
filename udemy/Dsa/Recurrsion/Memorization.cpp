#include <vector>
#include <iostream>

using namespace std;

int main(){
	
	int n;
	int t;
	cout<<"\n\n\t\tEnter the number of test cases : ";
	cin>>t;
	
	vector<int> vec;
	vec.resize(9);
	for(auto it:vec){
		cout<<it<<endl;
	}
	
	return 0;
}
