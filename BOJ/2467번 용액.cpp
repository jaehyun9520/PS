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

long long n,i,val,s,e,ans1,ans2,ans=2147000000;
vector <long long> array;

cin>>n;

for(i=1; i<=n; i++)
{
	cin>>val;
	array.push_back(val);
}
sort(array.begin(),array.end());


s=0; e=n-1;

while(s!=e)
{
	if(ans>abs(array[s]+array[e]))
	{
		ans1=array[s], ans2=array[e];
		ans=abs(array[s]+array[e]);
		
		
		if(abs(ans1)==abs(ans2))  
	    {
	    	break; 
		}
	}
	
	
	if(abs(array[s])>abs(array[e]))
	{
		s++;
	}
	
	else if(abs(array[s])<abs(array[e]))
	{
		e--;
	}
	

	
}

cout<<ans1<<" "<<ans2;

return 0;
}
