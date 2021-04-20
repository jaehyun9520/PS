#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct state{
	
	int x;
	int y;
	int dir;
};


int dx[4]={0,1,0,-1}; //동 남 서 북
int dy[4]={1,0,-1,0};  




int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int map[101][101]={0};

vector <state> array(101);

int a,b,n,m,x,y,i,j,tx,ty;
char dir,com;
int num,cnt,d;

cin>>a>>b;  // a:가로 b:세로  

cin>>n>>m; // n로봇 개수 , m명령 횟수 

for(i=1; i<=n; i++)
{
	cin>>x>>y>>dir;
	
	 
	
	array[i].x=b+1-y;
	array[i].y=x;
	
	if(dir=='E')
	array[i].dir=0;
	
	else if(dir=='S')
	array[i].dir=1;
	
	else if(dir=='W')
	array[i].dir=2;
	
	else if(dir=='N')
	array[i].dir=3;
	
	map[b+1-y][x]=i;
 } 

 for(i=1; i<=m; i++)
 {
 cin>>num>>com>>cnt;  //로봇 번호, 명령, 횟수 
 	
 	x=array[num].x;
 	y=array[num].y;
 	d=array[num].dir;
 	
 	if(com=='L'||com=='R') //방향 전환이 명령이라면 
    {
    	if(com=='R')  //오른쪽 90도 회전  
		{
			for(j=1; j<=cnt; j++)
			{
				d++;
				
				if(d>3) d=0;
				
			}
			
		 }
		 
		 else{
		 	
		 	for(j=1; j<=cnt; j++) //왼쪽 90도 회전  
		 	{
		 		d--;
		 		if(d<0) d=3;
			 }
		 } 
		 
		 array[num].dir=d;
	 } 
	 
	 
	 else  // 앞으로 움직이는 명령  
	 
	 {
	 	tx=x; ty=y;
	 
	 	for(j=1; j<=cnt; j++)
	 	{
	 		x=x+dx[d];  //그 방향으로 이동  
	 		y=y+dy[d];
	 		
	 
	 		
	 		if(x>b||x<1||y>a||y<1)   
	 		{  
	 			cout<<"Robot "<<num<<" crashes into the wall";
	 			exit(0);   
			 }
			 
		   else if(map[x][y]!=0)
		   {
		   	  cout<<"Robot "<<num<<" crashes into robot "<<map[x][y];
		   	  exit(0);
			} 
		 }
		 
		 
		 map[tx][ty]=0; //기존 로봇의 위치 
		 array[num].x=x; array[num].y=y; //이동으로 바뀐 로봇의 위치 
		 map[x][y]=num;  
	 	
	 }
 	
 	
 	
 }
 
 cout<<"OK";
return 0;
}
