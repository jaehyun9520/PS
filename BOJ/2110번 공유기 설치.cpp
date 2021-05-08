#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int n,c;
vector <int> list;

int check(int x)
{
	int cnt=1 ,val=list[0];
	
	for(int i=1; i<n; i++)
	{
		if(list[i]-val>=x)
		{
			cnt++;
			val=list[i];
			
			if(cnt>=c)
			{
				return cnt;
			}
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
int i,val,mid,lt,rt,ans=0;

cin>>n>>c;

for(i=1; i<=n; i++)
{
	cin>>val;
	list.push_back(val);
}
sort(list.begin(),list.end());

lt=1; rt=list[n-1];

while(lt<=rt)
{
	mid=(lt+rt)/2;
	
	if(check(mid)>=c)
	{
		ans=mid;
		lt=mid+1;
	}
	
	else
	{
		rt=mid-1;
	}
	
}
cout<<ans;

return 0;
}
