#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std; 
const int maxSize = 1000;
const int INF =1000000000;
int n,m,G[maxSize][maxSize];
int d[maxSize];
bool vis[maxSize]={false};

int prim()
{
	fill(d,d+maxSize,INF);
	d[0]=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int u=-1;
		int min=INF;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
			}
		}
		if(u==-1)
			return -1;
		vis[u]=true;
		ans+=d[u];
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF&&G[u][v]<d[v])
				d[v]=G[u][v];
		}
	} 
	return ans;
}

int main()
{
	int u,v,w;
	scanf("%d %d",&n,&m);
	fill(G[0],G[0]+maxSize*maxSize,INF);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		G[u][v]=G[v][u]=w;
	}
	int ans=prim();
	printf("%d\n",ans);
	for(int i=1;i<n;i++)
		printf("%d\n",d[i]);
}
