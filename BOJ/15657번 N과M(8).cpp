#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n,m;

vector <int> list;
int ans[9]={0};


void DFS(int sum, int cnt)
{
	if(cnt==m)
	{
		for(int i=1; i<=m; i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	
	
	else{
		
		  for(int i=sum; i<n; i++)
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
cin>>n>>m;
int val;

for(int i=1; i<=n; i++)
{
	cin>>val;
	list.push_back(val);
}

sort(list.begin(),list.end());


DFS(0,0); 


return 0;
}
