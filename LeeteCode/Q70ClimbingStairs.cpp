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
};

int main(){
    Solution *ob=new Solution();
    ob->climbStairs(5);
    return 0;
}