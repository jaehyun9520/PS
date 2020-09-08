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
int m,n,k,i,a,b,c,d,j,z,cnt=0,x,y,count,nx,ny;
int map[101][101]={0};

queue < pair < int , int > > Q;
vector <int> answer;
scanf("%d %d %d",&m,&n,&k);

for(i=1; i<=k ; i++)   // 입력값을 MAP에 1로 표시  
{
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	for(j=b+1; j<=d; j++)
	{
		for(z=a+1; z<=c; z++)
		{
			map[j][z]=1;
		}
	}
}

for(i=1; i<=m; i++)   // BFS를 이용해서 구역이 몇개인지 구역의 크기는 몇인지  
{
	for(j=1; j<=n; j++)
	{
		if(map[i][j]==0)
		{ 
		    cnt++;
		    count=1;
			map[i][j]=1;
			Q.push(make_pair(i,j));
			
			while(!Q.empty())
			{
			    
				x=Q.front().first;
				y=Q.front().second;
				
				Q.pop();
				for(k=0; k<=3; k++)
				{
					nx=x+dx[k];
					ny=y+dy[k];
					
					  if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&map[nx][ny]==0)
					  {
					  	
						count++;
					  	map[nx][ny]=1;
					  	Q.push(make_pair(nx,ny));
					  }
				}
			}
			answer.push_back(count);
		}
	}
}

sort(answer.begin(),answer.end());

printf("%d \n",cnt);

for(i=0; i<answer.size(); i++)
{
	printf("%d ",answer[i]);
}
return 0;

}

