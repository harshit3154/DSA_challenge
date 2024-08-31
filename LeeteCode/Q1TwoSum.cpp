#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<int> twoSum(vector<int> &nums,int target){
    int l=nums.size();
    unordered_map<int,int> position;
    for(int i=0;i<l;i++){
        position.insert({nums[i],i});
    }
    for(int i=0;i<l;i++){
        int tar=target-nums[i];
        if(position.find(tar)!=position.end() && i!=position[tar])
            return vector<int>{i,position[tar]};
    }
    return vector<int>{-1,-1};
}
int main(){
    vector<int> v{2,2,7,11,15};
    int target;
    target=18;
    cout<<"\n\n\t\tThe indext of the two number are : ";
    for(auto it:twoSum(v,target)){
        cout<<"\t"<<it;
    }
}