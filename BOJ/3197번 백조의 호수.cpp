#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


char a[1501];
int map[1501][1501]={0};
int check[1501][1501]={0};
int r,c;


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct state{
	
	int x;
	int y;
	int time;
	
	state(int a, int b, int c)
	{
		x=a;
		y=b;
		time=c;
		
	}
};

queue <state> Q;
queue <state> Q1;

void BFS()    
{
	int i,j,x,y,xx,yy,time;
	
	while(!Q1.empty())
{
	x=Q1.front().x;
	y=Q1.front().y;
	time=Q1.front().time;
	Q1.pop();
	
	
	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		
		
		if(xx>=1&&xx<=r&&yy>=1&&yy<=c)
		{
			if(map[xx][yy]=='.'&&check[xx][yy]==1)
			{
				check[xx][yy]=time;
				Q1.push(state(xx,yy,time));
			}
		}
	}
	
}
}

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,time,x,y,xx,yy,nx,ny,cnt=0,lx1,lx2,ly1,ly2,flag=0;
scanf("%d %d",&r,&c);



for(i=1; i<=r; i++)
{
	scanf("%s",a);
	
	for(j=0; a[j]!='\0'; j++)
	{
		map[i][j+1]=a[j];
	
		
		if(a[j]=='.'||a[j]=='L')   // 물이나 백조를 만나면 큐에 넣어준다.  
		{
			Q.push(state(i,j+1,0));
			check[i][j+1]=1;
		}
		
		if(a[j]=='L')
		{
			if(cnt==0)
			{
				lx1=i;
				ly1=j+1;
				cnt++;
			}
			else if(cnt==1)
			{
			
			lx2=i;
			ly2=j+1;
			cnt=0;
		}
		}
	}
}

// 백조가 이동할수있는 물의 범위를 체크배열로 표시해준다. 
Q1.push(state(lx1,ly1,2));   
Q1.push(state(lx2,ly2,3));
check[lx1][ly1]=2;
check[lx2][ly2]=3;
BFS();


while(!Q.empty())
{
	x= Q.front().x;
	y= Q.front().y;
	time=Q.front().time;
	Q.pop();
	

	if(time!=cnt)
	{
 
		cnt++;
		if(flag==1)
		{
			
			printf("%d",cnt);
			exit(0);
		}
		
		
	}
	
	for(i=0; i<=3; i++)    // 큐에 들어있는 물을 하나씩 꺼내서 상하좌우를 확인하며 얼음이 있는지 확인 
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=1&&xx<=r&&yy>=1&&yy<=c)
		{
			
			if(map[xx][yy]=='X')  // 얼음이 있다면? 물로 만들고 체크배열의 값도 어디에 속하는지 바꿔준다. 
			{
				check[xx][yy]=check[x][y];
				map[xx][yy]='.';
			
				Q.push(state(xx,yy,time+1));
							
		// 녹은 얼음의 상하좌우를  탐색한다.  
		// 1 0 0 2  =>   1 1 2 2  이런식으로 되면 2 2 2 2 로 만들어주기 위해서 	
		// 또는 1 0 2  => 1 1 2   => 2 2 2    		
					
					
					for(j=0; j<=3; j++)   
			{
			        nx=xx+dx[j];
			        ny=yy+dy[j];   
			
			
			if(check[xx][yy]==1)   // 백조의 이동범위가 아닌 물이 얼음을 녹이며 퍼지고있을때 
			
			{
				if(check[nx][ny]==2||check[nx][ny]==3)   // 얼음을 녹이고 물로 만들었는데 그 물 주변이 백조의 이동범위일때 
				{
				
				check[xx][yy]=check[nx][ny];     //  물의 범위를 백조의 이동범위로 바꿔준다. 
				Q1.push(state(xx,yy,check[nx][ny]));   
				BFS();
			}
			}
			
			if(check[xx][yy]==2||check[xx][yy]==3) //백조의 이동범위인 물이 얼음을 녹이며 퍼지고있을때 
			{
				if(map[nx][ny]=='.'&&check[nx][ny]==1)  // 백조의 이동범위가 아닌 물공간을 만나게 되면 
				{
					check[nx][ny]=check[xx][yy];   // 그 물공간을 백조의 이동공간으로 표시해준다. 
					Q1.push(state(nx,ny,check[xx][yy]));
					BFS();
				}
		
			
				
			}
			
			if(check[xx][yy]==2)    // 백조1의 이동가능 공간과 2의 이동가능 공간이 만나게 되면 만나게 된거니 flag값을 1로 해준다. 
			{
				if(check[nx][ny]==3)
				{
					flag=1;
				}
			}
			
			if(check[xx][yy]==3)
			{
				if(check[nx][ny]==2)
				{
					flag=1;
				}
			}			
		}
						
			}
			
		}
	}
	
}
return 0;
}
