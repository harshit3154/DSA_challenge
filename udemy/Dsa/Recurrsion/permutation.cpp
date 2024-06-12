#include <iostream>

using namespace std;

void permutation(string &str,int l,int r){
	
    for(int i=l;i<=r;i++){
    	
        swap(str[l],str[i]);
        cout<<str<<endl<<i<<endl<<l<<endl;
        permutation(str,l+1,r);
        swap(str[l],str[i]);
    }

}

int main(){
    string str="abc";
    permutation(str,0,2);
    return 0;
}
