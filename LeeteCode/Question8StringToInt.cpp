#include <iostream>

using namespace std;
int myAtoi(string s) {

        long int ans=0;
        int index=0;
        int sign=1;
        int l=s.length();

        while(index<l && s[index]==' '){
            index++;
        }
        
        cout<<"\n\n\t\tThe value of index is : "<<index;

        if(index==l)    return 0;
        
        if(s[index]=='-'){
            sign=-1;
            index++;
        }else if(s[index]=='+'){
            sign=+1;
            index++;
        }
        cout<<"\n\n\t\tThe value of index is : "<<index;
        while(s[index]>='0' && s[index]<='9' && index<l){
            if(ans<=INT_MIN/10)     return INT_MIN;
            if(ans>=INT_MAX/10)     return INT_MAX;
            ans=ans*10+(s[index++]-'0');
            cout<<"\n\n\t\tThe value of index and ans is :"<<index<<"\t"<<ans;
        }
        ans*=sign;
        return (int)ans;
    }
    
    int main(){
    	cout<<myAtoi("42");
    	return 0;
	}
