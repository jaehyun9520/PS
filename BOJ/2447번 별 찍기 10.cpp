#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char array[6562][6562];


void DFS(int n, int x, int y )
{
	
	int i,j;

	
	
	
	if(n==3)
	{
		for(i=x; i<=x+2; i++)
		{
			for(j=y ;j<=y+2; j++)
			{
				if(i==x+1&&j==y+1) continue;
				
				  array[i][j]='*';
				
			}
		}
		
		
	}
	
	else
	{
		
		
		
		
			for(i=1; i<=3 ;i++)
		     {
		     	DFS(n/3,x,y+(i-1)*n/3);
			 }
			 
			 for(i=1; i<=3; i++)
			 {
			 	if(i==2)continue;
			 	DFS(n/3,x+n/3,y+(i-1)*n/3);
			 }
		
		     for(i=1; i<=3; i++)
		     {
		     	
		     	DFS(n/3,x+2*(n/3),y+(i-1)*n/3);
			 }
			
		}
	
	
	
}
int main()
{
//freopen("input.txt", "rt", stdin);

int n,i,j;
scanf("%d",&n);




for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		array[i][j]=' ';
	}
}
DFS(n,1,1); 


for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		printf("%c",array[i][j]);
	}
	printf("\n");
}


return 0;
}
