#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

vector <int> a;

int check(int x)
{
	int cnt=0,i,loc=0,val;
	
	for(i=0; i<a.size(); i++)
	{
	        val=a[i]-loc;
	        
	        
	        
	if(val>x)  
	{
		  
		  if(val%x==0)
        {
        	cnt=cnt+(val/x)-1; 
		}
	 
	    else if(val%x!=0)
	    {
	    	cnt=cnt+(val/x);
		}
	}
        
	 
	 
	 loc=a[i];
	 }
	 
	
	 return cnt;
}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int n,m,l,lt,rt,mid,i,val,ans=31470000;

cin>>n>>m>>l;

for(i=1; i<=n; i++)
{
	cin>>val;
	a.push_back(val);
}

a.push_back(l);
sort(a.begin(),a.end());

lt=0; rt=l;

while(lt<=rt)
{
	mid=(lt+rt)/2;
	
	if(check(mid)<=m)
	{
		if(ans>mid)
		{
		
		ans=mid;
	}
		rt=mid-1;
	}
	
	else{
		lt=mid+1;
	}
}

cout<<ans;
return 0;
}
