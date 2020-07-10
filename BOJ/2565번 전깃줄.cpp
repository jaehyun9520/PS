#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;







int main()
{
//freopen("input.txt", "rt", stdin);
int dp[501]={ };
int arr[501]={ };
int n,i,j,a,b,max=0;

scanf("%d",&n);

for(i=1; i<=n; i++)
{
	scanf("%d %d",&a,&b);
	arr[b]=a;
	
}


for(i=1; i<=500; i++)
{
	if(arr[i]!=0)
	     
	  {
	  	 dp[i]=1;
	  	
	  	for(j=1; j<i; j++)
	  	{
	  		if(arr[j]<arr[i])
	  		{
	  			if(dp[i]<dp[j]+1)
	  			{
	  				dp[i]=dp[j]+1;
				  }
			  }
			  
		  }
		  if(max<dp[i])
		  {
		  	max=dp[i];
		  }
	  }
}

printf("%d",n-max);

return 0;
}
