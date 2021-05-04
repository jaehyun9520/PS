#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

vector <int> node[2000]; 
int check[2000]={0};

void DFS(int x, int cnt)
{

	if(cnt==5)
	{
		cout<<1;
		exit(0);
	}
	
	else
	{
		for(int i=0; i<node[x].size(); i++)
		{
			if(check[node[x][i]]==0)
			{
				
				check[node[x][i]]=1;
				DFS(node[x][i],cnt+1);
				check[node[x][i]]=0;
			}
		}
		
	}
	
}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,m;
cin>>n>>m;
int i,j,a,b;
for(i=1; i<=m; i++)
{
	cin>>a>>b;
	node[a].push_back(b);
	node[b].push_back(a);
}


for(i=0; i<n; i++)
{
	if(check[i]==0)
	{
		check[i]=1; 
		DFS(i,1);
		check[i]=0;
	}
	
}

cout<<0;
return 0;
}
