#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


char input[51];
int map[51][51]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int check[51][51]={0};
struct state{
	int x;
	int y;
	int time;
	int flag;
	
	state(int a, int b, int c,int d)
	{
		x=a;
		y=b;
		time=c;
		flag=d;
		
	}
	
};


int main()
{
//freopen("input.txt", "rt", stdin);
int r,c,i,j,x1=0,y1=0,xx,yy,time,flag;


queue <state> Q;
scanf("%d %d",&r,&c);

for(i=1; i<=r; i++)
{
	scanf("%s",input);
	  
	  for(j=0; input[j]!='\0'; j++)
	  {
	  	map[i][j+1]=input[j];
	  	
	  	if(input[j]=='S')
	  	{
	  		 x1=i;
	  		 y1=j+1;
	  		
		  }
		if(input[j]=='*')
		{
			Q.push(state(i,j+1,0,1));
		}
	  }
	
}
Q.push(state(x1,y1,0,0));

while(!Q.empty())
{
	x1=Q.front().x;
	y1=Q.front().y;
	time=Q.front().time;
	flag=Q.front().flag;
	
	Q.pop();

if(flag==0)
{
	map[x1][y1]='.';
	check[x1][y1]=1;
}
	
		for(int i=0; i<=3; i++)
		{
			xx=x1+dx[i];
			yy=y1+dy[i];
			
			if(xx>=1&&xx<=r&&yy>=1&&yy<=c)
			{
				if(flag==1&&map[xx][yy]=='.')
				{
					map[xx][yy]='*';
					Q.push(state(xx,yy,time+1,flag));
				}
				
				else if(flag==0)
				{
					if(map[xx][yy]=='.'&&check[xx][yy]==0)
					{   
						map[xx][yy]='S';
						
						
						
						Q.push(state(xx,yy,time+1,flag));
					}
					
					else if(map[xx][yy]=='D')
					{
						printf("%d",time+1);
						exit(0);
					}
				}
			}
		}
	}


printf("KAKTUS");
return 0;
}
