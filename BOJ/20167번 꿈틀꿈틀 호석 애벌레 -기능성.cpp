#include<iostream>
#include<algorithm>
#include<vector>
#include<queue> 
using namespace std;
int n,k,ans=0;
int list[21]={0};
void dfs(int now, int sum)
{
	if(sum>ans) ans=sum;	
	if(now<=n)
	{
		int val=0;
     for(int i=now; i<=n; i++)
	 {
        val+=list[i];
        
        if(val>=k)
        {
        	dfs(i+1,sum+val-k);
        	break;
		}
	 }	
	
	dfs(now+1,sum);
	
}
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>n>>k;

for(int i=1; i<=n; i++)
{
    cin>>list[i];	
}
dfs(1,0);
cout<<ans;
return 0;
}
