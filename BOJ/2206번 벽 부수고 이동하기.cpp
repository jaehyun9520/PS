#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};


struct state{
	int x; int y; int move; int use;
	
      state(int a, int b, int c, int d)
	     {
	     	x=a; y=b; move=c; use=d;
		 }
};


int map[1001][1001];
int check[2][1001][1001];
int main()
{
//freopen("input.txt", "rt", stdin);	
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

queue <state> Q;
int n,m,i,j,ans=1000000,x,y,xx,yy,move,use;
string input="";
cin>>n>>m;

for(i=1; i<=n; i++)
{
	cin>>input;
	for(j=1; j<=m; j++)
	{
		map[i][j]=input[j-1]-48;
	}
}
check[0][1][1]=1;
Q.push(state(1,1,1,0));

while(!Q.empty())
{
	x=Q.front().x; 
	y=Q.front().y;
	move=Q.front().move;
	use=Q.front().use;
	Q.pop();
	
	
	if(x==n&&y==m) //목적지에 도착  
	{
		if(ans>move) ans=move;
	}

	for(i=0; i<=3; i++)
	{
		xx=x+dx[i]; yy=y+dy[i];
		
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			if(map[xx][yy]==0&&check[use][xx][yy]==0)  
			{
				check[use][xx][yy]=1;
				Q.push(state(xx,yy,move+1,use));
			}
			
			else if(map[xx][yy]==1&&use==0&&check[1][xx][yy]==0)  
			{                                                          
				check[1][xx][yy]=1;
				Q.push(state(xx,yy,move+1,use+1));
			}
			
		}
	}
	
	
}
if(ans!=1000000)   
cout<<ans;

else
cout<<"-1";

return 0;
}
