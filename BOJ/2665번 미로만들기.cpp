#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


struct state{
	int x;
	int y;
	int cnt;
	
	state(int a, int b, int c)
	{
		x=a; y=b; cnt=c;
	}
};

int main()
{	
//freopen("input.txt", "rt", stdin);
int n,i,j,x,y,nx,ny,cnt,ans=10000;
int map[51][51]={0};
int check[51][51];
char input[51];
queue <state> Q;
scanf("%d",&n);

for(i=1; i<=n; i++)
{
	scanf("%s",input);
	
	for(j=1; j<=n; j++)
	{
		map[i][j]=input[j-1]-48;
		check[i][j]=-1;
	}
}
check[1][1]=0;
Q.push(state(1,1,0));


while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	cnt=Q.front().cnt;
	Q.pop();
	
	for(i=0; i<=3; i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&cnt<ans)
		{
		
			if(map[nx][ny]==1)  
			{
				if(check[nx][ny]==-1||cnt<check[nx][ny])   // -1: 한번도 방문 안한곳  , 현재 방을 바꾼개수보다 기록된 
				{                                          //개수가 크면  현재 방을 바꾼개수를 기록해주기    
					check[nx][ny]=cnt;
					Q.push(state(nx,ny,cnt));
					
				}
				
				if(nx==n&&ny==n)
				{
					if(cnt<ans)  ans=cnt;
				 } 
				 
			}
			
			
			else if(map[nx][ny]==0)
			{
				if(check[nx][ny]==-1||cnt+1<check[nx][ny])
				{
					check[nx][ny]=cnt+1;
					Q.push(state(nx,ny,cnt+1));
				}
			}
			
			
		}
	}
}

printf("%d",ans);


return 0;
}
