#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>


using namespace std;

void display(vector<vector<int>> &nums,string str){
    cout<<"\n\n\t\t"<<str<<" : ";
    for(auto it:nums){
        cout<<"\n\n\t\t\t\t";
        for(auto neighour:it){
            cout<<neighour<<"\t";
        }
    }
}

void calculateFireTime(vector<vector<int>> &grid,vector<vector<int>> &firetime,int r,int c){
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                firetime[i][j]=0;
                visited[i][j]=true;
                q.push({i,j});
            }
        }
    }
    vector<pair<int,int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
    while(!q.empty()){
        auto it=q.front();
        int x=it.first,y=it.second;
        q.pop();
        cout<<endl<<"Main cordinate : "<<x<<"\t"<<y<<endl;
        for(auto dir:direction){
            int dx=x+dir.first;
            int dy=y+dir.second;
            if( dx>=0 && dx<r && dy>=0 && dy<c && grid[dx][dy]==0 && !visited[dx][dy]){
                q.push({dx,dy});
                firetime[dx][dy]=firetime[x][y]+1;
                visited[dx][dy]=true;
            }
        }
        display(firetime,"");
        cout<<endl;
    }
}

int timeToReach(vector<vector<int>> &nums,vector<vector<int>> &firetime,vector<vector<bool>> &visited,int r,int c,int x,int y,int time){
    if(firetime[x][y]==-1){
        return -1;
    }
    vector<pair<int,int>> direction={{1,0},{-1,0},{0,1},{-1,0}};
    for(auto it:direction){
        int dx=x+it.first;
        int dy=y+it.second;
        if( dx>=0 && dy>=0 && dx<r && dy<r && (time<firetime[dx][dy] || ( time<= firetime[dx][dy] && x==r && y==c))){
            
        }
    }
}

int main(){
    std::vector<vector<int>> nums{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    display(nums,"The element of the nums vector");

    int r=nums.size();
    int c=nums[0].size();
    vector<vector<bool>> visited(r,vector<bool>(c,false));

    vector<vector<int>> firetime(r,vector<int>(c,-1));
    calculateFireTime(nums,firetime,r,c);
    int l=0,h=1e10;
    while(l<=h){
        int mid=l+(h-l)/2;
        int result=timeToReach(nums,firetime,visited,r,c,0,0,mid);
        if(result!=-1){
            cout<<"\n\n\t\tOne can reach destination after waiting "<<result<<" at level (0,0)";
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return 0;
}