#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set> 
using namespace std;
int n,m;
vector <int> list;
int ans[9];
set <int> s;

void DFS( int num,int cnt)
{

	if(cnt==m)
	{
		for(int i=1; i<=m; i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<"\n";	
	}
	else
	{
		for(int i=num; i<list.size(); i++)
		{
		        cnt++;
				ans[cnt]=list[i];		
				DFS(i,cnt);				
				cnt--;	
		}
		
	}
	
}



int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int val;
cin>>n>>m;


for(int i=1; i<=n; i++)
{
	cin>>val;
	
if(s.find(val)==s.end())
{
	s.insert(val);
	list.push_back(val);
}
   
}
sort(list.begin(),list.end());


DFS(0,0);

return 0;
}
