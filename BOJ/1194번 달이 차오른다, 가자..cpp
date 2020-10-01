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
	int key;
	
	state(int a, int b, int c,int d)
	{
		x=a;
		y=b;
		cnt=c;
		key=d;
	}
}; 

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,n,m,x,y,xx,yy,k,cnt,tmp;  
int map[51][51]={0};
int check[64][51][51]={0};
char a[51];
queue <state> Q;
scanf("%d %d",&n,&m);

for(i=1; i<=n; i++)
{
	scanf("%s",a);
	
	for(j=1; j<=m; j++)
	{
		map[i][j]=a[j-1];
		if(map[i][j]=='0') //시작지점  
		{
			map[i][j]='.';
			check[0][i][j]=1;    
			Q.push(state(i,j,0,0));
		}
	}
}

while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	cnt=Q.front().cnt; //이동횟수  
	k=Q.front().key;  // 키 보유 현황 
	Q.pop();

	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			
			if(map[xx][yy]=='.'&&check[k][xx][yy]==0)  //빈공간일 경우  
			{
				
				check[k][xx][yy]=1;
				Q.push(state(xx,yy,cnt+1,k));
			}
			
			else if('a'<=map[xx][yy]&&map[xx][yy]<='f'&&check[k][xx][yy]==0)  //열쇠를 발견한경우  
			{
				
				if( (k&(1<<(map[xx][yy]-97)))==0) // 보유하고 있지않은  새로운 키인가? 
				{
				
					tmp=k|(1<<(map[xx][yy]-97));  // 키 보유 목록에 추가  
				
					check[tmp][xx][yy]=1;
				Q.push(state(xx,yy,cnt+1,tmp));
					
				}
				else{
				
				check[k][xx][yy]=1;          // 이미 보유중이라면 그대로 진행  
				Q.push(state(xx,yy,cnt+1,k));
			}
			}
			
			
		   else if('A'<=map[xx][yy]&&map[xx][yy]<='F'&&check[k][xx][yy]==0) // 문발견   
		   {
		 
		   	       if(k&(1<<(map[xx][yy]-65)))  // 문을 열수있는 키를 보유하고있는가? 
		   	       {
		   	       	 
		   	       	  check[k][xx][yy]=1;   // 보유중이라면 열고 진행  
		   	       	  
		   	       	  Q.push(state(xx,yy,cnt+1,k));
					  }
			} 
			
			
			else if(map[xx][yy]=='1')    // 출구발견 
			{
				printf("%d",cnt+1);
				exit(0);
			}
		}
	}
}
printf("-1 \n");   


return 0;
}
