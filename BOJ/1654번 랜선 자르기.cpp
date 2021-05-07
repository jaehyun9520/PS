#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
vector <int> list;
int k,n; 


int check(long long x)
{
	int sum=0;
	
	for(int i=0; i<k; i++)
	{
		if(list[i]/x>0)
		{
			sum=sum+list[i]/x;
			
			if(sum>=n)
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
int i,val,ans=0;
long long lt,rt,mid;

cin>>k>>n;

for(i=0; i<k; i++)
{
	cin>>val;
	list.push_back(val);
}

sort(list.begin(),list.end());

lt=1; rt=list[k-1];


while(lt<=rt)
{
	mid=(lt+rt)/2;
	
	if(check(mid)>=n)
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
