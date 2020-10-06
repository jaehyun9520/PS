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
	int dis;  // 몇번이동했는지 
	int dir;  //방향  
	int cnt;  // 배달상태  
	
	state(int a, int b, int c, int d,int e)
	{
		x=a;
		y=b;
		dis=c;
		dir=d;
		cnt=e;
	}
};

int main()
{	
//freopen("input.txt", "rt", stdin);
int n,m,i,j,x,y,xx,yy,cnt=0,dir,dis;
int map[51][51];
int check[3][4][51][51]={0};

/*
맨앞 3은  0 : 어느곳에도 배달을 못한 상태
          1 : C중 하나인 1에 배달한 상태 
		  2:  C중 하나인 2에 배달한 상태
		  
4는 방향 		   

*/
char a[51];

queue <state> Q;

scanf("%d %d",&n,&m);
for(i=1; i<=n; i++)
{
	scanf("%s",a);
	for(j=1; j<=m; j++)
	{
		map[i][j]=a[j-1];
		
		if(map[i][j]=='S')
		{
		   map[i][j]='.';
		   
		   Q.push(state(i,j,0,-1,0));
		}
		
		if(map[i][j]=='C')  // 배달지를 1과 2로 다시 표시  
		{ 
		
			if(cnt==0)
			{
			
			map[i][j]='1' ,cnt++;
		}
		else
		{
			map[i][j]='2';
		}
		}
		
	}
}


while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	dis=Q.front().dis;
	dir=Q.front().dir;
	cnt=Q.front().cnt;     
	Q.pop();
	

	for(i=0; i<=3; i++)
	{
		if(dir!=i)
		{
			xx=x+dx[i];
			yy=y+dy[i];
		
			
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
			{
				if(map[xx][yy]=='.'&&check[cnt][i][xx][yy]==0)
				{
					
					
					check[cnt][i][xx][yy]=1;
					Q.push(state(xx,yy,dis+1,i,cnt));
				}
				
				else if(map[xx][yy]=='1'&&check[cnt][i][xx][yy]==0)
				{
					check[cnt][i][xx][yy]=1;
					
					if(cnt==0||cnt==1)
					{
						Q.push(state(xx,yy,dis+1,i,1));
					}
					else if(cnt==2)
					{
						printf("%d",dis+1);
						exit(0);
					}
				}
				
				else if(map[xx][yy]=='2'&&check[cnt][i][xx][yy]==0)
				{
					check[cnt][i][xx][yy]=1;
					
					if(cnt==0||cnt==2)
					{
						Q.push(state(xx,yy,dis+1,i,2));
					}
					
					else if(cnt==1)
					{
						printf("%d",dis+1);
						exit(0);
					}
				
				}
				
				
			}
			
			
			
			
		}
		
		
		
	}
}
printf("-1");

return 0;
}
