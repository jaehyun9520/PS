#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>



using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int map[101][101]={};
int check[101][101]={};
char a[101]={};
int n,cnt=0,color=0;

int main()
{
//freopen("input.txt", "rt", stdin);

int i,j,k,nowx,nowy,nextx,nexty,count=0;
queue < pair <int , int > > Q;
scanf("%d",&n);

for(i=1; i<=n; i++)
{
	scanf("%s",a);
	   
	   for(j=0; a[j]!='\0'; j++)
	   {
	   	map[i][j+1]=a[j];
	   }
}

while(count!=2)  // 일반인과 적록색약 두경우를 구하기위해  
{

for(i=1; i<=n; i++)   
{
	for(j=1; j<=n; j++)
	{
		if(check[i][j]==0&&color==0)    
		{
			check[i][j]=1;
			color=map[i][j];
			
			Q.push(make_pair(i,j));
			
			while(!Q.empty())    // 구역이 몇개인지 구하기  
			{ 
				nowx=Q.front().first;
				nowy=Q.front().second;
				Q.pop();
				for(k=0; k<=3; k++)
				{
					nextx=nowx+dx[k];
					nexty=nowy+dy[k];
					
					if(nextx>=1&&nextx<=n&&nexty>=1&&nexty<=n)
					{
						if(check[nextx][nexty]==0&&map[nextx][nexty]==color)
						{
							check[nextx][nexty]=1;
							Q.push(make_pair(nextx,nexty));
						}
						
					}
				}
				if(Q.empty())
				{
					cnt++;
					color=0;
					
					
				    	
				}
				
			}
		}
		
	}

}

printf("%d ",cnt);


count++; cnt=0;
if(count==1)   
{
for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		check[i][j]=0;
		
		if(map[i][j]==71)
		{
			map[i][j]=82;
		}
	}
}
}
}






return 0;
}
