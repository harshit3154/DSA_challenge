#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int ans=0;
        while(left<right){
            
            ans=max(ans,min(height[left],height[right])*(right-left));
            
            height[left]>height[right]?right--:left++;

        }
        return ans;
    }
};

int main(){

    Solution *ob=new Solution();
    vector<int> v1={1,3,2,5,25,24,5};
    vector<int> v2={1,2,3,4,5};
    cout<<ob->maxArea(v1);
    cout<<ob->maxArea(v2);
    return 0;
}