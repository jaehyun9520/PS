#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
vector <int> a;
int m;


unsigned long long check(unsigned long long x)
{
	int i;
	unsigned long long cnt=0;
	
	
	for(i=0; i<a.size(); i++)
	{
		cnt=cnt+x/a[i];
		
		
		if(cnt>=m)
		{
			break;
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

int n,i,val;
unsigned long long lt,rt,mid,ans;

cin>>n>>m;

for(i=1; i<=n; i++)
{
	cin>>val;
	a.push_back(val);
}

sort(a.begin(),a.end());

lt=1; rt=(long long)a[0]*m;

while(lt<=rt)
{
	mid=(lt+rt)/2;
	
	if(check(mid)>=m)
	{
		ans=mid;
		rt=mid-1;
		
	}
	else {
		
		lt=mid+1;
	}
	
	
}

cout<<ans;

return 0;
}
