#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int n,m; 
vector <int> list; 

int check(int x)
{
	 
	int cnt=1, sum=list[0];
	
    for(int i=1; i<n; i++)
	{
		
			if(sum+list[i]<=x)
			{	
			    sum+=list[i];
			 } 
			 
		
			 
		    else if(sum+list[i]>x)
			{
				sum=list[i];
				cnt++;
			  }  
			  
			  	if(cnt>m)
				{
					return cnt;
				}
	
		
	
		
		}	
	return cnt;
}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,val,low=0,high=0,mid,ans=0;
cin>>n>>m;

for(i=1; i<=n; i++)
{
	cin>>val;
	high+=val;
	
	if(low<val) low=val;
	
	list.push_back(val);
}



while(low<=high)
{
	mid=(low+high)/2;
	
	
	
	if(check(mid)<=m)
	{
		ans=mid;
	
		high=mid-1;
	}
	
	else
	{
		low=mid+1;
	}
	
}


cout<<ans;
return 0;
}
