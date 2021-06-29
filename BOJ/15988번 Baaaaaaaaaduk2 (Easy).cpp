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
			
			int a=selected[i].first+dx[j];   // ù��°(i=0) �ι�°(i=1) ���� ��ġ   
			int b=selected[i].second+dy[j];

			if(a>=1&&a<=n&&b>=1&&b<=m)
			{
				if(map[a][b]==2&&check[a][b]==0)  // ���� �����¿쿡�� ���� ���� �ְ� 
			{                                     // �湮�� �ȵȻ��¶�� ���ϼ� �ִ� �׷����� Ȯ�� 
				flag=0;  // �׷쳻�� ���� ��ĭ�� �������ִٸ� 1�� �ٲ�  
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
							 	if(map[nx][ny]==0)  // ��ĭ�� ���� 
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
	
	if(cnt==2) // �ΰ��� �� ���Ҵٸ� 
	{
	 
	  int val=BFS();  // ���� �� �ִ� ���� ���� ����� Ȯ��  
		
		ans=max(ans,val);
	}
	
	
	else   // �ι�° �� ���� �ڸ� ����  
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
 		if(map[i][j]==0)  // �� ��ĭ�� ù��° �� ���� �ڸ��� ����  
 		{
 		    map[i][j]=1;
			 	selected[0].first=i;  // ù��° �� ��ġ ���� 
	     		selected[0].second=j;
			 DFS(1,i,j); 	
 			
 			map[i][j]=0;   
 			
		}

	 }
 }
 
 cout<<ans;

return 0;
}
