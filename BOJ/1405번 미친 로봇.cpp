#include<iostream>
#include<algorithm>
#include<vector>
int map[29][29]={0}; 
int dx[4]={0,0,1,-1}; //동서남북  
int dy[4]={1,-1,0,0};
double dir[4];
int n,E,W,N,S,i,val=0;
double ans=0;

void DFS(int x, int y,int cnt, double p)
{
	int xx,yy;
	
	if(cnt==n)  ans=ans+p;
	
	if(cnt<n)
	{
		for(int i=0; i<=3; i++)
		{	
			xx=dx[i]+x; yy=dy[i]+y;
			if(dir[i]>0)   
			{

				if(map[xx][yy]==0)  
				{
				map[xx][yy]=1;
				DFS(xx,yy,cnt+1,p*dir[i]);  //  확률 * 해당 방향이 가지고 있는 확률  
				map[xx][yy]=0;
			}
		
		}
		
	}
	
	
}

using namespace std;
int main()
{	

//freopen("input.txt", "rt", stdin);
map[14][14]=1;
scanf("%d %d %d %d %d",&n,&E,&W,&S,&N);  
dir[0]=E*0.01; dir[1]=W*0.01; dir[2]=S*0.01; dir[3]=N*0.01; 
DFS(14,14,0,1); //처음 위치, 몇번이동했는지, 확률) 

printf("%.10f",ans);



return 0;
}
