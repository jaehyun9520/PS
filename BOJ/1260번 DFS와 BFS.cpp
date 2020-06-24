#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>



using namespace std;
vector <int> graph[1001];
int check[1001]={0};
queue <int> Q;
int n,m,v; 


void DFS(int x)
{
	
	for(int i=0; i<graph[x].size(); i++)
	{
		if(check[graph[x][i]]==0)
		{
			check[graph[x][i]]=1;
			printf("%d ",graph[x][i]);
			DFS(graph[x][i]);
		}
	}
}

int main()
{
freopen("input.txt", "rt", stdin);
int i,a,b,x;
scanf("%d %d %d",&n,&m,&v);

for(i=1; i<=m; i++)
{
	scanf("%d %d",&a,&b);
	graph[a].push_back(b);
	graph[b].push_back(a);
}

for(i=1; i<=n; i++)
{

sort(graph[i].begin(),graph[i].end());
}
check[v]=1;
printf("%d ",v);
DFS(v);
printf("\n");


for(i=1; i<=n; i++)
{
	check[i]=0;
}
check[v]=1;
Q.push(v);



while(!Q.empty())
{
	 x=Q.front();
	 Q.pop();
	 printf("%d ",x);
	 
	 for(i=0; i<graph[x].size(); i++)
     {
     	
     	if(check[graph[x][i]]==0)
     	{
     		check[graph[x][i]]=1;
     		Q.push( graph[x][i] );
		 }
	 }
}

return 0;
}
