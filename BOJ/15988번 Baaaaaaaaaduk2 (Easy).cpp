#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int map[21][21]={0};
int n,m;
int ans=0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector < pair < int , int > > selected(2);

int BFS()
{
  int cnt=0,sum=0; 
  bool flag=0;
   bool check[21][21]={0};	
   queue < pair < int , int  > > Q;	

	for(int i=0; i<=1; i++)  // 
	{	
		for(int j=0; j<=3; j++)
		{
			
			int a=selected[i].first+dx[j];   // 첫번째(i=0) 두번째(i=1) 돌의 위치   
			int b=selected[i].second+dy[j];

			if(a>=1&&a<=n&&b>=1&&b<=m)
			{
				if(map[a][b]==2&&check[a][b]==0)  // 돌의 상하좌우에서 적의 돌이 있고 
			{                                     // 방문이 안된상태라면 죽일수 있는 그룹인지 확인 
				flag=0;  // 그룹내의 돌이 빈칸과 인접해있다면 1로 바뀜  
		        cnt=1;		  
			   check[a][b]=1;   
			   Q.push({a,b});
	
			     	while(!Q.empty())
					 {
					 	int x=Q.front().first;
					 	int y=Q.front().second;
					 
					 	Q.pop();
					 	
					 	
					 	for(int k=0; k<=3; k++)
					 	{
					 		int nx=x+dx[k];
					 		int ny=y+dy[k];
					 		
					 		
					 		if(nx>=1&&nx<=n&&ny>=1&&ny<=m) 
							 {
							 	if(map[nx][ny]==0)  // 빈칸과 인접 
							 	{
							 		flag=1;  
								 }
								 
								 
								else if(map[nx][ny]==2&&check[nx][ny]==0)
								{
									check[nx][ny]=1;
									cnt++;
									Q.push({nx,ny});
									
									
								 } 
							 	
							  } 
			 		
						 }
		 	
					  } 
				
				if(flag==0)
				{
					sum+=cnt;  
					
				}
							
			}
				
			}
		
		}
	
	}
	
	return sum;
	
}

void DFS(int cnt, int x, int y)
{
	

	int i,j;
	
	if(cnt==2) // 두개를 다 놓았다면 
	{
	 
	  int val=BFS();  // 죽일 수 있는 적의 돌이 몇개인지 확인  
		
		ans=max(ans,val);
	}
	
	
	else   // 두번째 돌 놓을 자리 선택  
	{
	     for(j=y+1; j<=m; j++)
	     {
	     	if(map[x][j]==0)
	     	{
	     		map[x][j]=1;
	     		
	     		selected[1].first=x;
	     		selected[1].second=j;
	     		
	     		DFS(2,x,j);
	     		map[x][j]=0;	
			 }
	     	
		 }
	   
	   
	    for(i=x+1; i<=n; i++)
	    {
	    	for(j=1; j<=m; j++)
	    	{
	    		if(map[i][j]==0)  
	    		{
	    			map[i][j]=1;
	    			selected[1].first=i;   
	    			selected[1].second=j;
	    			DFS(2,i,j);
	    			map[i][j]=0; 
	    			
				}
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
int i,j;
cin>>n>>m; 

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		cin>>map[i][j];
	}
 } 
 
 
 for(i=1; i<=n; i++)
 {
 	for(j=1; j<=m; j++)
 	{
 		if(map[i][j]==0)  // 이 빈칸을 첫번째 돌 놓을 자리로 선택  
 		{
 		    map[i][j]=1;
			 	selected[0].first=i;  // 첫번째 돌 위치 저장 
	     		selected[0].second=j;
			 DFS(1,i,j); 	
 			
 			map[i][j]=0;   
 			
		}

	 }
 }
 
 cout<<ans;

return 0;
}
