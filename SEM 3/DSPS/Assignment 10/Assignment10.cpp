/*
* @Author: ubuntu
* @Date:   2017-11-06 12:52:28
* @Last Modified 2017-11-06
* @Last Modified time: 2017-11-06 12:59:50
*/
#include<iostream> 
using namespace std; 

#define Infinity 999 
#define MAX 20 

class graph 
{ 
	private: 
		int graph1[MAX][MAX]; 
		int span_tree[MAX][MAX]; 
		int v; 

	public: 
		void input(); 
		void display(); 
		void prims(); 
}; 


void graph::input() 
{ 
	int i,j,wt; 
	cout<<"\nEnter the number of vertices:\t"; 
	cin>>v; 
	for(i=1;i<=v;i++) 
	{ 
		for(j=1;j<=v;j++) 
		{ 
			graph1[i][j]=Infinity; 
		} 
	} 

	for(i=1;i<=v;i++) 
	{ 
		for(j=i+1;j<=v;j++) 
		{ 
			cout<<"\nEnter the weights between"<< i<<" and"<< j<<":\t"; 
			cin>>wt; 
			graph1[i][j]=graph1[j][i]=wt; 
		} 
	}    	 
} 

void graph::display() 
{ 
	int i,j; 
	cout<<"\nThe matrix representation is:\n"; 
	for(i=1;i<=v;i++) 
	{ 
		for(j=1;j<=v;j++) 
		{             
		cout<<"\t"<<graph1[i][j];              
		} 
		cout<<"\n"; 
	} 
	cout<<"\nThe spanning tree is:\n"; 
	for(i=1;i<=v;i++) 
	{ 
		for(j=1;j<=v;j++) 
		{ 
			cout<<"\t"<<span_tree[i][j]; 
		} 
		cout<<"\n"; 
	} 
} 

void graph::prims() 
{ 
	int i,j,u,ver; 
	int dist[MAX],visit[MAX],cost[MAX][MAX],via[MAX]; 
	int min_dist,edges=0,min_cost=0;; 

	for(i=0;i<=v;i++) 
		visit[i]=0; 

	for(i=1;i<=v;i++) 
	{ 
		for(j=1;j<=v;j++) 
		{ 
			span_tree[i][j]=0; 
		} 
	} 

	for(i=1;i<=v;i++) 
	{ 
		for(j=1;j<=v;j++) 
		{ 
			if(graph1[i][j]==0) 
				cost[i][j]=Infinity; 
			else 
				cost[i][j]=graph1[i][j]; 
		} 
	} 

	visit[1]=1; 
	dist[1]=0; 
	via[1]=1; 

	for(i=2;i<=v;i++) 
	{ 
		dist[i]=cost[1][i]; 
		via[i]=1; 
	} 

	while(edges< v-1) 
	{ 
		min_dist=Infinity; 
		for(i=2;i<=v;i++) 
		if(visit[i]==0&&dist[i]<min_dist) 
		{ 
			min_dist=dist[i]; 
			ver=i; 
		} 
		u=via[ver];   
		span_tree[u][ver]=dist[ver]; 
		span_tree[ver][u]=span_tree[u][ver]; 
		edges++; 
		visit[ver]=1; 
		for(i=1;i<=v;i++) 
		{ 
			if(visit[i]==0&&cost[i][ver]<dist[i]) 
			{ 
				dist[i]=cost[i][ver]; 
				via[i]=ver; 
			} 
		}        
		min_cost=min_cost+cost[u][ver]; 
	} 
	cout<<"\nMinimum distance is::\t"<<min_cost; 
} 
int main() 
{ 
	graph g; 
	g.input(); 
	g.prims(); 
	g.display(); 
	return 0; 
}
