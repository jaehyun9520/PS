#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int cnt=0; 
int map[9][9]={0};

void check1(int x, int y, int checkx[],int checky[]) //가로 세로 체크 후 넘겨주기  
{
	for(int k=0; k<9; k++)
				{
				
					if(map[x][k]!=0)
					{
					
					checkx[map[x][k]]=1;
				}
					if(map[k][y]!=0)
					{
					
					checky[map[k][y]]=1;
				}
}
}

void check2(int x, int y, int checkz[])  // 구역 체크 후 넘겨주기  
{
for(int k=x/3*3; k<x/3*3+3; k++)
		{
			for(int z=y/3*3; z<y/3*3+3; z++ )
			{
				if(map[k][z]!=0)
				{
					checkz[map[k][z]]=1;
				}
			}
		}	
}

void DFS(int x, int y, int count1)
{int i,j,flag=0;
int checkx[10]={0};
int checky[10]={0};
int checkz[10]={0};


	if(count1==0)   // 0이 다 채워진경우 배열 출력 후 종료  
	{
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				printf("%d ",map[i][j]);
			}
			printf("\n");
		}
		
		exit(0);
	}

	else if(count1>=1)  // 0이 아직 남아있는 경우  
	{

		for(j=y; j<9; j++)
		{
	
			if(map[x][j]==0&&flag==0) // 0인곳을 발견 
			{
		
				flag=1;
				check1(x,j,checkx,checky);  //  가로 세로줄의 정보를 저장  
			
		check2(x,j,checkz); // 구역 정보 저장  

				for(int k=1; k<=9; k++)
				{
					if(checkx[k]==0&&checky[k]==0&&checkz[k]==0)  // 가로, 세로 , 구역에서 한번도 쓰이지않은 수를 넣어 진행 
					{
						map[x][j]=k;
						DFS(x,j+1,count1-1);
						map[x][j]=0;
						
					}
				}
				
				j=9;
			}
	
		}
		
	if(flag==0)
	{
			
		for(i=x+1; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				if(map[i][j]==0&&flag==0)
			{
				flag=1;
			check1(i,j,checkx,checky);
				
				
				check2(i,j,checkz);
				
				
				for(int k=1; k<=9; k++)
				{
					if(checkx[k]==0&&checky[k]==0&&checkz[k]==0)
					{
						map[i][j]=k;
						DFS(i,j+1,count1-1);
						map[i][j]=0;
					}
				}
			    i=9;
			}
			
		}
		
		
		
	}
}
}
}

int main()
{
//freopen("input.txt", "rt", stdin);
int i, j;
for(i=0; i<9; i++)
{
	for(j=0; j<9; j++)
	{
		scanf("%d",&map[i][j]);
		
		if(map[i][j]==0) cnt++;		// 0의 개수 카운트  
	}
}


DFS(0,0,cnt); // 0,0 부터 시작  

return 0;
}
