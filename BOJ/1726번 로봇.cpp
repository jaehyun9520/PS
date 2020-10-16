#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int dx1[5]={0,0,1,0,-1};     // 동 남 서 북 으로 진행    
int dy1[5]={0,1,0,-1,0}; 

struct state{
	
	int x;
	int y;
	int dir;
	int cnt;
	 
	   state(int a, int b, int c , int d)
	   {
	   	x=a; y=b; dir=c; cnt=d;
	   }
	
};

int main()
{	
//freopen("input.txt", "rt", stdin);
int i,j,m,n,x,y,dir,cnt,xx,yy,dx,dy,ddir,flag=0,tmp,ans=10000,turn,turn1;
int map[101][101]={0};
int check[5][101][101]={0};

queue <state> Q;

scanf("%d %d",&m,&n);

for(i=1; i<=m; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
	}
}

for(i=1; i<=2; i++)
{
	scanf("%d %d %d",&dx,&dy,&ddir);
	if(i==1) {
		if(ddir==2) ddir=3;  else if(ddir==3)  ddir=2;
	
			Q.push(state(dx,dy,ddir,0)); 
	check[ddir][dx][dy]=1;
}
	if(ddir==2) ddir=3;  else if(ddir==3)  ddir=2;
	 
}

while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	dir=Q.front().dir;
	cnt=Q.front().cnt;
	Q.pop();

	if(x==dx&&y==dy) // 둘다 같은 칸에 있다면? 
	{
		if(abs(dir-ddir)==3) turn=1;    // 1 4  4 1 과 같은경우는  3번이 아니라 한번만 움직이면   
		else                            //되므로 1로 바꿔줌 
		{
		  turn=abs(dir-ddir); }  // 그외에는 두 방향을 뺀 값에 절대값을 주면 됨  
		tmp=cnt+turn;
		if(ans>tmp)  ans=tmp;
	 } 
	
	
	for(i=1; i<=4; i++) 
	{
	    xx=x; yy=y; 
	    flag=0;
	    
	    if(abs(dir-i)==3)  turn=1;  
	    else  {
		turn=abs(dir-i);}
	    
	   for(j=1; j<=3; j++)
	   {
	   
		xx=xx+dx1[i];
		yy=yy+dy1[i];
		
		
		if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&flag==0)
		{
			flag=1;		
			if(map[xx][yy]==0)   
			{
				flag=0;
				if(check[i][xx][yy]==0||check[i][xx][yy]>cnt+1+turn)  //아예 방문한적 없거나 
				{			                 // 기록된 명령횟수보다 지금 접근하려는 경우의 명령횟수가 적은경우 갱신 후 방문  
				if(xx==dx&&yy==dy)
				{				
					if(abs(i-ddir)==3) turn1=1;
				   
				   
				   else  { turn1=abs(i-ddir); }
					
					tmp=cnt+1+turn+turn1;
					
					if(ans>tmp) ans=tmp;		
				}				
				else{
					check[i][xx][yy]=cnt+1+turn;
					
					Q.push(state(xx,yy,i,cnt+1+turn));
					
				}
			}
			}
		}
}
	}	
}
printf("%d",ans);

return 0;
}
