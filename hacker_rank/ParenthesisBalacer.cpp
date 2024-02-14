#include <bits/stdc++.h>

using namespace std;
class Solution
{
    public:
    
    void displayStack(stack<char> c)
    {
        cout<<"\n\n\t\tThe element of the stack are : ";
        while(!c.empty())
        {
            cout<<c.top()<<"\t";
            c.pop();
        }
    }


    bool ispar(string x)
    {
        // Your code here
        unordered_map<char,int> m={ {'[',-1}, { '(',-2 },{'{',-3},
        {']',1},{')',2},{'}',3}};
        
        stack<char> check;
        
        for(int i=0;i<x.length();i++)
        {
            if(m[x[i]]<0)
            {
                check.push(x[i]);
            }
            else {
                if(!check.empty())
                {
                    if(m[check.top()]+m[x[i]]==0)
                        check.pop();
                    else
                        return false;
                }
                else{
                    return false;
                }
            }
            displayStack(check);
        }
        if(check.empty())
            return true;
        return false;
    }

};

int main()
{
    string str="{(])}";
    Solution *ob=new Solution();
    if(ob->ispar(str))
    {
        cout<<"\n\n\n\t\tThe paranthesis are balanced.";
    }
    else{
        cout<<"\n\n\t\tThe paranthesis are not balanced.";
    }
    return 0;
}