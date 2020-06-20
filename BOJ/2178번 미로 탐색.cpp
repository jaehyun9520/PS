#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

queue < pair < int , int > > Q;

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,n,m,tmpx,tmpy,a=0,b=0;
int map[101][101]={0};
int check[101][101]={0};
char val[100];
scanf("%d %d",&n,&m);

 for(i=1; i<=n; i++)
{
	scanf("%s",&val);
	
	for(j=1; j<=m; j++)
	{
		map[i][j]=val[j-1]-48;
	}
}
 
 
 
 Q.push(make_pair(1,1));
 map[1][1]=0;
 check[1][1]=1;
 
 while(!Q.empty())
 {
 	tmpx=Q.front().first;
 	tmpy=Q.front().second;
 	Q.pop();
 	
 	for(i=0; i<=3; i++)
 	{  
 	    
 		a=tmpx+dx[i];
 		b=tmpy+dy[i];
 		
 		
 		
 		
 		if(map[a][b]==1)
 		{ 
 		
 			Q.push(make_pair(a,b));
 			map[a][b]=0;
 			check[a][b]=check[tmpx][tmpy]+1;
 			
		 }
	 }
 }
printf("%d",check[n][m]);
return 0;
}
