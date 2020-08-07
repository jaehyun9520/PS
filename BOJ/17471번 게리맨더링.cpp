#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n,i,j,a,val,x=0,y=0,result=9999;
int color[11]={0};
int map[11]={0};
int check[11]={0};
vector <int> node[10];


void dfs2(int x)  // 선거구에 속한 구역끼리 연결되어있는지 확인 X=  구역번호  
{
	int tmp,j;
	check[x]=1;   
	

	for(j=0; j<node[x].size(); j++)
	{
		 tmp=node[x][j];
		 if(check[tmp]==0&&color[x]==color[tmp])   
		 {
		 	dfs2(tmp);
		 }
	}
}

void dfs(int cnt, int node)  // cnt= A선거구에 뽑는 구역의 개수 , node= 몇번 구역인지  
{
	int flag=0,a=0,b=0,j,i;   
   
   for(j=1; j<=n; j++)
   {
   	check[j]=0;          
   }

	if(cnt<=(n/2))    // 구역의 개수가 10개라면  A구역에 1개부터 5개까지 뽑는경우의 수만 하면 중복되는것 없음  
	{

	
	
	for(i=node; i<=n; i++)  // A선거구에 구역 뽑기    
	{	 
		if(color[i]==0)  
		{      
	
			color[i]=1;   // A선거구에 속한 구역은 1로 표시  
			
			
			
			 
			dfs2(i); // A선거구에 속한 구역끼지 서로 연결되어있는지 확인  
			
			
			
			for( j=1; j<=n; j++)     //  A선거구에 뽑히지않은 즉 B선거구에 속한 구역끼리 서로 연결되어있는지 확인  
			{
				if(color[j]==0&&check[j]==0)
				{
					dfs2(j);
					break;
				}
						}			
		
		
			for(j=1; j<=n; j++)   
			{
				if(check[j]==0)
				{
					flag=1;   //    같은 선거구의 구역들이 서로 연결되있지 않음   
				}
		}		
		if(flag==0)  // 각 선거구의 구역끼리 연결되어있음 
			{
				for(j=1; j<=n; j++)
				{
					if(color[j]==1)
					{
						a=a+map[j];     //   A선거구의 인구수 총합  
					}
					else if(color[j]==0)
					{
						b=b+map[j];  // B선거구의 인구수 총합  
					}
				}
				if(result>abs(a-b))   // 최소값 찾기  
			{
				
				result=abs(a-b);
			}
			
			}
			dfs(cnt+1,i+1);
			
			

			   color[i]=0;
               a=0; b=0; flag=0;  
			   for(j=1; j<=n; j++)    
			   {
			   	check[j]=0;
						   }			
			
		
		}
		
	}
}
	
	
}
 

int main()
{//freopen("input.txt", "rt", stdin);

scanf("%d",&n);


for(i=1; i<=n; i++)    // 각 구역의 인구수 받기  
{
	scanf("%d",&map[i]);
}


for(i=1; i<=n; i++)  // 각 구역들과 연결된 구역들 정보    백터 인접리스트 이용   
{
	scanf("%d",&a);
	
	for(j=1; j<=a; j++)
	{
		scanf("%d",&val);
		node[i].push_back(val);
	}
	
}


dfs(1,1);  //  N개의 구역을 A선거구로 뽑는 경우의 수 구하기 이때    1~N/2개를 뽑기  (조합) 

  
if(result==9999)    
{
	printf("-1");   
}
else{

printf("%d",result);
}
return 0;

}

