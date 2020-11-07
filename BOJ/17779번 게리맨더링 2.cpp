#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int area[5]={0} ;
int map[21][21]={0};
bool check[21][21]={0};
int n,ans=100000,total=0,val=0;

void line(int x, int y, int d1, int d2) // 경계선 만들기  
  {

	for(int i=0; i<=d1; i++) //1번 경계선					
		check[x+i][y-i]=1;   
		
   
  	for(int i=0; i<=d2; i++)//2번 경계선 
  	    check[x+i][y+i]=1;
  	    

    for(int i=0; i<=d2; i++)//3번 경계선  
     	check[x+d1+i][y-d1+i]=1;

  	for(int i=0; i<=d1; i++)//4번 경계선 	
  	    check[x+d2+i][y+d2-i]=1;
				 
  }  

void COUNT(int x, int y, int d1, int d2)//각 선거구 인구수 카운트  
  {
	int i,j;
	
	for(i=1; i<x+d1; i++)  //1번 선거구  
	{
	   for(j=1 ; j<=y; j++)
	    {
	    	if(check[i][j]==1) break;
	    	
	    	
	    	area[1]=area[1]+map[i][j];
		}
	}
	
	for(i=1; i<=x+d2; i++) //2번 선거구  
	{
	    for(j=n ; j>y; j--)
	    {
	    	if(check[i][j]==1) break;
	    	area[2]=area[2]+map[i][j];
		}
    }
    
	for(i=x+d1; i<=n; i++) //3번 선거구  
	{
	
	 for(j=1; j<y-d1+d2; j++)
	    {
	 	   if(check[i][j]==1) break;
	 	   area[3]=area[3]+map[i][j];
	    }
	 
    }
	
	 
	 for(i=x+d2+1; i<=n; i++) //4번 선거구  
	{
	 for(j=n; j>=y-d1+d2; j--)
	    {
	 	  if(check[i][j]==1) break;
	 	  area[4]=area[4]+map[i][j];
	    }
    }
}

int main()
{
//freopen("input.txt", "rt", stdin);	

int x,y,d1,d2,i,j;

cin>>n;

for(x=1; x<=n; x++)
  for(y=1; y<=n; y++) 
  {
      cin>>map[x][y];  total=total+map[x][y];
 }

for(x=1; x<=n-2; x++)
     for(d1=1; d1<=n-1-x; d1++)
       for(d2=1; d2<=n-d1-x; d2++)
         for(y=d1+1; y<=n-d2; y++)
             {
           	line(x,y,d1,d2); 
            COUNT(x,y,d1,d2);
	            
	            area[0]=total-area[1]-area[2]-area[3]-area[4]; // 5번 선거구 구하기 
	            
	            
	            sort(area,area+5);
	            val=area[4]-area[0];
	            
	            if(ans>val)  ans=val;
	            
	            for(i=0; i<=4; i++) area[i]=0;
	            
	            
	            for(i=1; i<=n;i++)
	              for(j=1; j<=n; j++)
	                 check[i][j]=0;
					 
					 			 }
       	 
cout<<ans;
return 0;
}
