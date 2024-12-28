#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int lOccurence(vector<int> &nums,int target){
    int size=nums.size();
    int l=0,h=size-1,ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]==target){
            ans=mid;
            h=mid-1;
        }else if(nums[mid]<target){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    
    }
    return ans;
}

int rOccurence(vector<int> &nums,int target){
    int size=nums.size();
    int l=0,h=size-1,ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]==target){
            ans=mid;
            l=mid+1;
        }else if(target<nums[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
        cout<<"\n\n\t\tThe value of l and high is : "<<l<<"\t"<<h;
    }
    return ans;
} 

int locate(vector<int> &nums,int target,bool left){
        int l=0,h=nums.size()-1,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            cout<<"\n\n\t\tThe value of mid is : "<<mid;
            if(target==nums[mid]){
                cout<<"\n\n\t\t\tThe target is found.";
                ans=mid;
                if(left){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }else if(target<nums[mid]){
                h=mid-1;
            }else{
                l=mid+1;
            }
            cout<<"\n\n\t\tThe value of left and right are : "<<l<<"\t"<<h;
        }
        return ans;
    }

int main(){
    vector<int> nums{5,7,7,8,8,10};
    cout<<"\n\n\t\tThe element of the vector are\n\n\t\t\t:\t";
    for(auto it:nums){
        cout<<it<<"\t";
    }
    // cout<<"\n\n\t\tThe left occurence of 4 is : "<<lOccurence(nums,8);
    // cout<<"\n\n\t\tThe right occurence of 4 is : "<<rOccurence(nums,8);
    cout<<"\n\n\t\tThe left occurence of 8 is : "<<locate(nums,8,true);
    cout<<"\n\n\t\tThe right occurence of 8 is : "<<locate(nums,8,false);
    return 0;
}