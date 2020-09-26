#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main()
{
//freopen("input.txt", "rt", stdin);
int map[13][7]={0};
int check[13][7]={0};
int i,j,k,x,y,xx,yy,flag=1,color=0,cnt=0,ans=0;
char a[8];

queue < pair < int , int > > Q;
vector < pair < int , int > > use;

for(i=1; i<=12; i++)
{
	scanf("%s",a);
	for(j=1; j<=6; j++)
	{
		map[i][j]=a[j-1];
	}
}



while(flag==1)  //  앞에서 연쇄작용이 안일어났으면 종료  
{
	flag=0;   
	
	for(i=1; i<=12; i++)
	{
		for(j=1; j<=6; j++)
		{
			if(map[i][j]=='R'||map[i][j]=='G'||map[i][j]=='B'||map[i][j]=='P'||map[i][j]=='Y')
			{
				if(check[i][j]==0)
				{
					check[i][j]=1;
					use.push_back(make_pair(i,j));
					color=map[i][j];
					cnt=1;
					Q.push(make_pair(i,j));
					
					
					while(!Q.empty())  // BFS를 통해 상하좌우에 같은색의 뿌요가 4개이상 있는지 확인  
					{
						x=Q.front().first;
						y=Q.front().second;
						Q.pop();
						
						for(k=0; k<=3; k++)
						{
							xx=x+dx[k];
							yy=y+dy[k];
							
							if(xx>=1&&xx<=12&&yy>=1&&yy<=6)
							{
								if(check[xx][yy]==0&&map[xx][yy]==color)
								{
									check[xx][yy]=1; 
									cnt++;
									use.push_back(make_pair(xx,yy));
									Q.push(make_pair(xx,yy));
																	}
							}
						}
					}
					if(cnt>=4)  // 4개이상 있으면 제거  
					{
						if(flag==0)
						{
							flag=1;
							ans++;    
						}
						while(!use.empty()) 
						{
							map[use.back().first][use.back().second]='.';
							use.pop_back();
						}
					}
					
					else{
						while(!use.empty()) 
						{
							
							use.pop_back();
						}
					}
					
				}
				
			}
		}
	}
	
	
 
  for(i=1; i<=12; i++)  
  {
  	for(j=1; j<=6; j++)
  	{
  		check[i][j]=0;
	  }
  }
  
  for(j=1; j<=6; j++)     // 비어있는곳이 없게끔 밑으로 내려주기  
  {
    
  for(i=11; i>=1; i-- ) 
  {
  	if(map[i][j]!='.')  
  	{
	  
  	 x=i;
	   while(1)
	   { 
	      x++;  
	   	  
	   	if(x<=12&&map[x][j]=='.')
	   	   {
	   	   	    map[x][j]=map[x-1][j];
	   	   	    map[x-1][j]='.';
			  }
	   	
	   	  else  break;
		} 
	}
  }
}


}

printf("%d",ans);

return 0;
}
