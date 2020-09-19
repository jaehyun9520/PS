#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int map[6][6]={0};
int check[6][6]={0};
int answer=0,count1=0;
vector < pair < int, int > > use;



void DFS2(int x, int y)
{
	int i,xx,yy;
	
	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=1&&xx<=5&&yy>=1&&yy<=5)
		{
			if(check[xx][yy]==1)
			{
				count1++;
				check[xx][yy]=2;
				use.push_back(make_pair(xx,yy));
				DFS2(xx,yy);
				
			}
		}
	}
	
	
	
	
}




void DFS(int x,int y, int cnt, int scnt)  
{

int i,j;
if(cnt==7&&scnt>=4)   // 7명이 결성됐으면 4명이상이 다솜파에 속하는지 확인  
	{
	
	count1=1;
	
	check[x][y]=2; // 맨 마지막으로 뽑힌 애를 DFS의 시작점으로 사용  
	
	use.push_back(make_pair(x,y)); // 체크를 다시 1로 돌려놓기위해서 pair 형 백터 use사용  
	DFS2(x,y); 
	
	if(count1==7) // 7명 다 인접해있으면 모든 조건을 충족하므로 출력값+1 
		{
		answer++;
		}
	
	while(!use.empty())
		{
		check[use.back().first][use.back().second]=1;
		use.pop_back();
		}
	
	}




else if(cnt<7)   // 25명중에 7명 뽑기 ( 조합 ) 
	{
      for(j=y; j<=5; j++)
		{	
	        if(check[x][j]==0)
			{
				check[x][j]=1;
				if(map[x][j]=='S')
				{
					DFS(x,j,cnt+1,scnt+1);
				}
				else
				{
				DFS(x,j,cnt+1,scnt);
				}
		check[x][j]=0;
			}		
		}

	  for(i=x+1; i<=5; i++)
		{
	        for(j=1; j<=5; j++)
			{
		         if(check[i][j]==0)
				{
			       check[i][j]=1;
			
				 	if(map[i][j]=='S')
					{
			
				    DFS(i,j,cnt+1,scnt+1);
					}
					else
					{
			
					DFS(i,j,cnt+1,scnt);
			
					}
			
			    check[i][j]=0;
				}
			}
		}
	}
	
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j;
char a[6];
for(i=1; i<=5; i++)
	{
	
	scanf("%s",a);
	for(j=1; j<=5; j++)
		{
		map[i][j]=a[j-1];
		}
	}


DFS(1,1,0,0);  // 25명중에 7명 뽑기  

printf("%d",answer);

return 0;
}
