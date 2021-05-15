#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int answer[100001];
int check[100001];

vector <int> node[100001];


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,i,a,b;
queue <int> Q;
cin>>n;

for(i=1; i<n; i++)
{
	cin>>a>>b;
	
	node[a].push_back(b);
	node[b].push_back(a);
}

Q.push(1);


while(!Q.empty())
{
	int now=Q.front();
	Q.pop();
	check[now]=1;
	
	
	for(int i=0; i<node[now].size(); i++)
	{
		if(check[node[now][i]]==0)
		{
			answer[node[now][i]]=now;
			Q.push(node[now][i]);
			
		}
	}
	
}

for(i=2; i<=n; i++)
{
	cout<<answer[i]<<"\n";
}

return 0;
}
