#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int dp[1000001];
int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,min,k,tmp;
int val[4]={};
dp[1]=0;
dp[2]=1;
dp[3]=1;
scanf("%d",&n);

for(i=4; i<=n; i++)
{
	min=500000000;
	tmp=i;
	
	if(tmp%2==0)
	{
		val[1]=dp[tmp/2]+1;
	}
	else
	     val[1]=99999;
	
	if(tmp%3==0)
	{
		val[2]=dp[tmp/3]+1;
	}
	
	else
	{
	
	    val[2]=99999;
    }
	
	val[3]=dp[tmp-1]+1;
	
	
	
	

	
	
	for(k=1; k<=3; k++)
	{
		if(min>val[k])
		min=val[k];
	}
     dp[i]=min;	
	
	
}

printf("%d",dp[n]);

 
return 0;
}
