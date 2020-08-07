#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
int n,m,d,i,j,dis,x,y,xx,yy,cnt,s,ex,ey,result=0,answer=0,size=0;

int dx[3]={-1,0,0};
int dy[3]={0,1,-1};

int map[17][16]={0};
int test[17][16]={0};
int check[17][16]={0};
int archer[3]={0};

struct state{
	
	int x;
	int y;
	int cnt;
	
	state(int a, int b, int c)
	{
		x=a;
		y=b;
		cnt=c;
	}
};



vector < pair < int , int > > del;
vector < pair < int, int > > used;

queue < state > Q;

void DFS(int count, int number)   // 궁수를 배치시킬 성을 몇개까지 뽑았는지 
{	

	if(count==3) // 궁수를 3명 다 성에 배치시켰으면 시뮬레이션  
	{ size=0;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				test[i][j]=map[i][j];
				
				if(test[i][j]==1)
				{
					size++;
				}
			}
		}
		
		 
		
		
		
		        result=0;
 	          while(size!=0) {   // 적이 맵에 하나도없으면 종료  
		
		for(i=0; i<=2; i++)
		{
			
			s=999;  // 가장 짧은 거리 변수  
			ex=0; ey=0;  // 가장짧은거리에 있는 적의 좌표  
			if(test[n][archer[i]]==1)  // 궁수바로 위에 적이 있는경우 
			{
				
				
				del.push_back(make_pair(n,archer[i]));   
			}
			
			else if(test[n][archer[i]]==0){
			
			Q.push(state(n,archer[i],1));
		    check[n][archer[i]]=1;
		    used.push_back(make_pair(n,archer[i]));   // 적을 탐색  
			
			while(!Q.empty())
			{

				x=Q.front().x;
				y=Q.front().y;
				cnt=Q.front().cnt;
				Q.pop();
				 
			 
				for(j=0; j<=2; j++)
				{
				
					xx=x+dx[j];
					yy=y+dy[j];
					
					if(xx>=1&&yy>=1&&yy<=m)
					{
						
						if(check[xx][yy]==0&&cnt+1<=d)  
						{   
							used.push_back(make_pair(xx,yy));
							check[xx][yy]=1;
							if(test[xx][yy]==1)
							{
								
								if(s>cnt+1)
								{   
								   s=cnt+1;
								    ex=xx;
								 	ey=yy;
								}
								
								else if(s==cnt+1)  // 가장 가까운적이 여럿일경우 가장 왼쪽에 있는걸 먼저 제거해준다. 
								{
									if(ey>yy)
									{
										ex=xx;
										ey=yy;
									}
								}
							}
							else if(test[xx][yy]==0&&cnt+1<s)    // 다음 거리로 넘어가며 적 탐색  
							{
								Q.push(state(xx,yy,cnt+1));
							}
							  
							
						}
					}
				}
				
			}
			
			while(!used.empty())    // 방문표시 풀기  
			{
			
				x= used.back().first;
				y=used.back().second;
		
				check[x][y]=0;
				used.pop_back();
			}
			if(ex!=0&&ey!=0)    // 제거 할 적의 위치 기록  
			{
				del.push_back(make_pair(ex,ey));
			 }
			
			
		}
		 	
			
		}   
		    while(!del.empty())  // 궁수 3명으로 공격이 다 끝나고 난뒤 가장짧은거리의 3명의 적 제거  
		    {
		    	x=del.back().first;
		    	y=del.back().second;
		       del.pop_back();
		    if(test[x][y]==1)   
		    {
			  
		    	test[x][y]=0;
		    	result++;
		    	
		    }
		    	
			}
		
			
			
			
			size=0;
			for(y=1; y<=m; y++)  //적들을 한칸씩 앞으로 이동시키기  
			{
				test[n][y]=0;
			}
			for(x=n-1; x>=1; x--)
			{
				for(y=1; y<=m; y++)
				{
					if(test[x][y]==1)
					{
						size++;
						test[x][y]=0;
						test[x+1][y]=1;
					}
				}
			}
			
			
			
		
		
	}
		
		if(result>answer)
		{
			answer=result;
		}

	}
	
	
	
	else if(count<=2)   // 궁수를 아직 덜 배치시켰으면  
	{
		for(int z=number; z<=m; z++)
		{	
			if(map[n+1][z]==0)  // 성에 궁수가 없다면? 
			{
				archer[count]=z;  // 1 번 2 번 3번 궁수가 몇번째 성에 있는지 저장  
				map[n+1][z]=2;  //  성에 궁수를 배치  
				DFS(count+1,z+1);  
				map[n+1][z]=0;
				
			}
		}
		
	}
	
}


int main()
{
//freopen("input.txt", "rt", stdin);


scanf("%d %d %d",&n,&m,&d);

	

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	
	{
		scanf("%d",&map[i][j]);
	}
}


DFS(0,1);   // 최대 15개의 성 중에서 궁수를 배치시킬 3개의 성 뽑기  15*14*13/6   
printf("%d",answer);



return 0;

}

