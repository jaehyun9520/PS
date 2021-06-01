#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
vector < pair < int , int > > node[100001]; 


int dijkstra(int s, int e, int cost, int val)
{
	
 vector < long long > dis(100001,pow(10,14));
	bool check[100001]={0};
	priority_queue < pair < int , int > > PQ;

	
	dis[s]=0;
	PQ.push({0,s}); 
	
	while(!PQ.empty()) 
	{
		int now=PQ.top().second;
		PQ.pop();

		if(check[now]==0)
		{
			check[now]=1;
			if(now==e)
			{
			
				return 1;
			}

			for(int i=0; i<node[now].size(); i++)
			{
				int next=node[now][i].first;  
				long long nextcost=node[now][i].second;
				if(nextcost<=val) 
				{
						if(dis[now]+nextcost<=cost)  
					{
						if(dis[now]+nextcost<dis[next])
						{
						
						dis[next]=dis[now]+nextcost;
						
						PQ.push({-1*(dis[now]+nextcost),next}); 
					}
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
int n,m,s,e,ans=-1; 
int i,a,b,val;
int low,high,mid,c;
cin>>n>>m>>s>>e>>c; 

for(i=1; i<=m; i++)
{
	cin>>a>>b>>val;
	
	node[a].push_back({b,val});
	node[b].push_back({a,val});	
}
low=1; high=20;    

while(low<=high)
{
	mid=(low+high)/2;
	
	if(dijkstra(s,e,c,mid))
	{
		ans=mid;
		high=mid-1;
	}
	
	else{
		
		 low=mid+1;
	}
}

cout<<ans;

return 0;
}
