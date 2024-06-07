#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(int**,int);
void dfs(int**,int,int);
int main(){

    int n,weight=1;
    int **adj;
    char ch;
    bool w;
    cout<<"\n\n\t\tEnter the number of vertices in the graph : ";
    cin>>n;
    adj=new int*[n];
    for(int i=0;i<n;i++){
        adj[i]=new int[n];
    }
    cout<<"\n\n\t\tEnter wheather the graph is wighted(y/n)";
    cin>>ch;
    w=(ch=='y'||ch=='Y')?true:false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"\n\n\t\tWheather there is edge between "<<i<<" and "<<j<<" node(y/n): ";
            cin>>ch;
            if(w&&(ch=='y'||ch=='Y'){
                cout<<"\n\n\t\tEnter the weight of the edge : ";
                cin>>weight;
            }
            adj[i][j]=(ch=='y'||ch=='Y')?weight:0;
        }
    }
    display(adj,n);
    cout<<"\n\n\t\tTraversing the graph with the help of dfs \n\n\t\t\t:";
    dfs(adj,n,adj[0][0]);
    return 0;
}
void display(int **p,int n){
    cout<<"\n\n\t\tThe adjacency matrices element are : ";
    for(int i=0;i<n;i++){
        cout<<"\n\n\t\t\t";
        for(int j=0;j<n;j++){
            cout<<p[i][j]<<"\t";
        }
    }
}

void dfs(int **p,int n,int node){
	static int *visited=new int[n];
	visited[node]=1;
	cout<<"\t"<<node;
	for(int i=0;i<n;i++){
		if(visited[i]!=1 && p[node][i]!=0){
			visited[node]=1;
			dfs(p,n,p[node][i]);
		}
	}
}
