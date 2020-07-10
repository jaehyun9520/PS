#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



int dp[1001]={ };
int arr[1001]={ };


int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,j,max=-123;
scanf("%d",&n);


for(i=1; i<=n; i++)
{
	scanf("%d",&arr[i]);
}

for(i=1; i<=n; i++)
{
	
	dp[i]=1;
	for(j=1; j<i; j++)
	{
		if(arr[i]>arr[j])
		{
			if(dp[i]<dp[j]+1)
			{
				dp[i]=dp[j]+1;
			}
		}
	}
}



for(i=1; i<=n; i++)
{
	if(max<dp[i])
	{
		max=dp[i];
	}
}

printf("%d",max);
return 0;
}
