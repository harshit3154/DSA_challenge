#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

int main(){
    stack<string> st;
    vector<string> v={"a","b","v","d","e"};
    for(auto it:v)
        st.push(it);

    cout<<st.top();
}