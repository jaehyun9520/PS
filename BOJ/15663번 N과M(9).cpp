#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set> 
using namespace std;
int n,m;
vector <int> list;
int check[9]={0};
int ans[9]={0};

void DFS(int cnt)
{
	if(cnt==m)
	{
		for(int i=1; i<=m; i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	  
	
	else{
		int pre=0;
		
		
		for(int i=0; i<n; i++)
		{
			if(check[i]==0&&pre!=list[i])
			{
				pre=list[i];
				check[i]=1;
				ans[++cnt]=list[i];
				
				DFS(cnt);
				cnt--;
				check[i]=0;
				
				
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


DFS(0);

return 0;
}
