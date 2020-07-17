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
	int time;
	int area;
	
	state(int a, int b, int c, int d)
	{
		x=a;
		y=b;
		time=c;
		area=d;
	}
};

int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,j,k=0,cnt=0,x=0,y=0,xx=0,yy=0,time=0,area=0,min=9999999,flag=0;
int map[101][101]={0};
int check[101][101]={0};

queue <state> Q;
scanf("%d",&n);

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
	}
}



for(i=1; i<=n; i++)  
{
	for(j=1; j<=n; j++)
	{
		if(map[i][j]==1&&check[i][j]==0)
		{
			cnt++;
			check[i][j]=1;
			map[i][j]=cnt;
			Q.push(state(i,j,0,0));
			
			
			
			while(!Q.empty())
			{
				x=Q.front().x;
				y=Q.front().y;
				Q.pop();
				
				for(k=0; k<=3; k++)
				{
					xx=x+dx[k];
					yy=y+dy[k];
					
					if(xx>=1&&xx<=n&&yy>=1&&yy<=n)
					{
						if(check[xx][yy]==0&&map[xx][yy]==1)
						{
							check[xx][yy]=1;
							map[xx][yy]=cnt;
							Q.push(state(xx,yy,0,0));
						}
					}
				}
			}
		}
	}
}


for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		check[i][j]=0;
	}
}



for(i=1; i<=n; i++)      
{
	for(j=1; j<=n; j++)
	{
		if(map[i][j]!=0&&check[i][j]==0)
		{   
		    
			check[i][j]=1;
		
			Q.push(state(i,j,0,map[i][j]));
			
			
			
			while(!Q.empty())
			{
			     x=Q.front().x;
				 y=Q.front().y;
				 time=Q.front().time;
				 area=Q.front().area;
				 Q.pop(); 
				 
				 
				 for(k=0; k<=3; k++)
				 {
				 	xx=x+dx[k];
				 	yy=y+dy[k];
				 	
				 	
				 	if(xx>=1&&xx<=n&&yy>=1&&yy<=n)
				 	
				 	{ 
					    if(map[xx][yy]!=0&&map[xx][yy]!=area)  
					 {
					 	if(min>time)
					 	{
					 		min=time;
						 }
					 	
					 }
					 
					 else if(min>time+1){ 
					 
				 	
				 	if(map[xx][yy]==area&&check[xx][yy]==0)    
				 	{
				 		check[xx][yy]=1; 
				 		Q.push(state(xx,yy,0,area));
					 }
					 
					 if(map[xx][yy]==0&&check[xx][yy]==0) 
					 {
					 	check[xx][yy]=time+1;
					 	Q.push(state(xx,yy,time+1,area));
					 }
					 
					 if(map[xx][yy]==0&&check[xx][yy]!=0)  
					 {
					 	if(check[xx][yy]>time+1) 
					 	{
					 		check[xx][yy]=time+1;
					 		Q.push(state(xx,yy,time+1,area));
						 }
					 }
				}
					 
					 
				}
				 }
			
			}
		}
	}
	
	
}

printf("%d",min);

return 0;
}
