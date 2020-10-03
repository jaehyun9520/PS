#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
struct state
{
	int x;
	int y;
	int cnt;  
	
	state(int a, int b, int c)
	{
		x=a;
		y=b;
		cnt=c;
	 } 
 } ;


int main()
{	
//freopen("input.txt", "rt", stdin);
int n,m,i,j,x,y,xx,yy,cnt,ans=10000000;
char a[101];
int map[101][101]={0};
int check[101][101];
queue <state> Q;
scanf("%d %d",&m,&n);

for(i=1; i<=n; i++)
{
	scanf("%s",a);
	for(j=1; j<=m; j++)
	{
		check[i][j]=-1;  // -1: 아무도 방문하지 않은 상태  
		map[i][j]=a[j-1]-48;
	}
}

check[1][1]=0;
Q.push(state(1,1,0));


while(!Q.empty())
{
	x=Q.front().x;   // 맵 배열 위치  
	y=Q.front().y;
	cnt=Q.front().cnt;  // 벽을 몇개 부쉈는지? 
	Q.pop();
	
	if(x==n&&y==m)
	{
		printf("0");
		exit(0);
	}
	
if(ans>cnt)
{
	
	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			
			if(map[xx][yy]==0)    // 빈공간  
			{
				if(check[xx][yy]==-1||check[xx][yy]>cnt)  //한번도 방문한적 없는지 또는   
				{                                       //현재 내가 벽을 부순횟수보다 많이 부순상태로 지나갔는지 
				
					check[xx][yy]=cnt;  //그렇다면 벽을 부순 횟수를 더 작게 갱신  
					
					if(xx==n&&yy==m)   // 목적지 도달했는가 
					{
						if(ans>cnt)  ans=cnt;
					
					}
					else  //아니라면 이동  
					{
					
					Q.push(state(xx,yy,cnt));
				}
				}
			}
			
			else if(map[xx][yy]==1)   // 벽을 만난경우  
			{
				if(check[xx][yy]==-1||check[xx][yy]>cnt+1)  // 한번도 방문한적 없는지 또는 
				{                                         //현재 내가 벽을 부순횟수보다 많이 부순상태로 지나갔는지                 
					check[xx][yy]=cnt+1;  
					  
					Q.push(state(xx,yy,cnt+1));
				}
			}
			
		}
	}
}
	
	}
	
	if(ans==10000000)
	printf("-1");

    else 
    printf("%d",ans);
	
return 0;
}
