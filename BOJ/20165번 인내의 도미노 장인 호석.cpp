#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dirx[4]={0,0,1,-1};  
int diry[4]={1,-1,0,0}; 
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,m,R,i,j,ans=0;  
int map[101][101]={0}; 
char check[101][101]={0}; 



int ax,ay,dx,dy;
char dir;

cin>>n>>m>>R;

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		cin>>map[i][j];
		check[i][j]='S';
	}
}

for(i=1; i<=R; i++)
{
	cin>>ax>>ay>>dir;
	
	if(check[ax][ay]=='S') //넘어지지 않았다면?
	{   
	    
		int cnt=1, k=map[ax][ay]-1;  // cnt는 넘어뜨린 개수 (기본 1개 ) 
		int nowdir=0;
		
		check[ax][ay]='F';
		
		if(dir=='E') nowdir=0;  //방향에 따른 설정  
		else if(dir=='W') nowdir=1;
		else if(dir=='S') nowdir=2;
		else  nowdir=3; 
		
	    while(k)
	    {
	    	k--;
	        ax=ax+dirx[nowdir];  //현재 방향만큼 한칸  
			ay=ay+diry[nowdir];	
	    
	    if(ax<1||ax>n||ay<1||ay>m) break; //배열 범위를 벗어나면 중단  
	    
	    if(check[ax][ay]=='S') //다음 도미노가 넘어지지 않았다면  
		{
			check[ax][ay]='F';
			
			if(k<map[ax][ay]-1) //현재 남아있는 진행 횟수보다 넘어뜨린 도미노의 높이-1이 크다면 
			{                 
			
                 k=map[ax][ay]-1;  
             }
				 cnt++;			
		 } 
		    	
		}		
		   ans+=cnt;		
	 } 
		
	cin>>dx>>dy;
	
	check[dx][dy]='S';
	
}

cout<<ans<<"\n";


for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		cout<<check[i][j]<<" ";
	}
	cout<<"\n";
}
return 0;
}
