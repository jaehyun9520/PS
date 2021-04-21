#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int n,m,i,val,lt,rt,ans=2147000000;
vector <int> a;

cin>>n>>m;

for(i=1; i<=n; i++)
{
	cin>>val;
	a.push_back(val);
	
}
sort(a.begin(),a.end());

lt=0; rt=1;

while(rt<a.size())
{
	val=a[rt]-a[lt];
  if(val==m) {
  	ans=m; break;
  }
  
  else if(val>m)
  {
  	lt++;
  	if(lt==rt)  rt++;
  	if(ans>val) ans=val;
  }
  else {
  	rt++;
  }
	
}

cout<<ans;
return 0;
}
