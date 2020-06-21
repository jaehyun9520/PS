#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector < pair < int , int > > body;
int val=0;   
int n;
int map[101][101]={0}; 
int time[10001]={0};
char dir[10001];  
int cnt=0;  // 시간초 
int direct=0;  //방향 

void DFS(int x, int y)
{ int xx, yy;
	if(time[cnt]==1)
	{
		if(dir[cnt]=='L')
		{
			direct=direct-1;
			if(direct==-1)
			{
			
			   direct=3;
		}
		}
		if(dir[cnt]=='D')
		{
			direct=direct+1;
			if(direct==4)
			{
			
			direct=0;
			
			}
		}
		
	}
	
	
	xx=x+dx[direct];
	yy=y+dy[direct];
	cnt++;
	
	
	
	if(map[xx][yy]==1||xx==0||xx==n+1||yy==0||yy==n+1)
	{ 
	    printf("%d",cnt);
		exit(0);   
	}
	
	if(map[xx][yy]==2)
	{
		body.push_back(make_pair(xx,yy));
		map[xx][yy]=1;
		DFS(xx,yy);
	}
	
	else if(map[xx][yy]==0)
	{
		map[body[val].first][body[val].second]=0;
		map[xx][yy]=1;
		body.push_back(make_pair(xx,yy));
		val++;		
		DFS(xx,yy);
	}
	
	
}
int main()
{
//freopen("input.txt", "rt", stdin);
int k,i,j,a,b,L,tmp;
char value;

scanf("%d",&n); 
scanf("%d",&k);

for(i=1; i<=k; i++)
{
	scanf("%d %d",&a,&b);
	map[a][b]=2;
}

scanf("%d",&L);

for(i=1; i<=L; i++)
{
	scanf("%d %c",&a,&value);
	
	dir[a]=value;
	tmp=a;
	time[tmp]=1;	
}

map[1][1]=1;
body.push_back(make_pair(1,1));
DFS(1,1);
return 0;
}
