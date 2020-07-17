#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,k;
long long ans=0;
stack <int> s;
scanf("%d",&n);



for(i=1; i<=n; i++)
{
	scanf("%d",&k);
	
	
	while(!s.empty()==1&&s.top()<=k)
	{
		
		s.pop();
	}
	ans=ans+s.size();
	
	s.push(k);
}




printf("%lli",ans);
return 0;
}
