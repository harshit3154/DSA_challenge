/*
Internship Alert!
Become an SDE Intern by topping this monthly leaderboard! 

banner
Given an unsorted array A of size N that contains only non negative integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.
Example 2:

Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.
Your Task:
You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N, and S as input parameters and returns an ArrayList containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. The two indexes in the array should be according to 1-based indexing. If no such subarray is found, return an array consisting of only one element that is -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
0 <= Ai <= 109
0<= S <= 109
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public :
         vector<int> subarraySum(vector<int>arr, int n, long long s)
        {
            long long sum=0;
            vector<int> ans;
            ans.push_back(1);
            for(int i=1;i<=n;i++)
            {

                if(sum == s)
                {
                    ans.push_back(i);
                    return ans;
                }
                else if( sum > s)
                {
                    while(sum > s)
                    {
                        sum-=arr[ans[0]-1];
                        ans[0]+=1;
                         if(sum==s)
                            {
                                ans.push_back(i-1);
                                return ans;
                            }
                    }
                }
                else{
                        sum+=arr[i-1];
                }
            }
            ans[0]=-1;
            return ans;

    }

    void display(vector<int>& v)
    {
        cout<<"\n\n\t\tThe element of the vector are\n\n\t\t\t: ";
        for(auto it:v)
        {
            cout<<it<<"\t";
        }
    }
};

int main()
{
    vector<int> v={1,2,3,7,5};
    Solution *ob=new Solution();
    ob->display(v);
    vector<int> ans=ob->subarraySum(v,v.size(),12);
    ob->display(ans);
    return 0;
}