#include <iostream>
#include <stdio.h>
#include <utility>
#include <unordered_map>

using namespace std;
int main(){
    unordered_map<int,int> um;
    for(int i=0;i<5;i++){
        um.insert({i,i+1});
    }
    um[0]=3;
    printf("\n\n\t\tThe element of the unordered_map um are : ");
    for(auto &pair:um){
        cout<<"\n\n\t\t\t"<<pair.first<<" ---------->"<<pair.second;
    }
    printf("\n\n\n\t\tThe size of the unordered_map um is : %d",um.size());
    printf("\n\n\n\t\t\tThe no bucket count for the map is : %d ",um.bucket_count());
    return 0;
}