#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int map[11][11]={0};
int food[11][11]={0};
vector <int> tree [101];
int born[11][11]={0}; 
int n,m,k;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void process()
{
	int i,j,x,y,flag,cnt,nx,ny;
	
	for(i=1; i<=n*n; i++)   
	{
		if(tree[i].size()!=0) // 각 칸에 나무가 있는지   
		{
					
			if(i%n==0) 
			{
			x=i/n;  y=n;  
		    }
			else 
			{
			x=i/n+1; y=i%n;     
		   }
			
			flag=0; cnt=0;
			
		   for(j=0; j<tree[i].size(); j++) 
		   {
		   	if(flag==0) //양분이 충분    
		   	{
			   
		   	   if(map[x][y]>=tree[i][j])
		   	   {
		   	 
		   	   	  map[x][y]-=tree[i][j];  
		   	   	  tree[i][j]++;
		   	   	 
		   	   	  if(tree[i][j]%5==0) 
						{
						 
							born[x][y]++;  
						 } 
			  }
			  
			  else    //양분이 부족하다면 나무가 죽고 나무나이/2만큼 양분에 추가  
			  {
			  	cnt++; map[x][y]+=(tree[i][j]/2);
			  	flag=1;
			  
		      }
		  }
		  
		  else{
		  	
		  	cnt++; map[x][y]+=(tree[i][j]/2);   
		  }
		  
			} 
			
			j=0;
			while(j!=cnt)   //죽은나무 제거   
			{
				j++;
				tree[i].pop_back();
			 } 
		 
		
		 } 
	}

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
		
			if(born[i][j]!=0) //5의 배수인 나무들의 위치와 개수  
			{
				
				cnt=0;
				while(cnt<born[i][j])  //개수만큼 주변 8칸에 퍼트리기  
				{
					for(int z=0; z<=7; z++)  
						{
							nx=i+dx[z];
							ny=j+dy[z];
							if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
							{
							
								tree[(nx-1)*n+ny].push_back(1);
							}
							
						}
					cnt++;
						}
								
						
								born[i][j]=0; //다시 초기화 				
			}
		}
	 } 
  
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			map[i][j]+=food[i][j];   //입력값만큼 양분 추가  
		
			
			
			if(tree[(i-1)*n+j].size()!=0)  // 나무 오름차순 정렬  
			{
				
				sort(tree[(i-1)*n+j].begin(),tree[(i-1)*n+j].end());
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

int i,j,x,y,age,ans=0;
cin>>n>>m>>k;

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		cin>>food[i][j];
		map[i][j]=5;
	}
}

for(i=1; i<=m; i++)
{
	cin>>x>>y>>age;
	tree[(x-1)*n+y].push_back(age);
	
}


for(i=1; i<=k; i++)
{ 
	process();
	
}

for(i=1; i<=n*n; i++)
{
	ans+=tree[i].size();
}

cout<<ans;
return 0;
}
