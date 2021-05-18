#include<iostream>
#include<algorithm>
#include<vector>
#include<queue> 
using namespace std;
vector < pair < int , int >  > node[10001];

int check(int s,int e,int val)
{
int visited[10001]={0};
queue <int>	Q;

visited[s]=1;

Q.push(s);


while(!Q.empty())
{
	int now=Q.front();
	Q.pop();
	
	
	for(int i=0; i<node[now].size(); i++)
	{
		if(node[now][i].second>=val&&visited[node[now][i].first]==0)
		{
			visited[node[now][i].first]=1;
			
			if(node[now][i].first==e)
			{
				return 1;
			}
			
			Q.push(node[now][i].first);
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
int n,m,i,a,b,c,s,e,ans;
int low=1000000001, high=0,mid;


cin>>n>>m;

for(i=1; i<=m; i++)
{
	cin>>a>>b>>c;
	
	if(low>c) low=c;
	if(high<c)  high=c;
	
	node[a].push_back(make_pair(b,c));
	node[b].push_back(make_pair(a,c));
}

cin>>s>>e;

while(low<=high)
{
	mid=(low+high)/2;
	
	
	 if(check(s,e,mid))
	 {
	 	ans=mid;
	 	low=mid+1;
	 }
	 
	 else{
	 	
	 	high=mid-1;
	 }
	
	
	
}
cout<<ans;

return 0;
}
