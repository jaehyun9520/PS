#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dx[9]={0,-1,-1,0,1,1,1,0,-1};
int dy[9]={0,0,-1,-1,-1,0,1,1,1};

int ans=0;

struct state{
	int x;
	int y;
	int dir;
	
	state(int a, int b, int c)
	{
		x=a;
		y=b;
		dir=c;
	}
	
	
};

void func(int sum,int pos[][4],int dir[][4])
{
	
	if(sum>ans)
	{
		
		ans=sum;
	}
	
	int i,j,k,x,y,xx,yy,dir2,tmp1,tmp2,flag,sx=0,sy=0,sdir=0,end=9;
	
	vector <state> fish[17]; // 물고기 1번부터 ~16번까지 움직이게 하기위한 구조체형 백터  
	
	int pos1[4][4]; // 번호 배열 복사본 

	int dir1[4][4]; // 방향 배열 복사본  

		
	for(i=0; i<=3; i++)    
	{
		for(j=0; j<=3; j++)
		{
		
			pos1[i][j]=pos[i][j];
			dir1[i][j]=dir[i][j];
			if(pos[i][j]!=-1) // 존재하는 물고기의 위치와 방향을 넣어준다. 
			{
			
		     fish[pos[i][j]].push_back(state(i,j,dir[i][j]));  	
		}
		     if(pos[i][j]==0)  // 상어의 현재 위치와 방향을 저장  
		     {
		     	sx=i;
		     	sy=j;
		     	sdir=dir[i][j];
			 }
		}
	}

	for(i=1; i<=16; i++)   //물고기 1번부터 ~16번까지 1회 이동  
	{
		if(fish[i].size()!=0)  
		{
			flag=0;
			x= fish[i][0].x;   
			y=fish[i][0].y;  
			dir2=fish[i][0].dir;  
			end=9;
			
			for(j=dir2; j<end; j++)    //  현재 방향부터  ↗(8번) 방향까지 확인  
			{
			
			      
			xx=x+dx[j];    
			yy=y+dy[j];
			 
			
			if(pos1[xx][yy]!=0&&flag==0&&xx>=0&&xx<=3&&yy>=0&&yy<=3)  
			{
				flag=1; 
				
				
				if(pos1[xx][yy]!=-1)  // 다음 이동할 칸에 물고기가 존재하면? 
				{
				
				tmp1=pos1[xx][yy];  // 이동할 칸의 물고기의 번호와 방향값을 저장  
			    tmp2=dir1[xx][yy];
				
				pos1[x][y]=tmp1; // 배열값과 백터의 정보도 변경   
				dir1[x][y]=tmp2; 
				fish[tmp1][0].x=x;  
				fish[tmp1][0].y=y;
				
			     }
			     
			     else if(pos1[xx][yy]==-1)  // 이동할 칸이 비어있으면 현재칸은 빈칸으로 변경 
			     {
			     	pos1[x][y]=-1;
			     	dir1[x][y]=-1;
				 }
			     
			     
			     
				pos1[xx][yy]=i;   // 현재 물고기를 이동할칸으로 옮기는과정  
				dir1[xx][yy]=j;
				fish[i][0].x=xx;
				fish[i][0].y=yy;
				fish[i][0].dir=j;
			
			
			}
	
	    if(flag==0&&j==8)
	    {
	    	j=0;
	    	end=dir2-1;
		}
		}
		
		
		
		
		
		
	 } 
	
}
//////////////물고기 전체 1회 이동 종료  

for(i=1; i<=3; i++) // 상어는 현재 가지고있는 방향으로 여러칸을 탐색하니 *i 
{

xx=sx+dx[sdir]*i;
yy=sy+dy[sdir]*i; 

if(xx>=0&&xx<=3&&yy>=0&&yy<=3&&pos1[xx][yy]!=-1)  
{


	
	tmp1=pos1[xx][yy];  // 상어가 이동하려는 곳이 물고기가 존재하면 위치 , 방향 복사본 배열 값 변경  
	pos1[xx][yy]=0;
	pos1[sx][sy]=-1;
	dir1[sx][sy]=-1;
	
  func(sum+tmp1,pos1,dir1);   
	pos1[xx][yy]=tmp1;  //다시 원상복귀 
	dir1[sx][sy]=sdir;
	pos1[sx][sy]=0;
	
}

}


}

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,a,b;
int dir[4][4]={0};
int pos[4][4]={0};


for(i=0; i<=3; i++)
{
	for(j=0; j<=3; j++)
	{
		scanf("%d %d",&a,&b);
		
		
		pos[i][j]=a;  // 번호를 나타내는 2차원 배열  1~16 : 물고기  -1: 비어있는곳 0: 상어 
	
		dir[i][j]=b;  // 방향 
	}
}

a=pos[0][0]; // 맨처음 상어의 시작위치에 있는 물고기의 번호  
pos[0][0]=0;  

func(a,pos,dir);  // a: 현재까지 상어가 잡아먹은 물고기의 번호 총합, 번호배열, 방향배열  

printf("%d",ans);
return 0;
}
