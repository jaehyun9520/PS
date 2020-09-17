#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,answer;
int map[16][16]={0};
void func(int cnt)
{ int i,j,x,y;
   vector < pair <int , int > > use;

	if(cnt==n)
	{
		answer++;
	}
	
	else
	{
		for(i=1; i<=n; i++)
	    {
	    	if(map[cnt+1][i]==0)  
	    	{
	    		map[cnt+1][i]=1;   // 퀸을 놓을수있는가? 
	    		
	    		
	    		for(j=cnt+2; j<=n; j++)   // 현재 퀸의 밑에쪽 공격범위 표시  
	    	      {
	    	      	if(map[j][i]==0)   // 이미 위쪽의 퀸에 의해 표시되어있으면 넘어감  
	    	      	{
					  
	    	      	map[j][i]=1;  
	    	      	use.push_back(make_pair(j,i));  
	    	      }
				  }
	    	
	    	    for(j=1; j<=n; j++)       // 오른쪽 밑 대각선 공격범위 표시  
	    	    {
	    	    	if((x=cnt+1+j)<=n&&(y=i+j)<=n)
	    	    	{
	    	    		
	    	    		if(map[x][y]==0)
	    	    		{
						map[x][y]=1;
						
						use.push_back(make_pair(x,y));
	    	    	}
	    	    		
	    	    		
					}
				}
				for(j=1; j<=n; j++)     //왼쪽 밑 대각선 공격범위 표시  
				{
					if((x=cnt+1+j)<=n&&(y=i-j)>=1)
					{
						if(map[x][y]==0)
						{
						
						map[x][y]=1;
						use.push_back(make_pair(x,y));
					}
					}
				}				
				func(cnt+1);  //다음단계로 
	    		
	    		map[cnt+1][i]=0;  // 퀸 공격범위와 위치 제거  
	    		
	    		while(!use.empty())
	    		{
	    			map[use.back().first][use.back().second]=0;
	    			
	    			use.pop_back();
				}
	    		
	    		
			}
	    	
		}
		
		
	}
	
}
int main()
{
	
	scanf("%d",&n);
	
	func(0);
//freopen("input.txt", "rt", stdin);
printf("%d",answer);
return 0;
}
