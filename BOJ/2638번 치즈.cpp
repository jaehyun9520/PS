#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int n , m; 
int map[101][101]={0};
int check[101][101]={0};    
queue < pair < int , int > > Q1;  // 외부 공기 넣어주는곳
queue < pair < int , int > > Q2; // 외부공기와 접촉된 치즈 넣어주는곳  

vector <pair <int , int > > del;  // 이번 턴에 녹은 치즈 저장  
vector <pair <int , int > > re;  // 녹지않은 치즈저장  다시 사용 

void air()   //외부공기 퍼지게 하고 주변에 치즈가 있는지 체크! 
{
	int x,y,xx,yy;
    while(!Q1.empty()) 
	{
		x=Q1.front().first;
		y=Q1.front().second;
		Q1.pop();
		
		for(int i=0; i<=3; i++)
		{
			xx=x+dx[i];
			yy=y+dy[i];
			
			
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
			{
				if(map[xx][yy]==0&&check[xx][yy]==0)  // 외부공기와 접촉된 공기면 ? 외부공기 
				{
					check[xx][yy]=1;
					Q1.push(make_pair(xx,yy));
				 }
				 
				 else if(map[xx][yy]==1&&check[xx][yy]==0)  // 외부공기와 접촉된 치즈  
				 {
				 	check[xx][yy]=1;
				 	Q2.push(make_pair(xx,yy));
				  } 
			}
		}
		
		
	   }   
		
}

int main()
{	
//freopen("input.txt", "rt", stdin);
int i,j,x,y,xx,yy,cnt,cheeze=0,time=0;

scanf("%d %d",&n,&m);

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		scanf("%d",&map[i][j]);
		if(map[i][j]==1) cheeze++;
	}
}

check[1][1]=1;
Q1.push(make_pair(1,1)) ;  // 가장자리에는 치즈가 존재하지 않으니 1,1을 넣어서 외부공기 탐색  
air(); // 외부공기 범위와 접촉된 치즈 확인


while(cheeze!=0)
{


while(!Q2.empty())
{
	
	x=Q2.front().first;
	y=Q2.front().second;
	cnt=0;
	Q2.pop();
	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			if(check[xx][yy]==1&&map[xx][yy]==0)  // 외부공기와 접촉 
			{
				cnt++ ;  //횟수 추가  
			}		
		}
	 } 
	 if(cnt>=2)   del.push_back(make_pair(x,y));  // 이번턴에  2변이상 접촉된 치즈
	else   re.push_back(make_pair(x,y));
	if(Q2.size()==0)  // 외부와 접촉된 치즈들을 다 확인했으면 
	{
		while(!del.empty())
		{
			cheeze--;
			x= del.back().first;
			y= del.back().second;
			map[x][y]=0 ;// 공기로 바꿔줌
			check[x][y]=1; // 외부 공기 표시도 해줌 
			del.pop_back();
			Q1.push(make_pair(x,y)); // 외부공기와 새롭게 접촉된 치즈 밑 내부공기 확인위해  
		 }
	 
		 if(cheeze==0)  printf("%d",time+1);
		 
		 else time++; 
		
	}  
 } 
         air();
         
         while(!re.empty())
         {
         	Q2.push(make_pair(re.back().first,re.back().second));
         	re.pop_back();
		 }

}




return 0;
}
