#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,n,m,L,x,y,low,high,mid,ans=0;
vector <int> list;

cin>>m>>n>>L;

for(i=1; i<=m; i++)
{
	cin>>x;
	list.push_back(x);
}

sort(list.begin(),list.end());

for(i=1; i<=n; i++)
{
	cin>>x>>y;
	
	low=0; high=m-1;
	
	
	while(low<=high)
	{
		
	
		mid=(low+high)/2;
		
		
		if(abs(list[mid]-x)+y<=L)
		{
			ans++;
			break;
		}
		
		else{
			
			if(list[mid]>x) high=mid-1;
			
			else if(list[mid]<x)  low=mid+1;
			
			else if(list[mid]==x)  break;
		}
		
		
	}
}

cout<<ans;
return 0;
}
