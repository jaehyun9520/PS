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
	int val=0;

	for(int i=0; i<m; i++)
	{
	
		if(list[i]-x<=val)
		{
			val=list[i]+x;
			
			if(val>=n) return 1;
		}
		
		else{
			return 0;
		}
	}
	
	return 0;
}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,val,low,high,mid,ans=0;

cin>>n>>m;

for(i=1; i<=m; i++)
{
	cin>>val;
	list.push_back(val);
}
list.push_back(n);

low=1; high=100000;

while(low<=high)
{
	mid=(low+high)/2;
	
	if(check(mid))
	{
		ans=mid;
		high=mid-1;
	}
	
	else{
		low=mid+1;
	}
	
	
}


cout<<ans;
return 0;
}
