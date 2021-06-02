#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int ans=0;
int cnt=0;
vector < pair < int , int > > node[801];

int save[800][800]={0};

int dijkstra(int s)
{
	bool check[801]={0};
	vector <int>  dis(801,214700000);
	priority_queue < pair < long long , int > > PQ ;
	dis[s]=0;
	PQ.push({0,s});
	
	while(!PQ.empty())
	{
		int now=PQ.top().second;  
		int val=-1*PQ.top().first;

		PQ.pop();
		if(check[now]==0)
		{
			
			save[s][now]=val;
			check[now]=1;
			
			
			for(int i=0; i<node[now].size(); i++)
			{
				int next=node[now][i].first;
				int nextcost=node[now][i].second;
				
				if(check[next]==0)
				{
					if(dis[now]+nextcost<dis[next])
					{
						dis[next]=dis[now]+nextcost;

						PQ.push({-dis[next],next});
						
					}
		
				}
				
				
			}
    	
		}
			
		}
		
		return 0;
		
	}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int a,b,val=0,x1,x2;
cin>>n>>m;

for(int i=1; i<=m; i++)
{
	cin>>a>>b>>val;
	
	node[a].push_back({b,val});
	node[b].push_back({a,val});
	
 } 
 cin>>x1>>x2;
 
dijkstra(1);
dijkstra(x1);
dijkstra(x2);


if(x1==1&&x2==n)
{
	if(save[1][n]==0)
	{
		cout<<-1;
	}
	
	else{
		cout<<save[1][n];
	}
	
}

else{
	
	int ans1=214700000; int ans2=214700000;
	
	if(save[1][x1]!=0&&save[x1][x2]!=0&&save[x2][n]!=0)
	{
		ans1=save[1][x1]+save[x1][x2]+save[x2][n];
	
	}
	
	if(save[1][x2]!=0&&save[x2][x1]!=0&&save[x1][n]!=0)
	{
		ans2=save[1][x2]+save[x2][x1]+save[x1][n];
	
	}
	
int val=min(ans1,ans2);

if(val==214700000) cout<<-1;

else cout<<val;
	
}

return 0;
}
