#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

#define pb push_back
#define INF 1<<30
#define mkp make_pair

int main(){
	int V; //number of ertices of graph 1,2,3...v
	cin>>V;
	vector<iPair> adj[V+1]; //adj list representation
	
	int E; //number of edges in the graph
	cin>>E;
	
	for(int j=1;j<=E;j++){
		//input the edge from u to v with w
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb(mkp(v,w));
	}
	
	int s;
	s = 1; //taking 1st edges as source vertex for bellman ford;
	
	int dist[V+1];
	for(int j=1;j<=V;j++){
		dist[j] = INF;
	}
	dist[s] = 0; 
	int t = V-1;
	
	while(t--){
		for(int u=1;u<=V;u++){
			for(int i=0;i<adj[u].size();i++){
				int v = adj[u][i].first;
				int w = adj[u][i].second;
				if(dist[u]!=INF && dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
				}
			}
		}
	}
	
	bool flag = 0;
	//check for all the edges
	for(int u=1;u<=V;u++){
		for(int i=0;i<adj[u].size();i++){
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if(dist[u]!=INF && dist[u] + w < dist[v]){
				cout<<"negative weight cycle detected!"<<endl;
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
	
	if(!flag) cout<<"No negative weight cycle found"<<endl;
	
	for(int i=1;i<=V;i++){
		cout<<"dist "<<i<<"  -->  "<<dist[i]<<endl;
	}
	
	return 0;
}
