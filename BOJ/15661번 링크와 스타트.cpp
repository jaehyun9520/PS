#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int array1[21][21]={0};
int check[21]={0};
int n,ans=214700000;

void dfs(int cnt, int num)
{
	if(cnt>=2)
	{
		int asum=0, bsum=0;
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(check[i]==1&&check[j]==1)
				{
					asum+=array1[i][j];
				}
				if(check[i]==0&&check[j]==0)
				{
					bsum+=array1[i][j];
				}
			}
		}
		
		
		if(ans>abs(asum-bsum))
		{
			ans=abs(asum-bsum);
		}
	}
	
	
	if(cnt<n/2)
	{
		for(int i=num; i<=n; i++)
		{
			check[i]=1;
			dfs(cnt+1,i+1);
			check[i]=0;
		}
		
		
		
	}
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,j;

cin>>n;

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		cin>>array1[i][j];
		
	}
}


dfs(0,1);   

cout<<ans;
return 0;
}
