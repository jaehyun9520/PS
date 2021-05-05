#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int min1=21470000;
int n;
int map[12][12]={0}; 
int check[12][12]={0};


void search(int cnt,int cost,int x, int y)
{
	int nx, ny,sum;
	vector < pair < int , int > > list;
	
	if(cnt==3)
	{
		if(min1>cost) min1=cost;
	}
	
	else
	{
		for(int i=x; i<=n-1; i++)
	    {
	    	for(int j=2 ;j<=n-1; j++ )
	    	{
	    		if(check[i][j]==0)
	    		{
	    			check[i][j]=1;
	    			
	    		    sum=map[i][j];
	    			
	    			
	    			for(int k=0; k<=3; k++)
	    			{
	    				nx=dx[k]+i;
	    				ny=dy[k]+j;
	    				
	    				if(check[nx][ny]==0)
	    				{
	    					check[nx][ny]=1;
	    					sum+=map[nx][ny];
	    					list.push_back(make_pair(nx,ny));
	    					
	    					
						}
	
					}
						if(list.size()==4&&min1>cost+sum)// 더크면 넘어갈 필요가 없죠 
						{
							search(cnt+1,cost+sum,i,j);
							
							
						}
						
						check[i][j]=0;
						
						for(int k=0; k<list.size(); k++)
						{
							check[list[k].first][list[k].second]=0;
						}
						list.clear();
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
int i,j;

cin>>n;

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		cin>>map[i][j];
	}
}


search(0,0,2,2);
cout<<min1;
return 0;
}
