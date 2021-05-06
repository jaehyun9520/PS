#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int T,n,m,i,j,val,ans,sum;
int l,r,mid;
vector <int> A;
vector <int> B;

cin>>T;

for(i=1; i<=T; i++)
{
	cin>>n>>m;
	
	
    for(j=1; j<=n; j++)
    {
    	cin>>val;
    	A.push_back(val);
	}
	
	for(j=1; j<=m; j++)
	{
		cin>>val;
	    B.push_back(val);
	}
   sort(A.begin(),A.end());
   sort(B.begin(),B.end());
   ans=0;
	
	for(j=0; j<A.size(); j++) 
	{
		val=A[j];  sum=0;
		l=0; r=m-1;
		
		while(l<=r)
		{
			mid=(l+r)/2;
			
		
			
		     if(val>B[mid])
			{
				l=mid+1;
				sum=mid+1;
			}
			
			else
			{
				r=mid-1;
			}
					
		}
		ans+=sum;	
	}
	cout<<ans<<"\n";
	A.clear();
	B.clear();
}


return 0;
}
