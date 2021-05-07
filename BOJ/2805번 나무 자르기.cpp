#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
vector <int> tree;
int n,m;

long long check(int x)
{
	long long sum=0;
	for(int i=0; i<n; i++)
{
	if(tree[i]-x>0)
	{
		sum= sum+tree[i]-x;
		
		if(sum>=m)
		{
			return sum;
		}
	}
	
}

return sum;	
	
}



int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,val,ans;
long long lt,rt,mid;

cin>>n>>m;

for(i=1; i<=n; i++)
{
	cin>>val;
	tree.push_back(val);
}

sort(tree.begin(),tree.end());

lt=0; rt=tree[n-1];

while(lt<=rt)
{
	mid=(lt+rt)/2;
	
	if(check(mid)>=m)
	{
		ans=mid;
		lt=mid+1;
	}
	
	else{
		rt=mid-1;
	}
	
}

cout<<ans;
return 0;
}
