#include <iostream>

using namespace std;
int myAtoi(string s) {

    int index=0;
    int length=s.length();
    int sign=1;
    int ans=0;
    while(s[index]==' ' && index++ < length)
    if(index==length)   return ans;
    if(s[index]=='+')
        index++;
    if(s[index]=='-'){
        sign=-1;
        index++;
    }
    char ch=s[index];
    while(ch<='9' && ch>='0' && index<length){
        int d=int(ch-'0');
        ans=ans*10+d;
        ch=s[++index];
    }
    return sign*ans;
}
    
    int main(){
    	cout<<myAtoi("0-1");
    	return 0;
	}
