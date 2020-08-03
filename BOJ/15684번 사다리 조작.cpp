#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
int n,m,h,i,j,a,b,f=0;
int result=9999;
int map[31][11]={0};


int move(int y)    // 사다리가 번호 그대로 도착하는지 확인 
  {int x=1;
	while(1)
	{
		
		if(x==h+1)
		{
			return y;
		     break;
		}
		
		
		 
		if(map[x][y]==1)
		{
				x++;
				y++;
				
		}
		else if(y>=2&&map[x][y-1]==1)
		{
			y--;
			x++;
		}
		
		
		
		else if(map[x][y]==0)
		{
			x++;
		}
		
	}
	
}


void DFS(int x, int y, int cnt)    
{
	int i,j,flag=0;
	
	
	
	
	for(i=1; i<=n; i++)
	{
		 
		 
		 if(i!=move(i))     // i번 사다리가 다른 번호의 사다리로 도착하면 종료   
		 {   
		     flag=1;
		     break;
		 }
	}
	
	if(flag==0)    // 모든 사다리가 각자의 사다리로 도착했으면 몇개의 가로선을 추가했는지 확인
	{
		
		
	  	if(result>cnt)    
	  	{
	  		result=cnt;
	  		
		}
	}
	

	
	
	
	
	
	if(result>cnt&&cnt<3)    // 가로선 1개 2개 3개를 놓을수있는 모든 경우의 수 확인  
	{
		
			for(j=y+1; j<=n-1; j++)
			{
			  
				if(map[x][j-1]==0&&map[x][j+1]==0&&map[x][j]==0)
				{
					map[x][j]=1;
					DFS(x,j,cnt+1);
					map[x][j]=0;
				}		
	        }
						
						
	        for(i=x+1; i<=h; i++)
	        {
		        for(j=1; j<=n-1; j++)
		        {
			
				
				
			      if(map[i][j-1]==0&&map[i][j+1]==0&&map[i][j]==0)
				   {  
					map[i][j]=1;
					DFS(i,j,cnt+1);
					map[i][j]=0;
				    }
				
				
	         	}  			
	        }
	
						
											
	}
		
		
}
	
	


int main()
{
//freopen("input.txt", "rt", stdin);


scanf("%d %d %d",&n,&m,&h);



    for(i=1; i<=m; i++)
    {
	scanf("%d %d",&a,&b);
	map[a][b]=1;

	}




    if(m==0)  //가로선이 0개면 그대로 내려갈테니 바로 0  
    {
	printf("0");
	exit(0);
    }


    DFS(1,0,0);
		
	if(result==9999)
	{
	   result=-1;
	}
	printf("%d",result);

return 0;

}
