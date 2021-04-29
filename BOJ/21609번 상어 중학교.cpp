#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct state{   // 기준블록의 좌표, 블록그룹의 사이즈, 무지개블록의 개수  
	
	int x, y, size,cnt;  
	
	state(int a, int b, int c, int d)
	{
		x=a; y=b; size=c; cnt=d;
	}
	
	bool operator<(const state &b)const
	{
		if(size==b.size)          //문제에 나온 우선순위대로  
		{
		    if(cnt==b.cnt)
			{
				if(x==b.x)
			{
				return y<b.y;	
			}
			
			
			else{
				return x<b.x;
			}
				
				
				}	
			
			else return cnt<b.cnt;
			
			
		}
		
		else return size<b.size;
	}
}; 



int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int map[21][21]={0};  
int check[21][21]={0};
int tmp[21][21]={0};  // 반시계 90도 움직일때 저장용 

queue < pair < int , int > > Q;  
priority_queue <state> PQ;  // 블록그룹을 넣어주는 우선순위 큐 
vector < pair < int , int > > list; // 무지개 블록 넣는곳(무지개 블록의 방문체크 풀어주기위해..) 

int n;


void move()   //중력 
{
	int i,j;
	
	
	for(j=1; j<=n; j++)
	{
		for(i=n-1; i>=1; i--)
		{
			
			if(map[i][j]!=6&&map[i][j]!=-1)   
			{
				int k=i+1;
				int cnt=0;
				
				while(k<=n)
				{
					
					if(map[k][j]==6)
					{
						cnt++;
						k++;
					}
					else{  
						break;
					}
				}
				map[i+cnt][j]=map[i][j];
				if(cnt!=0)
				map[i][j]=6;
			}
		}
	}
	
}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,j,m,color,size,x,y,nx,ny,ans=0,cnt;
int pointx,pointy;  
cin>>n>>m;  


for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		cin>>map[i][j];
	}
	
}

while(1)
{
	for(i=1; i<=n; i++) 
	{
		for(j=1; j<=n; j++)
		{
			if(map[i][j]>=1&&map[i][j]<=m&&check[i][j]==0)  //방문안된 일반블록이 있을경우  
			{
			
				size=1;  pointx=i; pointy=j,cnt=0;  //블록사이즈 1 , 기준블록좌표 지정, 무지개블록개수=0 
				color=map[i][j]; //같은색 구분을 위해  
				check[i][j]=1; 
				
				Q.push(make_pair(i,j));
				
				while(!Q.empty())
				{
					x=Q.front().first;
					y=Q.front().second;
					
					Q.pop();
					for(int k=0; k<=3; k++)
					{
						nx=x+dx[k];
						ny=y+dy[k];
						
						if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
						{
							if(map[nx][ny]==0||map[nx][ny]==color)
							{
								if(check[nx][ny]==0)
								{
								
									check[nx][ny]=1;
									size++;
									
									if(map[nx][ny]==0) //무지개 블록은 다른 블록그룹을 만들때도 쓸수있으니 방문체크를 풀기위해 저장 
									{
									   list.push_back(make_pair(nx,ny));
									   cnt++;
								     }
								     
								     
									else if(map[nx][ny]==color)  //일반블록일 경우 기준블록 정하기  
									{
										if(pointx>nx)
										{
											pointx=nx; pointy=ny;
									
										}
										
										else if(pointx==nx)
										{
											if(pointy>ny) {
												pointy=ny;
											}
										}
									}
								
									Q.push(make_pair(nx,ny)); 
								}
							}
						}
					}
					
				
					
				}
				for(int k=0; k<list.size(); k++)  //무지개블록 방문체크 풀기  
				{
					check[list[k].first][list[k].second]=0;
				}
				list.clear();
				
				
				if(size>=2)  //블록그룹 사이즈가 2이상이면 우선순위 큐에 넣어줌  
				{              
				  PQ.push(state(pointx,pointy,size,cnt));
					
				}
				
				
				
				
			 } 
		}
	}

	if(PQ.empty()) // 블록그룹이 없으면 종료  
	{

	break;  
     }
	else  
	{

	   ans+=PQ.top().size*PQ.top().size;  
        Q.push(make_pair(PQ.top().x,PQ.top().y)); 
        
        color=map[PQ.top().x][PQ.top().y]; 
        map[PQ.top().x][PQ.top().y]=6; 
        
        while(!PQ.empty()) PQ.pop();  
        
        while(!Q.empty())  //블록 그룹 제거 (빈공간을 6으로 표시)  
        {
        	x=Q.front().first; y=Q.front().second;
        	Q.pop();
        	
        	for(i=0; i<=3; i++)
        	{
        		nx=x+dx[i]; ny=y+dy[i];
        		
        		if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
        		{
        			if(map[nx][ny]==color||map[nx][ny]==0) 
					{
					
						map[nx][ny]=6; 
						Q.push(make_pair(nx,ny));
					 } 
				}
			}
        	
		}
  
    }
    
    
    move();  
		

	for(i=1; i<=n; i++)  // 반시계 90도  
	{
		for(j=1; j<=n; j++)
		{
			tmp[n-j+1][i]=map[i][j];
		}
	}

	for(i=1; i<=n; i++) 
	{
		for(j=1; j<=n; j++)
		{
			map[i][j]=tmp[i][j];
			check[i][j]=0;
		}
	}
	move(); 

}

cout<<ans;

return 0;
}
