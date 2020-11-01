#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int dx[8]={-1,-1,0,1,1,1,0,-1};   // 방향 
int dy[8]={0,1,1,1,0,-1,-1,-1};


struct state{
	
	int x;
	int y;
	int m;
	int s;
	int d;
	state(int a, int b, int c, int e, int f)
	{
		x=a; y=b; m=c; s=e; d=f;
	}
	
};

int main()
{	
//freopen("input.txt", "rt", stdin);
int n,M,k,i; //맵크기, 파이어볼개수, 파이어볼 이동명령 횟수 
int r,c,m,s,d; // rc행열, m 질량 s 속도 d 방향  
int x,y,ans=0;
vector < pair < int , int > > div;
vector < state > f; 
int map[4][51][51]={0};  //0은 파이어볼의 개수 , 1은 질량 2는 속도 3은 방향  
int check[51][51]={0}; 
queue < state> Q;

scanf("%d %d %d",&n,&M,&k); 

for(i=1; i<=M; i++)
{
	scanf("%d %d %d %d %d",&r,&c,&m,&s,&d);

	Q.push(state(r,c,m,s,d));	 
}



for(i=1; i<=k; i++)
{

		while(!Q.empty())
	{
		x=Q.front().x; y=Q.front().y;  m=Q.front().m;  s=Q.front().s;  d=Q.front().d;
		 Q.pop();
	      x=x+(dx[d]*s);  //방향만큼 속력으로 이동 
	      y=y+(dy[d]*s);  
	      
	  	if(x>n)  {x=x%n;}  if(y>n) {y=y%n;}  //n을 넘어서면 다시 앞쪽부터   
		  
		  
		if(x<1) {x=n-(abs(x)%n);}   if(y<1) { y=n-(abs(y)%n);} //
	  	
		
	  
		
		if(x>=1&&x<=n&&y>=1&&y<=n)
		{
		     map[0][x][y]++;  // 이동한 위치에 파이어볼 개수 +1 
		     map[1][x][y]+=m;   //질량 더해주기 
		     map[2][x][y]+=s;  //속도 더해주기  

			f.push_back(state(x,y,m,s,d)); 
			map[3][x][y]=map[3][x][y]+d%2; //짝수인지 홀수인지 
			
			if(map[0][x][y]>=2&&check[x][y]==0) // 2개이상의 파이어볼이 한곳에 위치하는경우  
			{
				check[x][y]=1;  
			
				div.push_back(make_pair(x,y));  //4개의 파이어볼로 나누기위해 넣어줌 
			 } 
		}
		 
		
	}

	while(!f.empty())
	{
		x=f.back().x;
		y=f.back().y;
		m=f.back().m;
		s=f.back().s;
		d=f.back().d;
		if(map[0][x][y]==1) //2개이상인 곳은 4개로 나눠지는곳에서 처리 여기서는 한개인것들만 처리  
		
		{ map[0][x][y]=0;  //다음이동때 누적된 파이어볼개수 체크위해 0으로  
			
			Q.push(state(x,y,m,s,d)); //값을 똑같이 넣어줌 
		map[1][x][y]=0;  //마찬가지로 질량 속도 방향도 초기화 
		map[2][x][y]=0;
		map[3][x][y]=0;
		}
		
		f.pop_back();
	}

	while(!div.empty())   //4개로 나눠주기  
	{
		x=div.back().first;
		y=div.back().second;
		check[x][y]=0;   
		m=floor(map[1][x][y]/5);   //질량 
	
		if(m>0)  //질량이 0이상이면  
		{
		   
			s=floor(map[2][x][y]/map[0][x][y]); // 속력 =누적된 속력/ 누적된 파이어볼개수  
			d=map[3][x][y];  
			
		
			if(d==0||d==map[0][x][y]) // 누적된 방향값이 0이거나(모두짝수)   누적된 파이어볼의 개수와 같거나(모두홀수)
			  
		    {
		    
		    	d=0;
		    	while(d<=6)
		    	{
		    		 Q.push(state(x,y,m,s,d)); // 0 2 4 6 방향  
		    		 d+=2;
		    		
				}
			}
			
			else 
			{
				d=1;
				while(d<=7)
				{
					
					Q.push(state(x,y,m,s,d));
					d+=2;
				}
				
			}
			
		}
		map[0][x][y]=0;
		map[1][x][y]=0;
		map[2][x][y]=0;
		map[3][x][y]=0;
		div.pop_back(); 
	}
		
}

while(!Q.empty()) // 이동명령이 다 끝나고 난뒤 남아있는 파이어볼의 질량 합 
{
	
	m=Q.front().m;
	ans+=m;
	Q.pop();
}

printf("%d",ans);
return 0;
}
