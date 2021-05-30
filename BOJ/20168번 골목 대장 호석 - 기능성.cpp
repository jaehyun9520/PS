#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,s,e,c;
int ans=1001; 

vector < pair < int , int > > node[21];
bool check[21]={0};

void DFS(int now, int cost, int max1)
{
	if(now==e)
	{
		if(ans>max1)
		{
			ans=max1;
		}
	}
	
	
	else if(cost!=0){
	
	
	for(int i=0; i<node[now].size(); i++)
	{
		if(check[node[now][i].first]==0)
		{
	       check[node[now][i].first]=1;  	
	   int next=node[now][i].first;  
	   int nextcost=node[now][i].second;
	   
	   if(cost-nextcost>=0)
	   {
	   	  if(max1<nextcost)  
	   	  DFS(next,cost-nextcost,nextcost);
	        
			else{
				DFS(next,cost-nextcost,max1);
			} 	
	   }
	   
	   check[next]=0;
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
int i,a,b,val;

cin>>n>>m>>s>>e>>c;


for(int i=1; i<=m; i++)
{
	cin>>a>>b>>val;
	
      node[a].push_back({b,val});	
	  node[b].push_back({a,val});
}


check[s]=1;


DFS(s,c,0); 

if(ans==1001) cout<<-1;

else
cout<<ans;
return 0;
}
