#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;


struct state {
	
	int x, y,  cnt, blank;
	
	state(int a, int b, int c, int d)
	{
		x=a, y=b, cnt=c, blank=d;
	}
	
	
	bool operator<(const state &b) const
	{
	
		 if(cnt==b.cnt)  //인접한 칸에 친구가 몇명있는지  
		        {
		        	
					
			      if(blank==b.blank)  //빈칸이 몇개 있는지  
				  {
				  	   
						 
						 if(x==b.x)
						 {
						 	return y>b.y;   
						  } 
						  
						 else return x>b.x;   
					}
					
					else return blank<b.blank;   		 
				
	            }
	       else  return cnt<b.cnt;     
}
};



int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int map[21][21]={0};
int i,n,number;
int a,b,c,d,j,k,ans=0,sum;
int blank,cnt,x,y;

priority_queue < state > PQ;
vector <int> list[401];
cin>>n;

for(i=1; i<=n*n; i++)
{
	cin>>number>>a>>b>>c>>d;
		
	list[number].push_back(a);
	list[number].push_back(b);
	list[number].push_back(c);
	list[number].push_back(d);
	
	
	for(j=1; j<=n; j++) 
	{
		for(k=1; k<=n; k++)
		{
			if(map[j][k]==0) 
			{
				blank=0; cnt=0;   
				 for(int z=0; z<=3; z++)
				 {
				 	int nj=j+dx[z];
				 	int nk=k+dy[z];
				 	
				 	if(nj>=1&&nj<=n&&nk>=1&&nk<=n)
				 	{
				 		if(map[nj][nk]==a||map[nj][nk]==b||map[nj][nk]==c||map[nj][nk]==d)
				 		{
				 			cnt++;
						 }
						 
						else if(map[nj][nk]==0) 
						{
							blank++; 
						 } 
	 		
					 }

				 }
				PQ.push(state(j,k,cnt,blank));
			} 
		}
	}
	
	
	x=PQ.top().x;
	y=PQ.top().y;
	map[x][y]=number;	
	while(!PQ.empty())
	{
		PQ.pop();
	}
	
	
	
}


for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		sum=0;
		
		number=map[i][j];
		
		for(k=0; k<=3; k++)
		{
			x=i+dx[k];
			y=j+dy[k];
			
			if(x>=1&&x<=n&&y>=1&&y<=n)
			{
				if(list[number][0]==map[x][y]||list[number][1]==map[x][y]||list[number][2]==map[x][y]||list[number][3]==map[x][y])
				{
					sum++;
				}
			}
		}
		if(sum==1)
		ans+=1;
		
		else if(sum==2)
		ans+=10;
		
		else if(sum==3)
		ans+=100;
		
		else if(sum==4)
		ans+=1000;	
	}

}

cout<<ans;

return 0;
}
