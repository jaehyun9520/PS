#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int wind[4][10][2]= //각 방향에 따른 흩날리는 위치 (퍼센트와 같이 쓰기위해서 맞춰줌) 
{
{{1,0},{-1,0},{2,0},{-2,0},{-1,1},{1,1},{-1,-1},{1,-1},{0,-2},{0,-1}},  //왼쪽  
{{0,-1},{0,1},{0,2},{0,-2},{-1,-1},{-1,1},{1,-1},{1,1},{2,0},{1,0}},   //아래쪽 
{{1,0},{-1,0},{2,0},{-2,0},{-1,-1},{1,-1},{-1,1},{1,1},{0,2},{0,1}},   //오른쪽 
{{0,-1},{0,1},{0,2},{0,-2},{1,-1},{1,1},{-1,-1},{-1,1},{-2,0},{-1,0}}  //위쪽   
};
double percent[9]={0.07,0.07,0.02,0.02,0.01,0.01,0.1,0.1,0.05}; // 흩날리는 칸의  퍼센트  

int dx[4]={0,1,0,-1};  //서남동북순으로 진행  
int dy[4]={-1,0,1,0}; 
int map[500][500]={0}; 
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,i,j,move,cnt,x,y,ans=0,nx,ny,val,sum=0,direct;
cin>>n;
x=n/2+1;
y=x;
//시작위치 지정 

for(i=1; i<=n; i++)
   for(j=1; j<=n; j++)
       cin>>map[i][j];


move=1; cnt=0,direct=0; 


while(1)  
{
	 
	     for(int i=1; i<=move; i++)  // 1 1 2 2 3 3 4 4 5 5 이렇게 움직인다 
     {
     	x=x+dx[direct];
     	y=y+dy[direct];
     
     	      sum=0;  
     	  for(int j=0; j<=9; j++)
     	  {
     	  	nx=x+wind[direct][j][0];   // a를 제외한 날라간 값들을 더해준다. 
     	  	ny=y+wind[direct][j][1];
     	  	
     	  	if(j!=9)  // a가 아닐경우 정해진 퍼센트만큼 날라가게 한다. 
     	  	{
			
     	  	val=map[x][y]*percent[j];
     	  	sum=sum+val;
     	    }
     	    
     	    if(j==9) // a일경우  
     	    val=map[x][y]-sum;
     	    
     	    
     	  	if(nx<1||nx>n||ny<1||ny>n)  //날아가는 모래바람이 범위를 벗어난경우? 
     	  	{
     	        ans=ans+val;	
		   }
		   
		   else    // 범위안이라면 해당위치에  더해준다. 
		   {
		   	  map[nx][ny]+=val; 
		   	
		   }
	
     	  	
		   }
		   
		   map[x][y]=0;  //토네이도에 의해 전체가 다 날라가니까 마지막은 0으로
		   
		   
		   if(x==1&&y==1) 
		   {
		   cout<<ans; exit(0);
            }
     	
	 }
	
	cnt++;  direct++;
	
	if(direct==4) direct=0;
	
     if(cnt==2)  //move만큼 두번 움직이면  move 1증가  
	 {
	 cnt=0; move++;
     }
	
}
														   
return 0;
}
