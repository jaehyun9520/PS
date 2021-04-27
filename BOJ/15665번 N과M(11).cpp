#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n,m;
vector <int> list;
int ans[9];
 

void dfs(int cnt)
{
	if(cnt==m)
	{
		for(int j=1; j<=m; j++)
		{
			cout<<ans[j]<<" ";
		}
		cout<<"\n";
	}
	
	
	else
	{
		int val=-1;

		for(int i=0; i<list.size(); i++)
		{
			if(val!=list[i])
			{		
				ans[cnt+1]=list[i];
				val=list[i];
				
				dfs(cnt+1);
			
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
cin>>n>>m;
int val;

for(int i=1; i<=n; i++)
{
	cin>>val;
	list.push_back(val);
}

sort(list.begin(),list.end());

dfs(0); 
return 0;
}
