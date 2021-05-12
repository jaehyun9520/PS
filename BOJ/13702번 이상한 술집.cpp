#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int n,k;
vector <int> list;

int check(int x)
{
	int cnt=0; 
	
	for(int i=0; i<n; i++)
	{
		cnt=cnt+list[i]/x;
		
		if(cnt>=k)
		
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
int val,ans=0,i;
long long low,mid,high;
cin>>n>>k;

for(i=1; i<=n; i++)
{
	cin>>val;
	list.push_back(val);
}

sort(list.begin(),list.end());

low=1; high=list[n-1];


while(low<=high)
{
	mid=(low+high)/2;
	
	if(check(mid)>=k) 
	{
		ans=mid;
		low=mid+1;
	}
	
	else
	{
		high=mid-1;
		
	}
	
	
}

cout<<ans;

return 0;
}
