#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main()
{
int n,a,i,c;
stack < pair < int , int > > s;

scanf("%d",&n);
vector <int> ans(n+1);


for(i=1; i<=n; i++)
{
	scanf("%d",&a);
	while(!s.empty())
	       {
	       	
	       	     if(s.top().first>a)
	       	     {
					  
	       	        ans[i]=s.top().second;
	       	             break;
	       	    }
	       	    if(s.top().first<a)
	       	    {
	       	    	s.pop();
				   }
				}     
				
				
				s.push(make_pair(a,i));
}

for(i=1; i<=n; i++)
{
	printf("%d ",ans[i]);
}
return 0;
}
