#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dz[2]={-1,1};

struct state{
	
	int x;
	int y;
	int z;
	int time;
	
	
	state(int a, int b, int c,int d )
	{
		x=a;
		y=b;
		z=c;
		time=d;
	}
};


int main()
{
//freopen("input.txt", "rt", stdin);
int map[31][31][31]={0};

int l,r,c,i,j,k,x,y,z,time,xx,yy,zz,flag=0;
char a[31];

queue <state> Q;

while(1)
{

scanf("%d %d %d",&l,&r,&c);


if(l==0&&r==0&&c==0)
{
	exit(0);
}

flag=0;

for(i=1; i<=l; i++)
{
	
	for(j=1; j<=r; j++)
	{
		scanf("%s",a);
		
		for(k=0; a[k]!='\0'; k++)
		{
			map[i][j][k+1]=a[k];
			
			if(a[k]=='S')
			{
				Q.push(state(i,j,k+1,0));
			}
			
		}
		
	}

   }
   
  while(!Q.empty()) 
  {
  	x=Q.front().x;
  	y=Q.front().y;
  	z=Q.front().z;
  	time=Q.front().time;
  	Q.pop();
  	
  	
  
  	
  	for(i=0; i<=3; i++)
  	{
  		yy=y+dx[i];
  		zz=z+dy[i];
  		
  		if(yy>=1&&yy<=r&&zz>=1&&zz<=c)
  		{
  			if(map[x][yy][zz]=='.')
  			{
  				map[x][yy][zz]='S';
  				Q.push(state(x,yy,zz,time+1));
			  }
			  
			 if(map[x][yy][zz]=='E') 
			 {
			 	flag=1;
			 	printf("Escaped in %d minute(s).\n",time+1);
			 	break;
			 }
		  }
  		
  	
	  }
	  
	  for(i=0; i<=1; i++)
	  {
	  	xx=x+dz[i];
	  	
	  	
	  	if(xx>=1&&xx<=l)
	  	{
	  		if(map[xx][y][z]=='.')
	  		{
	  			map[xx][y][z]='S';
	  			Q.push(state(xx,y,z,time+1));
			  }
			  
			  if(map[xx][y][z]=='E')
			  {
			  	flag=1;
			  	printf("Escaped in %d minute(s).\n",time+1);
			  	break;
			  }
		  }
	  }
	  
	  if(flag==1)
	  
	  	break;
	  
  	
	}  
	
	if(flag==0)
	{
		printf("Trapped!\n");
	}

while(!Q.empty())
{
	Q.pop();
}

	
}

return 0;
}
