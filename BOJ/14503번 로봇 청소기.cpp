#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;


int dx[4]={0,-1,0,1};   // 현재방향기준 왼쪽부터 탐색하도록 하기위해 사용  
int dy[4]={-1,0,1,0};   
 
int bx[4]={1,0,-1,0};   // 후진할때 사용   
int by[4]={0,-1,0,1};  

int mv[4]={3,0,1,2};    // 현재 방향을 현재 방향 기준의 왼쪽방향으로 바꿀때 사용 
int main()
{
//freopen("input.txt", "rt", stdin);
int n,m,r,c,d,i,j,result=1,x,y,cnt=0;

scanf("%d %d",&n,&m);
int map[n][m];
scanf("%d %d %d",&r,&c,&d);

for(i=0; i<n; i++)
{
	for(j=0; j<m; j++)
	{
		scanf("%d",&map[i][j]);
	}
}

map[r][c]=2;


while(1)
{


    if(cnt!=4){   // 상하좌우 탐색  
		x=dx[d]+r;
		y=dy[d]+c;
		
	
		if(map[x][y]==0)
		{
			
			r=x ;c=y;
			map[r][c]=2;
			 d=mv[d];
			 cnt=0;
			 result++;	 	 
			 
		}
		else {
			d=mv[d];
			cnt++;
		}
		
	}
	
	else if(cnt==4) //상하좌우 탐색했는데 청소하지 않은 공간이 없다면  
	{
	
		x=r+bx[d]; 
		y=c+by[d];
		
		if(map[x][y]==1)
		{
			printf("%d",result);
			exit(0);
		}
		
		else 
		{
			r=x; c=y;
			cnt=0;
		}
	}	
 } 
return 0;

}
