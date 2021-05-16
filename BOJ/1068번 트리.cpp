#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
vector <int> node[51];
int del,ans=0;


void DFS(int n)
{
	
	
	int cnt=0;
	if(node[n].size()==0) 
	{ 
    
	ans++;
     }
	
	else
	{
		for(int i=0; i<node[n].size(); i++)
		{
			if(node[n][i]!=del)
			{
				DFS(node[n][i]);
				cnt++;
			}
			
		}
		
		
		if(cnt==0)
		{
			
			ans++;
		}
		
		
	}
	
	
	
	
}
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,val,root;

cin>>n;

for(int i=0; i<n; i++)
{
	cin>>val;
	
	if(val==-1)
	root=i;
	
	else
	node[val].push_back(i);
	
}

cin>>del;
if(del!=root)
{

DFS(root);
}

cout<<ans;

return 0;
}
