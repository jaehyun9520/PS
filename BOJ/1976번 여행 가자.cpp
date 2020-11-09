#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector <int> node(201,-1);


int find(int a)
{
	if(node[a]==-1) return a;
	
	else return node[a]=find(node[a]);
}


void Union(int a, int b)
{
	a=find(a);
	b=find(b);
	
	
	if(a!=b)
	{
		node[a]=b;
	}
	
}



int main()
{
//freopen("input.txt", "rt", stdin);	
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,m,i,j,val,flag=0,plan=0;
int connect[201][201]={0};

cin>>n; cin>>m;

for(i=1; i<=n; i++)
  {
  	for(j=1; j<=n; j++)
  	{
  		cin>>connect[i][j];
  		
  		if(connect[i][j]==1)
  		{
  			
  			if(find(i)!=find(j)) 
			  {
			
             Union(i,j);
  		  }
		  }
  		
	}
  }

for(i=1; i<=m; i++)
{
	cin>>val;
	if(plan==0) plan=find(val);
	
	else{
		if(plan!=find(val)) flag=1;
	}
}

if(flag==0) cout<<"YES";
else cout<<"NO";

return 0;
}
