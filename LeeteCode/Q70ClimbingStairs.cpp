#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
       if(n<4)  return n;
       int a=2,b=3;
       for(int i=0;i<n-3;i++){
        b=a+b;
        a=b-a;
       }
       return b;
    }
    
    int climbStairsd(int n) {
		int (*fp)(int);
		fp=climbStairsd;
       if(n<4)  return n;
       return fp(n-1)+fp(n-2);
   }
};

int main(){
    Solution *ob=new Solution();
    for(int i=1;i<14;i++){
    	cout<<ob->climbStairs(i)<<"\t"<<ob->climbStairsd(i)<<endl;
	}
    return 0;
}
