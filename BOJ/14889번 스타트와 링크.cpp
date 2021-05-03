#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;

int check[21]={0};
int stat[21][21]={0};
int n,ans=214700000;

void select(int cnt, int number)
{
	int sum1=0 , sum2=0;
	
	if(cnt==n/2)  
	{	
		for(int i=1; i<=n; i++)
		{
			if(check[i]==1)
			{
				for(int j=1; j<=n; j++)
			    {
		          if(check[j]==1)
				   {
					sum1=sum1+stat[i][j];
				   }
			    }
		
			}
			
			else
			{
			    for(int j=1; j<=n; j++)
			    {
		      
				   if(check[j]==0)
				   {
					sum2=sum2+stat[i][j];
				   }
				
			    }
		    }
		  }

		if(ans>abs(sum1-sum2))
		{
			ans=abs(sum1-sum2);
		}
	}

	else   
	{
	for(int i=number; i<=n; i++)
	   {
	      check[i]=1;
		  select(cnt+1,i+1);
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
		cin>>stat[i][j];
	}
}
select(0,1);
cout<<ans;

return 0;
}
