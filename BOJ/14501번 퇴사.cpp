#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n,ans=0;
int cost[16]={0};
int period[16]={0}; 

void f(int day, int sum)
{
	if(sum>ans)  ans=sum;
	

	for(int i=day; i<=n; i++)
	{
		if(i+period[i]-1<=n)
		{
			sum+=cost[i];
			f(i+period[i],sum);
			sum-=cost[i];
		}
	}
		
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>n;

for(int i=1; i<=n; i++)
{
	cin>>period[i]>>cost[i];
}

f(1,0); 


cout<<ans;


return 0;
}
