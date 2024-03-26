#include <iostream>
#include <vector>

using namespace std;
int min_jump(vector<int> &v){
    int jump=0;
    int pos(0);
    int des(0);
    for(int i=0;i<v.size()-1;i++){
        des=max(des,(v[i]+i));
        if(i==pos){
            pos=des;
            jump++;
        }
        cout<<endl<<des<<"\t"<<pos<<"\t"<<jump<<endl;
    }
    return jump;
}
int main(){
    vector<int> v;
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            v.push_back(ele);
        }
        cout<<endl<<min_jump(v);
    }
    return 0;
}