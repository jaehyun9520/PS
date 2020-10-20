#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

struct state{
	
	int x;
	int y;
	int who; //  0이면 벽 , 1이면 욱제  
	int time;
	state(int a, int b, int c, int d)
	{
		x=a; y=b; who=c, time=d;
	}
};


int dx[8]={1,-1,0,0,-1,1,1,-1};  // 상하좌우 대각선  
int dy[8]={0,0,1,-1,1,1,-1,-1};
int main()
{	
//freopen("input.txt", "rt", stdin);
int i,j,x,y,xx,yy,who,time;
int map[9][9]={0};
int check[16][9][9]={0};
char a[9];

queue <state> Q;

for(i=1; i<=8; i++)
{
	scanf("%s",a);
	
	for(j=1; j<=8; j++)
	{
		map[i][j]=a[j-1];
	}
}
Q.push(state(8,1,1,0));
check[0][8][1]=1;  // 시작위치  
for(i=8; i>=1; i--)
{
	for(j=1; j<=8; j++)
	{
		if(map[i][j]=='#') Q.push(state(i,j,0,0));
	}
}

while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	who=Q.front().who;
	time=Q.front().time;
	Q.pop();
	if(who==0)  //돌이면 한칸씩 밑으로 내려가자  
	{
		map[x][y]='.';
		
	    if(x+1<=8)
	    {
		
		map[x+1][y]='#';
		Q.push(state(x+1,y,0,0));
	}
	}
	
	if(who==1&&map[x][y]=='.'&&time<=15)   // 욱제면 가능한 위치로 이동  
	{
		Q.push(state(x,y,1,time+1));
		
		for(i=0; i<=7; i++)
		{
			xx=x+dx[i];
			yy=y+dy[i];
			
		     if(xx>=1&&xx<=8&&yy>=1&&yy<=8)
		     {
		     	if(map[xx][yy]=='.'&&check[time][xx][yy]==0)
		     	{

		     		if(xx==1&&yy==8) 
					 {
					 	
					   printf("1");
					   exit(0);
		     	}
		     
		     		check[time][xx][yy]=1;

		     		Q.push(state(xx,yy,1,time+1));
		     	
				 }
		     	
			 }
		}	
	}	
}

printf("0");
return 0;
}
