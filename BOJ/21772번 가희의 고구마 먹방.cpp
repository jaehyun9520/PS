#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int r,c,t,ans=0;
int map[101][101]={0};
int check[101][101]={0};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void DFS(int x, int y, int time, int cnt)
{
	int nx,ny;
	if(time==t)
	{
	
		if(ans<cnt)
		{
			ans=cnt;
		}
}

	if(time<t)
	{
	 		for(int i=0; i<=3; i++)
	 		{
	 			nx=x+dx[i];
	 			ny=y+dy[i];
	 			
	 			if(nx>=0&&nx<r&&ny>=0&&ny<c)
	 			{
	 				if(map[nx][ny]!='#')
	 				{
	 					if(map[nx][ny]=='S')
	 					{
	 						
	 						map[nx][ny]='.';
	 						DFS(nx,ny,time+1,cnt+1);
	 						
	 						map[nx][ny]='S';
						 }
						 
						 else{ 
						    DFS(nx,ny,time+1,cnt);
						    
						 	
						 }
	 					
	 					
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
string input;  
int i,j,Gx=0,Gy=0;

cin>>r>>c>>t;

for(i=0; i<r; i++)
{
	cin>>input;
	
	for(j=0; j<c; j++)
	{
		map[i][j]=input[j];
		if(map[i][j]=='G')
		{
			map[i][j]='.';
			Gx=i; Gy=j;
			
		}
	}
}


DFS(Gx,Gy,0,0);


cout<<ans;
return 0;
}
