#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Graph{
	
	private : 
		
		int no_of_edges,no_of_vertices;
		unordered_map<int,vector<int>> adj;
	
	public :
		
		void addEdge(int u,int v,bool flag){
			adj[u].push_back(v);
			if(!flag){
				adj[v].push_back(u);
			}
		}
		
		void create_graph(){
			
			int u,v;
			char ch;
			
			cout<<"\n\n\t\tEnter the number of edges : ";
			cin>>no_of_edges;
			cout<<"\n\n\t\tEnter the number of vertices : ";
			cin>>no_of_vertices;
//			cout<<"\n\n\t\tIs the graph directed(Y/N) : ";
//			cin>>ch;
			ch='n';
			
			for(int i=0;i<no_of_edges;i++){
				cout<<"\n\n\t\tEnter the pair of edges : ";
				cin>>u>>v;
				addEdge(u,v,(ch=='y'||ch=='Y')?1:0);
			}
		}
		
		void displayAdjList(){
			cout<<"\n\n\n\t\tTHE ADJACENCY LIST OF THE GIVEN GRAPH IS : ";
			for(auto it:adj){
				cout<<"\n\n\t\t\t"<<it.first<<" ------> ";
				for(auto neighour:it.second){
					cout<<"\t"<<neighour;
				}
			}
		}
		
		void bfs(int node,vector<bool> &visited){
			
			queue<int> q;
			q.push(node);
			visited[node]=true;
			while(!q.empty()){
				int front_node=q.front();
				cout<<"\t"<<front_node;
				q.pop();
				for(auto neighour:adj[front_node]){
					if(!visited[neighour]){
						q.push(neighour);
						visited[neighour]=true;
					}
				}
			}
		}
		
		void BFS(){
			
			vector<bool> visited;
			
			cout<<"\n\n\n\t\tDISPLAYING THE BFS TRAVERSAL OF GRAPH\n\n\t\t\t:";
			for(auto it:adj){
				if(!visited[it.first]){
					bfs(it.first,visited);
				}
			}
			for(auto it:visited)
				cout<<it;
		}
};
int main(){
	
	Graph *g=new Graph();
	
	g->create_graph();
	g->displayAdjList();
	g->BFS();
	
	return 0;
}
