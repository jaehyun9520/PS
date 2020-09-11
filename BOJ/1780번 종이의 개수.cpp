#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int map[2188][2188];
int a[3]={0};
	

void func(int n, int x, int y)
{
	int i,j,val,flag=0;
	if(n==1)   
	{
		
				if(map[x][y]==-1)
				  {
				
				             a[2]++;
			      }
				             else
				             {
							 
				               a[map[x][y]]++;
				           }
		
	}
	
	else{
		
	          val=map[x][y];  // 확인할려고 하는 종이의 첫번째 값  
	         
	          
	          
	          
	          for(i=x; i<x+n; i++)
	          {
	          	for(j=y; j<y+n; j++)
	          	{
	          		if(val!=map[i][j])  // 값이 다르면 종이 9등분  
					  {
					  flag=1;
					  break;
				}
				  }
			  }
			  
			  if(flag==0)   //  종이 안의 값이 다 같은 수로 채워진경우  
			  {
			  	if(val==-1)   a[2]++;
			  	
			  	
			  	else
			  	   a[val]++;
			  }
			  
			  
			  else if(flag==1)  // 9등분  
			  {
			  	
			  	func(n/3,x,y);     
			  	func(n/3,x,y+n/3);   
			  	func(n/3,x,y+2*n/3);     
			  	func(n/3,x+n/3,y);     
			  	func(n/3,x+n/3,y+n/3);  
			  	func(n/3,x+n/3,y+2*n/3);
			  	func(n/3,x+2*n/3,y);
			  	func(n/3,x+2*n/3,y+n/3);
			  	func(n/3,x+2*n/3,y+2*n/3);
			  	
			  }
		
	}

	
	}	


int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,j,val;
scanf("%d",&n); 

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
		
	}
}

func(n,1,1);   

printf("%d\n%d\n%d",a[2],a[0],a[1]);
return 0;

}
