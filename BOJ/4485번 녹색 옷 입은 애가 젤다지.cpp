#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#define MAX 21470000
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct state {
	int x, y, cost;
	
	state(int a, int b, int c)
	{
		x=a; y=b; cost=c;
	}
	
	
	bool operator<(const state &b) const
	{
		return cost>b.cost;  
	}
};

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,i,j,x,y,nx,ny,cost,cnt=0;
int map[125][125];
int check[125][125];

priority_queue <state> PQ; 

while(1)
{
	cnt++;
	cin>>n;
	if(n==0) break;
	
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cin>>map[i][j];
			check[i][j]=MAX;
		}
	}
	
	check[0][0]=map[0][0];
	PQ.push(state(0,0,map[0][0]));
	
	
	while(!PQ.empty())
	{
		x=PQ.top().x;
		y=PQ.top().y;
		cost=PQ.top().cost;
		PQ.pop();

		if(x==n-1&&y==n-1) 
		{
		
		 cout<<"Problem "<<cnt<<": "<<cost<<"\n";
		 
		 while(!PQ.empty())  PQ.pop();
		
	     }
		for(i=0; i<=3; i++)
		{
			nx=x+dx[i];
			ny=y+dy[i];
		
			if(nx>=0&&nx<=n-1&&ny>=0&&ny<=n-1)
			{
				if(check[nx][ny]>map[nx][ny]+cost)
				{
					check[nx][ny]=map[nx][ny]+cost;
					PQ.push(state(nx,ny,check[nx][ny]));
				}
			}
			
		}
		
	}
	
}


return 0;
}
